#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
using namespace std;
int value = 0, countSpeed = 0; // QUESTION: Is countSpeed correct for integral???

void *inputReader( void *param );
void *countDownThread( void *param );
char userInput;
bool enable, countUp;

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
	while( value > -1 )
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

			if(countSpeed == 0){

				if(userInput == '+'){

					timing.tv_nsec = 250000000L;	// sleep time 500million nanoseconds
					countSpeed = 1;
				}	
			}

			else if(countSpeed == 1){

				if(userInput == '+'){

					timing.tv_nsec = 500000000L;	// sleep time 500million nanoseconds
					countSpeed = 2;
				}

				else if (userInput == '-'){

					timing.tv_nsec = 125000000L;	// sleep time 500million nanoseconds
					countSpeed = 0;
				}	
			}

			else if(countSpeed == 2){

				if(userInput == '+'){

					timing.tv_sec = 1;
					countSpeed = 3;
				}

				else if (userInput == '-'){

					timing.tv_nsec = 250000000L;
					countSpeed = 1;
				}
				
			}

			else if(countSpeed == 3){

				if(userInput == '-'){

					timing.tv_nsec = 500000000L;
					countSpeed = 2;
				}				
			}

			// if(userInput == '+'){

			// 	if(countSpeed == 0){

			// 		timing.tv_nsec = 250000000L;	// sleep time 500million nanoseconds

			// 	}

			// 	// Check the state!!!

			// 	//cout << "Inc" << endl;
			// }

			// else if(userInput == '-'){

			// 	timing.tv_nsec = 250000000L;	// sleep time 500million nanoseconds

			// 	//cout << "dec" << endl;
			// }

			cout << ++value << flush;	// flush to make the value display
			// sleep( 1 );							// wait 1 second

			nanosleep( &timing, NULL );
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