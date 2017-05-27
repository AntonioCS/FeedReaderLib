#https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html	
BIN=libxml
BUILD_DIR=./build
OBJ_DIR=./obj
TARGET=$(BUILD_DIR)/$(BIN)
CFLAGS=-std=c++14 -Wall -g -Werror -O3
LDFLAGS=`xml2-config --cflags`
LDLIBS=`xml2-config --libs`
CC=g++
SRC_DIR=./src
SRC=$(shell find $(SRC_DIR) -name '*.cpp')
HEADERS=$(shell find $(SRC_DIR) -name '*.h')
#https://www.gnu.org/software/make/manual/html_node/Text-Functions.html
OBJ=$(addprefix $(OBJ_DIR)/,$(notdir $(patsubst %.cpp, %.o, $(SRC))))

TESTS_TARGET=tests
TESTS_DIR=./tests
TESTS_OBJ_DIR=$(TESTS_DIR)/obj
TESTS_MAIN_SRC=$(TESTS_DIR)/test-main.cpp
TESTS_MAIN_OBJ=$(TESTS_OBJ_DIR)/test-main.o
TESTS_SRC=$(TESTS_DIR)/tests.cpp $(SRC)
TESTS_OBJ=$(addprefix $(TESTS_OBJ_DIR)/,$(notdir $(patsubst %.cpp, %.o, $(TESTS_SRC))))


#http://stackoverflow.com/a/1951111/8715
#‘$(@D)’ -  The directory part of the file name of the target, with the trailing slash removed. 
# If the value of ‘$@’ is dir/foo.o then ‘$(@D)’ is dir. This value is . if ‘$@’ does not contain a slash. 
dir_guard=@mkdir -p $(@D)


$(TARGET): $(OBJ)
	$(dir_guard)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $? $(LDLIBS)
#copy all the resources to the build dir so that the
#executable can access everything in ./resources/<RESOURCE>
#added the @ to suppress the echoing
	#@cp -n -R ./resources $(BUILD_DIR)/resources

$(OBJ):	$(SRC)
	$(dir_guard)
	$(CC) $(CFLAGS) -c $? $(LDLIBS)
#Put all the object files in the correct directory
	@mv *.o $(OBJ_DIR)

$(TESTS_TARGET): $(TESTS_OBJ)
	$(dir_guard)
#tests/tests.cpp src/XMLParser.cpp src/XMLNode.cpp src/Feeds/RssFeed.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(TESTS_MAIN_OBJ) $? $(LDLIBS)

$(TESTS_OBJ): $(TESTS_SRC)
	$(dir_guard)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^ $(LDLIBS)
	@mv *.o $(TESTS_OBJ_DIR)

test_main: tests/test-main.cpp
	$(CC) $(CFLAGS) -c $?
	@mv *.o $(TESTS_OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJ_DIR)/*

.PHONY: clean tests

all: $(TARGET)