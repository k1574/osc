<mkconfig

CFLAGS =
LDFLAGS = -lm

SRC = `{ls *.c}
TGT = ${SRC:%.c=%}

all :Q: $TGT 
	echo -n
& : &.o
	$LD $LDFLAGS -o $target $prereq
%.o :V: %.c
	$CC $CFLAGS -c -o $target $prereq
%.c :
	
%.h :
	
clean :V:
	rm -rf $TGT *.o
