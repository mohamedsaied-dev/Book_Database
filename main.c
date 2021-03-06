#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>

typedef struct listnode ListNode;
typedef long long int lli;
struct listnode
{
    lli id;
    char name [40];
    float price;
    int nbook;
    ListNode *next;
};
struct temps
    {
     lli id;
     char name [40];
     float price;
     int nbook;
    }t1;
typedef struct list
{
    ListNode *head;
    int size;
}List;

bool InsertList(List *pl,lli id,char n[],float p,int x);
void IncreaseByID(List *pl,lli id,int x);
void IncreaseByName(List *pl,char name[],int x);
void decreaseByID(List *pl,lli id,int x);
void decreaseByName(List *pl,char name[],int x);
void DeleteListID(List *pl,lli id);
void RetriveList(List *pl,lli id);
void TraverseList(List *pl);
void Display(char name[],lli id,float p,int n);
void ModifyPriceID(List *pl,lli id,float y);
void ModifyPriceName(List *pl,char n[],float p);
void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestoryList(List *pl);
char gettingStarted();
void LoadData(List *pl);
void SaveData(List *pl);
FILE *f_open;

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
        lli id ;
        float price;
        char name[25];
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
            bool isSuccess = InsertList(&l,id,name,price,x);
            if (isSuccess){
                    printf("Book has been added successfully !\n");
            }
            break;
        }
    case '2':
        {
            printf("To increase by id press 1\nto increase by name press 2\n ");
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
            char q;
        printf("To delete a single book press 1\nTo destroy all database press 2: ");
        scanf("%d",&temp);
        if(temp==1)
        {
        printf("Enter the id of the book: ");
        scanf("%lld",&id);
        DeleteListID(&l,id);
        break;
        }
        else if(temp==2)
         {

            printf("Are you sure you want to destroy all database? [y/n]\n");
            fflush(stdin);
            scanf("%c",&q);
            if(q=='y'||q=='Y')
            {
                DestoryList(&l);
                SaveData(&l);

                break;
            }
            else
                break;
        }
        else
            {
                printf("Wrong answer !\n");
                break;
            }

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
            else if(temp==2)
                TraverseList(&l);
            else printf("Wrong answer !\n");
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
                scanf("%f",&pp);
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
            printf("\nData saved !\n");
            break;
        }
    case 'S':
        {
            SaveData(&l);
            printf("\nData saved !\n");
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

bool InsertList(List *pl,lli id,char n[],float p,int x)
{

    ListNode *pn= (ListNode*)malloc(sizeof( ListNode));
    pn->next=NULL;
    pn->id=id;
    pn->price=p;
    strcpy(pn->name,n);
    pn->nbook=x;
    ListNode *qn=pl->head;

    while(qn)
    {
        if(qn->id == id)
        {   printf("ID is already taken, try another ID...\n");
            return false;}
        qn=qn->next;}
        if(pl->head==NULL || pl->head->id > id)
        {
            pn->next=pl->head;
            pl->head=pn;
        }
        else
        {
            ListNode *temp=pl->head;
            while (temp->next !=NULL && temp->next->id < id)
            {
                temp=temp->next;
            }
            pn->next=temp->next;
            temp->next=pn;
        }
        pl->size++;
    return true;
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
            pl->size--;
            printf("Book deleted successfully !\n");
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
            else if(a->id==id)
            {
             b->next=a->next;
             free(a);
             pl->size--;
             printf("Book deleted successfully !\n");
             return 0;
            }
        }
        if(!a)
        {
            printf("ID not found!\n");
            return 0;
        }
        }
    }
}

void RetriveList(List *pl,lli id)
{
    ListNode *qn=pl->head;
    if(qn==NULL) printf("ID not found !\n");
    else
    {
        while(qn)
        {
            if(qn->id==id)
            {
                Display(qn->name,qn->id,qn->price,qn->nbook);
                return 0;
            }
        qn=qn->next;
        }
        if(!qn)
            printf("Book not found");
    }
    //O(N)
}

void TraverseList(List *pl)
{
    if(pl->head==NULL)
        printf("----------------------------------------\nThere's no book in your database\n----------------------------------------\n");
    else
    {
    printf("Number of Different books: %d\n\n",pl->size);
    int i=1;
    for(ListNode *ln=pl->head;ln;ln=ln->next)
    {
        printf("Book number %d:\n",i++);
        Display(ln->name,ln->id,ln->price,ln->nbook);
    }
    //O(N)
    }
}
void Display(char name[],lli id,float p,int n)
{
    printf("---------------------------------------\n");
    printf("Book name: ");
    puts(name);
    printf("\nID: %lld\nPrice: %.2f\nNumber of same book: %d\n",id,p,n);
    printf("---------------------------------------\n");
    //O(1)
}

