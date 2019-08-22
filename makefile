readme.md: float_format.o
	cat _readme.md > readme.md
	./float_format.o >> readme.md

CXX ?= clang++
CXXFLAGS ?= -Wno-c++98-compat -Weverything --std=c++2a

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f float_format.o readme.md

wait:
	while :; do inotifywait -qe modify *.cpp; make -j; done
