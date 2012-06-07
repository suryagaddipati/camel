CFLAGS=-g -O2 -Wall -Wextra -Isrc   $(OPTFLAGS) -D_FILE_OFFSET_BITS=64
CC="clang" 
PREFIX?=/usr/local
get_objs = $(addsuffix .o,$(basename $(wildcard $(1))))

ASM=$(wildcard src/**/*.S src/*.S)
SOURCES=$(wildcard src/**/*.c src/*.c) 
OBJECTS=$(patsubst %.c,%.o,${SOURCES}) $(patsubst %.S,%.o,${ASM})
TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,${TEST_SRC})
MAKEOPTS=OPTFLAGS="${NOEXTCFLAGS} ${OPTFLAGS}" OPTLIBS="${OPTLIBS}" LIBS="${LIBS}" DESTDIR="${DESTDIR}" PREFIX="${PREFIX}"

all: bin/camel 
bin/camel: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o bin/camel  
tests: 
	echo not-implemented
clean: 
	rm -f camel
test: 
	@echo $(OBJECTS)
