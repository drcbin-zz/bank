main.out:B.o test.cpp
	g++ B.o test.cpp -o main.out
B.o:A.o B.cpp
	g++ -c A.o B.cpp
A.o:A.cpp
	g++ -c A.cpp
