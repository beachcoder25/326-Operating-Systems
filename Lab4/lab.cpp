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
    }
 

    // STEP 2: Child1 then forks and waits for it's first child (child2)

    else if(pid == 0)
    { 

        // CHILD 1

            //pid_t pid;

            // STEP 2: Child1 then forks and waits for it's first child (child2)

            cout << "CHILD1: About to fork and show long list of directory contents\n";
            pid = fork(); // CHILD2 created


            if(pid == 0){

                //STEP3: Child2 displaying long list of directory contents

                execlp("ls", "ls", "-l", NULL);
            }

            else{

                // CHILD1: Waiting for CHILD2
                wait(&pid); // Only wait if pd > 0 i.e inside parent
            }

            //pid_t pid;
            cout << "CHILD1: about fork and show hello.cpp contents\n";
            pid = fork(); // CHILD3


            if(pid < 0){

                cout << "Error: Fork failed!\n";    // Pid should not be less than 0, 
                                                    // means neither parent nor child
            }
        

            // STEP 2: Child1 then forks and waits for it's first child (child2)

            else if(pid == 0)
            { 
                // CHILD3

                execlp("more", "more", "hello.cpp", NULL);
            
            }

            else{
                // CHILD1 waiting for CHILD3
                wait(&pid); // Only wait if pd > 0 i.e inside parent
                        
            }

            //pid_t pid;
            cout << "CHILD1: about fork and compile hello.cpp\n";
            pid = fork(); // CHILD4


            if(pid < 0){

                cout << "Error: Fork failed!\n";    // Pid should not be less than 0, 
                                                    // means neither parent nor child
            }
        
            else if(pid == 0)
            { 
                // CHILD4
                
                //execlp("more", "more", "hello.cpp", NULL);
                execlp("g++", "g++", "hello.cpp", "-o", "hello.out", NULL);
            
            }

            else{
                // CHILD1 waiting for CHILD4
                wait(&pid); // Only wait if pd > 0 i.e inside parent
                cout << "CHILD1: doing ./hello.out 2\n";

                execlp("./hello.out", "./hello.out", "2", NULL);
                
                        
            }
    }

    else{

        cout << "PARENT: Waiting for child to exit...\n";
        wait(&pid);
        cout << "\nPARENT: Child finally exited\n";
    }

    

    exit(0);
}