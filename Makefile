CC		= gcc
OUT		= mkrepo
SOURCES = mkrepo.c

all:
	$(CC) -o $(OUT) $(SOURCES)
