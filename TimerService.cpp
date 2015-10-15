#define LOG_TAG "TimerService"

#include <sys/wait.h>
#include <unistd.h>

#include <cutils/log.h>
#include <binder/BinderService.h>

#include "TimerService.h"

namespace android {

TimerService::TimerService()
{
    this->run("TimerServiceThread");
}

TimerService::~TimerService()
{
}

void TimerService::registerCallback(sp<IBinder>& binder, int timeout)
{
    Mutex::Autolock _l(mLock);

    sp<ICallbackService> callback = interface_cast<ICallbackService>(binder);
    mCallbacks.push(callback);
    mTimeouts.add(callback, timeout);
    LOGD("Service does registerCallback timeout = 30");
}

bool TimerService::threadLoop()
{
    {
        Mutex::Autolock _l(mLock);

        for (int i = mCallbacks.size() - 1; i >= 0; i--) {
            sp<ICallbackService> callback = mCallbacks[i];

            if (--mTimeouts.editValueFor(callback) <= 0) {
                LOGD("Request callback to execute, timeout = 30");
                callback->execute();
                mCallbacks.removeAt(i);
                mTimeouts.removeItem(callback);
            }
        }
    }

    usleep(1000000);

    return true;
}

}; // namespace android
