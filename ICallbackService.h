#ifndef ICallbackSERVICE_H
#define ICallbackSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

namespace android {

class ICallbackService: public IInterface {
public:
    DECLARE_META_INTERFACE(CallbackService);

    virtual void execute() = 0;
};

class BnCallbackService: public BnInterface<ICallbackService> {
public:
    enum {
        TRANSACTION_EXECUTE = IBinder::FIRST_CALL_TRANSACTION,
    };

    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flag = 0);
};

}; // namespace android

#endif // ICallbackSERVICE_H
