#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
FILE *f;
char str[10000000],ch;
void NLOC();
void codeMenu();
void write();
void appendCode();
//void modifyCode();
void showCode();
void tokenMenu();
void totToken();
void indvToken();
struct Token    //structure to store token information.
{
    int total,oper,keyW;
    int str,cons,ident,sym;
}T={0};
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
        printf("\nWant to continue?[y/n]");
        ch= getch();
    } while (ch!='n');
}
//menu driven function for code modification
void codeMenu()
{   
    do{
                        
        system("cls");
        printf("\n\t\t\t\t\t\t\t\tCode Input\n");
        printf("1.Write Code\n2.Append Code\n");
        printf("3.Show Code\n4.Exit to main menu\n5.Exit\n");
        printf("Enter your choice: ");
        ch=getch();
        switch (ch)
        {
            case '1':
                write();
                break;
            case '2':
                appendCode();
                break;
            case '3':
                showCode();
                break;
            case '4':
                main();
                break;
            case '5':
                printf("\n Thank you!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice entered!!\n");
                break;
        }
        again:
        printf("\n*press[y]to continue\n*press[n]to exit\n*press[4]to go back to main menu\n>_");
        ch=getch();
        if(ch!='y'&&ch!='4'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='4');
    main();
}
//menu driven function for token count
void tokenMenu()
{
    
    do{
        system("cls");
        printf("\n\t\t\t\t\t\t\t\tTOKEN COUNT\n");
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
        printf("\n*press[y]to continue\n*press[n]to exit\n*press[4]to go back to main menu\n>_");
        ch=getch();
        if(ch!='y'&&ch!='4'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='4'); 
    main();
}

//func to calculate indvToken
void indvToken()
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
    //for loop to count symbols
    for(int i=0;i<=strlen(s);i++)
    {
        if (s[i] == ',' || s[i] == ';' || s[i] == '(' || s[i] == ')' ||
        s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '#' || s[i] == '\"')
        {
            //printf("\n%c",s[i]); -> just for debugging
            ++T.sym; 
        }
        
    }
    //for loop to count constant values
    for (i = 0; i < strlen(s);i++)
    {
        for(int j = i; j <strlen(s);j++)
        {
            if (isdigit(s[j])!=0)
            {
                //printf("\n%c\n", s[j]); -> just for debugging
                if(isdigit(s[j+1])!=0)
                continue;
                else
                {
                    ++T.cons;
                    i=j; 
                    break;
                }
            }
        } 
    }  
    //for loop to count operators 
    for(int i = 0; i <strlen(s);i++)
    {
         
        if ( s[i] == '/' || s[i] == '>' || s[i] == '<' )
        T.oper++;
        if(s[i] == '*')
        {
            if(s[i+1] == '*')
            {T.oper++; i=i++;}
            else
            T.oper++;
        }
        if(s[i] == '!'&&s[i+1] == '>')
        {
           T.oper++; i=i+2; 
        }
        if(s[i] == '!'&&s[i+1] == '<')
        {
            T.oper++; i=i+2; 
        }
        if(s[i] == '=')
        {
            if(s[i+1] == '=')
            {T.oper++; i++; continue;}
            else
            T.oper++;
        }
        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i+1] == '+' || s[i+1] == '-')
            {
                T.oper++; i++;
                continue;
            }
            else
            T.oper++;
        }
        
    }
    printf("\nOperators: %d\n",T.oper);
    printf("Symbols  : %d\n",T.sym);
    printf("Constants: %d\n",T.cons);
    fclose(f);
}

//func to count total no of token
void totToken()
{
    T.total=T.cons+T.ident+T.keyW+T.oper+T.str+T.sym;
    printf("Total No of Token: %d\n",T.total);
}

//function to write
void write()
{
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
void appendCode()
{
    showCode();
    int i=0;
    f= fopen("code.txt","a");
    printf("\nEnter Your Code(type and enter _ to end input):\n");
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
//show code
void showCode()
{
    printf("\nThe Code that was saved last time:\n ");
    f= fopen("code.txt", "r");
    fseek(f,0,SEEK_END);
    const int fileSize = ftell(f);int i=0;
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
    printf("Number of lines in code (NL0C) is : %d",count);
    fclose(f);
}