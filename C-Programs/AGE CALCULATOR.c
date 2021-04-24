#include<stdio.h>
#include<string.h>

int datecheck (int month,int day,int year);
int datecompare (int x);
int tryagain (int y);

int month1,day1,year1,month2,day2,year2,monthDIFF,dayDIFF,yearDIFF,x,y,month,day,year,valid=0,leapyr=0,ctr=0;
char ans[1]="Y";
char months[13][20]={"","January","February","March","April","May","June","July","August","September","October","November","December"};

int main()
{
	while(*ans=='Y'||*ans=='y')
	{
		while(valid==0)
		{
			printf("Input your birthday (mm/dd/yy)\n");
			scanf("%d %d %d",&month1,&day1,&year1);
			datecheck(month1,day1,year1);
		}
		valid=0;
		while(valid==0)
		{
			printf("\nInput someone's birthday (mm/dd/yy)\n");
			scanf("%d %d %d",&month2,&day2,&year2);	
			datecheck(month2,day2,year2);
		}
		valid=0;	
	
		datecompare(x);
		
		while(ctr==0)
		{
			tryagain(y);
		}
		ctr=0;
	}
	return 0;

}

int datecheck(int month,int day,int year)
{
	if (year>0 && year<=2021)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			leapyr=1;
		}
		
		if (month>=1 && month<=12)
		{
			if(month==2)
			{
				if(leapyr!=1 && day>28)
				{
					printf("%s %d is not a leap year, please try again\n",months[month],year);
				}
				else if(leapyr==1 && day>29)
				{
					printf("%s %d is a leap year but up to 29 only, please try again\n",months[month],year);
				}
				else
				{
					valid=1;
				}
			}
			else if(month==4 || month==6 || month==9|| month==11)
			{
				if(day>30)
				{
					printf("%s is up to 30 only, please try again\n",months[month]);
				}
				else
				{
					valid=1;
				}
			}
			else
			{
				if(day>31)
				{
					printf("%s is up to 31 only, please try again\n",months[month]);				
				}
				else
				{
					valid=1;				
				}
			}
		}
		else
		{
			printf("Date invalid try again\n");	
		}
	}
	else
	{
		printf("Date invalid try again\n");
	}
	leapyr=0;
	return 0;
}

int datecompare (int x)
{
	if (year1==year2)
	{
		if (month1>=month2)
		{
			if(day1>=day2)
			{
				dayDIFF = day1-day2;
			}
			else
			{
				if(month1==3)
				{
					if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) 
            	{
               		day1 += 29;
            	}
            	else
            	{	
                	day1 += 28;
				}
			}
				else if (month1==5||month1==7||month1==10||month1==12)
				{
					day1+=30;
				}
				else
				{
					day1+=31;
				}
			month1-=1;
			dayDIFF = day1-day2;
			}
			monthDIFF = month1 - month2;
		}
		else
		{
			if(day2>=day1)
			{
				dayDIFF = day2-day1;
			}
			else
			{
				if(month2==3)
				{
					if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            		{
               			day2 += 29;
            		}
            		else
            		{	
                		day2 += 28;
					}
				}
				else if (month2==5||month2==7||month2==10||month2==12)
				{
					day2+=30;
				}
				else
				{
					day2+=31;
				}
			month2-=1;	
			dayDIFF = day2-day1;			
			}
			monthDIFF = month1 - month2;
		}
		
		
		yearDIFF = 0;
		
		if (month1+day1>month2+day2)
		{
			printf("You are older by\n");
			printf("%d Day(s) %d Month(s) %d Year(s)\n\n",dayDIFF,monthDIFF,yearDIFF);
		}
		else if (month1+day1<month2+day2)
		{
			printf("You are younger by\n");
			printf("%d Day(s) %d Month(s) %d Year(s)\n\n",dayDIFF,monthDIFF,yearDIFF);
		}
		else
		{
			printf("Same age no difference\n");
		}
	}
	else if(year1>year2)
	{
		if (month1>=month2)
		{
			if(day1>=day2)
			{
				dayDIFF = day1-day2;
			}
			else
			{
				if(month1==3)
				{
					if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) 
            		{
               			day1 += 29;
            		}
            		else
            		{	
                		day1 += 28;
					}
				}
				else if (month1==5||month1==7||month1==10||month1==12)
				{
					day1+=30;
				}
				else
				{
					day1+=31;
				}
			month1-=1;
			dayDIFF = day1-day2;
			}
			monthDIFF = month1 - month2;
		}
		else /*if month2 > month1*/
		{
			if(day1>=day2)
			{
				dayDIFF = day1-day2;
			}
			else /*if day1 > day2*/
			{
				if(month1==3)
				{
					if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) 
            		{
               			day1 += 29;
            		}
            		else
            		{	
                		day1 += 28;
					}
				}
				else if (month2==5||month2==7||month2==10||month2==12)
				{
					day1+=30;
				}
				else
				{
					day1+=31;
				}
			month1-=1;	
			dayDIFF = day1-day2;			
			}
			month1+=12;
			monthDIFF = month1 - month2;
			year1-=1;
		}
		
		yearDIFF = year1 - year2;
		printf("You are younger by\n");
		printf("%d Day(s) %d Month(s) %d Year(s)\n\n",dayDIFF,monthDIFF,yearDIFF);
	}
	else /*if year2>year1*/
	{
		if (month2>=month1)
		{
			if(day2>=day1)
			{
				dayDIFF = day2-day1;
			}
			else
			{
				if(month2==3)
					{
						if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            			{
               				day2 += 29;
            			}
            			else
            			{	
                			day2 += 28;
						}
					}
				else if (month2==5||month2==7||month2==10||month2==12)
				{
					day2+=30;
				}
				else
				{
					day2+=31;
				}
			month2-=1;
			dayDIFF = day2-day1;
			}
			monthDIFF = month2 - month1;
		}
		else /*if month1>month2*/
		{
			if(day2>=day1)
			{
				dayDIFF = day2-day1;
			}
			else /*if day1>day2*/
			{
				if(month2==3)
				{
					if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            		{
               			day2 += 29;
            		}
            		else
            		{	
                		day2 += 28;
					}
				}
				else if (month2==5||month2==7||month2==10||month2==12)
				{
					day2+=30;
				}
				else
				{
					day2+=31;
				}
			month2-=1;	
			dayDIFF = day2-day1;			
			}
			month2+=12;
			monthDIFF = month2 - month1;
			year2-=1;
		}

		yearDIFF = year2 - year1;
		printf("You are older by\n");
		printf("%d Day(s) %d Month(s) %d Year(s)\n\n",dayDIFF,monthDIFF,yearDIFF);
	}
	
	return 0;
}

int tryagain(int y)
{
	puts("Do you want to try again? (Y/N)");
	fflush(stdin);
    	gets(&ans);
	
	if(strlen(ans)>1)
	{
		puts("Invalid answer please try again");
	}
	else if(*ans=='N'||*ans=='n'||*ans=='Y'||*ans=='y')
	{
		ctr=1;	
	}
	else
	{
		puts("Invalid answer please try again");
	}
}
