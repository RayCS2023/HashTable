all: orderedhttest openhttest

orderedhttest: orderedhttest.cpp Map.hpp Map.cpp List.hpp List.cpp 
		g++ -std=c++11 -o orderedhttest orderedhttest.cpp Map.cpp List.cpp

openhttest: openhttest.cpp DoubleHashing.hpp DoubleHashing.cpp 
		g++ -std=c++11 -o openhttest openhttest.cpp DoubleHashing.cpp 

run:    orderedhttest openhttest
	./orderedhttest < test01.in > chain01.out
	./orderedhttest < test02.in > chain02.out
	./orderedhttest < test03.in > chain03.out
	./orderedhttest < test04.in > chain04.out
	./openhttest < test01.in > open01.out
	./openhttest < test02.in > open02.out
	./openhttest < test03.in > open03.out

