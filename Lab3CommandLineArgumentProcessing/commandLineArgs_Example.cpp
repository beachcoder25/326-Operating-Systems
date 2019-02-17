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
		cout << "Error: No arguments entered, I'm done" << endl;
	}
	
	else if (argc == 2 || argc == 3) { 
		cout << "Error: Please enter more than 3 numerical arguments" << endl;
	}
	
	/**
	else if( argc == 3 ){

		
		// Atoi converts a string to integer, parses a c-string interpreting its content as an integral number,and is returned as an int
		int x = atoi( argv[ 1 ] ); 
		int y = atoi( argv[ 2 ] );

		int valuesArray [2] = {x,y};
		int sum = 0;

		for(int i=0; i < 2; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 2; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 2 << endl;
		cout << "The range is " << 1 << endl;
	}
*/
	
	else if( argc == 4 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );

		int valuesArray [3] = {x,y,z};
		int sum = 0;

		for(int i=0; i < 3; i++){

			int currentInt = valuesArray[i];
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 3; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 3 << endl;
		cout << "The range is " << 2 << endl;

	}

	else if( argc == 5 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );

		int valuesArray [4] = {x,y,z,a};
		int sum = 0;

		for(int i=0; i < 4; i++){

			int currentInt = valuesArray[i];
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 4; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 4 << endl;
		cout << "The range is " << 3 << endl;

	}

	else if( argc == 6 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );

		int valuesArray [5] = {x,y,z,a,b};
		int sum = 0;

		for(int i=0; i < 5; i++){

			int currentInt = valuesArray[i];
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 5; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 5 << endl;
		cout << "The range is " << 4 << endl;

	}

	else if( argc == 7 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );

		int valuesArray [6] = {x,y,z,a,b,c};
		int sum = 0;

		for(int i=0; i < 6; i++){

			int currentInt = valuesArray[i];
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 6; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		cout << "The average is " << sum / 6 << endl;
		cout << "The range is " << 5 << endl;

	}

	else if( argc == 8 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );
		int d = atoi( argv[ 7 ] );

		int valuesArray [7] = {x,y,z,a,b,c,d};
		double sum = 0;

		for(int i=0; i < 7; i++){

			int currentInt = valuesArray[i];
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < 7; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / 7 << endl;
		cout << "The range is " << 6 << endl;

	}

	else{
		cout << "ERROR: You have entered more than 10 numerical arguments"
		<< endl;
	}
	exit( 0 );
	
	
}