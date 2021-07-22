#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
FILE *f;
void NLOC();
void write();
int main()
{
    char ch,c;
    do
    {
        printf("\t\t\t\tWelcome\n");
        printf("\t\t\tLEXICAL ANALYSIS\n");
        printf("1.Modify Code\n2.NLOC\n");
        printf("3.Token Count\n4.Complexity Analysis\n");
        printf("Enter your choice: ");
        c= getch();
        switch (c)
        {
        case '1':
            printf("\nunder development!!");
            write();
            break;
        case '2':
            NLOC();
            break;
        case '3':
            printf("under development!!");
            break;
        case '4':
            printf("under development!!");
            break;
        default:
            printf("\nEnter Proper choice!!");
            break;
        }
        printf("\nWant to continue?[y:n]");
        ch= getch();
    } while (ch!='n');
}

void write()
{
    char str[100000]; 
    int i=0;
    printf("\nEnter Your Code(type and enter _ to end input):\n");
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
    if(f==NULL)
    printf("Code saved to code.txt in disk!!");
    fclose(f); 
}

void NLOC()
{
    int count = 0;
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