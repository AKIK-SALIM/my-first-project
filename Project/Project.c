#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *optr;
FILE *cptr;
FILE *cinfofptr;
char roomNumber[10];
int bill=0,quantity,flag=0;
typedef struct customer{
    char name[50];
    char password[50];

} CUSTOMER ;

CUSTOMER c;


typedef struct owner{
    char name[30];
    char password[30];
}OWNER;
OWNER o;

void creatAccount();

void login();

void byFood();

void breakfast();

void snacks();

void lunch();

void viewAllOrders();

int main()
{

    int choice;

        printf("Press 1 for Create Account\n");
        printf("Press 2 for login\n");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                creatAccount();
                break;
            case 2:
                login();
                break;
            default:
                printf("Wrong input");
        }

    return 0;
}



void creatAccount()
{
    int choice;
    char name[50],pass[50];

    printf("If you are Owner then press 1 for create account.\n");
    printf("If you are customer then press 2 for create account.\n");
    scanf("%d",&choice);
    getchar();

    if(choice==1)
    {
        optr=fopen("owner.txt","a");
        if(optr==NULL){
            printf("Database corrupted. Please do something :'( ");
            exit(1);
        } else{
            printf("Enter your name:\n");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';
            strcpy(o.name,name);


            printf("Enter your password:\n");
            fgets(pass,sizeof(pass),stdin);
            pass[strcspn(pass,"\n")]='\0';

            strcpy(o.password,pass);

            fwrite(&o, sizeof(o),1,optr);
            fclose(optr);

            printf("Your account create successful.\n");
            login();

        }


    }
    else if(choice==2)
    {

        cptr=fopen("customer.txt","a");
        if(cptr==NULL){
            printf("Database corrupted. Please do something :'( \n");
            exit(1);
        } else{
            printf("Enter your name:\n");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';
            strcpy(c.name,name);

            printf("Enter your password:\n");
            fgets(pass,sizeof(pass),stdin);
            pass[strcspn(pass,"\n")]='\0';
            strcpy(c.password,pass);

            fwrite(&c, sizeof(c),1,cptr);
            fclose(cptr);

            printf("Your account create successful.\n");

            login();
        }

    }


}

void login()
{
    int ch,flag=0;
    char name[50],pass[50];
    printf("Log in as Customer press 1.\nLog in as Owner press 2.\n");
    scanf("%d",&ch);
    getchar();
    if(ch==1)
    {
        cptr=fopen("customer.txt","r");
        if(cptr==NULL){
            printf("Database corrupted. Please do something :'(\n");
            exit(1);
        } else{

            printf("Enter your user Name:\n");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';

            printf("Enter your password:\n");
            fgets(pass,sizeof(pass),stdin);
            pass[strcspn(pass,"\n")]='\0';


            while (fread(&c, sizeof(c),1,cptr)>0){
                if(strcmp(c.name,name)==0 && strcmp(c.password,pass)==0){
                    //cinfofptr= fopen("CustomerInfo.txt","a");
                    //fputs(name,cinfofptr);
                    //fprintf(cinfofptr,"\n");
                    //fputs(pass,cinfofptr);
                    printf("Log in Successful.Happy shopping\n");
                   // fclose(cinfofptr);
                    flag=1;
                    break;
                }
            }
            fclose(cptr);
            if(flag==0){
                printf("Wrong password or UserName\n");
            }if(flag==1){
                byFood();
            }
        }

    }
     if(ch==2)
    {
        optr=fopen("owner.txt","r");
        if(optr==NULL){
            printf("Database corrupted.Please do something :'(\n");
            exit(1);
        } else{


            printf("Enter your user Name:\n");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';

            printf("Enter your password:\n");
            fgets(pass,sizeof(pass),stdin);
            pass[strcspn(pass,"\n")]='\0';

            while (fread(&o, sizeof(o),1,optr)>0){
                if(strcmp(o.name,name)==0 && strcmp(o.password,pass)==0){
                    printf("Log in Successful.\n");
                    flag=1;
                    break;
                }
            }
            fclose(optr);
            if(flag==0){
                printf("Wrong password or UserName\n");
            }
            if(flag==1){
                printf("View order");
                viewAllOrders();
            }
        }

    }


}
void byFood()
{


    int choice;
    ab:
    printf("\n\t\t*****Welcome to XYZ Canteen*****\n");
    printf("Press 1 for break fast Item.\n");
    printf("Press 2 for Lunch Item.\n");
    printf("Press 3 for snacks.\n");
    printf("Press 11 for see Menu.\n");


    scanf("%d",&choice);
     getchar();
    switch(choice)
    {
        case 1:
            breakfast();
            break;
        case 2:
            lunch();
            break;
        case 3:
            snacks();
            break;

        case 11:
            printf("For Break Fast.\n\t\t1.Paratha(15)\n\t\t2.Bhaji(25)\n\t\t3.Dal(20)\n");
            printf("For Lunch Item.\n\t\t1.Khicur And Dim(55)\n\t\t2.Khicuri And Murgi(65)\n\t\t3.Morog Polau(120)\n\t\t4.Setmenu(150)\n");
            printf("For Snacks Item.\n\t\t1.Vegetable Rol(25)\n\t\t2.Chicken Rol(35)\n\t\t3.Shawarma(55)\n\t\t4.Burger(55)\n\t\t5.Pasta(50)\n\t\t6.Sandwich(50)\n");

            goto ab;

        default:
            printf("Wrong input!!!!!!");

    }



}

