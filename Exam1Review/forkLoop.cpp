#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    for(int i = 0; i < 3; i++){
         int x = 0;
         x++;
        cout << "Child: " << getpid() << " has unique value: " << x << endl; 
        fork();
        
        
        
        

    }
}