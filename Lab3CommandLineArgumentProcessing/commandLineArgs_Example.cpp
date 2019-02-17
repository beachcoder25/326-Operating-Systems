#include <iostream>
using namespace std;



// ********************************************
// GOOD YOUTUBE VIDEO RESOURCE!!!!!!!!!!!!!!!!!
// https://www.youtube.com/watch?v=LU5nQUxaoiU
// ********************************************





// int argc = argument count (How many arguments there are)
// char argv, a matrix containing he argument
int main( int argc, char ** argv ){

	// If there is only one argument, which means ONLY the file name was provided
	// Ex: ./a.out
	if (argc == 1) { 
		cout << "Usage: ./program_name arg1" << endl;
	}
	if( argc == 3 ){

		// Atoi converts a string to integer, parses a c-string interpreting its content as an integral number,and is returned as an int
		int x = atoi( argv[ 1 ] ); 
		int y = atoi( argv[ 2 ] );
		cout << x << " and " << y << " were received through command line\n";
		cout << "x * y = " << x << " * " << y << " = " << ( x * y ) << endl;
	}
	else if( argc == 4 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		cout << x << ", " << y << " and " << z << " were received through command line\n";
		cout << "x + y + z = " << x << " + " << y << " + " << z 
		<< " = " << ( x + y + z ) << endl;
	}
	else{
		cout << "ERROR: run the program and enter either 2 or 3 decimal value command line arguments\n"
		<< endl;
	}
	exit( 0 );
	
	
}