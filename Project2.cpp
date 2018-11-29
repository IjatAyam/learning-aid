#include<iostream>
#include <stdlib.h>
#include<string>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>   
#include<stdio.h>              //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include <windows.h>
#include<fstream>
#include<fstream>
using namespace std;
float total_price = 0;
void cart(string, float);
void sign_up(void);
void login(void);
void smath();
void hist();
void com();
void buss();
void sci();
void findbook();
void searchbook();
void bookcategories();
void booktitle();
void DisplayOutput(void);
void menu();
void Receipt();
string pass[9][8]={};

int main()

{
	char choice;
	ofstream of;
	of.open("cart.txt");
	of.close();  // just to renew the cart file
	
	DisplayOutput();
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
		menu();

		
 return 0;
}
void sign_up(void)
{
	ofstream outputfile; 
	outputfile.open("ijat.txt");

	string name,pass, npass, enter;
	int Id_num,N=0,B=0;
	
	cout<<"PLEASE SIGN UP FIRST BEFORE ENTERING THE BOOKSTRORE!!!"<<endl;
	cout<<"\xDB\xDB\xDB\xDB\xB2 1.ENTER NAME : ";
	cin>>pass;

	outputfile<<pass<<endl;
	cout<<"\xDB\xDB\xDB\xDB\xB2 2.ENTER ID NUM : ";
	cin>>Id_num;
	cout<<"\xDB\xDB\xDB\xDB\xB2 3.Enter the password : ";
	cin>>npass;
	outputfile<<npass<<endl;
	cin.ignore();
	cout<<"\xDB\xDB\xDB\xDB\xB2 4.Retype your password : ";
	cin>>npass;
	outputfile<<npass<<endl;
	outputfile.close();
	login();
	
}
	
	
void login(void)
{
	
	ifstream inputfile;
	string user, check, pass, npass;
	
	inputfile.open("ijat.txt");  //---> ye cari file yg name tu
	
	cout << "Username: ";
	cin >> user;
	cin.ignore();
	
	while (inputfile){
		inputfile >> check;
		if (check == user)
			break;
	}
	
	inputfile >> pass; // inputfile kne dduk kat atas, bru ye bleh baca
	cout << "Password: ";
	cin >> npass;
	cin.ignore();
	
	while (npass != pass){
		cout << "Wrong password! Please re-enter: ";
		cin >> npass;
		cin.ignore();
	} 
	
	inputfile.close();

}

void searchbook()
{
	bookcategories();
	
}

void bookcategories()
{
	
	int choose;
	cout<<pass[0][0];
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
		case 1 : cout<<"Agricultural Sciences\n"<<"The price : RM 15.00";cart("Agricultural Sciences", 15);break;
		case 2 : cout<<"Anatomy\n"<<"The price : RM 75" ; cart("Anatomy", 75);break;
		case 3 : cout<<"Anatomy\n"<<"The price : RM 25.00"; cart("Anatomy", 25);break;
		case 4 : cout<<"Astronomy\n"<<"The price : RM 85.00"; cart("Astronomy", 85);break;
		case 5 : cout<<"Calculus\n"<<"The price : RM 150.00"; cart("Calculus", 150);break;
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
		case 1 : cout<<"Medieval\n"<<"The price : RM 100";cart("Medieval", 100);break;
		case 2 : cout<<"Middle Eastern\n"<<"The price : RM 80"; cart("Middle Eastern", 80);break;
		case 3 : cout<<"Military\n"<<"The price : RM 75"; cart("Military", 75);break;
		case 4 : cout<<"Modern\n"<<"The price : RM 45"; cart("Modern", 45);break;
		case 5 : cout<<"American\n"<<"The price : RM 55"; cart("American", 55);break;

	}
}


void com ()
{
	system("cls");
	int x;
	cout<< " 1) Database"<<endl <<" 2) CAD"<<endl<< " 3) Computer Science"<<endl<<" 4) Information Technology"<<endl<<" 5) Love Programming\n\n";
	cout<<"Please choose one : ";
	cin>>x;

		switch(x)
	{
		case 1 : cout<<"Database\n"<<"The price : RM 95";cart("Database", 95);break;
		case 2 : cout<<"CAD\n"<<"The price : RM 45"; cart("CAD", 45);break;
		case 3 : cout<<"Computer Science\n"<<"The price : RM 50"; cart("Computer Science", 50);break;
		case 4 : cout<<"Information Technology\n"<<"The price : RM 60"; cart("Information Technology", 60);break;
		case 5 : cout<<"Love Programming\n"<<"The price : RM 25";cart("Love Programming", 25); break;

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
		case 1 : cout<<"Finance\n"<<"The price : RM 56";cart("Finance", 56);break;
		case 2 : cout<<"Economy\n"<<"The price : RM 75"; cart("Economy", 75);break;
		case 3 : cout<<"International\n"<<"The price : RM 70"; cart("International", 70);break;
		case 4 : cout<<"Careers\n"<<"The price : RM 35"; cart("Careers", 35);break;
		case 5 : cout<<"Public Relation\n"<<"The price : RM 99"; cart("Public Relation", 99); break;

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
		case 1 : cout<<"Horror\n"<<"The price : RM 55";cart("Horror", 55);break;
		case 2 : cout<<"Humor\n"<<"The price : RM 35"; cart("Humor", 35);break;
		case 3 : cout<<"Space\n"<<"The price : RM 95"; cart("Space", 95);break;
		case 4 : cout<<"Role Playing\n"<<"The price : RM 45"; cart("role Playing", 45);break;
		case 5 : cout<<"Anthologies\n"<<"The price : RM 40"; cart("Anthologies", 40); break;
	}
}

