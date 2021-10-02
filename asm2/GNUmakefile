PROGRAMS = cc04
BUILDABLEASM := $(sort $(patsubst %.cc,%.s,$(wildcard f*.cc cc*.cc)) \
        $(patsubst src/%.cc,%.s,$(wildcard src/f*.cc src/cc*.cc)))
all: $(PROGRAMS) $(BUILDABLEASM)

BASEPROGRAMS = cc04
ALLPROGRAMS = $(PROGRAMS)

variants = $(1) $(addsuffix -noopt,$(1)) \
	$(addsuffix -clang,$(1)) $(addsuffix -clang-noopt,$(1)) \
	$(addsuffix -gcc,$(1)) $(addsuffix -gcc-noopt,$(1))

NEED_CXX_GCC = 1
PIE ?= 0
include ../common/rules.mk

UNSAFEFLAGS := -U_FORTIFY_SOURCE -fno-stack-protector


# Rules for making object files (i.e., parts of executables)
# from source files
%.o: %.cc $(BUILDSTAMP)
	$(call flagged_compile_c,$<,$@,$(CXXFLAGS))


# Rules for making assembly files from source files
%.s: %.cc GNUmakefile $(BUILDSTAMP)
	$(call flagged_compile_S,$<,$@,$(CXXFLAGS))

%.s: src/%.cc GNUmakefile $(BUILDSTAMP)
	$(call flagged_compile_S,$<,$@,-I. $(CXXFLAGS))

%-unsafe.s: %.cc GNUmakefile $(BUILDSTAMP)
	$(call flagged_compile_S,$<,$@,$(UNSAFEFLAGS) $(CXXFLAGS))

%-unsafe.s: src/%.cc GNUmakefile $(BUILDSTAMP)
	$(call flagged_compile_S,$<,$@,-I. $(UNSAFEFLAGS) $(CXXFLAGS))

%.asm: %.o
	objdump -d $< > $@


# Rules for making executables (runnable programs) from object files

$(BASEPROGRAMS): \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

$(addsuffix -clang,$(BASEPROGRAMS)): \
%: %.o hexdump.o
	clang++ $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

$(addsuffix -gcc,$(BASEPROGRAMS)): \
%: %.o hexdump.o
	$(CXX_GCC) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

$(addsuffix -noopt,$(BASEPROGRAMS)): \
%: %.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -O0 -o $@ $^

$(addsuffix -gcc-noopt,$(BASEPROGRAMS)): \
%: %.o hexdump.o
	$(CXX_GCC) $(CXXFLAGS) $(LDFLAGS) -O0 -o $@ $^

$(addsuffix -clang-noopt,$(BASEPROGRAMS)): \
%: %.o hexdump.o
	clang++ $(CXXFLAGS) $(LDFLAGS) -O0 -o $@ $^

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

add%: add.o addf%.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

checksummer: checksummer.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

checksummer-unsafe: checksummer-unsafe.o hexdump.o
	$(CXX) $(UNSAFEFLAGS) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

mb%: mb%.o mb-driver.o hexdump.o
	$(CXX) $(CXXFLAGS) -pthread $(LDFLAGS) $(O) -o $@ $^


attackfail.txt~: checksummer makeattack.pl
	perl makeattack.pl checksummer > attackfail.txt~

attack.txt~: checksummer-unsafe makeattack.pl
	perl makeattack.pl checksummer-unsafe > attack.txt~


clean:
	rm -rf $(call variants,$(ALLPROGRAMS)) *.o $(DEPSDIR) $(BUILDABLEASM)

.PHONY: all clean
.PRECIOUS: addf%.o
