#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
using namespace std;
int value = 0, countSpeed = 3; // QUESTION: Is countSpeed correct for integral???

void *inputReader( void *param );
void *countDownThread( void *param );
char userInput;
bool countEnable = true, countUp = true;

int main( int argc, char ** argv ){
	// cout << "Initially, value = " << value << endl;
	pthread_t tid_reader, tid_evenChecker, tid_countDownThread;
	pthread_attr_t attr;
	pthread_attr_init( &attr );
	pthread_create( &tid_reader, &attr, inputReader, NULL );	// create the thread
	pthread_create( &tid_countDownThread, &attr, countDownThread, NULL );	// create the thread
	cout << "Main thread blocking until worker threads finish\n";
	pthread_join( tid_reader, NULL );
	pthread_join( tid_countDownThread, NULL );
	cout << "Main thread unblocked and outta here";
}

void *inputReader( void *param ){
	cout << "!!! Reader Thread Running!\n";
	cout << "Type an integer value and press the Enter Key at any time (-1 to quit): ";
	value = 10;	// change value to make countDownThread unblock and begin counting
	while( value > -1 && userInput != 'a')
		cin >> userInput;	// BLOCKING operation
	cout << "inputReader thread exited\n";
	pthread_exit( 0 );
}

void *countDownThread( void *param ){
	
	struct timespec timing;


	cout << "!!! Count Down Thread Running!\n";
	timing.tv_sec = 0;
	timing.tv_nsec = 125000000L;	// sleep time 500million nanoseconds
	countSpeed = 3;

	
	while( value == 0 );	// BLOCK while value equals 0
	while( value > 0 )
	{


		//
		while(userInput != 'a')
		{
			if(userInput == 's'){

				countEnable = false;
			}

			else if(userInput == 'd'){

				countUp = false;
			}

			if(countSpeed == 0){

				cout << "countSpeed = 0\n";

				if(userInput == '+'){

					timing.tv_sec = 0;
					timing.tv_nsec = 500000000L;	// sleep time 500million nanoseconds
					countSpeed = 1;
					userInput = 'x';
				}	
			}

			else if(countSpeed == 1){

				cout << "countSpeed = 1\n";

				if(userInput == '-'){

					timing.tv_sec = 1;
					timing.tv_nsec = 000000000L;
					countSpeed = 0;
					userInput = 'x';
				}

				else if (userInput == '+'){

					timing.tv_sec = 0;
					timing.tv_nsec = 250000000L;	
					countSpeed = 2;
					userInput = 'x';
				}	
			}

			else if(countSpeed == 2){

				cout << "countSpeed = 2\n";

				if(userInput == '-'){

					timing.tv_sec = 0;
					timing.tv_nsec = 500000000L;	// sleep time 500million nanoseconds
					countSpeed = 1;
					userInput = 'x';
				}

				else if (userInput == '+'){

					timing.tv_sec = 0;
					timing.tv_nsec = 125000000L;
					countSpeed = 3;
					userInput = 'x';
				}
				
			}

			else if(countSpeed == 3){

				cout << "countSpeed = 3\n";
				if(userInput == '-'){

					timing.tv_sec = 0;
					timing.tv_nsec = 250000000L;
					countSpeed = 2;
					userInput = 'x';

				}				
			}

			if(countEnable){

				if(countUp){

					cout << ++value << flush;	// flush to make the value display	
					nanosleep( &timing, NULL );	

				}

				else{

					cout << --value << flush;	// flush to make the value display
					nanosleep( &timing, NULL );

				}

			}

			else if (countEnable = false){
				
				timing.tv_sec = 0;
				timing.tv_nsec = 000000000L;
			}

			//cout << ++value << flush;	// flush to make the value display
			// sleep( 1 );							// wait 1 second

			//nanosleep( &timing, NULL );
			// cout << "\r                       \r";	// overwrite previous number with spaces
			cout << "\b\b\b\b\b\b       \b\b\b\b\b\b";	// overwrite previous number with spaces
			// cout << "\b\b\b\b\b\b";	// backspace over previously  displayed characters
		}
		break;
		
	}



	cout << "countDownThread thread exited\n";
	pthread_exit( 0 );
}

/*
*/