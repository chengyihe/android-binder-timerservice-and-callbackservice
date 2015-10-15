#define LOG_TAG "ICallbackService"

#include <stdint.h>
#include <sys/types.h>

#include <utils/String16.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "ICallbackService.h"

namespace android {

class BpCallbackService: public BpInterface<ICallbackService>
{
public:
    BpCallbackService(const sp<IBinder>& impl)
        : BpInterface<ICallbackService>(impl)
    {
    }

    virtual void execute()
    {
        Parcel data, reply;
        data.writeInterfaceToken(ICallbackService::getInterfaceDescriptor());
        remote()->transact(BnCallbackService::TRANSACTION_EXECUTE, data, &reply);

        return;
    }
};

IMPLEMENT_META_INTERFACE(CallbackService, "chengyihe.test.ICallbackService");

status_t BnCallbackService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case TRANSACTION_EXECUTE: {
            CHECK_INTERFACE(ICallbackService, data, reply);
            execute();
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
