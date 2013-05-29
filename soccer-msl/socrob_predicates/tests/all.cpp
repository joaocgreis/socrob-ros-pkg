#include <boost/bind.hpp>

#include <ros/ros.h>

#include <socrob/predicates.h>

#include "test_topic_generator.h"



using namespace std;
using namespace socrob::predicates;



class PeriodicNegative :
  public Predicate
{
    PeriodicNegative() {
    }
    
    bool update() {
      return true;
    }
    
  public:
  
    static RunningPredicate
    build (PredicateManager* pm) {
      PeriodicNegative* instance = new PeriodicNegative();
      PredicateOptions options;
      options.p = instance;
      options.initial_value = false;
      options.update = boost::bind (&PeriodicNegative::update, instance);
      options.always_run_update = true;
      return pm->add (options);
    }
};



class PredicateTester :
  private PredicateManager
{
  public:
    PredicateTester() {
      /*RunningPredicate peiodicNegative =*/ PeriodicNegative::build (this).name ("PeiodicNegative");
      /*
      peiodicNegative->event_rise ("BallOurSide");
      peiodicNegative->event_fall ("BallTheirSide");
      */
    }
};



int
main (int argc,
      char* argv[])
{
  ros::init (argc, argv, "test_all");
  
  TestTopicGenerator ttg;
  
  PredicateTester pt;
  
  ros::spin();
  
  return 0;
}
