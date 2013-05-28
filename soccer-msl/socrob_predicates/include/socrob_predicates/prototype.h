#ifndef SOCROB_PREDICATES_PROTOTYPE_H
#define SOCROB_PREDICATES_PROTOTYPE_H



namespace socrob
{
  namespace predicates
  {
    class Predicate;
    class PredicateManager;
    class RP;
    
    class Predicate
    {
    };
    
    class PredicateManager
    {
    };
    
    class RP
    {
      public:
        void
        name (std::string const& name);
    };
  }
}



inline void
socrob::predicates::RP::
name (const std::string& name)
{
}

#endif
