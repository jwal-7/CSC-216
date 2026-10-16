#include <iostream>
#include "Heap.hpp"
#include "job.hpp"

#ifndef JOBQUEUE_LIBRARY
#define JOBQUEUE_LIBRARY

class JobQueue 
{
    private:
    Heap<Job> h = Heap<Job>();

    public:

    JobQueue(void) {} 

    void insert(Job input) 
    {
        h.insert(input);
    }

    void execute() 
    {
        Job j = h.extract();
        j.execute();
    }

    void runHighestPriority() 
    {
        execute();
    }

    bool is_empty() 
    {
        return h.empty();
    }
};


#endif