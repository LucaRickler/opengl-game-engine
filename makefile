CC := g++
SRCDIR := src
TESTDIR := tst
BUILDDIR := build
TARGETDIR := bin
TARGET := $(TARGETDIR)/moonbeam
TESTTARGET := bin/test

CFLAGS := -g -Wall -std=c++14
LIB := -pthread -lglfw -ldl
INC := -I include
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

TSOURCES := $(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
TOBJECTS := $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) $(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TSOURCES:.$(SRCEXT)=.o))
TINC := $(INC) -I tst

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $(OBJECTS))
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $(TOBJECTS))
	@echo "$(CC) $(CFLAGS) $(TINC) -c -o $@ $<"; $(CC) $(CFLAGS) $(TINC) -c -o $@ $<

clean:
	@echo "Cleaning..."; 
	@echo "$(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)

# Tests
test: $(TOBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TESTTARGET) $(LIB)"; $(CC) $^ -o $(TESTTARGET) $(LIB)

.PHONY: clean test all

.DELETE_ON_ERROR: clean