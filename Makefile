#############################################################
#  Setup variable section                                   #
#############################################################

# Compiler
COMPILER=g++

# C++ standard, ex. c++0x, c++11, c++14
CPP_STD= -std=c++14

# Optimization, ex. O3, O2
OPTIMIZATION=

# targets name
TARGETS=

# Linker flags variable
LDFLAGS=

# C, C++ flags
CFLAGS=

# debug flag
DBG= -g

# include path
INC=
SRC=


##############################################################
# Make file commands section                                 #
##############################################################

if[${CXX?}=""]; then CXX=$(COMPILER); fi;


CFLAGS+=$(CPP_STD)
CFLAGS+=-Wall 
CFLAGS+=-flto
CFLAGS+=$(DBG)
CFLAGS+=$(OPTIMIZATION)

INC+=.
SRC+=./tests/

CORRECT_TEST=correctTests
PERF_TEST=performanceTests

TARGETS+=$(CORRECT_TEST)
TARGETS+=$(PERF_TEST)

CXXFLAGS+=-std=$(CPPSTANDARD) 
CXXFLAGS+=$(CPPFLAGS)
CXXFLAGS+=$(OPTIMIZATION)

LDFLAGS+=-lgtest
LDFLAGS+=-pthread

all:
	 $(CXX) $(CFLAGS) -I $(INC) $(SRC)$(CORRECT_TEST).cpp -o $(CORRECT_TEST) $(LDFLAGS)
	 $(CXX) ${CFLAGS} -I $(INC) $(SRC)$(PERF_TEST).cpp -o $(PERF_TEST) $(LDFLAGS)

clean:
	rm -rf $(TARGETS) *.o
