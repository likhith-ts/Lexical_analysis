#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    char str[100000];int i=0;
    printf("enter:\n");
    f= fopen("code.txt","w");
    if(f == NULL)
    printf("buffer!!");
    scanf("%[32-125]%*c",str);
    fprintf(f,"%s",str);
    fclose(f); 
}