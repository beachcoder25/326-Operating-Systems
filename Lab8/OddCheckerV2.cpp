#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <string>
#include <stdio.h>
using namespace std;
int value = 0;

void *inputReader( void *param );
void *oddChecker( void *param );

int main( int argc, char ** argv ){
	// cout << "Initially, value = " << value << endl;
	pthread_t tid_reader, tid_evenChecker, tid_oddChecker;
	pthread_attr_t attr;
	pthread_attr_init( &attr );
	pthread_create( &tid_reader, &attr, inputReader, NULL );	// create the thread
	pthread_create( &tid_oddChecker, &attr, oddChecker, NULL );	// create the thread
	cout << "Main thread blocking until worker threads finish\n";
	pthread_join( tid_reader, NULL );
	pthread_join( tid_oddChecker, NULL );
	cout << "Main thread unblocked and outta here";
}

/* NOTE: Thread messages that are printed to standard out may get jubled
	sprintf is used to build the string before printing it to help minimize message jumbling
*/
void *inputReader( void *param ){
	cout << "!!! Reader Thread Running!\n";
	char* message = new char[10];
	while( value > -1 ){
		sprintf( message, "value = %d\n", value );
		cout << message;
		cout << "Input a new value: ";
		cin >> value;
	}
	cout << "inputReader thread exited\n";
	pthread_exit( 0 );
}

void *oddChecker( void *param ){
	cout << "!!! Odd Check Thread Running!\n";
	while( value > -1 ){
		if( value % 2 )
			cout << "\tvalue is odd!\n";
		int oldValue = value;
		while( oldValue == value ) ;
	}
	cout << "oddChecker thread exited\n";
	pthread_exit( 0 );
}