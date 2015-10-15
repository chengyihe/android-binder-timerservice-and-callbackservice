#ifndef TIMERSERVICE_H
#define TIMERSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>
#include <utils/Mutex.h>

#include <binder/IInterface.h>

#include "ITimerService.h"
#include "ICallbackService.h"

namespace android {

class TimerService: public BnTimerService, Thread
{
public:
    TimerService();
    ~TimerService();
    void registerCallback(sp<IBinder>& binder, int sec);
    virtual bool threadLoop();
private:
    mutable Mutex               mLock;
    KeyedVector<sp<ICallbackService>, int> mTimeouts;
    Vector<sp<ICallbackService> >  mCallbacks;
};

}; // namespace android

#endif // TIMERSERVICE_H
