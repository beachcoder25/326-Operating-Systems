
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

int main() {

    // Create msgQ with key value from ftok()
	int qid = msgget(ftok(".",'u'), IPC_EXCL | IPC_CREAT | 0600);
    
    
    if( qid < 0 ){ 
        cout << "A, Q create FAIL!\n";
	    qid = msgget(ftok(".",'u'), IPC_EXCL | 0600);

        if( qid < 0 ){
            cout << "A, Q access FAIL!\n";
            exit( -1 );
        }
    }
	else{
		cout << "Q create SUCCESS\n";
	}

	struct buf {
		long mtype;
		char g[5];
	};

    int count = 0;
    int remainder0 = 0;
    int remainder1 = 0;
    int sendInt = 0;
    int nextValue = 0;
	buf msg;
	int size = sizeof(msg)-sizeof(long);
	strcpy( msg.g, "From A");
	
	do{

        if(count == 0){
        
        count++;
        
        // Read message of type 0 to take first value entered into queue
        msgrcv (qid, (struct msgbuf *)&msg, size, 0,0);

        sendInt = atoi(msg.g);
        cout << "Challenger: Received " << msg.g << endl;

        remainder0 = sendInt % 2;

        if(remainder0 == 0){
            cout << "Value is even: \n";
            sendInt = sendInt / 2;
        }

        else if(remainder0 != 0){
            cout << "Value is odd: \n";
            sendInt = (3 * (sendInt)) + 1;
        }

        
        // Calculate next received value

        remainder1 = sendInt % 2;

        if(remainder1 == 0){
            cout << "Will receive even value: \n";
            sendInt = sendInt / 2;
        }

        else if(remainder1 != 0){
            cout << "Will receive odd: \n";
            sendInt = (3 * (sendInt)) + 1;
        }
        
        }
	    
        else{

        }
        
        cout << "Enter a message"
	            " TYPE to SEND: ";
        cin >> msg.mtype;
	    cout << "A,Sending: " << msg.mtype << endl;

        if(
        	msgsnd( qid,(struct msgbuf *)&msg, size, 0) < 0 ){
            cout << "A, send FAIL!\n";
        }

	}while( msg.mtype > 0 );

	cout << "Removing queue\n";
	if( msgctl (qid, IPC_RMID, NULL) )
	    cout << "A, Q remove FAIL!\n";
    else
	    cout << "A, Q remove SUCCESS!\n";
	exit(0);
}
