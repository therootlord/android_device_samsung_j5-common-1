# Copyright (C) 2009 The Android Open Source Project
# Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import common
import re
import os

"""Custom OTA commands for j5 devices"""

def FullOTA_InstallBegin(info):
    info.script.AppendExtra('ifelse(is_mounted("/system"), unmount("/system"));')
    info.script.Print("Mounting /system...")
    info.script.Mount("/system")
    info.script.Print("Checking SDK version...")
    info.script.AppendExtra('package_extract_file("install/bin/check_sdk_version.sh", "/tmp/check_sdk_version.sh");')
    info.script.AppendExtra('rename("/tmp/check_sdk_version.sh", "/tmp/install/bin/check_sdk_version.sh");')
    info.script.AppendExtra('set_metadata("/tmp/install/bin/check_sdk_version.sh", "uid", 0, "gid", 0, "dmode", 0755, "fmode", 0755);')
    info.script.AppendExtra('ifelse((run_program("/tmp/install/bin/check_sdk_version.sh") != 0), abort("Refusing to downgrade system. Wipe data and system first or install proper package."));')
    info.script.Unmount("/system")

def FullOTA_InstallEnd(info):
    info.script.Print("Mounting /system...")
    info.script.Mount("/system")
    info.script.Print("Updating device variant name...")
    info.script.AppendExtra('assert(run_program("/tmp/install/bin/update_device_name.sh") == 0);')
    info.script.Print("Copying device variant blobs ...")
    info.script.AppendExtra('assert(run_program("/tmp/install/bin/copy_variant_blobs.sh") == 0);')
    info.script.Print("Copying nfc files ...")
    info.script.AppendExtra('assert(run_program("/tmp/install/bin/copy_nfc_configs.sh") == 0);')
    info.script.Print("Flashing baseband...")
    info.script.AppendExtra('assert(run_program("/tmp/install/bin/update_baseband.sh") == 0);')
    info.script.Unmount("/system")

def FullOTA_PostValidate(info):
    # run e2fsck
    info.script.Print("Checking the file system on /system...")
    info.script.AppendExtra('run_program("/sbin/e2fsck", "-fy", "/dev/block/bootdevice/by-name/system");')
    # resize2fs: run and delete
    info.script.Print("Resizing /system to maximal size...")
    info.script.AppendExtra('run_program("/sbin/resize2fs", "-p", "/dev/block/bootdevice/by-name/system");')
    # run e2fsck
    info.script.Print("Checking the file system on /system after resize...")
    info.script.AppendExtra('run_program("/sbin/e2fsck", "-fy", "/dev/block/bootdevice/by-name/system");')
