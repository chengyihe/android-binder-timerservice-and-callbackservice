LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += \
	ICallbackService.cpp \
	CallbackService.cpp

LOCAL_STATIC_LIBRARIES += \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := libcallbackservice
LOCAL_MODULE_TAGS := optional

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += \
	ITimerService.cpp \
	TimerService.cpp

LOCAL_STATIC_LIBRARIES += \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := libtimerservice
LOCAL_MODULE_TAGS := optional

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := TimerServer.cpp
LOCAL_STATIC_LIBRARIES += \
	libtimerservice \
	libcallbackservice \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE:= timerserver
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := TimerClient.cpp
LOCAL_STATIC_LIBRARIES += \
	libtimerservice \
	libcallbackservice \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := timerclient
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