void breakfast()
{

    int Paratha =15,bhaji=25,dal=20,choice;
    printf("\n\t\tWe are providing\n");
    printf("\n\t\t1.Paratha(15)\n\t\t2.Bhaji(25)\n\t\t3.Dal(20)\n");
    printf("\t\tPress 1 for Paratha and Dal\n\t\tPress 2 for Paratha and Bhaji\n");
    //cinfofptr= fopen("CustomerInfo.txt","a");

    scanf("%d",&choice);
    getchar();
    if(choice==1){
        printf("How many paratha?\n");
        scanf("%d",&quantity);
        getchar();
        bill=Paratha*quantity;
        printf("How many Dal?\n");
        scanf("%d",&quantity);
        getchar();
        bill=bill+(dal*quantity);
    } else if(choice==2){
        printf("How many paratha?\n");
        scanf("%d",&quantity);
        getchar();
        bill=Paratha*quantity;
        printf("How many Bhaji?\n");
        scanf("%d",&quantity);
        getchar();
        bill=bill+(bhaji*quantity);
    }
    printf("\n\tEnter your room number with desk.\n");
    fgets(roomNumber,sizeof(roomNumber),stdin);
    roomNumber[strcspn(roomNumber,"\n")]='\0';

    printf("You want to buy something else? press y \n");
    char ch;
    scanf("%c",&ch);
    getchar();
    if(ch=='y'){
        a:
        printf("\t\tSnacks or Lunch?   press 's' for snacks and press 'l' for lunch");
        flag=1;
        char ch;
        scanf("%c",&ch);
        getchar();
        if(ch=='s'){
            snacks();
        } else if(ch=='l'){
            lunch();
        } else{
            printf("\t\t\tInvalid input\n");
            goto a;
        }
    } else{

        printf("\t\t\tThanks for your order.You have to pay %d Tk. Our delivery man reach you soon at ",bill);
        puts(roomNumber);
        printf("\n\n\n");
    }



}

void snacks()
{
    int vegetablerol=25,chickenrol=35,Shawarma=55,burger=55,pasta=50,sandwich=50;

    q:
    printf("\n\t\tWe are providing.\n");
    printf("\t\tPress 1 for vegetable rol(25)\n\t\tPress 2 for Chicken rol(35)\n\t\tPress 3 for Shawarma(55)\n\t\tPress 4 for Burger(55)\n\t\tPress 5 for Pasta(50)\n\t\tPress 6 for Sandwich(50)\n");
    int cc;
    scanf("%d",&cc);
    getchar();
    if(cc==1){
        printf("Enter the Quantity of vegetable rol\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(vegetablerol*quantity);
    } else if(cc==2){
        printf("Enter the Quantity of Chicken rol\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(chickenrol*quantity);
    } else if(cc==3){
        printf("Enter the Quantity of Shawarma\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(Shawarma*quantity);
    } else if(cc==4){
        printf("Enter the Quantity of Burger\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(burger*quantity);
    } else if(cc==5){
        printf("Enter the Quantity of Pasta\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(pasta*quantity);
    } else if(cc==6){
        printf("Enter the Quantity of Sandwich\n");
        scanf("%d",&quantity);
        getchar();
        bill+=(sandwich*quantity);
    } else{
        printf("!!!!!!!!!! Invalid input!!!!!!!!!!\n");
        goto q;
    }
    if(flag==0){
        printf("\n\tEnter your room number with desk.\n");
        fgets(roomNumber,sizeof(roomNumber),stdin);
        roomNumber[strcspn(roomNumber,"\n")]='\0';

    }

    printf("\n\n\t\t\tThanks for your order.You have to pay %d Tk. Our delivery man reach you soon at ",bill);
    puts(roomNumber);
    printf("\n\n\n");

}

void lunch()
{
    int khicurAndDim=55,khicuriAndMurgi=65,morogPolau=120,setmenu=150,Choicee;

    M:
    printf("\n\t\tWe are providing.\n");
    printf("\n\t\tPress 1 for Khicur And Dim(55)\n\t\tPress 2 for Khicuri And Murgi(65)\n\t\tPress 3 for Morog Polau(120)\n\t\tPress 4 for Setmenu(150)\n");
    scanf("%d",&Choicee);
    getchar();
    if(Choicee==1){
        printf("Enter the Quantity\n");
        scanf("%d",&quantity);
        getchar();
        bill=khicurAndDim*quantity;

    } else if(Choicee==2){
        printf("Enter the Quantity\n");
        scanf("%d",&quantity);
        getchar();
        bill=khicuriAndMurgi*quantity;

    } else if(Choicee==3){
        printf("Enter the Quantity\n");
        scanf("%d",&quantity);
        getchar();
        bill=morogPolau*quantity;

    } else if(Choicee==4){
        printf("Enter the Quantity\n");
        scanf("%d",&quantity);
        getchar();
        bill=setmenu*quantity;

    } else {
        goto M;
    }
    if(flag==0){
        printf("\n\tEnter your room number with desk.\n");
        fgets(roomNumber,sizeof(roomNumber),stdin);
        roomNumber[strcspn(roomNumber,"\n")]='\0';

    }

    printf("\n\n\t\t\tThanks for your order.You have to pay %d Tk. Our delivery man reach you soon at ",bill);
    puts(roomNumber);
    printf("\n\n\n");

}


void viewAllOrders(){


    printf("We need to work togather");


}
