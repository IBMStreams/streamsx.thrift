#! /bin/bash

THRIFT_TOOLKIT=$(echo ${STREAMS_STUDIO_SPL_PATH} | grep -oP '/[^:]*com.ibm.streamsx.thrift')

if [[ ! -L $THRIFT_TOOLKIT/impl/include/boost ]]; then
	ln -s $STREAMS_INSTALL/ext/include/streams_boost $THRIFT_TOOLKIT/impl/include/boost
fi

exit 0
