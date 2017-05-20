/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above
	  copyright notice, this list of conditions and the following
	  disclaimer in the documentation and/or other materials provided
	  with the distribution.
	* Neither the name of The Linux Foundation nor the names of its
	  contributors may be used to endorse or promote products derived
	  from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void init_dsds() {
    property_set("ro.multisim.simslotcount", "2");
    property_set("persist.radio.multisim.config", "dsds");
	property_set("persist.radio.lte_vrte_ltd", "1");
	property_set("telephony.lteOnCdmaDevice", "0");
}

void init_target_properties(void)
{
	std::string bootloader = property_get("ro.bootloader");

	if (bootloader.find("J510GN") == 0) {
		property_set("ro.build.product", "j5xnlte");
		property_set("ro.build.description", "lineage_j5xnlte-userdebug 7.1.2 NMF26V 4dae919457 test-keys");
		property_set("ro.build.fingerprint", "samsung/lineage_j5xnlte/j5xnlte:7.1.2/NMF26V/4dae919457:userdebug/test-keys");
		property_set("ro.product.device", "j5xnlte");
		property_set("ro.product.model", "SM-J510GN");

		init_dsds();
	}
	else if (bootloader.find("J510MN") == 0) {
		property_set("ro.build.product", "j5xnlte");
		property_set("ro.build.description", "lineage_j5xnlte-userdebug 7.1.2 NMF26V 4dae919457 test-keys");
		property_set("ro.build.fingerprint", "samsung/lineage_j5xnlte/j5xnlte:7.1.2/NMF26V/4dae919457:userdebug/test-keys");
		property_set("ro.product.device", "j5xnlte");
		property_set("ro.product.model", "SM-J510MN");

		init_dsds();
	}
	else if (bootloader.find("J510FN") == 0) {
		property_set("ro.build.product", "j5xnlte");
		property_set("ro.build.description", "lineage_j5xnlte-userdebug 7.1.2 NMF26V 4dae919457 test-keys");
		property_set("ro.build.fingerprint", "samsung/lineage_j5xnlte/j5xnlte:7.1.2/NMF26V/4dae919457:userdebug/test-keys");
		property_set("ro.product.device", "j5xnlte");
		property_set("ro.product.model", "SM-J510FN");

		init_dsds();
	}
	else if (bootloader.find("J510H") == 0) {
		property_set("ro.build.product", "j5x3g");
		property_set("ro.build.description", "lineage_j5x3g-userdebug 7.1.2 NMF26V 4dae919457 test-keys");
		property_set("ro.build.fingerprint", "samsung/lineage_j5x3g/j5x3g:7.1.2/NMF26V/4dae919457:userdebug/test-keys");
		property_set("ro.product.device", "j5x3g");
		property_set("ro.product.model", "SM-J510H");

		init_dsds();
	}

	std::string device = property_get("ro.product.device");
	INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}

void vendor_load_properties(void)
{
	/* set the device properties */
	init_target_properties();
}