void ModifyPriceID(List *pl,lli id,float y)
{

    ListNode *qn=pl->head;
    if(qn==NULL) printf("Empty Database !\n");
    else
    {
        while(qn)
        {
            if(qn->id==id)
            {
                qn->price=y;
                printf("Book modified\n");
                return 0;
            }
        qn=qn->next;
        }
        if(!qn)
            printf("Book not found !\n");
    }
    //O(N)
}
void ModifyPriceName(List *pl,char n[],float p)
{

    ListNode *qn=pl->head;
    if(qn==NULL) printf("Empty Database !\n");
    else
    {
        while(qn)
        {
            if(strcmp(qn->name,n)==0)
            {
                qn->price=p;
                printf("Book modified\n");
                return 0;
            }
            qn=qn->next;
        }
        if(!qn)
            printf("Book not found !\n");
    }
    //O(N)
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

void decreaseByID(List *pl,lli id,int x)
{
    ListNode *pn=pl->head;
    if(pn==NULL) printf("ID not found !\n");
    else
    {
    while(pn)
        {
          if(pn->id==id)
          break;
          pn=pn->next;
        }

    if(pn==NULL) printf("ID not found !\n");
    else
    {
        if(pn->nbook>=x)
            {
                pn->nbook-=x;
                printf("Book decreased successfully !\n");
            }
        else
            {
                printf("You don't have enough books\nYou only have %d\n",pn->nbook);
            }
    }
    }
}
void decreaseByName(List *pl,char name[],int x)
{
    ListNode *pn=pl->head;
    if(pn==NULL) printf("Name not found !\n");
    else
    {
    while(pn)
    {
        if(strcmp(pn->name,name)==0)
            break;
        pn=pn->next;
    }
    if(pn==NULL) printf("Name not found !\n");
    else
    {
        if(pn->nbook>=x)
      {
          pn->nbook-=x;
          printf("Book decreased successfully !\n");
      }
    else
        {
            printf("You don't have enough books\nYou only have %d\n",pn->nbook);
        }
    }
    }
}

void DestoryList(List *pl)
{
  ListNode *q;
    if(pl->head==NULL)
    {
        printf("Database is empty !\n");
        return 0;
    }
    else
   {
    while(pl->head)
    {
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size=0;
    printf("Data deleted successfully !\n");
   }
    //O(N)
}

void CreateList(List *pl)
{
    pl->head=NULL;
    pl->size=0;
    //O(1)
}
int ListEmpty(List *pl)
{
    return !pl->head;
    //O(1)
}
int ListFull(List *pl)
{
    return 0;
    //O(1)
}
int ListSize(List *pl)
{
    return pl->size;
    //O(1)
}

char gettingStarted()
{
    char c;
    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\tTo add new book press 1\n");
    printf("\t\t\t\tTo increase amount of old book press 2\n");
    printf("\t\t\t\tTo delete book press 3\n");
    printf("\t\t\t\tTo decrease amount of old book press 4\n");
    printf("\t\t\t\tTo print data press 5\n");
    printf("\t\t\t\tTo modify the price press 6\n");
    printf("\t\t\t\tTo exit press 7\n");
    printf("\t\t\t\tATTENTION: To save data to the file press s\n");
    printf("\t\t\t\t----------------------------------------\n");
    fflush(stdin);
    scanf("%c",&c);

    return c;
}
void LoadData(List *pl)
{
    while(fread(&t1,sizeof(t1),1,f_open))
    {
    InsertList(pl,t1.id,t1.name,t1.price,t1.nbook);
    }
    fclose(f_open);
}

void SaveData(List *pl)
{

    ListNode *pn;

    if(!(f_open=fopen("1.dat","wb")))
    {
        printf("Can't open The file\n");
        return 0;
    }
    else
    {
        for(pn=pl->head;pn;pn=pn->next)
        {
            t1.id=pn->id;
            strcpy(t1.name,pn->name);
            t1.price=pn->price;
            t1.nbook=pn->nbook;
            fwrite(&t1,sizeof(t1),1,f_open);

        }
    }
    fclose(f_open);
    return 0;
}

