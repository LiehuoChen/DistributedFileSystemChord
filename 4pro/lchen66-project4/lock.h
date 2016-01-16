#ifndef _LH_LOCK_H
#define _LH_LOCK_H


class PthreadMutex;

class AutoLock
{
private:
    PthreadMutex *_lock;

public:
    static PthreadMutex* init();
    static void destroy(PthreadMutex *lock);
    AutoLock(PthreadMutex *lock);
    ~AutoLock();
};

#endif

