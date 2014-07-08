SPL_PKGCFG := $(STREAMS_INSTALL)/bin/dst-pe-pkg-config.sh
SPL_PKG := dst-spl-pe-install
SPL_INCLUDE_OPTIONS := `$(SPL_PKGCFG) --cflags $(SPL_PKG)`
SPL_LINK_OPTIONS := `$(SPL_PKGCFG) --libs $(SPL_PKG)`

SOURCES := src/$(SERVICE)_constants.cpp src/$(SERVICE)_types.cpp src/$(SERVICE).cpp

INCLUDE := -Iinclude -I/$(OP)/include -I$(SPL_INCLUDE_OPTIONS)

OBJS := bin/$(SERVICE)_constants.o bin/$(SERVICE)_types.o bin/$(SERVICE).o

#TARGET := lib/libStreamsThrift.so
TARGET := ../lib/libStreamsThrift.a

CPPFLAGS += $(INCLUDE)
CPPFLAGS += -DHAVE_NETINET_IN_H
#CXXFLAGS += -O3 -Wall -fmessage-length=0 -fPIC
CXXFLAGS += -O3 -Wall -fmessage-length=0
LDFLAGS += -L/$(OP)/lib
LDFLAGS += -lthrift
#LDFLAGS += -shared $(SPL_LINK_OPTIONS)
LDFLAGS += $(SPL_LINK_OPTIONS)

.PHONY: clean distclean thrift

all: clean thrift namespace $(TARGET)

thrift:
	$(OP)/bin/thrift --gen cpp $(SERVICE).thrift
	mv $(SERVICE).thrift $(THRIFT_OUTPUT_DIR)
	mv gen-cpp/*.h include
	mv gen-cpp/*.cpp src

namespace:
	sed -i '1 i\#include <streams_boost/shared_ptr.hpp>' include/$(SERVICE).h
	sed -i '2 i\#include <streams_boost/static_assert.hpp>' include/$(SERVICE).h
	sed -i '3 i\#define BOOST_STATIC_ASSERT(X) do { STREAMS_BOOST_STATIC_ASSERT(X); } while(0)' include/$(SERVICE).h
	sed -i '4 i\namespace boost = streams_boost;' include/$(SERVICE).h
	sed -i '1 i\#include <streams_boost/shared_ptr.hpp>' include/$(SERVICE)_types.h
	sed -i '2 i\#include <streams_boost/static_assert.hpp>' include/$(SERVICE)_types.h
	sed -i '3 i\#define BOOST_STATIC_ASSERT(X) do { STREAMS_BOOST_STATIC_ASSERT(X); } while(0)' include/$(SERVICE)_types.h
	sed -i '4 i\namespace boost = streams_boost;' include/$(SERVICE)_types.h

bin/%.o: src/%.cpp
	@$(COMPILE.cc) -o $@ $<

$(TARGET): $(OBJS)
	@ar rcs $(TARGET) $(OBJS)
#	@flock -x -w 30 $(LOCK) -c "ar rcs $(TARGET) $(OBJS)"
#	@$(LINK.cc) -o $(TARGET) $(OBJS)
	
clean:
	rm -rf $(SOURCES) $(OBJS)

distclean: clean