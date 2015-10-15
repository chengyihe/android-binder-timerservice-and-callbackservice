#ifndef ITIMERSERVICE_H
#define ITIMERSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

namespace android {

class ITimerService: public IInterface {
public:
    DECLARE_META_INTERFACE(TimerService);

    virtual void registerCallback(sp<IBinder>& binder, int timeout) = 0;
};

class BnTimerService: public BnInterface<ITimerService> {
public:
    enum {
        TRANSACTION_REGISTER_CALLBACK = IBinder::FIRST_CALL_TRANSACTION,
    };

    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flag = 0);
};

}; // namespace android

#endif // ITIMERSERVICE_H
