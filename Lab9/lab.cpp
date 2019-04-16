#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
using namespace std;

// pthread variables
pthread_t
    *tids; // array of worker thread IDs
pthread_cond_t
    *tEnable,   // enable a worker thread to print
    tPrinted;   //worker thread printing complete
pthread_mutex_t
    theMutex;   // mutex variable

static int cleanup_pop_arg = 0;
static void cleanupHandler( void *arg){
    cout << "Worker " << cleanup_pop_arg
        << " cleaning up and exiting\n"
        "Worker ";
    if( pthread_mutex_unlock( &theMutex ) != 0)
        cout << "UHOH!\n";
}

short signify = 0; // thread launch delay variable

//Worker Info Management Class

// class for Worker Threa data
class WorkerInfo {


public:


    WorkerInfo(){}

    WorkerInfo(WorkerInfo &wi)
    
        :workerID( wi.workerID), 
        sizeOfDataSet( wi.sizeOfDataSet) {
        dataSet = new short[ sizeOfDataSet];

        for(int i = 0; i < sizeOfDataSet; i++)
            dataSet[ i] = wi.dataSet[ i ];
        }  
    

    WorkerInfo ( short wid, short sods )
        :workerID( wid ), sizeOfDataSet( sods ){}

    void putDataInSet( short sA[], short size ){

        if( size != sizeOfDataSet ){
            cout << "\tsize not equal\n";
            sizeOfDataSet = size;
            
            if( dataSet != nullptr )
                delete [] dataSet;
            
            dataSet = new short[ size ];
        }

        if( dataSet == nullptr) {
            cout << "Allocating  memory for sata set!\n";
            dataSet = new short[ size ];

        }

        cout << "\tinitializing dataset\n";

        for( int i = 0; i < sizeOfDataSet; i++ )
            dataSet[ i ] = sA[ i ];
    }

    void showDataSet( ){
        cout << "worker " << workerID << " showing data:\n";

        for( int i = 0; i < sizeOfDataSet; i++ )
            cout << '\t' << dataSet[ i ] << endl;
    }

    short getWorkerID(){ return workerID; }

    ~WorkerInfo(){
        cout << workerID << " destroying data set\n\n";
        delete [] dataSet;
    }
private: 
    short workerID = 0;
    short sizeOfDataSet = 0;
    short *dataSet = nullptr;


};

void *boss(void *param){

    
    short runningWorkers = *((short *) param);
    bool workerRunning[*(short *)param];
    

    // DOUBLE CHECK
    // for loop is correct?
    for(int i = 0; i < *(short *)param; i++){
        workerRunning[i] = true;

    }

    cout << "!!! boss Thread running!\n"
            "managing "
            << *(short *)param << " workerthreads\n";

    cout << "Enter a number of 1 to " << *(short *)param << " "
    "to make a thread print it's data set\n"
    "Enter the negated value of a worker"
    "thread to cancel to that thread\n"
    "Enter 0 to make all threads"
    "output their data sets\n";

    int input = 0;

    // loop1 


    while(runningWorkers != 0){ // Double check this is what the loop should be!!!
        cout << "> ";
        cin >> input;

        if(input == 0){
            

            // loop2

            for(int i = 0; i < *(short *)param; i++){

                if(workerRunning[i]){
                    pthread_cond_signal( &tEnable[i]);
                    
                }
            }

            // loop1 continue check
            //break;
        }

        else if(input > 0 && input <= *(short *)param){

            // Not sure about this conditional check
            if(workerRunning[input - 1]){
                pthread_cond_signal( &tEnable[ input -1]);
                
            }

            else{
                cout << "worker " << input << " already finished\n";

            }

        }

        // Do we have to do anything for loop1 continue check 
        // besides ensuring we are back in the loop?

        else if(input < 0 && (-input) <= *(short *)param){
            input = -input;

            if(workerRunning[ input - 1 ]){

                // DOUBLE CHECK
                // if False

                cout << "Cancelling worker " << input << endl;

                cleanup_pop_arg = input;

                pthread_cancel( tids[ input - 1] );

                workerRunning[ input - 1 ] = false;
                    runningWorkers--;

            }

            else{
                cout << "Worker" << input << " already cancelled\n";

            }    
            
        }

        else{
            cout << "ERROR: Invalid Entry\n";}

    }

            // DOUBLE CHECK
        // Confused on loop condition for next step!!!!!!

        cout << "Boss exits!\n";

        pthread_exit( 0 );

}

void *worker(void *param){

    WorkerInfo myInfo( *(WorkerInfo *)param);

    cout << "Worker Thread " << myInfo.getWorkerID() << " Running!\n";
    signify++;
    pthread_cleanup_push( cleanupHandler, NULL); 

    while(true){

        pthread_mutex_lock( &theMutex);

        pthread_cond_wait( &tEnable[ myInfo.getWorkerID() - 1], &theMutex);
        myInfo.showDataSet();
        pthread_mutex_unlock( &theMutex);

    }

    pthread_cleanup_pop(cleanup_pop_arg);

}
// worker controller thread function    
void *boss( void *param );

// worker thread function
void *worker( void *param);




int main( int argc, char ** argv ){
    short numThreads = atoi( argv[1] );
    tids = new pthread_t[ numThreads ];
    tEnable = new pthread_cond_t[ numThreads ];
    pthread_t bossTid;
    pthread_mutex_init( &theMutex, 0);
    short dataSetIndex = 2;

    for( int i = 0; i < numThreads; i++ ){
        short sizeOfDataSet = atoi( argv[ dataSetIndex ] );

        WorkerInfo tempWorker( i + 1, sizeOfDataSet );
        
        cout    << "Temp worker "
                << tempWorker.getWorkerID()
                << " initializing!\n";
        
        short dSet[ sizeOfDataSet ];
        dataSetIndex++;

        for( int j = 0; j < sizeOfDataSet; ++j ){

            dSet[ j ] = atoi( argv[dataSetIndex ] );
            cout << "dSet [ " << j << "  ] = " << dSet[ j ] << endl;
            dataSetIndex++;
        }

        cout    << "sizeof dset: " << ( sizeof(dSet) / sizeof( short ) ) << endl;

        tempWorker.putDataInSet( dSet, sizeOfDataSet );
        pthread_cond_init( &tEnable[ i ], 0);
        cout << "Creating worker theead\n";
        short tmp = signify;
        pthread_create( & tids[ i], NULL, worker, &tempWorker );

        // wait for thread to launch / initialize

        while(signify == tmp ) ;
            cout << "temp worker ";
    }

    pthread_create( &bossTid, NULL, boss, &numThreads );
    cout << "Main thread blocking until boss thread finishes\n\n";
    pthread_join( bossTid, NULL);
    cout << "\n\nMain thread unblocked and outta here\n\n";

    for( int i = 0; i < numThreads; i++ )
        pthread_mutex_destroy( &theMutex );
        delete [] tids;
        delete [] tEnable;

}