#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <unistd.h>

typedef struct
{
    char dish[100];
    int price;
    int qty;
}food;

void mainmenu();
void starters();
void maincourse();
void gravy();
void dessert();
int foodOrder(food x);
void placeorder();

int main()
{
    mainmenu();
    return 0;
}
void mainmenu()
{
    int c;
    l1:system("cls");

    printf("\n\t\t FOOD MENU \t");
    printf("\n\t ------------------------------------------------------");
    printf("\n\t 1. Starters");
    printf("\n\t 2. Maincourse");
    printf("\n\t 3. Gravy");
    printf("\n\t 4. Desserts");
    printf("\n\t 5. Exit");

    printf("\n\t TO PLACE ORDER, TYPE 123..");

    printf("\n\t Enter your choice : ");
    scanf("%d",&c);
    fflush(stdin);
    if(c==1)
    {
        starters();
    }
    else if(c==2)
    {
        maincourse();
    }
    else if(c==3)
    {
        gravy();
    }
    else if(c==4)
    {
        dessert();
    }
    else if (c==123)
    {
        placeorder();
    }

    else if (c==5)
    {
        printf("\n\t\tThank you!\n\n");
        sleep(3);
        exit(0);
    }
    else
    {
        printf("\t Invalid choice!");
        goto l1;
    }
}

void existingAcc()
{
    FILE *f=fopen("userpass.txt","a");
    fclose(f);
    char user1[100],pass1[100];
    char user2[100],pass2[100];
    int flag=0;
    ll1:printf("\nEnter username : ");
    scanf("%s",user1);
    scanf("%*c");
    printf("\nEnter password : ");
    scanf("%s",pass1);
    scanf("%*c");
    FILE *fp2 = fopen("userpass.txt","r");
    if (fp2==NULL)
    {
        printf("\n\t Can't open file");
    }
    else
    {
        while(flag!=1)
        {
            fscanf(fp2,"%s %s",user2,pass2);
            if (strcmp(user2,user1)==0)
            {
                if (strcmp(pass2,pass1)==0)
                {
                    flag=1;
                    printf("\n Successful login!\n");
                }
            }

            if (feof(fp2))
            {
                flag=2;
                break;
            }
        }

        if (flag==2)
            {
                printf("\nInvalid username or password. Try again.\n");
                goto ll1;
            }
    }

}

void newAcc()
{
    FILE *f=fopen("userpass.txt","a");
    fclose(f);

    printf("\nEnter your details\n");
    char user1[100],password1[100],user2[100],pass2[100];
    char name[100],user[100],password[100];
    long long int phone;
    printf("\nEnter your name : ");
    scanf("%s",name);
    printf("\nEnter your phone number :");
    scanf("%lld",&phone);
    fflush(stdin);
    printf("\nEnter username : ");
    scanf("%s",user);
    printf("\nEnter password : ");
    scanf("%s",password);
    fflush(stdin);

    FILE *fp=fopen("userpass.txt","r");

    if (fp==NULL)
        printf("File doesnt exist yet.\n");

    else
    {
        while (fscanf(fp,"%s %s",user2,pass2)!=EOF)
        {
            if (strcmp(user2,user)==0)
            {
                printf("\nUsername already exists! Start again.\n");
                newAcc();
            }
        }
    }
    fclose(fp);

    FILE *fp1 = fopen("userpass.txt","a");

    if (!fp1)
    {
        printf("Can't open file.\n");
    }

    else
    {
        fprintf(fp1,"%s %s\n",user,password);
    }
}

void starters()
{
    printf("\n\t\t Starters \n\n");
    int strp[20]={0},chk;
    char strt[10][100],cchk[100];
    int i=0,j,strch,strqty;
    food f1;
    FILE *fp1=fopen("starters.txt","r");

    while(fscanf(fp1,"%s %d",cchk,&chk)!=EOF)
    {
        strcpy(strt[i],cchk);
        strp[i]=chk;
        i++;
    }

    for (j=0;j<10;j++)
    {
        printf("\t %2d.%20s %-4s %d\n",j+1,strt[j],"Rs",strp[j]);
    }

    printf("\t 11.\t%15s\n","Back to Main menu");
    printf("\n\tEnter your choice : ");
    scanf("%d",&strch);
    if (strch==11)
    {
        mainmenu();
    }
    else if (strch<1 || strch>11)
    {
        printf("\n\n\t Invalid choice!");
        sleep(3);
        starters();
    }
    else
    {
        strcpy(f1.dish,strt[strch-1]);
        f1.price=strp[strch-1];
        printf("\n\tEnter quantity : ");
        scanf("%d",&f1.qty);
        foodOrder(f1);
        mainmenu();
    }
    fclose(fp1);
}

