#!/system/bin/sh

LOG_TAG="perm_fixup"
LOG_NAME="${0}:"

TO_FIXUP="bin/qseecomd bin/qcom-system-daemon .perm_fixup"

loge ()
{
  /system/bin/log -t $LOG_TAG -p e "$LOG_NAME $@"
}

logi ()
{
  /system/bin/log -t $LOG_TAG -p i "$LOG_NAME $@"
}

if ! [ -f /system/.perm_fixup ]; then
	logi "Starting Permissions Fixup"

	logi "Remounting /system rw"
	mount -o remount,rw /system

	for file in $TO_FIXUP; do
		logi "Setting $file permissions to 0644... "
		touch /system/$file
		chmod 0644 /system/$file
	done

	logi "Remounting /system ro"
	mount -o remount,ro /system

	logi "Finished Permissions Fixup. Rebooting..."
	reboot
fi
