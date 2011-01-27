#!/usr/bin/perl -w

use strict;

my $str;
my @num;
my $count = 0;

open(F, "data.txt");

while (<F>) {
	@num = split(/\s+/);
}

foreach (@num) {
	print "0x$_, ";
	++$count;
	if (($count % 8) == 0) {
		print "\n";
	}
}

print "\n";

close F;
