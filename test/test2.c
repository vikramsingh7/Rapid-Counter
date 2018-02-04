#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
printf("print some");




int pre = 1;
char filename[10];
sprintf(filename, "%d", pre);
char *suf = ".txt";
strcat(filename, suf);


//printf("%s" , spre);

 fopen(filename, "w");

}
