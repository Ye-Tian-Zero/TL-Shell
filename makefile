CXX = g++

FLAGS = -std=c++11 

TLSH : *.cpp
	$(CXX) $(FLAGS) -o TLSH $^

