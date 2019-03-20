#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>

#include <iostream>
using namespace std;

int main(){

	const int SIZE = 128;
	const char *name = "Challenge";
	char messageBuffer[ 5 ];
	int shm_fd;
	void *ptr;
	bool anotherRound = true;
	shm_fd = shm_open(name, O_RDWR, 0666);	// opening shared memory region
	if(shm_fd == -1){
		cout << "CLEANER: ERROR: Opening shared memory failed\n";
		exit(-1);
	}

	ptr = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED){
		cout << "reader: ERROR: Map failed\n";
		exit(-1);
	}
	short newvalue = 0;
	short value = 0;
	do{
		bool oldData = true;
		while( oldData ){
			newvalue = *((short *)ptr);
			if( newvalue != value )
				oldData = false;
		}	// end of while( oldData )
		value = newvalue;

	
		// value will have newest value in shared mem
		
		// if first value (counter) print FIRST

		cout << "2: Value Received: " << value << endl;  //else 

		if (value == 1) {
			cout << "2: I lose!\n" << endl;
			break;
		}

		else if (value == 2){
			cout << "VICTORY IS MINE!\n\n" << endl;
			*((short *)ptr) = 1;
			break;
		}

		bool even = (value % 2 == 0);

		if (even){
			value = value / 2;
		}
		else {
			value = (value * 3) + 1;
		}


		cout << "2: Value to write into shared memory: " << value << endl;
		cout << "2: Awaiting new data in shared memory region" << endl;
		// WRITE NEW VALUE
		*((short *)ptr) = value;
		// increment counter for first value used


		cout << "reader: Value Received: " << value << endl;
	
	}while( newvalue > 0 );



	if(shm_unlink(name) == -1){
		cout << "2: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	cout << "2: Successfully closed shared memory region" << endl;
	return 0;
}