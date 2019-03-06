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
	shm_fd = shm_open(name, O_RDWR, 0666); // Step1: Open shared memory region


	// Step 2: Read a short integer value from base address of the shared memory region
	
	// Questions:

	// Do we need to create the struct buf? 
	// If so I believe char messageBuffer would go in there/be re-defined in there...?

	// struct buf{
	// 	long mtype;
	// 	char msgBuffer[5]; // Message data
	// } msg;

	// Do we need to create the queue? I dont think so, but am unsure of how we would receive without it

	// int qid = msgget(ftok(".", 'Z'), IPC_EXCL | IPC_CREAT | 0600);

	if(shm_fd == -1){
		cout << "CLEANER: ERROR: Opening shared memory failed\n";
		exit(-1);
	}

	// memory map the shared memory object
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

	if(ptr == MAP_FAILED){
		cout << "ERROR: Map failed\n";
		exit(-1);
	}

	cout << "Message received"  << (char *)ptr << endl;
	
	if(shm_unlink(name) == -1){
		cout << "CLEANER: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	cout << "CLEANER: Successfully closed shared memory region" << endl;
	return 0;
}

