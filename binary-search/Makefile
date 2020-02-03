CC=cl.exe
CFLAGS=/nologo /Tc
LFLAGS=/nologo

all: test

test: test.exe
	test.exe

test.exe: binary_search.c binary_search.h test_binary_search.c
	$(CC) $(CFLAGS) binary_search.c test_binary_search.c vendor/unity.c /link $(LFLAGS) /out:test.exe

.IGNORE:
clean:
	del /q *.exe *.obj

