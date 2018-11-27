#include <iostream>
#include <stdlib.h>
#include <string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include <time.h>
#define RETURNTIME 15
using namespace std;

void sign_up(void);
void login(int [], string []);

int main(){
	char choice;
	string name[20], pass[20];
	int z, s;
	int Id_num[]={};
	string npass[]={};

	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to Ayam Bookstores \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

	cout<<"Already member ? (Y/N)"<<endl;

	cin>>choice;
	for( ;choice!='Y'||choice!='N';){
		if (choice=='Y'){
			login(name, pass);
			break;
		}
		else if(choice =='N'){
			sign_up();
			break;
		}
		else{
		cout<<"Wrong input!!"<<endl;
		cout<<"Already member ? (Y/N)"<<endl;
		cin>>choice;
		}
	}

 return 0;
}
void sign_up(string name[], string pass[]){


	cout<<"PLEASE SIGN UP FIRST BEFORE ENTERING THE BOOKSTRORE!!!"<<endl;
	cout<<"\xDB\xDB\xDB\xDB\xB2 1.ENTER NAME : ";
	cin>>name;
	cin.ignore();
	cout<<"\xDB\xDB\xDB\xDB\xB2 2.ENTER ID NUM : ";
	cin>>Id_num;
	cout<<"\xDB\xDB\xDB\xDB\xB2 3.Enter the password : ";
	cin>>pass;
	cin.ignore();
	cout<<"\xDB\xDB\xDB\xDB\xB2 4.Retype your password : ";
	cin>>npass;
	cin.ignore();
	login(z,s);

	}
void login(int num[], string X[]){
	string pass;
	int id_num;

	cout<<"Enter your Id : ";
	cin>>id_num;
	cout<<"Enter your password : ";
	cin>>pass;

	if(id_num==num&& pass==X){
		cout<<"T";
	}
}
