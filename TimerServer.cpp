#define LOG_TAG "TimerServer"

#include <utils/Log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "TimerService.h"

using namespace android;

int main()
{
    LOGD("TimerServer is starting");

    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();

    defaultServiceManager()->addService(String16("timer"), new TimerService);

    LOGD("Successfully register service: timer");
    LOGD("Ready to joinThreadPool");

    IPCThreadState::self()->joinThreadPool();

    return 0;
}
