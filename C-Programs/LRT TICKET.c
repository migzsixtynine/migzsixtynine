#include<stdio.h>
#include<string.h>
int station(int x); 
int fare(int y); 
int stationcheckst(int stz); 
int stationchecken(int enz);

int i,t=19,stx=0,st,en,dist,amount,x,y,enz,stz,ticket,price,stchk=0,enchk=0;

char stations[][20]={"Baclaran","EDSA","Libertad","Gil Puyat","Vito Cruz","Quirino","Pedro Gil","United Nations","Central Terminal","Carriedo","Doroteo Jose","Bambang","Tayuman","Blumentritt","Abad Santos","R. Papa","5th Avenue","Monumento","Balintawak","Roosevelt"};
char temp[20];
char ans[1];

int main()
{
	while(stx==0)
	{
		puts("Northbound or Southbound? <N/S>: ");
		gets(ans);
		station(x);
	}

	while(stchk==0)
	{
		printf("\nEnter Starting Station No.<1-20>: ");
		scanf("%d", &st);
		stationcheckst(st);
	} 
	printf("%s\n",stations[st-1]);

	while(enchk==0)
	{
		printf("\nEnter Destination Station No.<1-20>: ");
		scanf("%d", &en);
		stationchecken(en);
	} 
	printf("%s\n",stations[en-1]);
	
	fare(y);
	return 0;
}

int stationcheckst(stz)
{
	if (st==0)
	{
		printf("You have entered a wrong number please try again.\n");
	}
	else if(st>=20)
	{
		printf("You have entered a wrong number please try again.\n");
	}
	else
	{
		stchk++;
	}
	return 0;
}

int stationchecken(enz)
{
	if(en<=st)
	{
		printf("You have entered a wrong number please try again.\n");
	}
	else if(en>20)
	{
		printf("You have entered a wrong number please try again.\n");
	}
	else
	{
		enchk++;
	}
	return 0;
}

int fare(y)
{
	dist = en-st;
	if(dist<=5)
	{
		amount = 15;
	}
	else if(dist<=11)
	{
		amount = 20;
	}
	else
	{
		amount = 30;
	}
	printf("You are about to travel %d stations\n",dist);
	printf("One ticket costs: Php%d\n\n",amount);
	printf("How many ticket(s)?: ");
	scanf("%d",&ticket);
	price = amount * ticket;
	printf("Total fare is: Php%d\n",price);
	return 0;
}

int station(x)
{
	if(strlen(ans)>1)
	{
		printf("You have entered a wrong answer please try again.\n");
	}	
	else if(*ans=='N' || *ans=='n')
	{
		puts("\nNorthbound Stations");
		for(i=0;i<20;i++)
		{
			printf("%d.%s\n",i+1,stations[i]);
			stx++;
		}
	}
	else if(*ans=='S' || *ans=='s')
	{
		for(i=0;i<10;i++)
		{
			strcpy(temp,stations[i]);
			strcpy(stations[i],stations[t]);
			strcpy(stations[t],temp);
			t--;
		}
		puts("\nSouthbound Stations");
		for(i=0;i<20;i++)
		{
			printf("%d.%s\n",i+1,stations[i]);
			stx++;
		}
	}
	else
	{
		printf("You have entered a wrong answer please try again.\n");
	}
	return 0;
}
