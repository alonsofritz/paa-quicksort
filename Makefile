build_central:
	g++ -o ./centralPivot/quickSort.exe ./centralPivot/quickSort.cpp

run_central: build_central
	./centralPivot/quickSort.exe

build_median:
	g++ -o ./medianPivot/quickSort.exe ./medianPivot/quickSort.cpp

run_median: build_median
	./medianPivot/quickSort.exe

build_random:
	g++ -o ./randomPivot/quickSort.exe ./randomPivot/quickSort.cpp

run_random: build_random
	./randomPivot/quickSort.exe

run_all: build_central build_median build_random
	./centralPivot/quickSort.exe 
	./medianPivot/quickSort.exe 
	./randomPivot/quickSort.exe