CXXFLAGS += -Wall
CXXFLAGS += -g
#CXXFLAGS += -std=c2x
CXXFLAGS += -std=c++20
#CXXFLAGS += -std=c++23
#OPTIMIZE := 1
ifdef OPTIMIZE
CXXFLAGS += -O2
endif
#CXXFLAGS += -DUSE_PLAIN_C

ifdef WSL_DISTRO_NAME
CXX := g++
else
# default g++ (11.5.0) on OL9 is too old to use std::format()
CXX := /opt/rh/gcc-toolset-13/root/usr/bin/g++
endif
#CXX := clang++

#ALL += b2
#ALL += removevowels
#ALL += removevowels2
#ALL += removevowels3
#ALL += sumnaturals
#ALL += factorial
#ALL += isprime
#ALL += ispal
#ALL += armstrong
#ALL += fib
#ALL += gcd

ALL := $(addprefix exe/,$(ALL))
DUMPS := $(addsuffix .objdump,$(ALL))

all :: $(ALL)
ifdef OPTIMIZE
all :: $(DUMPS)
endif

exe/% : %.cc
	mkdir -p exe
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) $(LOADLIBES)

%.objdump : %
	objdump -dr --no-show-raw-insn $^ > $@

clean ::
	rm -rf exe

# vim: noet ts=8 sw=8
