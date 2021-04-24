#include<stdio.h>
#include<string.h>

int UNsignup (int userup);
int UNcheck1 (int usercheck1);
int UNcheck2 (int usercheck2);
int UNstore (int userstore);

int PWsignup (int passup);
int PWcheck (int passcheck);
int PWstore (int passstore);

int UNsignin (int userin);
int PWsignin (int passin);

int admincheck (int adminuser);

char UN[100][15]={"admin"},PW[100][15]={"pass"},ans[1],UNholder[15],PWholder[15],userans[1],adminans[1];
int UNctr=0,UNctr1=0,PWctr1=0,UNctr2,PWctr2,UNctr3=0,userup,usercheck1,usercheck2,passup,passcheck,userin,passin,lowercase=0,uppercase=0,symbol=0,number=0,i,t=0,userctr=1,passctr=1,userstore,passstore,usernum,adminuser,adminctr=0,nametaken=0;


int main()
{
	while (1)
	{
		puts("Already a member? (Y/N)");
		gets(ans);
		if(*ans=='n'||*ans=='N')
		{
			UNsignup(userup);
			do
			{
				gets(UNholder);
				UNctr=0;
				UNcheck1(usercheck1);
				if(UNctr==0)
				{
					UNcheck2(usercheck2);
				}
			}while(UNctr1==0);
			UNctr1=0;
			UNstore(userstore);
			
			PWsignup(passup);
			do
			{
				gets(PWholder);
				PWcheck(passcheck);
			}while(PWctr1==0);
			PWctr1=0;
			PWstore(passstore);
			puts("Sign up complete!!");

		}
		else if(*ans =='y'||*ans =='Y')
		{

			do
			{
				puts("Enter user name");
				gets(UNholder);
				UNsignin(userin);
				if(UNctr2==0)
				{
					puts("Invalid User Name would you like to try again?(Y/N)");
					do
					{
						gets(userans);
						if (strlen(userans)>1)
						{
							puts("Invalid answer please try again");							
						}
						else if (*userans == 'N' || *userans == 'n')
						{
							break;
						}
						else if (*userans == 'Y' || *userans == 'y')
						{
							UNctr3++;
						}
						else
						{
							puts("Invalid answer please try again");
						}
					}while(UNctr3==0);
				}
			}while(UNctr2==0);
			
			do
			{
				if (*userans == 'N' || *userans == 'n')
				{
					break;
				}
				puts("Enter password");
				gets(PWholder);
				PWsignin(passin);
			}while(PWctr2==0);
			if (*userans != 'N' || *userans != 'n')
			{
				puts("Login Successful!!");
				printf("Welcome %s\n",UNholder);
			}
			admincheck (adminuser);
		}
	}

	return 0;
}

int UNsignup(userup)
{
	puts("Enter user name");
	puts("*maximum of 15 characters");
	puts("*minimum of 5 characters");
	return 0;
}

int UNcheck1(usercheck1)
{
	for (i=0;i<100;i++)
	{
		if (strcmp(UN[i],UNholder)==0)
		{
			puts("User Name already taken please try again");
			UNctr++;
		}
	}
}

int UNcheck2(usercheck2)
{
	if(strlen(UNholder)<5)
	{
		puts("User Name too short pls try again");
	}
	else if (strlen(UNholder)>15)
	{
		puts("User Name too long pls try again");
	}
	else
	{
		UNctr1=1;
	}
	return 0;
}

int UNstore(userstore)
{
	for(i=userctr;i<100;i++)
	{
		strcpy(UN[i],UNholder);
		userctr++;
		break;
	}
}

int PWsignup(passup)
{
	puts("Enter password");
	puts("*maximum of 15 characters");
	puts("*minimum of 5 characters");
	puts("*must have one upper case and lower case letter");
	puts("*must have atleast one number");
	puts("*must have atleast one symbol - ! @ # $ % ^ & * ( )");
	return 0;
}

