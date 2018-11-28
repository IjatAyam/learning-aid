#include<iostream>
#include <stdlib.h>
#include<string>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#define RETURNTIME 15
using namespace std;
void sign_up(void);
void login(void);
void smath();
void hist();
void com();
void buss();
void sci();
void findbook();
void addbook();
void bookcategories();
void booktitle();

int main()

{
	char choice;
	int z;
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to Ayam Bookstores \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

	cout<<"already member ? (Y/N)"<<endl;

	cin>>choice;
	while(choice!='Y'||choice!='N')
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

	cout<<"Main Menu : \n\n";
	cout<<" 1) Add book"<<endl<<" 2) Delete book"<<endl<<" 3)Exit"<<endl;
	cout<<" Please choose : ";
	cin>>z;

	while(z<1 || z>3)
	{
		cout<<"\nInvalid!\n";
		cout<<"\nPlease re-enter choice : ";
		cin>>z;
	}
	switch(z)
	{
		case 1 : cout<<"Add book\n";addbook(); break;
		case 2 : cout<<"Delete book\n"; break;
		case 3 : cout<<"Thank you and come again"; break;

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
	string members[5]={"1816077", "181555", "181324", "181234", "182567"};
	string verify[5]={"wwe","eew", "ttt", "fff", "qqq"};
	string Id_num;

	bool have = false;
	int i;
	
	cout<<"Enter your Id : ";
	cin>>Id_num;
	cin.ignore();
	
	while(!have){
		for(i=0; i<5;i++)
		{
			if(Id_num == members[i])
			{
				have = true;
				break;
			}
		}
		if (!have){
			cout<< "Invalid!,re-enter Id : ";
			cin >> Id_num;
			cin.ignore();
		}
	}
	
	cout << "Enter your password: ";
	cin >> pass;
	cin.ignore();
	while (pass != verify[i]){
		cout << "wrong pass bitch panas ";
		cin >> pass;
		cin.ignore();
	}
}

void addbook()
{
	int press;
	cout<<"Press 1 if want to find your book (categories)";
	cin>>press;
	
	while(press!=1)					
	{
		cout<<"\nInvalid!\n";
		cout<<"\nPlease re-enter choice : ";
		cin>>press;
	}
		if(press==1)
		{
		bookcategories(); 
	    }
	
}

void bookcategories()
{
	int choose;
	cout<<"Book categories : \n";
	cout<<" 1) Science and Math"<<endl <<" 2) History"<<endl<< " 3) Computer and Tech"<<endl<<" 4) Bussiness"<<endl<<" 5) Science-Fiction\n";
	cout<<"***Info : Get 30% discount for History and Bussiness books\n\n";
	cout<<"Please choose one : ";
	cin>>choose;

	while(choose<1 || choose>5)
	{
		cout<<"\nInvalid!\n";
		cout<<"\nPlease re-enter choice : ";
		cin>>choose;
	}


	switch(choose)
	{
		case 1 : cout<<"Science and Math\n"; smath(); break;
		case 2 : cout<<"History\n"; hist(); break;
		case 3 : cout<<"Computer and Tech\n"; com(); break;
		case 4 : cout<<"Bussiness\n";buss(); break;
		case 5 : cout<<"Science-Fiction\n"; sci(); break;
	}

}

void smath ()
{
	int x;
	cout<<" 1) Agricultural Sciences"<<endl <<" 2) Anatomy"<<endl<< " 3) Animals"<<endl<<" 4) Astronomy"<<endl<<" 5) Calculus\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Agricultural Sciences\n"<<"The price : RM 15.00";break;
		case 2 : cout<<"Anatomy\n"<<"The price : RM 75" ; break;
		case 3 : cout<<"Animals\n"<<"The price : RM 25.00"; break;
		case 4 : cout<<"Astronomy\n"<<"The price : RM 85.00"; break;
		case 5 : cout<<"Calculus\n"<<"The price : RM 150.00"; break;
	}
}


void hist ()
{
	int x;
	cout<<" 1) Medieval"<<endl <<" 2) Middle Eastern"<<endl<< " 3) Military"<<endl<<" 4) Modern"<<endl<<" 5) American\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Medieval\n"<<"The price : RM 100";break;
		case 2 : cout<<"Middle Eastern\n"<<"The price : RM 80"; break;
		case 3 : cout<<"Military\n"<<"The price : RM 75"; break;
		case 4 : cout<<"Modern\n"<<"The price : RM 45"; break;
		case 5 : cout<<"American\n"<<"The price : RM 55"; break;

	}
}


void com ()
{
	int x;
	cout<< " 1) Database"<<endl <<" 2) CAD"<<endl<< " 3) Computer Science"<<endl<<" 4) Information Technology"<<endl<<" 5) Love Programming\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Database\n"<<"The price : RM 95";break;
		case 2 : cout<<"CAD\n"<<"The price : RM 45"; break;
		case 3 : cout<<"Computer Science\n"<<"The price : RM 50"; break;
		case 4 : cout<<"Information Technology\n"<<"The price : RM 60"; break;
		case 5 : cout<<"Love Programming\n"<<"The price : RM 25"; break;

	}
}


void buss ()
{
	int x;
	cout<< " 1) Finance"<<endl <<" 2) Economy"<<endl<< " 3) International"<<endl<<" 4) Careers"<<endl<<" 5) Public Relation\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Finance\n"<<"The price : RM 56";break;
		case 2 : cout<<"Economy\n"<<"The price : RM 75"; break;
		case 3 : cout<<"International\n"<<"The price : RM 70"; break;
		case 4 : cout<<"Careers\n"<<"The price : RM 35"; break;
		case 5 : cout<<"Public Relation\n"<<"The price : RM 99"; break;

	}
}


void sci()
{
	int x;
	cout<< " 1) Horror"<<endl <<" 2) Humor"<<endl<< " 3) Space"<<endl<<" 4) Role Playing"<<endl<<" 5) Anthologies\n\n";
	cout<<"Please choose one : ";
	cin>>x;

	switch(x)
	{
		case 1 : cout<<"Horror\n"<<"The price : RM 55";break;
		case 2 : cout<<"Humor\n"<<"The price : RM 35"; break;
		case 3 : cout<<"Space\n"<<"The price : RM 95"; break;
		case 4 : cout<<"Role Playing\n"<<"The price : RM 455"; break;
		case 5 : cout<<"Anthologies\n"<<"The price : RM 40"; break;
	}
}
