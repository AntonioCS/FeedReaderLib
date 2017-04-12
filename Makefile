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

#http://stackoverflow.com/a/1951111/8715
dir_guard=@mkdir -p $(@D)

.PHONY: clean

all: $(TARGET)

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

tests: tests/tests.cpp src/XMLParser.cpp src/XMLNode.cpp src/Feeds/RssFeed.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	

clean:
	rm -rf $(TARGET) $(OBJ_DIR)/*	