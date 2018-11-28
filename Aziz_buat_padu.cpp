#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include <ctype.h>                   //contains toupper(), tolower(),etc
#include <dos.h>                     //contains _dos_getdate
#include <time.h>
//#include<bios.h>
using namespace std;

#define RETURNTIME 15

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findbook;
char password[10]={"codewithc"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct books a;
int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{
//loaderanim();
system("cls");
//    textbackground(13);
int i;
gotoxy(20,3);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
//    show_mouse();
gotoxy(20,5);
cout << "\xDB\xDB\xDB\xDB\xB2 1. Add Books   ";
gotoxy(20,7);
cout << "\xDB\xDB\xDB\xDB\xB2 2. Delete books";
gotoxy(20,9);
cout << "\xDB\xDB\xDB\xDB\xB2 3. Search Books";
gotoxy(20,11);
cout << "\xDB\xDB\xDB\xDB\xB2 4. Issue Books";
gotoxy(20,13);
cout << "\xDB\xDB\xDB\xDB\xB2 5. View Book list";
gotoxy(20,15);
cout << "\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record";
gotoxy(20,17);
cout << "\xDB\xDB\xDB\xDB\xB2 7. Close Application";
gotoxy(20,19);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,20);
t();
gotoxy(20,21);
cout << "Enter your choice:";
switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
issuebooks();
break;
case '5':
viewbooks();
break;
case '6':
editbooks();
break;
case '7':
{
system("cls");
gotoxy(16,3);
cout << "\tLibrary Management System";
gotoxy(16,4);
cout << "\tMini Project in C";
gotoxy(16,5);
cout << "\tis brought to you by";
gotoxy(16,7);
cout << "\tCode with C Team";
gotoxy(16,8);
cout << "******************************************";
gotoxy(16,10);
cout << "*******************************************";
gotoxy(16,11);
cout << "*******************************************";
gotoxy(16,13);
cout << "********************************************";
gotoxy(10,17);
cout << "Exiting in 3 second...........>";
//flushall();
Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
cout << "\aWrong Entry!!Please re-entered correct option";
if(getch())
mainmenu();
}

}
}
void addbooks(void)    //funtion that add books
{
system("cls");
int i;
gotoxy(20,5);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,7);
cout << "\xDB\xDB\xDB\xDB\xB2 1. Computer";
gotoxy(20,9);
cout << "\xDB\xDB\xDB\xDB\xB2 2. Electronics";
gotoxy(20,11);
cout << "\xDB\xDB\xDB\xDB\xB2 3. Electrical";
gotoxy(20,13);
cout << "\xDB\xDB\xDB\xDB\xB2 4. Civil";
gotoxy(20,15);
cout << "\xDB\xDB\xDB\xDB\xB2 5. Mechanical";
gotoxy(20,17);
cout << "\xDB\xDB\xDB\xDB\xB2 6. Architecture";
gotoxy(20,19);
cout << "\xDB\xDB\xDB\xDB\xB2 7. Back to main menu";
gotoxy(20,21);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,22);
cout << "Enter your choice:";
cin >> s;
if(s==7)

