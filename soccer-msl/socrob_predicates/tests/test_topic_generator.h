#ifndef _TEST_TOPIC_GENERATOR_H_
#define _TEST_TOPIC_GENERATOR_H_

#include <cmath>

#include <ros/ros.h>
#include <std_msgs/Float64.h>



class TestTopicGenerator
{
    ros::NodeHandle nh_;
    
    double number_;
    ros::Publisher number_pub_;
    ros::Publisher periodic_pub_;
    ros::Timer number_timer_;
    
    
  public:
    TestTopicGenerator() :
      nh_(),
      number_ (0),
      number_pub_ (nh_.advertise<std_msgs::Float64> ("test_number", 1)),
      periodic_pub_ (nh_.advertise<std_msgs::Float64> ("test_periodic", 1)),
      number_timer_ (nh_.createTimer (ros::Duration (1.0 / 6), &TestTopicGenerator::numberTimerCallback, this)) {
    }
    
    void
    numberTimerCallback (const ros::TimerEvent&) {
      {
        std_msgs::Float64 msg;
        msg.data = number_;
        number_pub_.publish (msg);
      }
      
      {
        std_msgs::Float64 msg;
        msg.data = sin (number_);
        periodic_pub_.publish (msg);
      }
      
      number_ += M_PI / 6;
    }
};

#endif
