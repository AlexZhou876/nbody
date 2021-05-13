
EXE = nbody
OBJS = main.o qtree.o particle.o vec2d.o directSum.o

CXX = clang++
CXXFLAGS = -stdlib=libc++ -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -stdlib=libc++ -std=c++1y -lc++abi -lpthread -lm
SFML = -L./SFML-2.5.1 -lsfml-graphics -lsfml-window -lsfml-system

all : nbody

$(EXE) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) $(SFML) -o $(EXE) 

main.o : main.cpp qtree.h particle.h vec2d.h sim.h directSum.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $@

qtree.o : qtree.cpp qtree.h particle.h vec2d.h sim.h
	$(CXX) $(CXXFLAGS) qtree.cpp -o $@

directSum.o : directSum.cpp particle.h vec2d.h sim.h
	$(CXX) $(CXXFLAGS) directSum.cpp -o $@

# sim.o : sim.h particle.h 
# 	$(CXX) $(CXXFLAGS) sim.h -o $@

particle.o : particle.cpp particle.h
	$(CXX) $(CXXFLAGS) particle.cpp -o $@

vec2d.o : vec2d.cpp vec2d.h
	$(CXX) $(CXXFLAGS) vec2d.cpp -o $@

clean :
	-rm -f *.o $(EXE)
