#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/mman.h>

#include <iostream>
using namespace std;


int main(){

	const int SIZE = 128;
	const char *name = "Challenge"; // name of the shared memory object

	char messageBuffer[ 5 ];
	int shm_fd;
	void *ptr;
	bool anotherRound = true;
	int count = 0;
	
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // Step1: Open shared memory region
    
	
	if(shm_fd == -1){
		cout << "CLEANER: ERROR: Opening shared memory failed\n";
		exit(-1);
	}

    // cout << "shm_fd: " << shm_fd << endl;

	// memory map the shared memory object
	ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if(ptr == MAP_FAILED){
		cout << "ERROR: Map failed\n";
		exit(-1);
	}

	// STEP 2 CORRECT?
	// Step 2: Read a short integer value from base address of the shared memory region

	short *num = (short *)ptr; // This points to shared memory, this "reads" it

    // Must check if new data is in shared memory region
    // done polling technique

    //bool oldData

    // Once new value is received
	
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

		if(count == 0){
			cout << "2: FIRST Value Received: " << value << endl;
		}

		else{
			cout << "2: Value Received: " << value << endl;
		}
		
        short x = value % 2;

        

        if(newvalue == 1){
            cout << "2: I lose!\n";
            break;
        }

        else if(newvalue == 2){
            cout << "VICTORY IS MINE!\n\n\nI WIN!\n\n";
            *((short *)ptr) = 1;
            break;

        } 

        if(x == 0){ // If even
        //cout << value << " is even\n";
	 	value =  value / 2;}

        else if(x != 0){ // If odd
        //cout << value << " is odd\n";
		value = (3 * (value)) + 1;}

        cout << "2: Value to write into shared memory: " << value << endl;
        cout << "2: Awaiting new data in shared memory region" << endl;
        *((short *)ptr) = value;
		count++;	
		
	}while( newvalue > 0 ); // While value is greater than 0


	

    cout << "2: About to close the shared memory region\n";

	

	// cout << "Message received"  << (char *)ptr << endl;
	
	if(shm_unlink(name) == -1){ // Remove shared memory object p133
		cout << "2: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	cout << "2: Successfully closed shared memory region" << endl;
	return 0;
}

