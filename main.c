
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/stat.h>

  int ssum = 0; // The final sum of all words

  void *frequency(void *arg){
  int *p = (int*) arg;
  int limit = *p;
  char filename[20];
  sprintf(filename ,"%d" , limit);
  char *back = ".txt";
  strcat(filename,back);
      FILE *ob = fopen(filename, "r");
      int counter = 0;
      while(!feof(ob)){
      char c = getc(ob);
      if(c == ' '){
      counter++;
      ssum++;
  
     }
       }
  if((limit == 1)|| (limit ==4)|| (limit == 16)){
  printf("Filename %s  Number of Words %i \n " , filename, counter);
}
           pthread_exit(0);
}


int main(int adrgs, char **argv){
       
      

      int segments = atoi(argv[1]); // Number files to break the main file into
      pthread_t tid[segments];
      int args[segments];
 // It gives us the size of file total number of characters
       struct stat st;
       stat("just.txt", &st); 
       int size = st.st_size; // Number of Chars in main FILE
       int numOfChars = size/segments; //Number of chars each newly file have
// This loop will open  new files equal to required segments
        for(int seg=0; seg<segments; seg++){ 
        int pre = seg;     
        char filename[100];

        sprintf(filename, "%d", pre);  // It converts integer into stirng
        char *suf = ".txt";
        strcat(filename, suf); //Combined filename
        fopen(filename, "w"); // files opens here
 
}


// Main potion of code
 FILE *mainFile;  // Main file of program
 mainFile  = fopen("just.txt", "r");

 FILE *openFile[segments]; // Array of File Pointers

 char *back = ".txt"; 
 // This open the already created file so that words can be appended in them
  for(int fileNumber =0; fileNumber<segments; fileNumber++){
  int front = fileNumber;
  char filename1[100];
  sprintf(filename1, "%d" , front);
  strcat(filename1, back);

 openFile[fileNumber] = fopen(filename1,"a"); // Array pointers are used to create object of already created files
}

 int checker = numOfChars;
 int controller =0;
 int fileCounter =0; // suffix of filename
 while(!feof(mainFile)){
  char cc = getc(mainFile);
  fputc(cc, openFile[fileCounter]);  //appending data into files
  if(controller == checker){  // check if numchars reached
  fclose(openFile[fileCounter]); // close previous file
  fileCounter++;           // for new file
  checker = checker+numOfChars; //new test range 
  }

  controller++;  // gets update each time

 }
fclose(mainFile);
// files have been written

//Each thread will open different file
     for( int test=0; test<segments; test++){
     args[test] = test;
     pthread_create(&tid[test], NULL , frequency, &args[test]);
    }
   for(int numjoin=0; numjoin<segments; numjoin++){
    pthread_join(tid[numjoin], NULL);
   }
   printf("Total Number of Words %d \n" , ssum);
  exit(0);
}
