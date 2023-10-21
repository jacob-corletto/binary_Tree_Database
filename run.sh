rm *.o
rm *.out

g++ -c -m64 -Wall -g -o node.o node.cpp -fno-pie -std=c++2a

g++ -c -m64 -Wall -g -o main.o main.cpp -fno-pie -std=c++2a

g++ -c -m64 -Wall -g -o tree.o tree.cpp -fno-pie -std=c++2a

g++ -m64 -g -o run.out  main.o node.o tree.o -fno-pie -std=c++2a

./run.out