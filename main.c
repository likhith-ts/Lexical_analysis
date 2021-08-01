#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
FILE *f;
char ch;
void NLOC();
void codeMenu();
void write();
void modify();
void showCode();
void tokenMenu();
int totToken();
int indvToken();
struct Token    //structure to store token information.
{
    int total,oper,keyW;
    int str,cons,ident,sym;
}T;

int main()
{
    do
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\t\t\tWelcome\n");
        printf("\t\t\t\t\t\t\t\t   LEXICAL ANALYSIS\n");
        printf("1.Code Input\n2.NLOC\n");
        printf("3.Token Count\n4.Complexity Analysis\n5.Exit\n");
        printf("Enter your choice: ");
        ch= getch();
        switch (ch)
        {
        case '1':
            //under development!!
            codeMenu();
            break;
        case '2':
            NLOC();
            break;
        case '3':
            //under development!!
            tokenMenu();
            break;
        case '4':
            printf("under development!!");
            break;
        case '5':
            printf("\nThank you!!");
            exit(0);
            break;
        default:
            printf("\nEnter Proper choice!!");
            break;
        }
        printf("\nWant to continue?[y:n]");
        ch= getch();
    } while (ch!='n');
}
//menu driven function for code modification
void codeMenu()
{   
    do{
                        
        system("cls");
        printf("\n\t\t\t\t\t\t\t\t\tCode Input\n");
        printf("1.Write Code\n2.Modify/append existing code\n");
        printf("3.Show Code\n4.Exit to main menu\n5.Exit\n");
        printf("Enter your choice: ");
        ch=getch();
        switch (ch)
        {
            case '1':
                write();
                break;
            case '2':
                modify();
                break;
            case '3':
                showCode();
                break;
            case '4':
                main();
                break;
            case '5':
                exit(0);
                break;
            default:
                break;
        }
        again:
        printf("\npress[y]to continue, 4 to exit to main menu and[n]to exit: ");
        ch=getch();
        if(ch!='y'&&ch!='4'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='4');
}
//menu driven function for token count
void tokenMenu()
{
    system("cls");
    do{
        printf("\n\t\t\t\t\t\t\t\t\tTOKEN COUNT\n");
        printf("1.Total Token Count\n2.Classified Token count\n");
        printf("3.Most Repeated Token\n4.Back To Main menu\n");
        printf("Enter your choice: ");
        ch=getch();
        switch (ch)
        {
        case '1':
            printf("under Devlopment!!\n");
            totToken();
            break;
        case '2':
            printf("under Devlopment!!\n");
            indvToken();
            break;
        case '3':
            printf("under Devlopment!!");
            break;
        case '4':
            main();
            break;
        default:
            printf("Enter a Valid choice!! ");
            break;
        }
        again:
        printf("\npress[y]to continue, 4 to exit to main menu and[n]to exit: ");
        ch=getch();
        if(ch!='y'&&ch!='4'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='4'); 
    main();
}

//func to calculate indvToken
int indvToken()
{
    f= fopen("code.txt", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize];
    fseek(f,0,SEEK_SET);
    s[i]=getc(f);
    while(s[i]!= EOF)
    {
        ++i;
        s[i]=getc(f);
    }
    printf("\n");
    puts(s);
    fclose(f);
}

//func to count total no of token
int totToken()
{
    T.total=T.cons+T.ident+T.keyW+T.oper+T.str+T.sym;
    return T.total;
}

//function to write
void write()
{
    char str[100000]; 
    int i=0;
    printf("\nEnter Your Code(type and enter _ to end input):\n");
    f= fopen("code.txt","w");
    if(f == NULL)
    printf("file not exist!!");
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
    if(f!=NULL)
    printf("Code saved to code.txt successfuly!!");
    fclose(f); 
}
//modify
void modify()
{
    char str[100000]; 
    int i=0;
    printf("\nAppend Your Code(type and enter _ to end input):\n");
    f= fopen("code.txt","a");
    if(f == NULL)
    printf("file not exist!!");
    fprintf(f,"\n");
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
    fseek(f,0,SEEK_END);
    fprintf(f,"%s",str);
    if(f!=NULL)
    printf("Code saved to code.txt successfuly!!");
    fclose(f); 
}
//show code
void showCode()
{
    f= fopen("code.txt", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize];
    fseek(f,0,SEEK_SET);
    s[i]=getc(f);
    while(s[i]!= EOF)
    {
        ++i;
        s[i]=getc(f);
    }
    printf("\n");
    puts(s);
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