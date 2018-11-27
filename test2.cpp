#include <iostream>
using namespace std;
void smkath();
void hist();
void com();
void buss();
void sci();


int main()
{
	int choose;
	cout<<"Book categories : \n";
	cout<<" 1) Science and Math"<<endl <<" 2) History"<<endl<< " 3) Computer and Tech"<<endl<<" 4) Bussiness"<<endl<<" 5) Science-Fiction\n\n";

	cout<<"Please choose one : ";
	cin>>choose;

	switch(choose)
	{
		case 1 : cout<<"Science and Math\n"; smath(); break;
		case 2 : cout<<"History\n"; hist(); break;
		case 3 : cout<<"Computer and Tech\n"; com(); break;
		case 4 : cout<<"Bussiness\n";buss(); break;
		case 5 : cout<<"Science-Fiction\n"; sci(); break;

	}

	return 0;
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
		case 1 : cout<<"Medieval\n"<<"The price : RM 75";break;
		case 2 : cout<<"Middle Eastern\n"<<"The price : RM 75"; break;
		case 3 : cout<<"Military\n"<<"The price : RM 75"; break;
		case 4 : cout<<"Modern\n"<<"The price : RM 75"; break;
		case 5 : cout<<"American\n"<<"The price : RM 75"; break;

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
		case 1 : cout<<"Database\n"<<"The price : RM 75";break;
		case 2 : cout<<"CAD\n"<<"The price : RM 75"; break;
		case 3 : cout<<"Computer Science\n"<<"The price : RM 75"; break;
		case 4 : cout<<"Information Technology\n"<<"The price : RM 75"; break;
		case 5 : cout<<"Love Programming\n"<<"The price : RM 75"; break;

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
		case 1 : cout<<"Finance\n"<<"The price : RM 75";break;
		case 2 : cout<<"Economy\n"<<"The price : RM 75"; break;
		case 3 : cout<<"International\n"<<"The price : RM 75"; break;
		case 4 : cout<<"Careers\n"<<"The price : RM 75"; break;
		case 5 : cout<<"Public Relation\n"<<"The price : RM 75"; break;

	}
}


void sci ()
{
	int x;
	cout<< " 1) Horror"<<endl <<" 2) Humor"<<endl<< " 3) Space"<<endl<<" 4) Role Playing"<<endl<<" 5) Anthologies\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Horror\n"<<"The price : RM 75";break;
		case 2 : cout<<"Humor\n"<<"The price : RM 75"; break;
		case 3 : cout<<"Space\n"<<"The price : RM 75"; break;
		case 4 : cout<<"Role Playing\n"<<"The price : RM 75"; break;
		case 5 : cout<<"Anthologies\n"<<"The price : RM 75"; break;

	}
}
