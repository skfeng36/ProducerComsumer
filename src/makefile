CXX = g++
CC  = gcc


CXXFLAGS = 	-g -Wall -fmessage-length=0
CCFLAGS = 	-g -Wall -fmessage-length=0

DEST = 		./
INCLUDES += 	-I./include 
LDFLAGS +=	
LIBS +=		

#%.o:%.cpp
#	$(CXX) $(CCFLAGS) $(INCLUDES)  -o $@  -c $< 

INCLUDEDIRS =  -I./include/ 

SRC = $(wildcard *.cc) 
#$(warning  $(SRC)) 
OBJS =		$(SRC:.cc=.o)
LIBS =		-lpthread 
TARGET =	ProducerConsumer

.cpp.o:
	$(CXX) $(CCFLAGS) $(INCLUDEDIRS)  -c $< -o $@
.cc.o:
	$(CXX) $(CXXFLAGS) $(INCLUDEDIRS) -c $< -o $@

$(TARGET):	$(OBJS)

	$(CXX) $(CCFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	cp $(TARGET) ../bin

all:	$(TARGET) 
	rm -f $(OBJS)
	cp $(TARGET) ../bin
install:
	cp $(TARGET) ../bin	
clean:
	rm -f $(OBJS) $(TARGET)


