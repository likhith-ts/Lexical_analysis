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
void showCode();
void tokenMenu();
void specificToken(int a);
void countToken();
void keywordCount();
void operatorCount();
void identifierCount();
struct Token    //structure to store token count information.
{
    int total,oper,keyW;
    int cons,ident,sym;
}T={0};
struct constant  //structure to store constants count information.
{
    int integers,decimals,strings,chr;
}con={0};
struct operator //structure to store operators
{
    int arithmetic,relational,logical,bitwise,assignment,misc;
}ops={0};
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
        printf("\n*press[y]to continue\n*press[n]to exit\n*press[b]to go back to main menu\n>_");
        ch=getch();
        if(ch!='y'&&ch!='b'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='b');
    main();
}
//menu driven function for token count
void tokenMenu()
{
    int x;
    do{
        system("cls");
        countToken();
        printf("\n\t\t\t\t\t\t\t\tTOKEN COUNT\n");
        printf("1.Total No of Tokens\n2.Classified Token count\n");
        printf("3.Specific Token count\n4.Back To Main menu\n5.Exit\n");
        printf("Enter your choice: ");
        ch=getch();
        switch (ch)
        {
        case '1':
            printf("Total No of Token: %d\n",T.total);
            break;
        case '2':
            system("cls");
            printf("Operators  : %d\n",T.oper);
            printf("Symbols    : %d\n",T.sym);
            printf("Constants  : %d\n",T.cons);
            printf("KeyWords   : %d\n",T.keyW);
            printf("Identifier : %d\n",T.ident);
            break;
        case '3':
            system("cls");
            try:
            printf("1.KeyWords\n2.Identifier\n3.Operators\n4.Symbols\n5.Constants\nEnter Your choice:");
            scanf("%d",&x);
            if(x<=5)
            {
                system("cls");
                specificToken(x);
            }
            else
            {
                system("cls");
                printf("\nInvalid choice!!Try again\n");
                goto try;  
            }
            break;
        case '4':
            main();
            break;
        case '5':
            exit(0);
            break;
        default:
            printf("Enter a Valid choice!! ");
            break;
        }
        again:
        printf("\n*press[y]to continue\n*press[n]to exit\n*press[b]to go back to main menu\n>_");
        ch=getch();
        if(ch!='y'&&ch!='b'&&ch!='n') {printf("Invalid choice!!"); goto again;}
        else if(ch=='n') {printf("\nThank you");exit(0);}
    }while(ch!='b'); 
    main();
}

