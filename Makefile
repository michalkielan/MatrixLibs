#############################################################
#  Setup variable section                                   #
#############################################################

# Compiler
COMPILER=g++

# C++ standard, ex. -std=c++0x, c++11, c++14; -std=gnu++11, gnu++14
CPP_STD= -std=c++14 -std=gnu++14

# Optimization, ex. O3, O2
OPTIMIZATION=

# targets name
TARGETS=

# Linker flags variable
LDFLAGS=

# C, C++ flags
CXXFLAGS=

# debug flag
DBG= -g

# include path
INC=
SRC=


##############################################################
# Make file commands section                                 #
##############################################################

if[${CXX?}=""]; then CXX=$(COMPILER); fi;


CXXFLAGS+=$(CPP_STD)
CXXFLAGS+=-Wall 
CXXFLAGS+=-flto
CXXFLAGS+=$(DBG)
CXXFLAGS+=$(OPTIMIZATION)

INC+=.
SRC+=./tests/

CORRECT_TEST=correctTests
PERF_TEST=performanceTests

TARGETS+=$(CORRECT_TEST)
TARGETS+=$(PERF_TEST)

LDFLAGS+=-lgtest
LDFLAGS+=-pthread
LDFLAGS+=-flto

TESTS=

TESTS+=run_tests_performance 
TESTS+=run_tests_correct

.PHONY: clean all run_tests_all $(TESTS)

all:
	 $(CXX) $(CXXFLAGS) -I $(INC) $(SRC)$(CORRECT_TEST).cpp -o $(CORRECT_TEST) $(LDFLAGS)
	 $(CXX) ${CXXFLAGS} -I $(INC) $(SRC)$(PERF_TEST).cpp -o $(PERF_TEST) $(LDFLAGS)

run_tests_performance:
	./$(PERF_TEST)

run_tests_correct:
	./$(CORRECT_TEST)

run_test_all: $(TESTS)

clean:
	rm -rf $(TARGETS) *.o plots/*
