#ifndef SOCROB_PREDICATES_PROTOTYPE_H
#define SOCROB_PREDICATES_PROTOTYPE_H

#include <string>
#include <vector>

#include <boost/function.hpp>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

#include <ros/ros.h>

#include <socrob_predicates/PredicateInfoMap.h>



namespace socrob
{
  namespace predicates
  {
    using namespace std;
    
    typedef unsigned int RunningPredicate;
    
    
    
    struct CallbackOptionsBase {};
    
    struct SubscriberOptionsBase {};
    template<typename TYPE>
    struct SubscriberOptions:
      public SubscriberOptionsBase {
      string topic_name;
      bool force_update;
      vector<CallbackOptionsBase*> callbacks_;
    };
    
    struct PredicateOptions {
      // Predicate* p;
      bool initial_value;
      
      boost::function<bool() > update;
      bool always_run_update;
      
      vector<SubscriberOptionsBase*> subscriptions;
    };
    
    
    
    ros::Publisher predicate_info_map_pub_;
    
    void init (ros::NodeHandle& nh)
    {
      predicate_info_map_pub_ = nh.advertise<socrob_predicates::PredicateInfoMap> ("predicate_info_map", 1, true);
    }
    
    
    
    uint32_t next_id_;
    uint32_t getNextId()
    {
      return next_id_++;
    }
    
    
    
    vector<bool> value_;
    
    vector<bool> named_;
    vector<string> name_;
    vector<uint32_t> pub_id_;
    
    vector<boost::function<bool() > > update_;
    vector<bool> always_run_update_;
    
    RunningPredicate addPredicate (PredicateOptions options)
    {
      value_.push_back (options.initial_value);
      named_.push_back (false);
      name_.push_back ("");
      pub_id_.push_back (0);
      update_.push_back (options.update);
      always_run_update_.push_back (options.always_run_update);
      
      return value_.size() - 1;
    }
    
    
    
    void name (RunningPredicate id, string const& name)
    {
      named_[id] = true;
      name_[id] = name;
      pub_id_[id] = getNextId();
      
      // update_predicate_info_map
      socrob_predicates::PredicateInfoMap::Ptr msg = boost::make_shared<socrob_predicates::PredicateInfoMap>();
      msg->header.stamp = ros::Time::now();
      
      for (std::size_t i = 0; i < value_.size(); ++i) {
        if (named_[i]) {
          socrob_predicates::PredicateInfo pi;
          pi.id = pub_id_[i];
          pi.name = name_[i];
          ROS_DEBUG_STREAM ("update_predicate_info_map: Adding \"" << pi.name << "\" with id " << pi.id);
          msg->map.push_back (pi);
        }
      }
      
      predicate_info_map_pub_.publish (msg);
    }
  }
}

#endif
