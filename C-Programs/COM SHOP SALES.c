#include<stdio.h>
#include<string.h>

int service (int x);
int servicecheck (int y);

int DP,IP,CR,SCAN,TYPE,DPans=0,DPtotal=0,DPanstotal,IPans=0,IPanstotal=0,IPtotal=0,CRans=0,CRanstotal,CRtotal=0,SCANans=0,SCANanstotal,SCANtotal=0,TYPEans=0,TYPEanstotal,TYPEtotal=0,x,y,SERVICEchoice=0,total=0,ctr1=0,ctr2=0,ctr3=0;
char SERVICEans[1]="y";

int main()
{
	while (ctr1==0)
	{
		puts("ABC COMPUTER SHOP RATES");
		puts("1. Document Printing\t2.00 per page");
		puts("2. Image Printing\t10.00 per page");
		puts("3. Computer Rental\t15.00 per hour");		
		puts("4. Scanning\t\t10.00 per scan");
		puts("5. Typing\t\t15.00 per page");
		while (ctr2==0)
		{
			printf("\nEnter type of service you want: ");
			scanf("%d",&SERVICEchoice);
			service (x);
			fflush(stdin);
		}
		while (ctr3==0)
		{
			servicecheck (y);
		}
		ctr2=0;
		ctr3=0;
	}
	
	printf("ABC COMPUTER SHOP DAILY SALES REPORT");
	printf("\nTYPE OF SERVICES\tQUANTITY\tAMOUNT");
	printf("\nDocument Printing\t%d\t\t%.2f",DPans,(float)DPans*2);
	printf("\nImage Printing\t\t%d\t\t%.2f",IPans,(float)IPans*10);
	printf("\nComputer Rental\t\t%d\t\t%.2f",CRans,(float)CRans*15);
	printf("\nScanning\t\t%d\t\t%.2f",SCANans,(float)SCANans*10);
	printf("\nTyping\t\t\t%d\t\t%.2f",TYPEans,(float)TYPEans*15);	
	total = (DPans*2+IPans*10+CRans*15+SCANans*10+TYPEans*15);
	printf("\n\t\t\tTotal Sales:\t%.2f",(float)total);	
	
	return 0;

}

int service (x)
{
	switch(SERVICEchoice)
	{
		case 1:
				printf("How many pages? ");
				scanf("%d",&DP);
				DPans+=DP;
				DPtotal = DP*2;
				printf("\nTotal amount to be paid: Php%.2f", (float)DPtotal);
				ctr2++;
				break;	
		case 2:
				printf("How many pages? ");
				scanf("%d",&IP);
				IPans+=IP;
				IPtotal =IP*10;
				printf("\nTotal amount to be paid: Php%.2f", (float)IPtotal);
				ctr2++;
				break;				
		case 3:
				printf("How many hours? ");
				scanf("%d",&CR);
				CRans+=CR;
				CRtotal = CR*15;
				printf("\nTotal amount to be paid: Php%.2f", (float)CRtotal);
				ctr2++;			
				break;				
			
		case 4:
				printf("How many scans? ");
				scanf("%d",&SCAN);
				SCANans+=SCAN;
				SCANtotal = SCAN*10;
				printf("\nTotal amount to be paid: Php%.2f", (float)SCANtotal);	
				ctr2++;							
				break;	
		case 5:
				printf("How many pages? ");
				scanf("%d",&TYPE);
				TYPEans+=TYPE;
				TYPEtotal = TYPE*15;
				printf("\nTotal amount to be paid: Php%.2f", (float)TYPEtotal);
				ctr2++;									
				break;	
		default:
				printf("Wrong choice");
				break;				
	}
	return 0;
}

int servicecheck (y)
{
	puts("\nAnother Service? [Y/N]: ");
	gets(SERVICEans);
	
	if (strlen(SERVICEans)>1)
	{
		printf("Wrong choice\n");
	}
	else if(*SERVICEans=='n'||*SERVICEans=='N')
	{
		ctr1++;
		ctr3++;
	}
	else if(*SERVICEans=='y'||*SERVICEans=='Y')
	{
		ctr3++;
	}
	else
	{
		printf("Wrong choice\n");		
	}
	return 0;
}
