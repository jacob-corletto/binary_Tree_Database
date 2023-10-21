rm *.o
rm *.out

g++ -c -m64 -Wall -g -o node.o node.cpp -fpie -std=c++2a

g++ -c -m64 -Wall -g -o main.o main.cpp -fpie -std=c++2a

g++ -c -m64 -Wall -g -o tree.o tree.cpp -fpie -std=c++2a

g++ -m64 -g -o run.out  main.o node.o tree.o -fpie -std=c++2a

./run.out