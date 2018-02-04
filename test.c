#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

int ssum = 0; // The final sum of all the words
void *sum(void *arg){

int *p = (int*) arg;
int limit = *p;


char filename[20];
sprintf(filename ,"%d" , limit);
char *back = ".txt";

strcat(filename,back);

FILE *ob = fopen(filename, "r");
//printf("The current file is %s \n" , filename);
int counter = 0;
while(!feof(ob)){
char c = getc(ob);
if(c == ' '){
counter++;
ssum++;
}



}
printf("Number of words in file are %i in file %s \n" , counter, filename);

pthread_exit(0);
}
int main(){

int segments = 4;

int limit1=0;
int limit2=1;
int limit3=2;
int limit4=3;
pthread_t tid[segments];
int args[segments];




//printf("S %i \n" , args[s]);
for( int test=0; test<segments; test++){
args[test] = test;
pthread_create(&tid[test], NULL , sum, &args[test]);

}
//pthread_create(&tid[1], NULL , sum, &limit2);
//pthread_create(&tid[2], NULL , sum, &limit3);
//pthread_create(&tid[3], NULL , sum, &limit4);



for(int numjoin=0; numjoin<segments; numjoin++){

pthread_join(tid[numjoin], NULL);

}
//pthread_join(tid[1], NULL);
//pthread_join(tid[2], NULL);
//pthread_join(tid[3], NULL);

printf("This is the fina lol dude%d" , ssum);


exit(0);
}
