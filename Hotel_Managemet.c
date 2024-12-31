#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create_room_list();
void display();
void book();
void avail();
void cancel();
void food();
void veg();
void breakfast();
void lunch();
void dinner();
void snacks();
void nonveg();
void nbreakfast();
struct node
{
   int room;
   struct node *next;
 	int tno;
   int status;
};
struct node *head=NULL,*tail,*temp,*p;
int main()
{
    int ch;
    char option;
     printf("*****************************************\n*\t\t\t\t\t*");
    printf("\n*-------------- HOTEL ----------------- *");
    printf("\n*\t\t\t\t\t*\n*****************************************\n");
    create_room_list();
    do
    {
      printf("\n1.Display room status\n2.Book room \n3.Available rooms\n4.Cancel room\n5.Food ordering");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
            case 1:
               display();
                break;
            case 2:
                book();
                break;
            case 3:
                avail();
                break;
            case 4:
                cancel();
                break;
           case 5:
	           	food();
	           	break;
            default:
               printf("\n Invalid choice");
      }
      printf("\n Do you want to continue [y/n]:");
      scanf(" %c",&option); 
    }while(option=='y');
}
void create_room_list()
{
    int i=1;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->room=1;
    temp->status=0;
    temp->tno=NULL;
    temp->next=NULL;
    head=temp;
    for(i=2;i<=100;i++)
    {
       p=(struct node *)malloc(sizeof(struct node));
       p->room=i;
       p->status=0;
       p->tno =NULL;
       p->next=NULL;
       temp->next=p;
       temp=temp->next;
    }
}
void display()
{
    int r=1,count=0;
    temp=head;
    printf("\n--------------------------------------------\n");
    printf(" \n  ****   TOTAL NUMBER OF ROOMS  ****  \n\n");
    printf("--------------------------------------------\n");
    while(temp!=NULL)
    {
      if((temp->room)/100==0)
      {
       printf(" %d",temp->room);
      }
      else
      {
         printf(" %d",temp->room);
      }
      if(temp->status==0)
      {
        printf("|_|");
      }
      else
      {
        printf("|B|");
      }
      count++;
      if(count%10==0)
      {
		printf("\n");
        r++;
      }
      temp=temp->next;
    }
}
void book()
{
    int x,y;
    char s;
    label:
    printf("\n Enter room number to be booked(1-100):");
    scanf("%d",&x);
    printf("\n Enter your tno[1/2/3/4/5]:");
    scanf("%d",&y);
    if(x<1||x>100)
    {
        printf(" Enter correct room number to book (1-100)\n");
        goto label;
    }
    temp=head;
    while(temp->room!=x)
    {
        temp=temp->next;
    }
    if(temp->status==1)
    {
    printf("\n Room already booked!");
    }
    else
    {
    temp->status=1;
    temp->tno=y;
    printf(" Room %d booked!\n",x);
    }
}
void cancel()
{
    int x,y;
    label1:
    printf("\n Enter your Room number to cancel booking:");
    scanf("%d",&x);
    printf("\n Enter your tno[1/2/3/4/5]:");
    scanf("%d",&y);
    if(x<1||x>100)
    {
        printf("\n Enter correct room number to cancel (1-100):");
        goto label1;
    }
    temp=head;
    while(temp->room!=x)
    {
        temp=temp->next;
    }
    if(temp->status==0)
    {
        printf(" Room not booked yet!!\n");
    }
    else
    {
      if(temp->tno==y)
      {
       temp->status=0;
       printf(" Room %d cancelled!\n",x);
       }
       else
       {
       printf(" Wrong user tno ,room cannot be cancelled\n");
       }
    }
}
void avail()
{
    int r=1,count=0;
    temp=head;
    printf("\n\n");
    printf("--------------------------------------------------\n");
    printf("                  Screen this way                  \n");
    printf("--------------------------------------------------\n");
    while(temp->next!=NULL)
    {
        if((temp->room)/100==0)
        printf("%d",temp->room);
        else
        printf("%d",temp->room);
        if(temp->status==0)
        printf("|_| ");
        else if(temp->status==1)
        printf("|B|");
        count++;
        if(count%10==0)
        {
            printf("\n");
        }
        temp=temp->next;
    }
    if(temp->status==0)
    {
    printf("%d |_| ",temp->room);
    }
}
void food()
{
	int choice;
	char ch;
	abc:
	 printf("\n [1]->Vegterian");
	 printf("\n [2]->Non-Vegterian");
	 printf("\n Enter your choice from above:");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	 	case 1:
	 		printf("\n ----------Vegterian menu------------");
	 		 veg();
	 		break;
	 	case 2:
	 		printf("\n ----------Non-Vegterian menu---------");
	 		nonveg();
	 		break;
	 	default:
	 		printf("\nEnter correct choice:");
	 }
	printf("\n Want to order your FOOD:[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		} 
}

