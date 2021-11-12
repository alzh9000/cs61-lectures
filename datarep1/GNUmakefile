<<<<<<< HEAD
PROGRAMS = objects
all: $(PROGRAMS)

TESTQSPROGRAMS = testqs0 testqs1 testqs2 testqs3 testqs4 testqs5 testqs6
ALLPROGRAMS = $(PROGRAMS) $(TESTQSPROGRAMS) \
	intgen accessor inserter0 inserter1 inserter2 \
	inserter3 inserter4 inserter5 inserter6 accessor

include ../common/rules.mk


# Rules for making object files (i.e., parts of executables)
# from source files

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

addf.o: addf.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -fcf-protection=none -o $@ -c $<

addf%.o: addf%.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -fcf-protection=none -o $@ -c $<


# Rules for making executables (runnable programs) from object files

objects intgen inserter0 inserter1 inserter2 inserter3 \
inserter4 inserter5 inserter6 accessor: \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

add%: add.o addf%.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

addin: addin.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

testqs: $(TESTQSPROGRAMS)

testqs%: testqs%.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)


clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
.PRECIOUS: addf%.o
=======
PROGRAMS = objects
all: $(PROGRAMS)

TESTQSPROGRAMS = testqs0 testqs1 testqs2 testqs3 testqs4 testqs5 testqs6
ALLPROGRAMS = $(PROGRAMS) $(TESTQSPROGRAMS) \
	intgen accessor inserter0 inserter1 inserter2 \
	inserter3 inserter4 inserter5 inserter6 accessor

include ../common/rules.mk


# Rules for making object files (i.e., parts of executables)
# from source files

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

addf.o: addf.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -fcf-protection=none -o $@ -c $<

addf%.o: addf%.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -fcf-protection=none -o $@ -c $<


# Rules for making executables (runnable programs) from object files

objects intgen inserter0 inserter1 inserter2 inserter3 \
inserter4 inserter5 inserter6 accessor: \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

add%: add.o addf%.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

addin: addin.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)

testqs: $(TESTQSPROGRAMS)

testqs%: testqs%.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^ $(LIBS)


clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
.PRECIOUS: addf%.o
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
