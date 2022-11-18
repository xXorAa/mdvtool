TOOL=mdvtool

all: $(TOOL)

$(TOOL): $(TOOL).c
	$(CC) -o $@ $< -lzip

clean:
	-rm $(TOOL)

