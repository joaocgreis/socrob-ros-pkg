#ifndef SOCROB_PREDICATES_PROTOTYPE_H
#define SOCROB_PREDICATES_PROTOTYPE_H

#include <string>
#include <vector>

#include <ros/ros.h>



namespace socrob
{
  namespace predicates
  {
    using namespace std;
    
    class Predicate;
    class PredicateManager;
    class PredicateController;
    class RunningPredicate;
    
    
    
    class Predicate
    {
    };
    
    
    
    class PredicateManager
    {
        ros::NodeHandle nh_;
        
        vector<PredicateController*> predicates_;
        
      public:
        PredicateManager();
        
        RunningPredicate add (Predicate* p);
    };
    
    
    
    class PredicateController
    {
        Predicate* p_;
        
      public:
        PredicateController (Predicate* p);
    };
    
    
    
    class RunningPredicate
    {
        PredicateController* pc_;
        
      public:
        RunningPredicate (PredicateController* pc);
        
        RunningPredicate name (string const& name);
    };
    
    
    
    inline
    PredicateManager::
    PredicateManager() :
      nh_()
    {
    }
    
    
    
    inline RunningPredicate
    PredicateManager::
    add (Predicate* p)
    {
      PredicateController* pc = new PredicateController (p);
      predicates_.push_back (pc);
      return RunningPredicate (pc);
    }
    
    
    
    inline
    PredicateController::
    PredicateController (Predicate* p) :
      p_ (p)
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
      return *this;
    }
  }
}

#endif
