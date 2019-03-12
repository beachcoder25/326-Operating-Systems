#include <sys/types.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(){
	string write_msg, msg_read;
	int write_int, int_read, count, total; 
	int num1 = -1;
	int num2 = -1;
	int exitNum = -1;
	int *num1pointer = &num1;
	int *num2pointer = &num2;

	const short MSG_SIZE = 25;
	char msg_write[ MSG_SIZE ];
	char read_msg[ MSG_SIZE ];


	int fd[2], childCount;
	int parentCount = 0;
	pid_t pid;
	pipe( fd );
	pid = fork();


	if( pid > 0 ){	// in parent
	
		 	close( fd[0] );	// close unused Read End


		while( write_msg != "done" ){
		//while(parentCount < 3){

			if(parentCount == 3){
				close( fd[1] );	// all done, close the pipe!
				cout << "Parent process about to exit\n";
				exit(0);
			}
			cout << "PARENT: Enter a message to send: ";
			cin >> write_msg;
			
			parentCount ++;
			cout << "Pcount" << parentCount << endl;
			// cout << "PARENT, sending: " << write_msg << endl; CHECKING COUNT WORKS
			unsigned int size = write_msg.length();
			write_msg.copy( msg_write, write_msg.length(), 0 );
			write( fd[1], msg_write, MSG_SIZE );
			for( int i = 0; i < MSG_SIZE; i++ )
				msg_write[ i ] = '\0';	// overwrite the message local array
			//write( fd[1], msg_write, MSG_SIZE );	// overwrite the shared memory area
			//parentCount++;
		}
		close( fd[1] );	// all done, close the pipe!
		cout << "Parent process about to exit\n";
	}
	else{
		
		close( fd [1] );	// close unused write end
		
		// Use a counter for while loop, once count == 3 break
		while( msg_read != "done" ){
		
			read( fd[0], read_msg, MSG_SIZE );
			cout << "In child, msg read: " << read_msg << endl;

			if(num1 == -1){
				num1 = atoi(read_msg);
				
				// Check to make sure proper digit entered
				if(num1 < 0 || num1 > 99){
					cout << "ERROR: Program can only process positive digits less than 100, please start over" << endl;
					break;
				}
				num1pointer = &num1;
				cout << "CHILD: Value A = " << num1 << endl;
				
			}

			else if(num1 != -1 && count != 99){
				msg_read = read_msg;
				
				// Dummy count used for if statements
				count = 99;
				
				if(msg_read == "+"){
					cout << "CHILD: Operation addition" << endl;
				}

				else{
					cout << "CHILD: Operation subtraction" << endl;
				}
			}

			else if(num2 == -1){
				num2 = atoi(read_msg);

				// Check to make sure proper digit entered
				if(num2 < 0 || num2 > 99){
					cout << "ERROR: Program can only process positive digits less than 100, please start over" << endl;
					break;
				}

				cout << "CHILD: Value B = " << num1 << endl;

				if(msg_read == "+"){
				total = *num1pointer + num2;
				cout << num1 << " + " << num2 << " = " << total << endl;
				exitNum = 99;
				parentCount = 3;
				break;

				}

				else if(msg_read == "-"){
				total = num1 - num2;
				cout << num1 << " - " << num2 << " = " << total << endl;
				exitNum = 99;
				parentCount =3;
				break;

			}

			
			}
			

						
		}
		close( fd[0] );	// all done, close the pipe!
		cout << "Child process about to exit\n";
	}
	exit(0);
}