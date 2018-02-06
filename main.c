#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<sys/stat.h>


int finalChars = 0;
int fCounter = 0;

void *counter(void *arg){
fCounter++;

int *ar = (int* ) arg;
int numChars = *ar;
int limit =0;
limit = numChars*fCounter;


int pre = limit - finalChars;

FILE *ob = fopen("just.txt" , "r");

printf("Start from %i \n" , pre);
printf( "Upto %i \n" ,finalChars);


fseek(ob ,  6 , SEEK_SET);

for(int i=0; i<finalChars; i++){
char c = getc(ob);
printf("%c" , c);
}
pthread_exit(0);
}


int main(){
      int segments = 4; // Number files to break the main file into
      pthread_t tid[segments];
      int args;


       struct stat st;
       stat("just.txt", &st); 
       int size = st.st_size; // Number of Chars in main FILE
       int numOfChars = size/segments;
    printf(" Size of file %i \n " ,size);
    printf( "Num chars %i \n " ,numOfChars);
      
       finalChars = numOfChars;
      args = numOfChars;
   for(int i=0; i<segments; i++){
      
   pthread_create(&tid[i], NULL, counter, &args);

   }

   for(int j=0; j<segments; j++){
   pthread_join(tid[j], NULL);
   }

   exit(0);
}
