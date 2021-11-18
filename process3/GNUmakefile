PROGRAMS = timedwait-poll timedwait-block timedwait-blockvar \
	timedwait-alarm timedwait-selfpipe timedwait-selectpipe \
	timedwait-signalfd

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) timedwait-selfpipe2

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
