#include<iostream>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#define RETURNTIME 15
using namespace std;
void sign_up(void);
void login(void);
int main()
{
	char choice;
	
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 welcome to Ayam Bookstores \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
	
	cout<<"already member ? (Y/N)"<<endl;
	
	cin>>choice;
	for( ;choice!='Y'||choice!='N';)
	{
		if (choice=='Y')
		{	
			login();
			break;
		}
		else if(choice =='N')
		{
			sign_up();
			break;	
		}
		else;
		{
		cout<<"wrong input"<<endl;
		cout<<"already member ? (Y/N)"<<endl;
		cin>>choice;
		}
	}
	
 return 0;	
}
void sign_up(void)
{
	
	string name, pass, npass;
	int Id_num;
	cout<<"PLEASE SIGN UP FIRST BEFORE ENTERING THE BOOKSTRORE!!!"<<endl;
	cout<<"\xDB\xDB\xDB\xDB\xB2 1.ENTER NAME : ";
	cin>>name;
	cout<<"\xDB\xDB\xDB\xDB\xB2 2.ENTER ID NUM : ";
	cin>>Id_num;
	cout<<"\xDB\xDB\xDB\xDB\xB2 3.Enter the password : ";
	cin>>pass;
	cin.ignore();
	cout<<"\xDB\xDB\xDB\xDB\xB2 4.Retype your password : ";
	cin>>npass;
	
	login();
	}
void login(void)
{
	string pass;
	int Id_num;
	
	cout<<"Enter your Id : ";
	cin>>Id_num;
	cout<<"Enter your password : ";
	cin>>pass;
}
