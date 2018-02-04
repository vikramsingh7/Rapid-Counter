#include<math.h>
#include<pthread.h>
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long sum = 0;

void* ssum(void* arg){
long long *limitPTR = (long long*) arg;
long long  value = *limitPTR;

for(long long i=0; i<=value; i++){
sum += i;
} 

pthread_exit(0);

}
int main(int args, char **argv){


long long limit = atoll(argv[1]);

pthread_t tid;
pthread_attr_t attr;

pthread_attr_init(&attr);

pthread_create(&tid, &attr, ssum, &limit);

//wait unit
pthread_join(tid, NULL);

printf("SUm is %lld \n" , sum);
}
