#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
using namespace std;
class bank
{
	int ac,m,dma,wma,i;
	char n[20],add[50],name[20];
	float balance,interest;
	void calculate_interest()
	{
	interest=(10*balance)/100+balance;
	}
	public:
	void newcustomer()
	{
	cout<<"\n Enter Account Number-";
	cin>>ac;
	cout<<"\n Enter Name-";
	scanf("%s",n);
	cout<<"\n Enter the Address-";
	scanf("%s",add);
	cout<<"\n Enter Mobile-";
	cin>>m;
	do
	{
	cout<<"\n Enter the Balance Amount-";
	cin>>balance;
	if(balance>1000)
	cout<<"Valid";
	else
	cout<<"Try Again";
	}
	while(balance<1000);
	calculate_interest();
	}
	void display()
	{
	cout<<"\n"<<ac;
	cout<<"\n"<<n;
	cout<<"\n"<<add;
	cout<<"\n"<<m;
	cout<<"\n"<<balance;
	cout<<"\n Amount after applying interest is-"<<interest;
	}
	void deposit()
	{
	cout<<"\nEnter the amount of money to be deposited";
	cin>>dma;
	balance=balance+dma;
	cout<<"\n Total Balance is-"<<balance;
	}
	void withdrawal()
	{
	cout<<"\n Enter the amount of money for withdrawal";
	cin>>wma;
	if(wma<balance-1000)
	{
		if(wma<balance)
		{
			balance=balance-wma;
			cout<<"\n Transaction Done";
			cout<<"\n Left Amount is-"<<balance;
		}
		else
		cout<<"\n No Sufficient Balance";
	}
	else
	{
		if(wma=balance)
		{
		balance=balance-wma;
		cout<<"\n Left Amount is-"<<balance;	
		}
		else
		{
		cout<<"\n No Balance";	
		}	
	}	
	}
	int search(char name[])
	{
		if(strcmp(name,n)==0)
		return(1);
		else
		return(0);
	}
};

main()
{
	fstream file,file1;
	int choice;
	char n[20];
	bank b;
	do
	{
		
		cout<<"\n 1.New Customer";
		cout<<"\n 2.Display";
		cout<<"\n 3.Deposit";
		cout<<"\n 4.Withdrawal";
		cout<<"\n 5.Exit";
		cout<<"\n Enter Your Choice-";
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.newcustomer();
				file.open("Bank.txt",ios::app);
				file.write((char*)&b,sizeof(b));
				file.close();
				break;
			case 2:
				cout<<"\n Details Are-";
				file.open("Bank.txt",ios::in);
				while(file)
				{
					file.read((char*)&b,sizeof(b));
					if(file)
					b.display();
				}
				file.close();
				break;	
			case 3:
				cout<<"\n Enter the Name to Deposit Amount-";
				scanf("%s",n);
				file.open("Bank.txt",ios::in);
				file1.open("temp.txt",ios::out);
				while(file)
				{
					file.read((char*)&b,sizeof(b));
					if(file)
					{
					if(b.search(n)==1)
					b.deposit();
					file1.write((char*)&b,sizeof(b));
					}
				}
				file.close();
				file1.close();
				remove("Bank.txt");
				rename("temp.txt","Bank.txt");
				break;
			case 4:
				cout<<"\n Enter the Name for withdrawal-";
				scanf("%s",n);
				file.open("Bank.txt",ios::in);
				file1.open("temp.txt",ios::out);
				while(file)
				{
				file.read((char*)&b,sizeof(b));
				if(file)
				{
				if(b.search(n)==1)
				b.withdrawal();
				file1.write((char*)&b,sizeof(b));
				}
				}
				file.close();
				file1.close();
				remove("Bank.txt");
				rename("temp.txt","Bank.txt");
				break;	
		}
	}
	while(choice<5);
}

