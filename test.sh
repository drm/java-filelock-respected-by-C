#!/usr/bin/env bash

set -e

rm -f foo
touch foo
echo "./foo created, now starting lock using C in background: "
./lock ./foo &
echo "Now acquiring lock in java"
java Test ./foo &
sleep .2 # give java a little bootstrapping time...
echo "And trying if C respects java's lock:"
./lock ./foo 

