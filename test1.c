#include<math.h>
#include<pthread.h>
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long sum = 0;
int kk = 45;
void* countWord(void* arg){
long long *limitPTR = (long long*) arg;
long long  idNumber = *limitPTR;

for(long long i=0; i<=value; i++){
sum += i;
} 

pthread_exit(0);

}
int main(int args, char **argv){
long long segments = atoll(argv[1]);

pthread_t arrayTid[segments];

// Create seperate thread for each segment
for(int createT=0; createT<segments; createT++){
pthread_create(&arrayTid[createT], NULL, &countWord, )
}
pthread_create(&tid, NULL, ssum, &limit);
pthread_create(&tid2, NULL , ssum, &kk);
//wait unit
pthread_join(tid, NULL);

printf("First Thread has finished");
printf("Sum after first %lld \n" ,sum);
pthread_join(tid2, NULL);


//printf("The tid value of thread %d /n" ,(int) tid);

 // printf("The pid of process %d /n") ,
printf("SUm is %lld \n" , sum);



}
