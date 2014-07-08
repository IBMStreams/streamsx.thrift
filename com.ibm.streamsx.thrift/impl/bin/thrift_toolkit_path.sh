#! /bin/bash

THRIFT_TOOLKIT=$(echo ${STREAMS_STUDIO_SPL_PATH} | grep -oP '/[^:]*streamsx.thrift')

if [[ ! -L $THRIFT_TOOLKIT/impl/include/boost ]]; then
	ln -s $STREAMS_INSTALL/ext/include/streams_boost $THRIFT_TOOLKIT/impl/include/boost
fi

if [ "$1" = "includePath" ]; then 
	echo $THRIFT_TOOLKIT/impl/include;
elif [ "$1" = "libPath" ]; then 
	echo "$THRIFT_TOOLKIT/impl/lib";
fi

exit 0