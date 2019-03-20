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
	
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // Step1: Open shared memory region
	
	if(shm_fd == -1){
		cout << "CLEANER: ERROR: Opening shared memory failed\n";
		exit(-1);
	}

	cout << "shm_fd: " << shm_fd << endl;

	// memory map the shared memory object
	ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

	// STEP 2 CORRECT?
	// Step 2: Read a short integer value from base address of the shared memory region

	short *num = (short *)ptr; // This points to shared memory, this "reads" it
	
	// read from a shared memory object
	printf("Num Received: %i\n", *num);

	cout << "Message received: "  << *num << endl;

	// STEP 4

	*num = *num % 2; // 0 if even, NOT 0 if odd

	if(*num == 0){ // If even
		*num =  *num / 2;
		ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
		//sprintf((char *)ptr, "%s\n");
	}

	else if(*num != 0){ // If odd
		*num = (3 * (*num)) + 1;
		ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
		//sprintf((char *)ptr, "%s\n");

	}

	

	if(ptr == MAP_FAILED){
		cout << "ERROR: Map failed\n";
		exit(-1);
	}

	// cout << "Message received"  << (char *)ptr << endl;
	
	if(shm_unlink(name) == -1){ // Remove shared memory object p133
		cout << "CLEANER: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	cout << "CLEANER: Successfully closed shared memory region" << endl;
	return 0;
}