void veg()
{
	int  vi;
	char ch;
	abc:
	printf("\n [1]--> BREAKFAST");
	printf("\n [2]--> LUNCH");
	printf("\n [3]--> DINNER");
	printf("\n [4]--> SNACKS");
	printf("\n Enter your choice from above:");
	scanf("%d",&vi); 
	switch(vi)
	{
		case 1:printf("\n ---------BREAKFAST----------");
		       breakfast();
		break;
		case 2:printf("\n--------LUNCH ITEMS-----------");
		   lunch();
		break;
		case 3:printf("\n-------- DINNER ITEMS---------");
		 dinner();
		break;
		case 4:printf("\n -------SNACKS ITEMS----------");
		 snacks();
		break;
		default:
			printf("\n Enter correct choice:");
	}
	printf("\n Want to order again from VEG MENU:[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}
	}
void breakfast()
{
	int ch;
	abc:
	printf("\n [1] IDLI.................-RS.20");
	printf("\n [2] DOSA..................RS.35");
	printf("\n [3] VADA..................RS.25");
	printf("\n [4] IDLI+VADA.............RS30");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n IDLI is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.20");
			break;
		case 2:
			printf("\n DOSA is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.35");
			break;
		case 3:
			printf("\n VADA is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.25");
			break;
		case 4:
			printf("\n IDLI+VADA is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		default:
			printf("\n Enter correct choice:");
		}
		printf("\n Want to order again from BREAKFAST MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
			


}	
void  lunch()
{
	
		int ch;
	abc:
	printf("\n [1] VEG PULAV.......................-RS.200");
	printf("\n [2] Squah sambar.......................RS.350");
	printf("\n [3] Green moong gravy..................RS.250");
	printf("\n [4] Lemon RIce...........................RS300");
	printf("\n [5] Bottle ground kootu/potato fry.......RS200");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n VEG PULAV is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.200");
			break;
		case 2:
			printf("\n Squah sambar is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.350");
			break;
		case 3:
			printf("\n Green moong gravy is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.250");
			break;
		case 4:
			printf("\n Lemon RICE is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.300");
			break;
		default:
			printf("\n Enter correct choice:");
}
printf("\n Want to order again from LUNCH MENU:[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	

}
void dinner()
{
	int ch;
	abc:
	printf("\n [1] Roti/Panner gravy.......................-RS.200");
	printf("\n [2] Idli/Sambar..............................RS.350");
	printf("\n [3] Doas/Green moong gravy...................RS.250");
	printf("\n [4] Adai/Chutney..............................RS200");
	printf("\n [5] Roti/Bottle ground dal...................RS.150");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n Roti/Panner gravy is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.200");
			break;
		case 2:
			printf("\n Idli/Sambar is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.350");
			break;
		case 3:
			printf("\n Doas/Green moong gravy is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.250");
			break;
		case 4:
			printf("\n Adai/Chutney is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.350");
			break;
		case 5:
			printf("\n Roti/Bottle ground dal is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.300");
			break;
		default:
			printf("\n Enter correct choice");
}
printf("\n Want to order again from DINNER MENU:[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}
void snacks()
{
	int ch;
	abc:
	printf("\n [1] MURUKU.........................RS.50");
	printf("\n [2] Punugulu.......................RS.30");
	printf("\n [3] Banana chips...................RS.30");
	printf("\n [4] Soya 65 ........................RS20");
	printf("\n [5] Thattai........................RS.30");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n  MURUKU is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.50");
			break;
		case 2:
			printf("\n Punugulu is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		case 3:
			printf("\n Banana chips is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		case 4:
			printf("\n Soya 65 is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.20");
			break;
		case 5:
			printf("\n Thattai is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		default:
			printf("\n Enter correct choice");
}
printf("\n Want to order again from SNACKS MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}
void nonveg()
{
	int  vi;
	char ch;
	abc:
	printf("\n [1]--> BREAKFAST");
	printf("\n [2]--> LUNCH");
	printf("\n [3]--> DINNER");
	printf("\n [4]--> SNACKS");
	printf("\n Enter your choice from above:");
	scanf("%d",&vi); 
	switch(vi)
	{
		case 1:printf("\n ---------BREAKFAST-------");
		    nbreakfast();
		break;
		case 2:printf("\n -------LUNCH ITEMS------- ");
		    nlunch();
		break;
		case 3:printf("\n ------DINNER ITEMS--------");
		   ndinner();
		break;
		case 4:printf("\n -------SNACKS ITEMS-------");
		   nsnacks();
		break;
		default:
			printf("\n Enter correct choice:");
	}
	printf("\n Want to order again from NON-VEG [y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}
}
void nbreakfast()
{
	int ch;
	abc:
	printf("\n [1] EGG DOSA..................................RS.50");
	printf("\n [2] BREAD OMELETTE............................RS.80");
	printf("\n [3] CHAPATHI/EGG KHEEMA CURRY..................RS.95");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n  EGG DOSA is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.50");
			break;
		case 2:
			printf("\n BREAD OMELETTE is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.80");
			break;
		case 3:
			printf("\n CHAPATHI/EGG KHEEMA CURRY is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.95");
			break;
	
		default:
			printf("\n Enter correct choice :");
			
}
printf("\n Want to order again from BREAKFAST MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}	
void  nlunch()
{
	
	int ch;
	abc:
	printf("\n [1] MUTTON BYRYANI.............................RS.200");
	printf("\n [2] CHICKEN DUM  BYRYANI.......................RS.150");
	printf("\n [3] EGG BYRYANI................................RS.200");
	printf("\n [4] CHICKEN FRIED RICE..........................RS120");
	printf("\n [5] FRANCE......................................RS250");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n  MUTTON BYRYANI is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.200");
			break;
		case 2:
			printf("\n  CHICKEN DUM  BYRYANI  is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.150");
			break;
		case 3:
			printf("\n   EGG BYRYANI is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.200");
			break;
		case 4:
			printf("\n CHICKEN FRIED RICE is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.120");
			break;
			case 5:
			printf("\n FRANCE  is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.250");
			break;
			
		default:
			printf("\n Enter correct choice:");
}
printf("\n Want to order again from LUNCH MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}
void ndinner()
{
	int ch;
	abc:
	printf("\n [1] Grilled CHICKEN............................RS.200");
	printf("\n [2] MUTTON KORMA...............................RS.350");
	printf("\n [3] Malabar Fish Biryani.......................RS.250");
	printf("\n [4] GONGURA MAMSAM..............................RS200");
	printf("\n [5] BUTTER CHICKEN.............................RS.150");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n Grilled CHICKEN is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.200");
			break;
		case 2:
			printf("\n MUTTON KORMA is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.350");
			break;
		case 3:
			printf("\n Malabar Fish Biryani is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.250");
			break;
		case 4:
			printf("\n GONGURA MAMSAM is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.350");
			break;
		case 5:
			printf("\n BUTTER CHICKEN is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.300");
			break;
		default:
			printf("\n Enter correct choice");
}
printf("\n Want to order again from DINNER MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}
void nsnacks()
{
	int ch;
	abc:
	printf("\n [1] Kerala-style Chicken 65.........................RS.50");
	printf("\n [2] Fried prawns.......................RS.30");
	printf("\n [3] Fried chicken...................RS.30");
	printf("\n Enter your choice from above:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n Kerala-style Chicken 65 is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.50");
			break;
		case 2:
			printf("\n Fried prawns is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		case 3:
			printf("\n Fried chicken is orderd");
			printf("\n ----BILL PAYMENT------");
			printf("\n cost:RS.30");
			break;
		
		default:
			printf("\n Enter correct choice");
}
printf("\n Want to order again from SNACKS MENU :[y/n]:");
	scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			goto abc;
		}	
}
