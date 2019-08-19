#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int g;
struct ad
{
int adID;

int area;
char size[5];
char desc[2000];
int cost;
char city[20];
struct ad *next;

};
struct ad* temp;
struct ad* head=NULL;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void load_main()
 {
   system("cls");
   printf("WAIT......");
     for(int i=1;i<=50;i++)
      {    system("cls");
  printf("\n\n\n\n\t\t\t\t  WELCOME TO AGENCY\n\t\t\t\t");
  printf("\n\n\n\n\t\t\t\t  LOADING\n\t\t\t\t");
 for(int j=1;j<=i;j++)
  printf("²");
  printf("\n\n\t%d/-",2*i);
  printf("%");
 if( i > 1 && i < 20)
  printf("\n\n\tCreating Temporary files....PLS WAIT......IT MAY TAKE A WHILE");
 else if( i > 20 && i<40)
  printf("\n\n\tAccessing Main Memory");
 else if(i >40 && i<48)
  printf("\n\n\tAccessing Cache");
 else printf("\n\n\tComplete. ");
  delay(150 - i*3);
      }

 }





int main()
{
    load_main();

    main_display();
}
void main_display()
{
    system("cls");
    int ch;

    printf("******************************************************\n");
    printf("                                                                  WELCOME\n");
    printf("********************************************************\n");
    printf("\n");
        printf("\n");
            printf("\n");
                printf("\n");
                    printf("\n");
                        printf("\n");
    printf("*********************************************************\n");
    printf("1:SELLER\t2:BUYER\t\t3:ADMIN\t\t4:ABOUT US\t\t5:EXIT\n");
    printf("*********************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("ENTER YOUR CHOICE(1-5)\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        seller();
        break;

    case 5:
        exit(1);

    default:
        printf("invalid choice");
        break;
    }

}
void seller()
{
    int ch;

    system("cls");
    printf("******************************************************\n");
    printf("                                                                  WELCOME TO AGENCY\n");
    printf("********************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("*********************************************************\n");
    printf("1:  POST AD\t2:REMOVE AD\t\t3:MAIN MENU\n");
    printf("*********************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("ENTER YOUR CHOICE(1-3)\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        post_ad();
        break;
    case 2:
        display_remove(head);
        break;


    case 3:
        main_display();
        break;


    }
}



struct ad* create_ad()
{
int adID;

int area;
int cost;
char size[5];
char desc[2000];
char city[20];
printf("\n");
printf("enter adID");
printf("\n");
scanf("%d",&adID);

printf("Enter area of house");
printf("\n");
scanf("%d",&area);

printf("Enter size of house\n");

scanf("%s",size);
printf("Enter cost in rupees\n");
scanf("%d",&cost);
printf("Enter city\n");
scanf("%s",city);
printf("Write a lucrative paragraph about the perks of living in the house on sale");
printf("\n");
scanf("%s",desc);

struct ad *m;
m=(struct ad*)malloc(sizeof(struct ad));
m->adID=adID;
m->next=NULL;
m->area=area;
m->cost=cost;
strcpy(m->size,size);
strcpy(m->city,city);
strcpy(m->desc,desc);



return(m);
}
struct ad* createlinkedlist(struct ad *head){

    int i;
    int n;




    printf("Enter no. of new ADS to be posted");
    printf("\n");
    scanf("%d",&n);

    if(head==NULL)
        {
            head=create_ad();
            i=1;
            temp=head;
            while(i<n)
                  {
            temp->next=create_ad();
            temp=temp->next;
            i++;
                  }

        return(head);
        }
        else
        {   i=0;
            while(i<n)
                  {
            temp->next=create_ad();
            temp=temp->next;
            i++;
                  }
            return(head);
        }
}

void display_ll(head)
{
    int z;
	struct ad *temp1;
	temp1=head;
	while(temp1->next!=NULL)
	{   printf("\n");
		printf("AdID:%d",temp1->adID);
        printf("\n");
        printf("Type:%s",temp1->size);
        printf("\n");
		printf("Area:%d sq.ft",temp1->area);
		printf("\n");
		printf("City:%s",temp1->city);
		printf("\n");
		printf("Cost:Rs.%d",temp1->cost);
		printf("\n");
        printf("Description:%s",temp1->desc);
        printf("\n");
		temp1=temp1->next;

		printf("");



	}
        printf("\n");
        printf("AdID:%d",temp1->adID);
        printf("\n");
        printf("Type:%s",temp1->size);
        printf("\n");
		printf("Area:%d sq.ft",temp1->area);
		printf("\n");
		printf("City:%s",temp1->city);
		printf("\n");
		printf("Cost:Rs.%d",temp1->cost);
		printf("\n");
		printf("Description:%s",temp1->desc);
		printf("\n");








		printf("\n1:main menu\t\t\t2:exit");
		scanf("%d",&z);
		switch(z)
		{
        case 1:
            post_ad();
            break;
        case 2:
            seller();
            break;
		}
}



int count(struct ad* head)
{
    struct ad* temp1;
    temp1=head;
    int c=0;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
        c++;
    }
    return(c+1);
}
void post_ad()
{

    int ch;
    do
	{
	        system("cls");
	    printf("******************************************************\n");
    printf("                                                                 ADVERTISEMENT MANAGEMENT WIZARD\n");
    printf("********************************************************\n");
		printf("SELECT OPERATION\n1.POST AD?\n2.VIEW ADS IN DATABASE\n3.BACK TO PREVIOUS PAGE?\n4.MAIN MENU?\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
        case 1:  system("cls");
        printf("******************************************************\n");
    printf("                                                                 POST YOUR ADVERTISEMENT\n");
    printf("********************************************************\n");

            head=createlinkedlist(head);
        break;
        case 2:
            display_ll(head);
            break;


        case 3:
            seller();
            break;
        case 4:
            main_display();
            break;
        default:
            main_display();

	}

}while(ch!=3);
}
void display_remove(head)
{
    int z;
    struct ad *temp1;
	temp1=head;
    system("cls");
    printf("******************************************************\n");
    printf("                                                                 ADVERTISEMENT DATABASE\n");
    printf("********************************************************\n");
    printf("\n\nAD_ID\t\tCITY\t\tCOST\t\tSIZE\n");
    while(temp1->next!=NULL)
    {
    printf("\n%d\t\t%s\t\t%d\t\t%s\n",temp1->adID,temp1->city,temp1->cost,temp1->size);
    temp1=temp1->next;
}
printf("\n%d\t\t%s\t\t%d\t\t%s\n",temp1->adID,temp1->city,temp1->cost,temp1->size);
printf("\n\nENTER THE AD ID TO BE DELETED FROM DATABASE");
scanf("%d",&g);

delete_ad(g);
main_display();


}

void delete_ad(g)
{
    int z;
    z=g;

    struct ad* tempdel =head;
    struct ad*   prev;

    if (tempdel != NULL && tempdel->adID == z)
    {
        head = tempdel->next;
        free(tempdel);
        return;
    }


    while (tempdel != NULL && tempdel->adID != z)
    {
        prev = tempdel;
        tempdel = tempdel->next;
    }


    if (tempdel == NULL) return;

    prev->next = tempdel->next;

    free(tempdel);



    if (tempdel == NULL) return;

    prev->next = tempdel->next;

    free(tempdel);
}