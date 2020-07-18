#include<iostream>
#include<string.h>
#include<iomanip>
#include"encrypt.h"
using namespace std;

class user
{
protected:
	char email_id[30],password[20],name[20];
public:
	void setdata(char id[30],char pass[20],char n[20])
	{
		strcpy(email_id,id);
		strcpy(password,pass);
		strcpy(name,n);
	}	

  void showdata(char *email,char *password,char *name)
	{
		cout<<"NAME: "<<name<<endl;
		cout<<"EMAIL ID: "<<email<<endl;
		decrypt(password);
		cout<<"PASSWORD: "<<password<<endl;
		encrypt(password);
	}
	
};

       

class admin: public user
{
 public:
 friend void display(admin obj); 
};

void display(admin obj)
 {
 	cout<<left<<setw(28)<<obj.email_id<<left<<setw(28)<<obj.password<<endl;
 }

int main()
{
	char na[20],eid[30],ps[20];
	int count=0,key,i,j=0,ch;
	char password_admin[]={"admin123"},password_check[20];
	admin ob1[30];
	for(i=0;i<=30;i++)
	{
	cout<<"\n\n---------------------------------------------------------\n\n";
	cout<<"1.Sign up  |  2.Find account  |  3.Admin LogIn  |  4.Quit\n\n";
	cout<<"-----------------------SELECT OPTION---------------------\n\n";
	cin>>ch;
	switch(ch)
	{
		case 1:count++;
			   cout<<"Enter your name: ";
			   cin>>na;
			   cout<<"\nEnter valid email id: ";
			   cin>>eid;
			   cout<<"\nEnter password of MAX 20 characters: ";
			   cin>>ps;
			   encrypt(ps);
			   cout<<"\nYour unique number to find your account is: "<<count<<endl;
			   ob1[j].setdata(eid,ps,na);
			   j++;
			   break;
		case 2:cout<<"enter the unique number to find your: ";
			   cin>>key;
			   ob1[key-1].showdata(eid,ps,na);
			   break;
		case 3:cout<<"Enter admin password: ";
			   cin>>password_check;
			   if((strcmp(password_admin,password_check)==0))
			   {
			   		cout<<"\n\nCORRECT PASSWORD\n\n";
			   }
			   else
               {
               		cout<<"\n\nTRY AGAIN\n\n";
               		break;
               }
               cout<<"------------------------------------\n";
               cout<<left<<setw(28)<<"EMAIL ID"<<left<<setw(28)<<"PASSWORD";
               cout<<"\n------------------------------------\n\n";
			   for(i=0;i<count;i++)
		       		display(ob1[i]);
		       break;
		case 4:cout<<"*******QUITTING*******\n\n";
		       exit(0);	   
		default:cout<<"enter valid choice\n";
				
	}
	}
return 0;
}
