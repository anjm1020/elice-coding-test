main.out : main.cpp
	g++ main.cpp -o main.out -std=c++11	
clean :
	rm *.out