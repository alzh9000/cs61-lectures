PROGRAMS = forkmyecho myecho execmyecho spawnmyecho waitmyecho \
	waitdemo childpipe forkorder pipesizer

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O ?= 3
include ../common/rules.mk
-include config.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%: %.o
	$(CXX) $(CXXFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS)


clean:
	rm -f $(ALLPROGRAMS) *.o
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all always clean
