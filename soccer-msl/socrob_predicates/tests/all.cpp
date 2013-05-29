#include <boost/bind.hpp>

#include <ros/ros.h>

#include <socrob/predicates.h>

#include "test_topic_generator.h"



using namespace std;
using namespace socrob::predicates;



namespace PeriodicNegative
{
  bool update()
  {
    return true;
  }
  
  RunningPredicate build ()
  {
    PredicateOptions options;
    options.initial_value = false;
    options.update = update;
    options.always_run_update = true;
    return addPredicate (options);
  }
};



int
main (int argc,
      char* argv[])
{
  ros::init (argc, argv, "test_all");
  TestTopicGenerator ttg;
  
  ros::NodeHandle nh;
  init (nh);
  
  RunningPredicate periodicNegative = PeriodicNegative::build();
  name (periodicNegative, "PeiodicNegative");
  
  /*
  peiodicNegative->event_rise ("BallOurSide");
  peiodicNegative->event_fall ("BallTheirSide");
  */
  
  ros::spin();
  return 0;
}
