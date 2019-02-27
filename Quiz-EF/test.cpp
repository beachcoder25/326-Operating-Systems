#include <stdio.h>
#include <unistd.h>


int main(){
    static const char *mesg[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int display(const char *), i;

    for(i=0; i < 10; i++)
            display(mesg[i]);
    sleep(2);
    return 0;
 
}   

int display(const char *m){
    char err_msg[25];
    switch(fork()){
        case 0:
                execlp("/bin/fakeDir", "echo", m, (char *)NULL);
                sprintf(err_msg, "%s Exec failuer", m);
                perror(err_msg);
                return(1);
                // _exit(1);
        case -1:
                perror("Fork failure");
                return(2);
        default:
                return(0);
    }
}