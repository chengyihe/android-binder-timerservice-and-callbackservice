#define LOG_TAG "CallbackService"

#include <sys/wait.h>
#include <unistd.h>

#include <cutils/log.h>
#include <binder/BinderService.h>

#include "CallbackService.h"

namespace android {

CallbackService::CallbackService()
{
}

CallbackService::~CallbackService()
{
}

void CallbackService::execute()
{
    Mutex::Autolock _l(mLock);

    LOGD("callback is executed");
    mCondition.signal();
}

}; // namespace android
