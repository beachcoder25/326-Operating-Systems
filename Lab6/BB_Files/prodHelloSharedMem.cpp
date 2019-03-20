#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
	const int SIZE = 4096;

	const char *message = "Hello\n";

	const char *name = "SharedHello";

	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	ftruncate(shm_fd, SIZE);

	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	sprintf((char *)ptr, "%s", message);

	return 0;

}
