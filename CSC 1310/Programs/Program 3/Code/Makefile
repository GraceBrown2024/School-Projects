

#COMPILATION FOR FOOD TRACKER 1310
#in your terminal, you will type "make" then "make run"
#Windows: Ensure MinGW is installed before compilation ... You will have to rename the command!
#MacOS: Ensure Make is installed before compilation ... Use Homebrew to install and update!

#-------------------------#
#Compiler and Flags 
#	I use the G++ compiler so to make this run the same way
#	it ran for me, I wanted to compile it the same way
CXX = g++
CXXFLAGS = -Wall

#SOURCE FILES in SourceCode/
SRCS = 	SourceCode/Driver.cpp \
		SourceCode/food.cpp \
		SourceCode/calculations.cpp \
		SourceCode/UserInfo.cpp

#Exe name
TARGET = TRACKER

all: $(TARGET)

$(TARGET): $(SRCS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run:	$(TARGET)
		./$(TARGET)

clean:	$(TARGET)
		rm -f $(TARGET)