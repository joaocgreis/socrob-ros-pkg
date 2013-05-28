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
    
    bool state() {
    }
};



class PredicateTester :
  private PredicateManager
{
  public:
    PredicateTester() {
      /*
      RP peiodicNegative = add<PeriodicNegative>().name ("PeiodicNegative");
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