void DisplayOutput(void)
{
	int x;
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading";
	for(x=0;x<3;x++)
	{
		cout<<".";

	}
	system("cls");
     
     cout<<"\n\n\n\n\n\n";
     cout<<"\t\t\t\t ___________________________________________________________\n";
     cout<<"\t\t\t\t |    000000    00000    000000     000000                 |\n";
     cout<<"\t\t\t\t |    000  00  000  000  000  000  000  000                |\n";
     cout<<"\t\t\t\t |    000  00  000  000  000  000  000  000                |\n";
     cout<<"\t\t\t\t |    00000    000  000  000  000  00000000                |\n";
     cout<<"\t\t\t\t |    000 00   000  000  000  000  000  000                |\n";
     cout<<"\t\t\t\t |    000  00   00000    000000    000  000                |\n";
     cout<<"\t\t\t\t |                                                         |\n";
     cout<<"\t\t\t\t |  000  000     000  000000   000   000000   000     000  |\n";
     cout<<"\t\t\t\t |  000  0000   0000  000  00  000  000  000  0000    000  |\n";
     cout<<"\t\t\t\t |  000  000 0 0 000  000  00  000  000  000  000 0   000  |\n";
     cout<<"\t\t\t\t |  000  000  0  000  000000   000  00000000  000  0  000  |\n";
     cout<<"\t\t\t\t |  000  000     000  000      000  000  000  000   0 000  |\n";
     cout<<"\t\t\t\t |  000  000     000  000      000  000  000  000    0000  |\n";
     cout<<"\t\t\t\t |_________________________________________________________|\n";
 	system("color 4");Beep(600, 250);//red
   
    system("color 5");Beep(600, 250);//purple
   
    system("color 6");Beep(600, 250);//gold
   
    system("color 7");Beep(600, 250);//White
    
	system("color C");Beep(600, 250);//light red

    system("color D");Beep(600, 250);//light purple
   
   	system("color 0B");Beep(600,250);
   
    system("cls");
    
}

void cart(string bk_name, float price){
	char buy;
	ofstream outfile;
	outfile.open("cart.txt", ios_base::app);  // adding book to cart without delete the file before (just append it)
	cout << "\nDo you want to buy?(Y/N)";
	cin >> buy;
	cin.ignore();
	
	while (buy != 'Y' && buy != 'N') {
        cout << "Re-enter!(Y/N) : ";
    	cin >> buy;
        cin.ignore();
    }
	
	if (buy == 'Y'){
		total_price += price;
		outfile << bk_name << endl;
		menu();
		
	}
	else if (buy == 'N')
		menu();
}

void menu()
{
	int z;
	    cout<<"Welcome to Main Menu : \n\n";
		cout<<"1) Search book\n";
		cout<<"2) Add Book\n"; 
		cout<<"3) Delete Book\n"; 
		cout<<"4) Cart\n";
		cout<<"5) Receipt\n";
		cout<<"6) Close Application\n";
		cin>>z;
	
	switch(z)
	{
		case 1 : searchbook();break;
		case 2 : 
		case 3 : 
		case 4 :
		case 5 : Receipt(); break;
		case 6 : cout<<"Thank You!!! ";break;
	

	}
}

void Receipt(){
	ifstream inFile;
	inFile.open("cart.txt");
	string name_book;
	
	cout<<"\t\t\t\t\t\t Ayam Bookstore"<<endl<<"\t\t\t\t\t JALAN PERSIARAN PUSAT BANDAR"<<endl<<"\t\t\t\t\t BANDAR BARU NILAI"<<endl<<"\t\t\t\t\t 71800 NILAI, NEGERI SEMBILAN"<<endl;
	cout<<"\t\t\t-----------------------------------------------------------\n";
	
	
	
	
	cout<<"\t\t\t-----------------------------------------------------------\n";\
	
	while (!inFile.eof()){
		inFile >> name_book;
		cout << name_book << endl;
	}
	cout << total_price;
	cout<<"\t\t\t\t\t\tPlease Come Again";
}


