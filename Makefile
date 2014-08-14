CC		= gcc
OUT		= mkrepo
CFLAGS	= 
SOURCES = mkrepo.c

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SOURCES)
