#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    char str[100000];
    printf("enter:\n");
    f= open("code.txt","w");
    fscanf(f,"%[^\0]%s",str);
    fclose(f); 
}