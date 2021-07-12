#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    char str[100000];int i=0;
    printf("Enter Your Code(type and enter _ to end input):\n");
    f= fopen("code.txt","w");
    if(f == NULL)
    printf("buffer!!");
    while(1)
    {
        str[i]=getchar();
        if(str[i]==95)
        {
            break;
        }
        i++;
    }    
    str[i-1]='\0';
    fprintf(f,"%s",str);
    fclose(f); 
}