int PWcheck(passcheck)
{
	for(i=0;i<strlen(PWholder);i++)
	{
		if (PWholder[i]== 'A' || PWholder[i]== 'B' || PWholder[i]== 'C' || PWholder[i]== 'D' || PWholder[i]== 'E' || PWholder[i]== 'F' || PWholder[i]== 'G' || PWholder[i]== 'H' || PWholder[i]== 'I' || PWholder[i]== 'J' || PWholder[i]== 'K' || PWholder[i]== 'L' || PWholder[i]== 'M' || PWholder[i]== 'N' || PWholder[i]== 'O' || PWholder[i]== 'P' || PWholder[i]== 'Q' || PWholder[i]== 'R' || PWholder[i]== 'S' || PWholder[i]== 'T' || PWholder[i]== 'U' || PWholder[i]== 'V' || PWholder[i]== 'W' || PWholder[i]== 'X' || PWholder[i]== 'Y' || PWholder[i]== 'Z')
		{
			uppercase++;
		}
		if (PWholder[i]== 'a' || PWholder[i]== 'b' || PWholder[i]== 'c' || PWholder[i]== 'd' || PWholder[i]== 'e' || PWholder[i]== 'f' || PWholder[i]== 'g' || PWholder[i]== 'h' || PWholder[i]== 'i' || PWholder[i]== 'j' || PWholder[i]== 'k' || PWholder[i]== 'l' || PWholder[i]== 'm' || PWholder[i]== 'n' || PWholder[i]== 'o' || PWholder[i]== 'p' || PWholder[i]== 'q' || PWholder[i]== 'r' || PWholder[i]== 's' || PWholder[i]== 't' || PWholder[i]== 'u' || PWholder[i]== 'v' || PWholder[i]== 'w' || PWholder[i]== 'x' || PWholder[i]== 'y' || PWholder[i]== 'z')
		{
			lowercase++;
		}
		if (PWholder[i]== '0' || PWholder[i]== '1' || PWholder[i]== '2' || PWholder[i]== '3' || PWholder[i]== '4' || PWholder[i]== '5' || PWholder[i]== '6' || PWholder[i]== '7' || PWholder[i]== '8' || PWholder[i]== '9')
		{
			number++;
		}
		if (PWholder[i]== '!' || PWholder[i]== '@' || PWholder[i]== '#' || PWholder[i]== '$' || PWholder[i]== '%' || PWholder[i]== '^' || PWholder[i]== '&' || PWholder[i]== '*' || PWholder[i]== '(' || PWholder[i]== ')')
		{
			symbol++;
		}
	}
	if(strlen(PWholder)<5)
	{
		puts("Password too short please try again");
	}
	else if (strlen(PWholder)>15)
	{
		puts("Password too long please try again");
	}
	else if (uppercase==0)
	{
		puts("Password do not have uppercase letter please try again");
	}
	else if (lowercase==0)
	{
		puts("Password do not have lowercase letter please try again");
	}
	else if (number==0)
	{
		puts("Password do not have a number please try again");
	}
	else if (symbol==0)
	{
		puts("Password do not have a symbol please try again");
	}
	else
	{
		PWctr1++;
	}
	return 0;
}

int PWstore(passstore)
{
	for(i=passctr;i<100;i++)
	{
		strcpy(PW[i],PWholder);
		passctr++;
		break;
	}	
	return 0;
}

int UNsignin (userin)
{
	for(i=0;i<100;i++)
	{
		if(strcmp(UN[i],UNholder)==0)
		{
			UNctr2=1;
			usernum=i;
		}
	}
	return 0;
}

int PWsignin (passin)
{
	if(strcmp(PW[usernum],PWholder)==0)
	{
			PWctr2=1;
	}
	if(PWctr2==0)
	{
		puts("Invalid Password please try again");
	}
	return 0;
}

int admincheck (adminuser)
{
	if (strcmp(UN[0],UNholder)==0)
	{
		do
		{
			puts("Would you like to view the users?(Y/N)");
			gets(adminans);
			if (strlen(adminans)>1)
			{
				puts("Invalid answer please try again");
			}
			else if (*adminans == 'Y' || *adminans == 'y')
			{
				for (i=0;i<userctr;i++)
				{
					printf("#%d. %s\n",t+1,UN[i]);
					t++;
				}
				printf("There are %d registered user(s)\n",userctr);
				adminctr++;
			}
			else if (*adminans == 'N' || *adminans == 'n')
			{
				adminctr++;
			}
			else
			{
				puts("Invalid answer please try again");
			}
		}while(adminctr==0);
	}
	t=0;
	return 0;
}

