#include <pthread.h>
#include "lock.h"


class atomic_count
{
private:

    class scoped_lock
    {
    public:

        scoped_lock(pthread_mutex_t & m): m_(m)
        {
            pthread_mutex_lock(&m_);
        }

        ~scoped_lock()
        {
            pthread_mutex_unlock(&m_);
        }

    private:

        pthread_mutex_t & m_;
    };

public:

     atomic_count() 
    {
        pthread_mutex_init(&mutex_, 0);
    }

    ~atomic_count()
    {
        pthread_mutex_destroy(&mutex_);
    }

    void lock()
    {
        scoped_lock lock(mutex_);
        return ++value_;
    }


private:
    mutable pthread_mutex_t mutex_;
};
