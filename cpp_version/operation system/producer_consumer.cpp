#define N 100
typedef int semaphore;
semaphore mutex = 1; // default: available
semaphore empty = N; // the number of empty slots [00000]
semaphore full = 0; // the number of full slots. [11111]

void producer(){
    while(true){
        int item = produce_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        up(&mutex);
        up(&full);
    }
}

void consumer(){
    while(true){
        down(&full);
        down(&mutex);
        int item = remove_item();
        consume_item(item);
        up(&mutex);
        up(&empty);
    }
}
