PROGRAMS = sizes sizeof compounds
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

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

sizes sizeof compounds: \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testaccess: testaccess.o qslib.o allowexec.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testinsert0: testinsert0.o qslib.o allowexec.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testinsert1: testinsert1.o qslib.o allowexec.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testinsert2: testinsert2.o qslib.o allowexec.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

add%: add.o addf%.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

addin: addin.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs: $(TESTQSPROGRAMS)

testqs0: testqs0.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs1: testqs1.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs2: testqs2.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs3: testqs3.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs4: testqs4.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs5: testqs5.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs6: testqs6.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^



clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
.PRECIOUS: addf%.o
