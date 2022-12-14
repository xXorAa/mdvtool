TOOL=mdvtool

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    STATIC_LIBS := -DZIP_STATIC -Wl,-Bstatic -lzip -lbcrypt -lbz2 -llzma -lzstd -lz -Wl,-Bdynamic
    LIBS :=
    EXE := .exe
else
    LIBS := $(shell pkg-config --libs libzip)
    CFLAGS := $(shell pkg-config --cflags libzip)
    STATIC_LIBS :=
    EXE := 
endif

all: $(TOOL)$(EXE)

$(TOOL)$(EXE): $(TOOL).c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS) $(STATIC_LIBS)

clean:
	-rm $(TOOL)$(EXE)

