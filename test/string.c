#include<stdio.h>
#include<stdlib.h>

int main(int argc , char **argv){

char *name = argv[1];

 

printf("This is argv %s \n" , name);
printf("THis is the address of the arg %p \n" , name);
printf("This is hte address of pinter it serlf %p \n", &name);
}

