#include<stdio.h>
#include<conio.h>
#include<string.h>

#define ESC 27;
#define F1 59;
#define F2 60;

void signup(void);
void login(void);

struct
{
    char password[20];
    char username[20];
}s;

FILE *fp;

void main()
{
    int ch;
    while(1)
    {
        system("cls");
        gotoxy(20,5);
        printf("---------------Abhishek Login System----------------");
        gotoxy(28,7);
        printf("Your Welcome Here..............");
        gotoxy(28,9);
        printf("Press F1 For Login");
        gotoxy(28,11);
        printf("Press F2 For SignUp");
        gotoxy(28,13);
        printf("Press ESC For Exit");
        gotoxy(28,15);
        printf("---------------*-*-*-*-*-*-*-*-*-*-*-*--------------");
        getch();
        ch = getch();
        switch(ch)
        {
            case F1:
                system("cls");
                gotoxy(10,14);
                for(int i=0; i<10; i++)
                {
                    printf("_");
                    delay(40);
                }
                login();
            break;

            case F2:
                system("cls");
                gotoxy(10,14);
                for(int i=0; i<10; i++)
                {
                    printf("_");
                    delay(40);
                }
                signup();
            break;

            case ESC:
                exit(0);
            break;
            
        }
    }
    getch();
}

void signup(){
    char c;
    fp=fopen("record.bin","ab");
    system("cls");
    gooxy(23,5);
    printf("..............SignUp Zone..................");
    gotoxy(23,7);
    printf("Set Username    : ");
    gets(s.username);

    gotoxy(23,9);
    printf("Set Password    : ");
    for(int i=0; c=getche()!=13; i++)
    {
        s.password[i]=c;
    }
    gotoxy(23,11);
    printf("Press Enter to continue.....................");
    if(getch()==13)
    {
        fwrite(&s,sizeof(s),1,fp);
        gotoxy(23,13);
        cprintf("\nInformation Saved..................");
    }
    else
    {
        return;
    }
    fclose(fp);

    getch();
}

void login(){
    char username[20];
    char pass[20];
    char chkp;
    char chku;

    system("cls");
    gotox(23,5);
    printf("...................LogIn Zone.....................");
    gotoxy(23,7);

    fp=fopen("record.bin","rb");

    printf("Enter UserName      : ");
    getc(username);
    gotoxy(23,9);
    printf("Enter Password      : ");

    for(int i=0; c=getch()!=13; i++)
    {
        pass[i]=c;
        printf("*");
    }
    pass[i]='\o';

    while(!feof(fp))
    {
        fread(&s,sizeof(s),1,fp);

        chku = strcmp(username,s.username);
        chkp = strcmp(pass,s.password);

        if(chku==0 && chkp!=0)
        {
            printf("Invalid Password!!!!!!!!!!!!!!!!!");
            break;
        }
        else if(chku!=0 && chkp==0)
        {
            printf("\n\tInvalid Username!!!!!!!!!!!!!!");
            break;
        }
        else if(chkp==0 && chkp==0)
        {
            clrscr();
            gotoxy(10,10);
            printf("_Hello $s Welcome Here_",s.username);
            break;
        }
    }
    getch();
}