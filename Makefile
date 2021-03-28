.PHONY: all test


all: Test.class lock test

lock: lock.c
	gcc -o ./lock ./lock.c

Test.class: Test.java
	javac Test.java

test:
	./test.sh

