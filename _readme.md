For some reason I've spent a bit of time recently hunting in hex dumps for
floats. So I thought I'd generate a crib sheet.

Running ```make``` generates this readme.
```
$ make clean
rm -f float_format.o readme.md
$ make
clang++ -Wno-c++98-compat -Weverything -o float_format.o float_format.cpp -std=c++14
```

See Wikipedia's article on [floating point numbers](https://en.wikipedia.org/wiki/Single-precision_floating-point_format).

```
A - 32-bit hex representation
B - sign bit
C - exponent
D - mantissa
E - as a float

A         B C        D                        E
3d75c28e "0 01111010 11101011100001010001110" 0.06
```