mainmenu() ;
system("cls");
fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
cout << "The record is sucessfully saved";
gotoxy(21,15);
cout << "Save any more?(Y / N):";
if(getch()=='n')
mainmenu();
else
system("cls");
addbooks();
}
}
void deletebooks()    //function that delete items from file fp
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
cout << "Enter the Book ID to  delete:";
cin >> d;
fp=fopen("Bibek.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
cout << "The book record is available";
gotoxy(10,8);
cout << "Book name is " << a.name;
gotoxy(10,9);
cout << "Rack No. is " << a.rackno;
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
cout << "No record is found modify the search";
if(getch())
mainmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
cout << "Do you want to delete it?(Y/N):";
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("Bibek.dat");
rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
fp=fopen("Bibek.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
cout << "The record is sucessfully deleted";
gotoxy(10,11);
cout << "Delete another record?(Y/N)";
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}
void searchbooks()
{
system("cls");
int d;
cout << "*****************************Search Books*********************************";
gotoxy(20,10);
cout << "\xDB\xDB\xDB\xB2 1. Search By ID";
gotoxy(20,14);
cout << "\xDB\xDB\xDB\xB2 2. Search By Name";
gotoxy( 15,20);
cout << "Enter Your Choice";
fp=fopen("Bibek.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
cout << "****Search Books By Id****";
gotoxy(20,5);
cout << "Enter the book id:";
cin >> d;
gotoxy(20,7);
cout << "Searching........";
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
cout << "The Book is available";
gotoxy(20,8);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,9);
cout << "\xB2 ID:" << a.id;gotoxy(47,9);cout << "\xB2";
gotoxy(20,10);
cout << "\xB2 Name:" << a.name;gotoxy(47,10);cout << "\xB2";
gotoxy(20,11);
cout << "\xB2 Author:" << a.Author;gotoxy(47,11);cout << "\xB2";
gotoxy(20,12);
cout << "\xB2 Qantity:" << a.quantity;gotoxy(47,12);cout << "\xB2"; gotoxy(47,11);cout << "\xB2";
gotoxy(20,13);
cout << "\xB2 Price:RM" << a.Price;gotoxy(47,13);cout << "\xB2";
gotoxy(20,14);
cout << "\xB2 Rack No:" << a.rackno;gotoxy(47,14);cout << "\xB2";
gotoxy(20,15);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,9);cout << "\xB2";  gotoxy(38,9);cout << "\xB2";
gotoxy(20,10);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(22,9);cout << "\aNo Record Found";
}
gotoxy(20,17);
cout << "Try another search?(Y/N)";
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
cout << "****Search Books By Name****";
gotoxy(20,5);
cout << "Enter Book Name:";
cin >> s;
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
cout << "The Book is available";
gotoxy(20,8);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,9);
cout << "\xB2 ID:" << a.id;gotoxy(47,9);cout << "\xB2";
gotoxy(20,10);
cout << "\xB2 Name:" << a.name;gotoxy(47,10);cout << "\xB2";
gotoxy(20,11);
cout << "\xB2 Author:" << a.Author;gotoxy(47,11);cout << "\xB2";
gotoxy(20,12);
cout << "\xB2 Qantity:" << a.quantity;gotoxy(47,12);cout << "\xB2";
gotoxy(20,13);
cout << "\xB2 Price:RM" << a.Price;gotoxy(47,13);cout << "\xB2";
gotoxy(20,14);
cout << "\xB2 Rack No:" << a.rackno;gotoxy(47,14);cout << "\xB2";
gotoxy(20,15);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
d++;
}

}
if(d==0)
{
gotoxy(20,8);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,9);cout << "\xB2";  gotoxy(38,9);cout << "\xB2";
gotoxy(20,10);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(22,9);cout << "\aNo Record Found";
}
gotoxy(20,17);
cout << "Try another search?(Y/N)";
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}
void issuebooks(void)  //function that issue books from library
{
int t;

system("cls");
cout << "********************************ISSUE SECTION**************************";
gotoxy(10,5);
cout << "\xDB\xDB\xDB\xDb\xB2 1. Issue a Book";
gotoxy(10,7);
cout << "\xDB\xDB\xDB\xDb\xB2 2. View Issued Book";
gotoxy(10,9);
cout << "\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book";
gotoxy(10,11);
cout << "\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book";
gotoxy(10,14);
cout << "Enter a Choice:";
switch(getch())
{
case '1':  //issue book
{
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
cout << "***Issue Book section***";
gotoxy(10,6);
cout << "Enter the Book Id:";
cin >> t;
fp=fopen("Bibek.dat","rb");
fs=fopen("Issue.dat","ab+");
if(checkid(t)==0) //issues those which are present in library
{
gotoxy(10,8);
cout << "The book record is available";
gotoxy(10,9);
cout << "There are " << a.quantity << " unissued books in library ";
gotoxy(10,10);
cout << "The name of book is " << a.name;
gotoxy(10,11);
cout << "Enter student name:";
cin >> a.stname;
//struct dosdate_t d; //for current date
//_dos_getdate(&d);
//a.issued.dd=d.day;
//a.issued.mm=d.month;
//a.issued.yy=d.year;
gotoxy(10,12);
cout << "Issued date=" << a.issued.dd << "-" << a.issued.mm << "-" << a.issued.yy;
gotoxy(10,13);
cout << "The BOOK of ID " << a.id << " is issued";
a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
a.duedate.mm=a.issued.mm;
a.duedate.yy=a.issued.yy;
if(a.duedate.dd>30)
{
a.duedate.mm+=a.duedate.dd/30;
a.duedate.dd-=30;

}
if(a.duedate.mm>12)
{
a.duedate.yy+=a.duedate.mm/12;
a.duedate.mm-=12;

}
gotoxy(10,14);
cout << "To be return:" << a.duedate.dd << "-" << a.duedate.mm << "-" << a.duedate.yy;
fseek(fs,sizeof(a),SEEK_END);
fwrite(&a,sizeof(a),1,fs);
fclose(fs);
c=1;
}
if(c==0)
{
gotoxy(10,11);
cout << "No record found";
}
gotoxy(10,15);
cout << "Issue any more(Y/N):";
fflush(stdin);
another=getche();
fclose(fp);
}

break;
}
case '2':  //show issued book list
{
system("cls");
int j=4;
cout << "*******************************Issued book list*******************************\n";
gotoxy(2,2);
cout << "STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE";
fs=fopen("Issue.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{

gotoxy(2,j);
cout << a.stname;
gotoxy(18,j);
cout << a.cat;
gotoxy(30,j);
cout << a.id;
gotoxy(36,j);
cout << a.name;
gotoxy(51,j);
cout << a.issued.dd << "-" << a.issued.mm << "-" << a.issued.yy;
gotoxy(65,j);
cout << a.duedate.dd << "-" << a.duedate.mm << "-" << a.duedate.yy;
//struct dosdate_t d;
//_dos_getdate(&d);
gotoxy(50,25);
//            cout << "Current date=%d-%d-%d",d.day,d.month,d.year);
j++;

}
fclose(fs);
gotoxy(1,25);
returnfunc();
}
break;
case '3':   //search issued books by id
{
system("cls");
gotoxy(10,6);
cout << "Enter Book ID:";
int p,c=0;
char another='y';
while(another=='y')
{

cin >> p;
fs=fopen("Issue.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==p)
{
issuerecord();
gotoxy(10,12);
cout << "Press any key.......";
getch();
issuerecord();
c=1;
}

}
fflush(stdin);
fclose(fs);
if(c==0)
{
gotoxy(10,8);
cout << "No Record Found";
}
gotoxy(10,13);
cout << "Try Another Search?(Y/N)";
another=getch();
}
}
break;
case '4':  //remove issued books from list
{
system("cls");
int b;
FILE *fg;  //declaration of temporary file for delete
char another='y';
while(another=='y')
{
gotoxy(10,5);
cout << "Enter book id to remove:";
cin >> b;
fs=fopen("Issue.dat","rb+");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==b)
{
issuerecord();
findbook='t';
}
if(findbook=='t')
{
gotoxy(10,12);
cout << "Do You Want to Remove it?(Y/N)";
if(getch()=='y')
{
fg=fopen("record.dat","wb+");
rewind(fs);
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id!=b)
{
fseek(fs,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,fg);
}
}
fclose(fs);
fclose(fg);
remove("Issue.dat");
rename("record.dat","Issue.dat");
gotoxy(10,14);
cout << "The issued book is removed from list";

}

}
if(findbook!='t')
{
gotoxy(10,15);
cout << "No Record Found";
}
}
gotoxy(10,16);
cout << "Delete any more?(Y/N)";
another=getch();
}
}
default:
gotoxy(10,18);
cout << "\aWrong Entry!!";
getch();
issuebooks();
break;
}
gotoxy(1,30);
returnfunc();
}
void viewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
cout << "*********************************Book List*****************************";
gotoxy(2,2);
cout << " CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ";
j=4;
fp=fopen("Bibek.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
cout << a.cat;
gotoxy(16,j);
cout << a.id;
gotoxy(22,j);
cout << a.name;
gotoxy(36,j);
cout << a.Author;
gotoxy(50,j);
cout << a.quantity;
gotoxy(57,j);
cout << a.Price;
gotoxy(69,j);
cout << a.rackno;
cout << "\n\n";
j++;
i=i+a.quantity;
}
gotoxy(3,25);
cout << "Total Books =" << i;
fclose(fp);
gotoxy(35,25);
returnfunc();
}
void editbooks(void)  //edit information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
cout << "****Edit Books Section****";
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
cout << "Enter Book Id to be edited:";
cin >> d;
fp=fopen("Bibek.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
cout << "The book is availble";
gotoxy(15,8);
cout << "The Book ID:" << a.id;
gotoxy(15,9);
cout << "Enter new name:";cin >> a.name;
gotoxy(15,10);
cout << "Enter new Author:";cin >> a.Author;
gotoxy(15,11);
cout << "Enter new quantity:";cin >> a.quantity;
gotoxy(15,12);
cout << "Enter new price:";cin >> a.Price;
gotoxy(15,13);
cout << "Enter new rackno:";cin >> a.rackno;
gotoxy(15,14);
cout << "The record is modified";
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
cout << "No record found";
}
}
gotoxy(15,16);
cout << "Modify another Record?(Y/N)";
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
cout << " Press ENTER to return to main menu";
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);cout << "Enter the Information Below";
gotoxy(20,4);cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,5);
cout << "\xB2";gotoxy(46,5);cout << "\xB2";
gotoxy(20,6);
cout << "\xB2";gotoxy(46,6);cout << "\xB2";
gotoxy(20,7);
cout << "\xB2";gotoxy(46,7);cout << "\xB2";
gotoxy(20,8);
cout << "\xB2";gotoxy(46,8);cout << "\xB2";
gotoxy(20,9);
cout << "\xB2";gotoxy(46,9);cout << "\xB2";
gotoxy(20,10);
cout << "\xB2";gotoxy(46,10);cout << "\xB2";
gotoxy(20,11);
cout << "\xB2";gotoxy(46,11);cout << "\xB2";
gotoxy(20,12);
cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(21,5);
cout << "Category:";
gotoxy(31,5);
cout << catagories[s-1];
gotoxy(21,6);
cout << "Book ID:\t";
gotoxy(30,6);
cin >> t;
if(checkid(t) == 0)
{
gotoxy(21,13);
cout << "\aThe book id already exists\a";
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
cout << "Book Name:";gotoxy(33,7);
cin >> a.name;
gotoxy(21,8);
cout << "Author:";gotoxy(30,8);
cin >> a.Author;
gotoxy(21,9);
cout << "Quantity:";gotoxy(31,9);
cin >> a.quantity;
gotoxy(21,10);
cout << "Price:";gotoxy(28,10);
cin >> a.Price;
gotoxy(21,11);
cout << "Rack No:";gotoxy(30,11);
cin >> a.rackno;
return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t;
time(&t);
cout << "Date and time:" << ctime(&t) << "\n";

return 0 ;
}
/*void show_mouse(void) //show inactive mouse pointer in programme
{
union REGS in,out;
       in.x.ax = 0x1;
       int86(0x33,&in,&out);
}*/
void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
//textbackground(WHITE);
//textcolor(RED);
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
cout << "*";
}
for(j=0;j<20;j++)
{
Sleep(50);
cout << d[j];
}
for(j=0;j<20;j++)
{
Sleep(50);
cout << "*";
}
gotoxy(10,10);
gotoxy(15,7);
cout << "Enter Password:";

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
cout << "Password match";
gotoxy(17,10);
cout << "Press any key to countinue.....";
getch();
mainmenu();
}
else
{
gotoxy(15,16);
cout << "\aWarning!! Incorrect Password";
getch();
Password();
}
}
void issuerecord()  //display issued book's information
{
system("cls");
gotoxy(10,8);
cout << "The Book has taken by Mr. " << a.stname;
gotoxy(10,9);
cout << "Issued Date:%d-%d-%d";
gotoxy(10,10);
cout << "Returning Date:%d-%d-%d";
}
/*void loaderanim()
{
int loader;
system("cls");
gotoxy(20,10);
cout << "LOADING........";
cout << "\n\n";
gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
Sleep(100);cout << "%c",219);}
}*/
//End of program
