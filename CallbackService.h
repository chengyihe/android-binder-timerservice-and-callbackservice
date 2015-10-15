#ifndef CallbackSERVICE_H
#define CallbackSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

#include "ICallbackService.h"

namespace android {

class CallbackService: public BnCallbackService
{
public:
    CallbackService();
    ~CallbackService();
    virtual void execute();
    mutable Condition mCondition;
    mutable Mutex mLock;
};

}; // namespace android

#endif // CallbackSERVICE_H
