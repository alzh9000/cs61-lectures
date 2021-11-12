PROGRAMS = accessor list-inserter \
	matrixmultiply matrixmultiply-base matrixmultiply-transpose \
	fork1 fork2 fork3 forkmix

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O ?= 3
include ../common/rules.mk
-include config.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

accessor list-inserter fork1 fork2 fork3 forkmix \
matrixmultiply matrixmultiply-base matrixmultiply-transpose: \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS)

matrixmultiply-blas: matrixmultiply-blas.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS) -lblas


clean:
	rm -f $(ALLPROGRAMS) *.o
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all always clean
