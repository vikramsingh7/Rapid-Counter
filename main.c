
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/stat.h>

int main(int args, char **argv){

  
  int segments = 2; // Number files to break the main file ito
// It gives us the size of file total number of characters
  struct stat st;
  stat("just.txt", &st); 
  int size = st.st_size; // size of file

   printf("This size of file is %i \n" , size);
  //equal number of char in each new file
  int numOfChars = size/segments; 
  printf("%i" ,numOfChars); // print number of char for each file
printf("This size of file is %i \n" , numOfChars);

// This loop will open  new files equal to required segments
  for(int seg=0; seg<segments; seg++){ 
   int pre = seg;     
   char filename[100];
  sprintf(filename, "%d", pre);  // It converts integer into stirng
  char *suf = ".txt";
  strcat(filename, suf); //Combined filename
  fopen(filename, "w"); // file opens here
 
}



// GAME
 FILE *mainFile;
 mainFile  = fopen("just.txt", "r");

 FILE *openFile[segments]; // Array of File Pointers

 char *back = ".txt"; 
// This open the already created file so that words can be appended in them
 for(int fileNumber =0; fileNumber<segments; fileNumber++){
  int front = fileNumber;
char filename1[100];
sprintf(filename1, "%d" , front);
strcat(filename1, back);

 openFile[fileNumber] = fopen(filename1,"a");
 
}

int checker = numOfChars;
int controller =0;
int fileCounter =0;
 while(!feof(mainFile)){
 
char c = getc(mainFile);

fputc(c, openFile[fileCounter]);  //appending data into files
if(controller == checker){
fclose(openFile[fileCounter]);
fileCounter++;
}

 controller++;
printf("%c" , c);
}
fclose(mainFile);
}
