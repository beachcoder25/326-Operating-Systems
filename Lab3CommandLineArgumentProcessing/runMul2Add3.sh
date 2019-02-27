g++ commandLineArgs_Example_mul2add3.cpp -o mul2Add3.out
echo running without arguments
echo ./mul2Add3.out
./mul2Add3.out
echo

echo running with one argument
echo ./mul2Add3.out 1
./mul2Add3.out 1
echo

echo running with 3 args: 1, 2, 4
echo ./mul2Add3.out 1 2 4
./mul2Add3.out 1 2 4
echo

echo running with 3 args: 1, 2, 4, 5
echo ./mul2Add3.out 1 2 4 5 -111
./mul2Add3.out 1 2 4 5 -111

echo running with 3 args: 1, 2, 4, 5
echo ./mul2Add3.out 1 2 4 5 3 6 7 8 9 10 11
./mul2Add3.out 1 2 4 5 3 6 7 8 9 10 11

