
CXXFLAGS=-O2 -g -Wall -fmessage-length=0 -Wextra -std=c++0x 

OBJS=Plasmou.o

LIBS= -lsfml-system -lsfml-window -lsfml-graphics

TARGET=Plasmou

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
