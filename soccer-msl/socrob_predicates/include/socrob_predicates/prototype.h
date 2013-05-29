#ifndef SOCROB_PREDICATES_PROTOTYPE_H
#define SOCROB_PREDICATES_PROTOTYPE_H

#include <string>
#include <vector>

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

#include <ros/ros.h>

#include <socrob_predicates/PredicateInfoMap.h>



namespace socrob
{
  namespace predicates
  {
    using namespace std;
    
    class Predicate;
    struct PredicateManager;
    struct PredicateController;
    struct RunningPredicate;
    
    
    
    class Predicate
    {
    };
    
    
    
    struct PredicateManager {
      ros::NodeHandle nh_;
      ros::Publisher predicate_info_map_pub_;
      
      uint32_t next_id_;
      vector<PredicateController*> predicates_;
      
      
      PredicateManager();
      
      RunningPredicate add (Predicate* p);
      
      void update_predicate_info_map();
      uint32_t getNextId();
    };
    
    
    
    struct PredicateController {
      PredicateManager* pm_;
      Predicate* p_;
      
      bool named_;
      string name_;
      uint32_t id_;
      
      
      PredicateController (PredicateManager* pm, Predicate* p);
    };
    
    
    
    struct RunningPredicate {
      PredicateController* pc_;
      
      
      RunningPredicate (PredicateController* pc);
      
      RunningPredicate name (string const& name);
    };
    
    
    
    inline
    PredicateManager::
    PredicateManager() :
      nh_(),
      predicate_info_map_pub_ (nh_.advertise<socrob_predicates::PredicateInfoMap> ("predicate_info_map", 1, true)),
      next_id_()
    {
      ROS_DEBUG_STREAM ("Initializing PredicateManager");
    }
    
    
    
    inline RunningPredicate
    PredicateManager::
    add (Predicate* p)
    {
      PredicateController* pc = new PredicateController (this, p);
      predicates_.push_back (pc);
      return RunningPredicate (pc);
    }
    
    
    
    inline void
    PredicateManager::
    update_predicate_info_map()
    {
      socrob_predicates::PredicateInfoMap::Ptr msg = boost::make_shared<socrob_predicates::PredicateInfoMap>();
      msg->header.stamp = ros::Time::now();
      
      foreach (PredicateController * pc, predicates_) {
        if (pc->named_) {
          socrob_predicates::PredicateInfo pi;
          pi.id = pc->id_;
          pi.name = pc->name_;
          ROS_DEBUG_STREAM ("update_predicate_info_map: Adding \"" << pi.name << "\" with id " << pi.id);
          msg->map.push_back (pi);
        }
      }
      
      predicate_info_map_pub_.publish (msg);
    }
    
    
    
    inline uint32_t
    PredicateManager::
    getNextId()
    {
      return next_id_++;
    }
    
    
    
    inline
    PredicateController::
    PredicateController (PredicateManager* pm, Predicate* p) :
      pm_ (pm),
      p_ (p),
      named_ (false),
      name_(),
      id_()
    {
    }
    
    
    
    inline RunningPredicate::RunningPredicate (PredicateController* pc) :
      pc_ (pc)
    {
    }
    
    
    
    inline RunningPredicate
    RunningPredicate::
    name (const string& name)
    {
      pc_->named_ = true;
      pc_->name_ = name;
      pc_->id_ = pc_->pm_->getNextId();
      pc_->pm_->update_predicate_info_map();
      return *this;
    }
  }
}

#endif
