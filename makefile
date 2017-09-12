readme.md: float_format.o
	cat _readme.md > readme.md
	echo '```' >> readme.md
	./float_format.o >> readme.md
	echo '```' >> readme.md

%.o:%.cpp
	clang++ -Wno-c++98-compat -Weverything -o $@ $< -std=c++14

clean:
	rm -f float_format.o readme.md
