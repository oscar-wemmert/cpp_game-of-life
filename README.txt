~~~Usage~~~
compile all .cpp files in folder src, use -std=c++11 or eq
cd src && g++ -std=c++11 -o gameoflife *.cpp
program can be run with 1 argument, and accepts 0, 1 or 2.
0 is the default option, which runs if you do not supply one.
./gameoflife   OR   ./gameoflife 1   OR   ./gameoflife 2

~~~Notes~~~
I chose to use c++11 for this for this assignment, mostly to get
a portable sleep function and some other things.

The program features 3 patterns, all taken from the wikipedia page
on Conway's Game of Life (http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).
0 is Acorn, 1 is The R-pentomino and 2 is another found there.