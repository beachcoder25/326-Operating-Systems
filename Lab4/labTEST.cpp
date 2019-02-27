#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(){

    pid_t pid;

    // STEP 1: Forks and makes the parent wait for it's child (child1)
    pid = fork(); 

    if(pid < 0){

        cout << "Error: Fork failed!\n";    // Pid should not be less than 0, 
                                            // means neither parent nor child

        if(execlp( "./repeatHello.out", ".repeatHello.out", "3", NULL) == - 1){

            cout << "Error: exec failed!\n"; // Ask about what is happening here...
            _exit(1);
        }
    }
 



    // STEP 2: Child1 then forks and waits for it's first child (child2)

    else if(pid == 0){ /* child process */

        // CHILD 1


        // STEP 5 child3 displays contents of hello.cpp (more hello.cpp)
        char *cwd = getcwd(NULL, 0); // Gets current working directory
        execlp("ls", "ls", "-l", cwd, NULL);

    }

    else{ // positive pid means this is a parent process
        
        cout << "\nParent: Waiting for child to exit...\n";
        wait(&pid); // Only wait if pd > 0 i.e inside parent
        cout << "\nParent: Child finally finally exited";


    }

    _exit(0);
}