void maincourse()
{
    printf("\n\t\t Maincourse \n\n");
    int maip[20]={0},chk;
    char mai[10][100],cchk[100];
    int i=0,j,maich,maiqty;
    food f2;
    FILE *fp2=fopen("maincourse.txt","r");

    while(fscanf(fp2,"%s %d",cchk,&chk)!=EOF)
    {
        strcpy(mai[i],cchk);
        maip[i]=chk;
        i++;
    }

    for (j=0;j<10;j++)
    {
        printf("\t %2d.%20s %-4s %d\n",j+1,mai[j],"Rs",maip[j]);
    }

    printf("\t 11.\t%15s\n","Back to Main menu");
    printf("\n\tEnter your choice : ");
    scanf("%d",&maich);
    if (maich==11)
    {
        mainmenu();
    }
    else if (maich<1 || maich>11)
    {
        printf("\n\n\t Invalid choice!");
        sleep(3);
        maincourse();
    }
    else
    {
        strcpy(f2.dish,mai[maich-1]);
        f2.price=maip[maich-1];
        printf("\n\tEnter quantity : ");
        scanf("%d",&f2.qty);
        foodOrder(f2);
        mainmenu();
    }
    fclose(fp2);
}

void gravy()
{
    printf("\n\t\t Gravy \n\n");
    int grap[20]={0},chk;
    char gra[6][100],cchk[100];
    int i=0,j,grach,graqty;
    food f3;
    FILE *fp3=fopen("gravy.txt","r");

    while(fscanf(fp3,"%s %d",cchk,&chk)!=EOF)
    {
        strcpy(gra[i],cchk);
        grap[i]=chk;
        i++;
    }

    for (j=0;j<6;j++)
    {
        printf("\t %d.%22s %-4s %d\n",j+1,gra[j],"Rs",grap[j]);
    }

    printf("\t 7.\t%15s\n","Back to Main menu");
    printf("\n\tEnter your choice : ");
    scanf("%d",&grach);
    if (grach==7)
    {
        mainmenu();
    }
    else if (grach<1 || grach>7)
    {
        printf("\n\n\t Invalid choice!");
        sleep(3);
        gravy();
    }
    else
    {
        strcpy(f3.dish,gra[grach-1]);
        f3.price=grap[grach-1];
        printf("\n\tEnter quantity : ");
        scanf("%d",&f3.qty);
        foodOrder(f3);
        mainmenu();
    }
    fclose(fp3);
}


void dessert()
{
    printf("\n\t\t Dessert \n\n");
    int desp[20]={0},chk;
    char des[10][100],cchk[100];
    int i=0,j,desch,desqty;
    food f4;
    FILE *fp4=fopen("dessert.txt","r");

    while(fscanf(fp4,"%s %d",cchk,&chk)!=EOF)
    {
        strcpy(des[i],cchk);
        desp[i]=chk;
        i++;
    }

    for(j=0;j<10;j++)
    {
        printf("\t %2d.%20s %-4s %d\n",j+1,des[j],"Rs",desp[j]);
    }

    printf("\t 11.\t%15s\n","Back to Main menu");
    printf("\n\tEnter your choice : ");
    scanf("%d",&desch);
    if(desch==11)
    {
        mainmenu();
    }
    else if(desch<1 || desch>11)
    {
        printf("\n\n\t Invalid choice!");
        sleep(3);
        dessert();
    }
    else
    {
        strcpy(f4.dish,des[desch-1]);
        f4.price=desp[desch-1];
        printf("\n\tEnter quantity : ");
        scanf("%d",&f4.qty);
        foodOrder(f4);
        mainmenu();
    }
    fclose(fp4);
}


int foodOrder(food x)
{
    FILE *fp5=fopen("Foodorder.txt","a");
    fprintf(fp5,"%s %d %d\n",x.dish,x.price,x.qty);
    static int total1;
    total1+=x.price*x.qty;
    fclose(fp5);
    return total1;
}

void placeorder()
{

    int c1;
    l1:printf("\n\t Sign up before you can order/login if you already have and account:  ");
    printf("\n\t 1.Sign up");
    printf("\n\t 2.Login");
    printf("\n\t Enter choice : ");
    scanf("%d",&c1);
    if(c1==1)
    {
        newAcc();
    }
    else if(c1==2)
    {
        existingAcc();
    }
    else
    {
       printf("\n\t Invalid choice!");goto l1;
    }

    FILE *fp0=fopen("Foodorder.txt","r");
    int pr[100]={0};
    int q[10]={0},i,c=0;
    char item[100][100];
    food f0;
    strcpy(f0.dish," ");
    f0.price=0;
    f0.qty=0;
    while(fscanf(fp0,"%s %d %d",item[c],&pr[c],&q[c])!=EOF)
        c++;

    printf("Your Order Details: \n");
    for (i=0;i<c;i++)
    {
        printf("%d. %20s      Rs.%3d %5d %5d\n",i+1,item[i],pr[i],q[i],pr[i]*q[i]);
    }
    sleep(3);
    printf("\n%10s Rs.%8d","Total",foodOrder(f0));

    fclose(fp0);
    FILE *fp00=fopen("Foodorder.txt","w");
    fclose(fp00);
    sleep(2);
    printf("\n\n\t\tThank you!");
    sleep(3);

    exit(0);
}
