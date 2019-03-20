#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>

#include <iostream>
using namespace std;

int main(){

	const int SIZE = 4096;
	const char *name = "SharedHello";
	int shm_fd;
	void *ptr;
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if(shm_fd == -1){
		cout << "ERROR: Shared memory failed\n";
		exit(-1);
	}
	
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED){
		cout << "ERROR: Map failed\n";
		exit(-1);
	}
	cout << (char *)ptr << endl;
	if(shm_unlink(name) == -1){
		cout << "ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	return 0;
}

