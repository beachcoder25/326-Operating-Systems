#include <iostream>
#include <array>
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
		cout << "No arguments entered, I'm done" << endl;
	}
	
	else if (argc == 2) { 
		cout << "Please enter more than 3 numerical arguments" << endl;
	}
	
	
	else if( argc == 3 ){

		
		// Atoi converts a string to integer, parses a c-string interpreting its content as an integral number,and is returned as an int
		int x = atoi( argv[ 1 ] ); 
		int y = atoi( argv[ 2 ] );

		int valuesArray [2] = {x,y};
		int sum = 0;

		for(int i=0; i < 2; i++){

			int currentInt = valuesArray[i];
			cout << currentInt << endl;
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
			/**
			if(valuesArray[i] < -100 || valuesArray[i] > 100){
				cout << "You have entered a value outside of the range -100 to 100";
				return 0;
			}
			*/
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 2; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		
		cout << x << " and " << y << " were received through command line\n";
		cout << "x * y = " << x << " * " << y << " = " << ( x * y ) << endl;
		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 2 << endl;
		cout << "The range is " << 1 << endl;
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