LOCAL_PATH := $(call my-dir)
ifneq ($(filter gprimelte gprimeltexx gprimeltespr gprimeltetfnvzw gprimeltezt, $(TARGET_DEVICE)),)
######################
### init.target.rc
include $(CLEAR_VARS)
LOCAL_MODULE       := init.target.rc
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/$(LOCAL_MODULE)
LOCAL_MODULE_PATH  := $(TARGET_ROOT_OUT)
include $(BUILD_PREBUILT)
### init.perm_fixup.sh
include $(CLEAR_VARS)
LOCAL_MODULE       := init.perm_fixup.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/$(LOCAL_MODULE)
LOCAL_MODULE_PATH  := $(TARGET_ROOT_OUT)
include $(BUILD_PREBUILT)

######################
### init.ksm.sh
include $(CLEAR_VARS)
LOCAL_MODULE       := init.ksm.sh
LOCAL_MODULE_TAGS  := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/$(LOCAL_MODULE)
LOCAL_MODULE_PATH  := $(TARGET_ROOT_OUT)
include $(BUILD_PREBUILT)
######################
endif
