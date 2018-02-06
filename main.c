#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<sys/stat.h>




int startFrom = 0;
int range = 0;
int fCounter = 0;
int finalSum = 0;

void *counter(void *arg){
fCounter++;
char arr[range];

int *ar = (int* ) arg;
int threadNumber = *ar;
int wordC = 0;
//printf( "The threadnumber is %i \n" , threadNumber);
FILE *ob = fopen("MAINTAINERS.txt" , "r");


fseek(ob, startFrom, SEEK_SET);

fread(arr,1, range, ob);
for(int i=0; i<range; i++){
char c = arr[i];
if(c == ' '){
wordC++;
finalSum++;
}
}

if(fCounter == -5){
printf("%i" , threadNumber);
}

if(fCounter == 1 || fCounter ==4 || fCounter == 16){
printf("Words in Thread %i are %i \n", fCounter, wordC);
}
startFrom = range*fCounter;
pthread_exit(0);
}


int main(int argx , char **argv){

      int segments = atoi(argv[1]); // Number files to break the main file into
      pthread_t tid[segments];
      int args;


       struct stat st;
       stat("MAINTAINERS.txt", &st); 
       int size = st.st_size; // Number of Chars in main FILE
       int numOfChars = size/segments;
      
       //printf(" Size of file %i \n " ,size);
       //printf( "Num chars %i \n " ,numOfChars);
      
       range = numOfChars;
     
   for(int i=0; i<segments; i++){
      args++;
   pthread_create(&tid[i], NULL, counter, &args);

   }

   for(int j=0; j<segments; j++){
   pthread_join(tid[j], NULL);
   }

 printf("Total number of words are %i: ", finalSum);

   exit(0);
}
