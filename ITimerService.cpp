#define LOG_TAG "TimerService"

#include <stdint.h>
#include <sys/types.h>

#include <utils/String16.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "ITimerService.h"
#include "ICallbackService.h"

namespace android {

class BpTimerService: public BpInterface<ITimerService>
{
public:
    BpTimerService(const sp<IBinder>& impl)
        : BpInterface<ITimerService>(impl)
    {
    }

    virtual void registerCallback(sp<IBinder>& binder, int timeout)
    {
        Parcel data, reply;
        data.writeInterfaceToken(ITimerService::getInterfaceDescriptor());
        data.writeStrongBinder(binder);
        data.writeInt32(timeout);
        remote()->transact(BnTimerService::TRANSACTION_REGISTER_CALLBACK, data, &reply);
        return;
    }
};

IMPLEMENT_META_INTERFACE(TimerService, "chengyihe.test.ITimerService");

status_t BnTimerService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case TRANSACTION_REGISTER_CALLBACK: {
            CHECK_INTERFACE(ITimerService, data, reply);
            sp<IBinder> service = data.readStrongBinder();
            int timeout = data.readInt32();
            registerCallback(service, timeout);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
    // should be unreachable
    return NO_ERROR;
}

}; // namespace android