//func to calculate Tokens
void countToken()
{
    memset(&T, 0, sizeof T);
    memset(&con, 0, sizeof con);// using memset(memory set) predifined function to set all struc variables to 0 
    f= fopen("code.txt ", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize];
    fseek(f,0,SEEK_SET);
    s[i]=getc(f);
    while(s[i]!= EOF) //while to get all char from file
    {
        ++i;
        s[i]=getc(f);
    }
    //for loop to count special characters (symbols)
    for(int i=0;i<=strlen(s);i++)
    {
        if (s[i] == ',' || s[i] == ';' || s[i] == '(' || s[i] == ')' ||
        s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '#')
        {
            //printf("\n%c",s[i]); -> just for debugging
            ++T.sym; 
        }
        
    }
    //3 loops to count constant values of 3 types
    /*1.for loop to count constant integers
    for (i = 0; i < strlen(s);i++)
    {
        for(int j = i; j <strlen(s);j++)
        {
            if (isdigit(s[j])!=0&&s[i+1]!='.')
            {
            //printf("\n%c\n", s[j]); //-> just for debugging
                if(isdigit(s[j+1])!=0)
                continue;
                else if(s[j+1]!='.')
                {
                    ++con.integers;
                    for(int k=j+1; k <strlen(s);k++) 
                    {
                        
                        if(isdigit(s[k])!=0)
                        continue;
                        else 
                        i=k; 
                    }
                    break;
                }
            }
        } 
    }  */
    //2.for loop to count constant decimals
    for (i = 0; i < strlen(s);i++)
    {
        for(int j = i; j <strlen(s);j++)
        {
            if (isdigit(s[j])!=0)
            {
               //printf("\n%c\n", s[j]); //-> just for debugging
                if(isdigit(s[j+1])!=0)
                continue;
                else if(s[j+1]=='.')
                continue;
                else
                {
                    ++con.decimals;
                    i=j+1; 
                    break;
                }
            }
        } 
    } 
    //3.for loop to count constant strings
    for (i = 0; i < strlen(s);i++)
    {
        if (s[i]=='\"')
        {
            for(int j = i+1; j <strlen(s);j++)
            {
                //printf("\n%c\n", s[j]);//just for debugging
                if(s[j]!='\"')
                {continue;}
                else
                {
                    //printf("\n%c\n", s[j+1]);
                    ++con.strings;
                    i=j; 
                    break;
                }
            }
        }
        else
        continue;
    }  
    //4.for loop to count constant characters
    for(int i = 0; i < strlen(s);i++)
    {
        if(s[i]=='\''&&(s[i+2]=='\''||s[i+3]=='\'')) 
        {
            ++con.chr;
            if(s[i+2]=='\'')
            i+=2;
            else if(s[i+3]=='\'')
            i+=3;
        }
        else
        continue;
    }
    keywordCount();// calling function function to count keywords
    operatorCount();
    identifierCount();
    T.oper= ops.arithmetic+ops.assignment+ops.bitwise+ops.logical+ops.relational+ops.misc;
    T.cons= con.strings+con.chr+con.decimals;
    T.total=T.cons+T.ident+T.keyW+T.oper+T.sym;
    fclose(f);
}
//function to count operators
void operatorCount()
{
    memset(&ops, 0, sizeof ops);
    f= fopen("code.txt ", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize];
    fseek(f,0,SEEK_SET);
    s[i]=getc(f);
    while(s[i]!= EOF) //while to get all char from file
    {
        ++i;
        s[i]=getc(f);
    }
    //for loop to count operators 
    for(int i = 0; i <strlen(s);i++)
    {
        //to count logical operators
        if((s[i]=='&'&&s[i+1]=='&')||(s[i]=='|'&&s[i+1]=='|')||s[i]=='!')
        {
            ++ops.logical;
            if(s[i+1]=='&'||s[i+1]=='|')
            ++i;
        }
        //to count bitwise operators
        if((s[i]=='|'&&isalnum(s[i+1])!=0)||(s[i]=='&'&&isalnum(s[i+1])!=0)||(s[i]=='^'&&isalnum(s[i+1])!=0)
        ||(s[i]=='~'&&isalnum(s[i+1])!=0)||(s[i]=='<'&&s[i+1]=='<')||(s[i]=='>'&&s[i+1]=='>'))
        {
            ++ops.bitwise;
            ++i;
        }
        //to count misc operators
        if((s[i]=='?'&&s[i+2]==':')||(s[i]=='*'&&s[i+1]=='*'))
        {
            ++ops.misc;
            if(s[i+2]==':')
            i+=2;
            else
            ++i;
        }
        //to count assignment operators
        if((s[i]=='='&&s[i+1]!='=')||(s[i]=='+'&&s[i+1]=='=')||(s[i]=='-'&&s[i+1]=='='))
        {
            ++ops.assignment;
            if(s[i+1]=='=')
            ++i;
        }
        //to count relational operators
        if((s[i]=='='&&s[i+1]=='=')||(s[i]=='!'&&s[i+1]=='=')||(s[i]=='<'&&s[i+1]=='=')||(s[i]=='>'&&s[i+1]=='='))
        {
            ++ops.relational;
            ++i;
        }
        if((s[i]=='<'&&isalnum(s[i+1])!=0&&s[i-8]!='#')||(s[i]=='>'&&isalnum(s[i+1])!=0))
        //s[i-8]!=# condition is exclude headerfile statements
        ++ops.relational;
        //to count arithmetic
        if((s[i]=='+'&&(s[i+1]=='+'||isalnum(s[i+1])!=0))||(s[i]=='-'&&(s[i+1]=='-'||isalnum(s[i+1])!=0))
        ||(s[i]=='*'&&isalnum(s[i+1])!=0))
        {
            ++ops.arithmetic;
            if(s[i+1]=='+'||s[i+1]=='-')
            ++i;
        }
        if(s[i]=='/'||s[i]=='%')
        ++ops.arithmetic;
    }
}
//function to count keywords
void keywordCount()
{
    f= fopen("code.txt ", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize]; char s2[10000];
    fseek(f,0,SEEK_SET);
    while(s[i]!= EOF) //while to get all char from file
    {
        ++i;
        s[i]=getc(f);
    }
    for(int i= 0; i <strlen(s);i++)
    {
        char s2[10000]={"\0"};
        for(int j=i; j <strlen(s);j++)// for parsing string
        {
            if(isalpha(s[j])!=0&&(s[j]!=' '))
            {
                s2[j-i]=s[j];
            }
            else
            {
                i=j;
                break;
            }
        }
        if(s!=NULL){
        if(strcmp(s2,"auto")==0||strcmp(s2,"break")==0||strcmp(s2,"case")==0
        ||strcmp(s2,"char")==0||strcmp(s2,"const")==0||strcmp(s2,"continue")==0||strcmp(s2,"default")==0)
        T.keyW++;
        else if(strcmp(s2,"do")==0||strcmp(s2,"double")==0||strcmp(s2,"else")==0||strcmp(s2,"enum")==0
        ||strcmp(s2,"extern")==0||strcmp(s2,"float")==0||strcmp(s2,"for")==0||strcmp(s2,"goto")==0)
        T.keyW++;
        else if(strcmp(s2,"if")==0||strcmp(s2,"int")==0||strcmp(s2,"long")==0||strcmp(s2,"register")==0
        ||strcmp(s2,"return")==0||strcmp(s2,"short")==0||strcmp(s2,"signed")==0||strcmp(s2,"sizeof")==0)
        T.keyW++;
        else if(strcmp(s2,"static")==0||strcmp(s2,"struct")==0||strcmp(s2,"switch")==0||strcmp(s2,"typedef")==0
        ||strcmp(s2,"union")==0||strcmp(s2,"unsigned")==0||strcmp(s2,"void")==0||strcmp(s2,"volatile")==0||strcmp(s2,"while")==0)
        T.keyW++;
        }
    }
}
//function to count identifiers 
void identifierCount()
{
    f= fopen("code.txt ", "r");
    fseek(f,0,SEEK_END);
    int const fileSize = ftell(f);int i=0;
    char s[fileSize]; char s2[10000];
    fseek(f,0,SEEK_SET);
    while(s[i]!= EOF) //while to get all char from file
    {
        ++i;
        s[i]=getc(f);
    }
    for(int i= 0; i <strlen(s);i++)
    {
        char s2[10000]={"\0"};
        for(int j=i; j <strlen(s);j++)// for parsing string
        {
            if(isalpha(s[j])!=0&&(s[j]!=' '))
            {
                s2[j-i]=s[j];
            }
            else
            {
                i=j;
                break;
            }
        }
        //to count variable and function names
        if(strcmp(s2,"int")==0||strcmp(s2,"float")==0||strcmp(s2,"char")==0||strcmp(s2,"double")==0)
        {
            if(isalpha(s[i+1])!=0||s[i+1]=='_'||(s[i+1]='*'&&isalpha(s[i+2])!=0))
            {
                for(int j=i+1;j<strlen(s);j++)
                {
                    if(isalnum(s[j])!=0||s[j]=='_'||s[j]=='['||s[j]=='*')
                    {
                        continue;
                    }
                    else if(s[j]==',')
                    {
                        ++T.ident;
                        continue;
                    }
                    else if(s[j]==']')
                    {
                        ++T.ident;
                        if(s[j+1]==',')
                        ++j;
                        else if(s[j+1]==';')
                        {++j; break; }
                        continue;
                    }
                    else if(ispunct(s[j])!=0)
                    {
                        ++T.ident;
                        break;
                    }
                }
            }
        }
        if(strcmp(s2,"struct")==0||strcmp(s2,"union")==0)
        {
            if(isalpha(s[i+1])!=0||s[i+1]=='_')
            {
                for(int j=i+1;j<strlen(s);j++)
                {
                    if(isalnum(s[j])!=0||s[j]=='_')
                    {
                        continue;
                    }
                    else
                    {
                        T.ident++;
                        break;
                    }
                }
            }
        }
    }
}
//function to show specific token count
void specificToken(int a)
{
    if(a==1)
    printf("\nNo. of keywords in code:%d\n",T.keyW);
    else if(a==2)
    printf("\nNo. of Identifiers in code:%d\n",T.ident);
    else if(a==3)
    {
        printf("\nNo. of Operators in code:%d\n",T.oper);
        printf("\tNo. of Arithmetic operators in code   :%d\n",ops.arithmetic);
        printf("\tNo. of Relational operators in code   :%d\n",ops.relational);
        printf("\tNo. of Assignment operators in code   :%d\n",ops.assignment);
        printf("\tNo. of Logical operators in code      :%d\n",ops.logical);
        printf("\tNo. of Bitwise operators in code      :%d\n",ops.bitwise);
        printf("\tNo. of Misc operators in code         :%d\n",ops.misc);
    }
    else if(a==4)
    printf("\nNo. of Special Symbols in code:%d\n",T.sym);
    else if(a==5)
    {
        printf("\nNo. of Constants in code:%d :-\n",T.cons);
        //printf("\tNo. of Integer Constants in code  :%d\n",con.integers);
        printf("\tNo. of Numerical constants in code:%d\n",con.decimals);
        printf("\tNo. of String constants in code   :%d\n",con.strings);
        printf("\tNo. of Character constants in code:%d\n",con.chr);
    }
    else
    printf("\nInvalid choice!!\n");
}
//function to write
void write()
{
    int i=0;
    printf("\nEnter Your Code(type and enter _ to end input):\n");
    f= fopen("code.txt ","w");
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
    for(int j=0;str[j]!=95;j++)
    fprintf(f,"%c",str[j]);
    if(f!=NULL)
    printf("Code saved to code.txt  successfuly!!");
    fclose(f); 
}
//modify
void appendCode()
{
    showCode();
    int i=0;
    char s[10000]="\0";
    f= fopen("code.txt ","a+");
    fseek(f,0,SEEK_END);
    again:
    printf("\nWant to append in same line or next line[s/n]?");
    ch=getch();
    if(ch=='n')
    fprintf(f,"%s","\n");
    else if(ch!='s'&&ch!='n')
    {
        printf("\nInvalid choice!! try again");
        goto again;
    }
    printf("\nEnter Your Code(type and enter _ to end input):\n");
    if(f == NULL)
    printf("file not exist!!");
    while(1)
    {
        s[i]=getchar();
        if(s[i]==95)
        break;
        ++i;
    } 
    for(int j=0;s[j]!=95;j++)
    fprintf(f,"%c",s[j]);
    if(f!=NULL)
    printf("\nCode saved to code.txt  successfuly!!");
    fclose(f); 
}
//show code
void showCode()
{
    printf("\nThe Code that was saved last time:\n ");
    f= fopen("code.txt ", "r");
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