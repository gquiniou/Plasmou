CPPFLAGS= -ID:\dev\libs\SFML-2.0\include -I./include


CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Wextra -std=c++0x 

OBJS =		Plasmou.o

LIBS = -LD:\dev\libs\SFML-2.0\lib  -lsfml-system -lsfml-window -lsfml-graphics

TARGET =	Plasmou.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
