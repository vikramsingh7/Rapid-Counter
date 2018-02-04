#include<stdio.h>
#include<stdlib.h>

int main()
{

int x = 5;
int *c;


printf(" Value at memory address stored in x: %i \n" , x);
printf(" Memory address of value: %p \n",  &x);

//c = &x;
*c = 23;
printf("The value stored at in c's stored memory address %i \n" , *c);
printf("This is the momory addres of %p \n",  &c);
printf("Memoery addrees c has %p \n",  c);


printf(" Value at memory address stored in x: %i \n" , x);

}
