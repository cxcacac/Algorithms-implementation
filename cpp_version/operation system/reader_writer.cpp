typedef int semaphore;
semaphore count_mutex = 1;
semephore data_mutex = 1;
int count = 0;

void reader(){
    while(true){
        down(&count_mutex);
        count++;
        if(count==1)
            down(&data_mutex); // the first reader must lock data;
        up(&count_mutex);
        read();
        down(&count_mutex);
        count--;
        if(count==0)
            up(&data_mutex); // the last reader must unlock data;
        up(&count_mutex);
    }
}

void writer(){
    while(true){
        down(&data_mutex);
        write();
        up(&data_mutex);
    }
}
