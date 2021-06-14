#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct listnode ListNode;
typedef long long int lli;
struct listnode
{
    lli id;
    char name [25];
    float price;
    int nbook;
    ListNode *next;
};
struct temps
    {
     lli id;
     char name [25];
     float price;
     int nbook;
    }t1;
typedef struct list
{
    ListNode *head;
    int size;
}List;

void InsertList(List *pl,lli id,char n[],float p,int x);
void IncreaseByID(List *pl,lli id,int x);
void IncreaseByName(List *pl,char name[],int x);
void IncreaseByID(List *pl,lli id,int x);
void IncreaseByName(List *pl,char name[],int x);
void DeleteListID(List *pl,lli id);

int main()
{
    char sw;

    List l;
    CreateList(&l);
    printf("\t\t\t\tWelcome to your book database\n");
    system("pause");
    sw=gettingStarted();
    if(f_open=fopen("1.dat","rb"))
            LoadData(&l);
    while (1<2)
    {
        lli id ,*Pid;
        float price,*Pprice;
        char name[25],rname[25];
        int temp,amount,*nbooks,x;


    switch (sw)
    {
    case '1':
        {
            printf("Enter the name of the book: ");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            printf("Enter the id of the book: ");
            scanf("%lld",&id);
            printf("Enter the Price of the book: ");
            scanf("%f",&price);
            printf("Enter number of books: ");
            scanf("%d",&x);
            InsertList(&l,id,name,price,x);
            printf("Book has been added successfully !\n");
            break;
        }
    case '2':
        {
            printf("To increase by id press 1\n\tto increase by name press 2\n ");
            scanf("%d",&temp);
            if(temp==1)
            {
                lli idd;
                printf("Please enter the id of the book: ");
                scanf("%lld",&idd);
                printf("Enter the amount of books to be increased: ");
                scanf("%d",&amount);
                IncreaseByID(&l,idd,amount);
            }
            else if(temp==2)
            {

                printf("Please enter the name of the book: ");
                fflush(stdin);
                gets(name);
                fflush(stdin);
                printf("Enter the amount of books to be increased: ");
                scanf("%d",&amount);
                fflush(stdin);
                IncreaseByName(&l,name,amount);
            }
            else
                printf("Wrong answer\n");
            break;
        }
    case '3':
        {
        printf("Enter the id of the book: ");
        scanf("%lld",&id);
        DeleteListID(&l,id);
        printf("Book Deleted successfully !\n");
        break;
        }
    case '4':
        {

            printf("To decrease by id press 1 \nTo decrease by name press 2 \n");
            scanf("%d",&temp);

            if(temp==1)
            {
                printf("Enter the id: ");
                scanf("%lld",&id);
                printf("Enter the amount to be decreased: ");
                scanf("%lld",&amount);
                decreaseByID(&l,id,amount);


            }
            else if(temp==2)
            {
                printf("Enter the name: ");
                fflush(stdin);
                gets(name);
                fflush(stdin);
                printf("Enter the amount to be decreased: ");
                scanf("%lld",&amount);
                decreaseByName(&l,name,amount);

            }
            else
                printf("Wrong answer\n");
            break;
        }
    case '5':
        {
            printf("To print single book press 1\nTo print all books press 2\n");
            scanf("%d",&temp);
            if(temp==1)
            {
                printf("Enter the id of the book: ");
                scanf("%lld",&id);
                RetriveList(&l,id);
            }
            else
                TraverseList(&l,Display);
            break;
        }

    case '6':
        {
            printf("To modify by id press 1\nTo modify by name press 2\n");
            scanf("%d",&temp);
            if(temp==1)
            {
                float pp;
                printf("Enter the id of the book: ");
                scanf("%lld",&id);
                printf("Enter the new price: ");
                scanf("%f",&pp);printf("%f",pp);
                ModifyPriceID(&l,id,pp);
            }
            else if(temp==2)
            {
                float pp;
                printf("Enter the name of the book: ");
                fflush(stdin);
                gets(name);
                fflush(stdin);
                printf("Enter the new price: ");
                scanf("%f",&pp);
                ModifyPriceName(&l,name,pp);
            }
            else
                printf("Wrong answer !\n");
            break;


        }
    case '7':
        {

            printf("\t\t\t\t\t\tGoodBye<3\n\n\n");

            exit(1);
        }

    case 's':
        {
            SaveData(&l);
            break;
        }
    default:
        {
            printf("Wrong answer\n");
        }
        }
        system("pause");
        system("cls");
       sw= gettingStarted();
    }

}

void InsertList(List *pl,lli id,char n[],float p,int x)
{
    ListNode *pn= (ListNode*)malloc(sizeof( ListNode));

    pn->id=id;
    pn->price=p;
    strcpy(pn->name,n);
    pn->nbook=x;

    if(pl->head==NULL)
    {
        pn->next=pl->head;
        pl->head=pn;
    }
    else
    {
        ListNode *a=pl, *b=pl->head;
        if(pn->id<b->id)
        {
            pn->next=pl->head;
            pl->head=pn;
        }
        else if(pn->id>b->id&&b->next==NULL)
        {
            pn->next=NULL;
            pl->head->next=pn;
        }
        else
        {
            a=pl->head;
            b=pl->head->next;
            while(pn->id>b->id&&b->next!=NULL)
                b=b->next;
            pn->next=b->next;
            b->next=pn;
        }
    }

     pl->size++;
    //O(N)
}

void DeleteListID(List *pl,lli id)
{
    ListNode *a,*b;
    a=pl->head;
    if(!a)
    {   printf("List empty !\n");
        return 0;
    }
    else
        {
        if(a->id==id)
        {
            pl->head=a->next;
            free(a);
            fflush(stdout);
            pl->size--;
            printf("Book deleted!\n");

            return 0;
        }
        else
        {
        a=a->next;
        b=pl->head;
        while(a)
        {
            if(a->id!=id)
            {
                a=a->next;
                b=b->next;
            }
            else if(a->id!=id)
                break;
        }


        if(!a)
        {
            printf("ID not found!\n");
            return 0;
        }
        else if(a->id==id)
        {
            b->next=a->next;
             free(a);
              pl->size--;
        }
        }
    }
    SaveData(pl);
    LoadData(pl);

}

void IncreaseByID(List *pl,lli id,int x)
{
    ListNode *pn=pl->head;
    if(!pn) printf("Empty database !\n");
    else
    {
    while(pn)
        {
            if(pn->id==id)
            {
                pn->nbook+=x;
                printf("Book increased successfully !\n");
                return 0;
            }
            pn=pn->next;
        }
    }
     if(!pn)
        printf("ID not found !\n");
}
void IncreaseByName(List *pl,char name[],int x)
{
    ListNode *pn=pl->head;
    if(pn==NULL) printf("Empty Database !\n");
    else
    {
    while(pn)
           {
            if(strcmp(pn->name,name)==0)
            {
                pn->nbook+=x;
                printf("Book increased successfully !\n");
                return 0;
            }
            pn=pn->next;
            }
     if(!pn)
        printf("Name not found !\n");

    }
}
