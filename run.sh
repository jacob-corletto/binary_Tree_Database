rm *.o
rm *.out

g++ -c -m64 -Wall -g -o node.o node.cpp -fno-pie -std=c++20

g++ -c -m64 -Wall -g -o main.o main.cpp -fno-pie -std=c++20

g++ -c -m64 -Wall -g -o tree.o tree.cpp -fno-pie -std=c++20

g++ -m64 -g -o run.out  main.o node.o tree.o -fno-pie -std=c++20

./run.out