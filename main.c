#include<stdio.h>
#include<string.h>
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
    str[i]=feof(f);
    fprintf(f,"%s",str);
    fclose(f); 
    int count = 0;i=0;
    f=fopen("code.txt","r");
    char chr;
    chr= getc(f);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count++;
        }
        chr = getc(f);
    }
    if (chr!='\n')
    {
       count++;
    }
    printf("Number of line in code (NL0C) => %d",count);
    fclose(f);
}