readme.md: float_format.o
	cat _readme.md > readme.md
	./float_format.o >> readme.md

%.o:%.cpp
	clang++ -Wno-c++98-compat -Weverything -o $@ $< -std=c++14

clean:
	rm -f float_format.o readme.md

wait:
	while :; do inotifywait -qe modify *.cpp; make -j; done
