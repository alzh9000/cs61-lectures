PROGRAMS = structs accessor mb0 mb1 mb2 mb3 mb4
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk


# Rules for making object files (i.e., parts of executables)
# from source files

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<


# Rules for making executables (runnable programs) from object files

structs accessor: \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

mb%: mb%.o mb-driver.o hexdump.o
	$(CXX) $(CXXFLAGS) -pthread $(LDFLAGS) $(O) -o $@ $^


clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
.PRECIOUS: addf%.o
