#!/system/bin/sh

LOG_TAG="copy_db"
LOG_NAME="${0}:"

loge ()
{
  /system/bin/log -t $LOG_TAG -p e "$LOG_NAME $@"
}

logi ()
{
  /system/bin/log -t $LOG_TAG -p i "$LOG_NAME $@"
}

TELEPHONY_DIR=/data/data/com.android.providers.telephony
TELEPHONY_DB_DIR=${TELEPHONY_DIR}/databases
TELEPHONY_DB=telephony.db

if ! [ -e $TELEPHONY_DB ]; then
    logi "Starting Copy RIL Database"
    mkdir -p ${TELEPHONY_DB_DIR}

    logi "Copying database..."
    cp /system/vendor/${TELEPHONY_DB} ${TELEPHONY_DB_DIR}/${TELEPHONY_DB}

    logi "Setting permissions..."
    chown radio:radio ${TELEPHONY_DB_DIR} -R
    chmod 0751 ${TELEPHONY_DIR}
    chmod 0771 ${TELEPHONY_DB_DIR}
    chmod 0660 ${TELEPHONY_DB_DIR}/${TELEPHONY_DB}
fi
