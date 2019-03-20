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
	
	else if (argc == 2 || argc == 3 || argc == 4) { 
		cout << "Error: Please enter more than 3 numerical arguments" << endl;
	}
	

	else if( argc == 5 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );

		int valuesArray [4] = {x,y,z,a};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;

	}

	else if( argc == 6 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );

		int valuesArray [5] = {x,y,z,a,b};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;

	}

	else if( argc == 7 ){
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );

		int valuesArray [6] = {x,y,z,a,b,c};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;

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
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;
	}

		else if( argc == 9 ){

		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );
		int d = atoi( argv[ 7 ] );
		int e = atoi( argv[ 8 ] );
		//int f = atoi( argv[ 9 ] );

		int valuesArray [8] = {x,y,z,a,b,c,d,e};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;


	}

	

	else if( argc == 10 ){
			
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );
		int d = atoi( argv[ 7 ] );
		int e = atoi( argv[ 8 ] );
		int f = atoi( argv[ 9 ] );

		int valuesArray [9] = {x,y,z,a,b,c,d,e, f};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;

	}

	else if( argc == 11 ){
			
		int x = atoi( argv[ 1 ] );
		int y = atoi( argv[ 2 ] );
		int z = atoi( argv[ 3 ] );
		int a = atoi( argv[ 4 ] );
		int b = atoi( argv[ 5 ] );
		int c = atoi( argv[ 6 ] );
		int d = atoi( argv[ 7 ] );
		int e = atoi( argv[ 8 ] );
		int f = atoi( argv[ 9 ] );
		int g = atoi( argv[ 10 ] );

		int valuesArray [10] = {x,y,z,a,b,c,d,e,f,g};
		int sizeOfArray = argc - 1;
		
		double sum = 0;

		int min = valuesArray[0]; // For calculating minimum
		int max = valuesArray[0];
		for(int i=0; i < sizeOfArray; i++){

			int currentInt = valuesArray[i];
			
			
			if(currentInt > 100 || currentInt < -100){
				cout << "Value: " << valuesArray[i] << " is out of range, please enter digits between -100 and 100" << endl;
				return 0;
			}

			if(currentInt < min){ // Re-assign min, used in range calculation
				min = currentInt;
			}

			if(currentInt > max){ // Re-assign min, used in range calculation
				max = currentInt;
			}

			sum = sum + valuesArray[i];
			
		}

		cout << "The numbers are being buffered as follows: " << endl;
		for(int i = 0; i < sizeOfArray; i++){
			cout << "numbersArray[ " << i << " ] = " << valuesArray[i] << endl;
		}

		cout << "The sum is " << sum << endl;
		//double sumDub = (double)sum;
		cout << "The average is " << sum / sizeOfArray << endl;
		cout << "The range is " << (max - min) << endl;

	}


	else{
		cout << "ERROR: You have entered more than 10 numerical arguments"
		<< endl;
	}
	exit( 0 );
	
	
}