#include<fstream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
class dish1
{long cno;
char name[20],addr[50],plan[40],phno[100];
public:
void getdetail()
{int a=0;
int ch;
cout<<"\n\n\n\n\t\t\t\tENTER DETAILS\t\t\t\t\nYour Customer Number is : "<<cno<<"\n\n\nEnter Name              : ";
gets(name);
cout<<"Enter Phone Number      : ";
gets(phno);
cout<<"Enter Address           : ";
gets(addr);
cout<<"Press Any Key To Select Plan ";
getch();
plan1();
do{
cout<<"\n\nEnter Plan Which You Want To Select(1/2/3/4) : ";
cin>>ch;
if(ch==1)
{
strcpy(plan,"Super Pack");
a=1;
}
else if(ch==2)
{
strcpy(plan,"Budget Pack");
a=1;
}
else if(ch==3)
{
strcpy(plan,"Large Pack");
a=1;
}
else if(ch==4)
{
strcpy(plan,"Ultimate Pack");
a=1;
}
else
cout<<"Wrong choice";
}while(a!=1);
}
void putdetail()
{cout<<"Your Customer Number is : "<<cno<<"\n\n\nName                    : ";
puts(name);
cout<<"Phone Number            : ";
puts(phno);
cout<<"Address                 : ";
puts(addr);
cout<<"Plan Selected By You    : ";
puts(plan);}
long funcno()
{return cno;}
dish1()
{cno=1;}
void pk()
{fstream file;
file.open("dish.dat",ios::in|ios::binary);
long s=1;
dish1 d1;
do{
file.read((char*)&d1,sizeof(d1));
if(file.eof())
break;
s++;}while(!file.eof());
cno=s;}}d1;
void add()
{fstream file;
file.open("dish.dat",ios::app|ios::binary);
dish1 d1;
d1.pk();
d1.getdetail();
file.write((char*)&d1,sizeof(d1));
file.close();}
void know()
{fstream file;
file.open("dish.dat",ios::in|ios::binary);
dish1 d1;
long b,c=0;
if(!file)
{cout<<"No Records";}
else
{cout<<"\n\n\n\nEnter Customer Number To Be Searched : ";
cin>>b;
cout<<"\n\n";
while(!file.eof())
{file.read((char*)&d1,sizeof(d1));
if(file.eof())
break;
if(d1.funcno()==b)
{d1.putdetail();
c=1;}}
if(c==0)
cout<<"Record Not Found";
file.close();
}}
void modify()
{fstream file;
file.open("dish.dat",ios::out|ios::in|ios::binary);
long b,pos=0,c=0;
dish1 d1;
cout<<"\n\n\n\nEnter Customer Number To Be Modify : ";
cin>>b;
cout<<"\n\n";
while(!file.eof())
{pos=file.tellg();
file.read((char*)&d1,sizeof(d1));
if(file.eof())
break;
if(d1.funcno()==b)
{c=1;
d1.getdetail();
file.seekg(pos);
file.write((char*)&d1,sizeof(d1));
}}
if(c==0)
cout<<"Record Not Found";
file.close();
}
void display()
{fstream file;
file.open("dish.dat",ios::in|ios::binary);
dish1 d1;
char ch;
if(!file)
cout<<"No Records";
while(!file.eof())
{do{clrscr();
file.read((char*)&d1,sizeof(d1));
if(file.eof())
break;
d1.putdetail();
cout<<"Next(Y/N):-";
cin>>ch;
if(ch=='n'||ch=='N')
break;
}while(ch=='y'||ch=='Y');
}
file.close();
}
void close1()
{fstream f1,f2;
f1.open("dish.dat",ios::in|ios::binary);
f2.open("temp.dat",ios::app|ios::binary);
long b,c=0;
char ch;
dish1 d1;
if(!f1)
cout<<"No Records To Be Deleted";
else
{cout<<"\n\n\n\nEnter Customer Number To Be Deleted : ";
cin>>b;
cout<<"\n\n";
while(!f1.eof())
{f1.read((char*)&d1,sizeof(d1));
if(f1.eof())
break;
if(d1.funcno()==b)
{d1.putdetail();
c=1;
cout<<"Are You Sure,You Want To Delete This Record?(Y/N):-";
cin>>ch;
if(ch=='n'|ch=='N')
f2.write((char*)&d1,sizeof(d1));}
else
f2.write((char*)&d1,sizeof(d1));
}
if(c==0)
cout<<"Record Not Found";
f1.close();
f2.close();
remove("dish.dat");
rename("temp.dat","dish.dat");
}}
void plan1()
{clrscr();
cout<<"\n1.SUPER PACK";
cout<<"\nStar Plus       Sony TV       Sony Max       Zoom           Sony Sab";
cout<<"\nChannel V       Star News     NDTV India     IBN7           India TV";
cout<<"\nCNBC            Times Now     DD National    Disney         Discovery";
cout<<"\nDiscoveryHD     MTV           ESPN           ETC            National Geographic Jetix";
cout<<"\nET Now          Nick          Filmy          Aaj Tak        Bindass";
cout<<"\nB4U Movies      Hungama       VHR            HomeShop 18    Animal Planet";
cout<<"\n\n2.BUDGET PACK (Super Pack + 5 Channels)";
cout<<"\nZee TV          9XM           NDTV 24x7      Star Gold      Zee Cinema";
cout<<"\n\n3.LARGE PACK (Budget Pack + 10 Channels)";
cout<<"\nStar Movies     Sony Pix      HBO            AXN            Star World";
cout<<"\nZee Cafe        POGO          DisneyXD       CNN            NDTV Profit";
cout<<"\n\n4.ULTRA PACK (Large Pack + 5 Channels)";
cout<<"\nNEO Cricket     NEO Sports    Ten Sports     Colors         UTV Action";}
main()
{clrscr();
int a;
char ch;
cout<<"\n\n\n\n\t&&        &&  &&&&&&&  &&        &&&&&  &&&&&    &&     &&  &&&&&&&\n";
cout<<"\t&&        &&  &&       &&       &&     &&   &&   &&&   &&&  &&\n";
cout<<"\t&&   &&   &&  &&___    &&      &&     &&     &&  &&&& &&&&  &&___\n";
cout<<"\t&&   &&   &&  &&~~~    &&      &&     &&     &&  && &&& &&  &&~~~\n";
cout<<"\t&&   &&   &&  &&       &&      &&      &&   &&   &&     &&  &&\n";
cout<<"\t &&&&&&&&&&   &&&&&&&  &&&&&&&  &&&&&   &&&&&    &&     &&  &&&&&&&\n";
cout<<"\n\n\n\n\t\t      TO DISHNET DTH CONNECTIONS PVT. LTD.\n\t\t\t\tCLASS XII PROJECT";
getch();
do{clrscr();
cout<<"\n\n\n\n\t\t\t\t     $$&&#**#&&$$\n";
cout<<"\t\t\t\t     $   MENU   $\n";
cout<<"\t\t\t\t     $$&&#**#&&$$";
cout<<"\n\n\n1.Open a New Connection";
cout<<"\n2.Know Your Plan";
cout<<"\n3.Modify Your Plan";
cout<<"\n4.Display all Connections";
cout<<"\n5.Close Your Plan";
cout<<"\n6.Exit\n\n\nEnter Choice :-";
cin>>a;
if(a==1)
{clrscr();
add();}
else if(a==2)
{clrscr();
know();}
else if(a==3)
{clrscr();
modify();}
else if(a==4)
{clrscr();
display();}
else if(a==5)
{clrscr();
close1();}
else if(a==6)
{clrscr();
cout<<"\n\n\n\n\t&&&&&&& &&   &&   &&&   &&&  &&  &&   &&  &&   &&  &&&&&  &&   &&";
cout<<"\n\t  &&&   &&   &&  && &&  &&&& &&  &&  &&    &&&&&  &&   && &&   &&";
cout<<"\n\t  &&&   &&&&&&& &&&&&&& && &&&&  &&&&&      &&&   &&   && &&   &&";
cout<<"\n\t  &&&   &&   && &&   && &&  &&&  &&  &&     &&&   &&   && &&   &&";
cout<<"\n\t  &&&   &&   && &&   && &&   &&  &&   &&    &&&    &&&&&   &&&&&";
cout<<"\n\n\n\t\t\tFor Entering DISHNET DTH Connection\n\t\t       May You Have A Pleasant Day Sir/Ma'am";
getch();
exit(0);
}
else
cout<<"Wrong Choice";
cout<<"\nDo You Want To Continue(Y/N):-";
cin>>ch;
}while(ch=='y'|ch=='Y');
clrscr();
cout<<"\n\n\n\n\t&&&&&&& &&   &&   &&&   &&&  &&  &&   &&  &&   &&  &&&&&  &&   &&";
cout<<"\n\t  &&&   &&   &&  && &&  &&&& &&  &&  &&    &&&&&  &&   && &&   &&";
cout<<"\n\t  &&&   &&&&&&& &&&&&&& && &&&&  &&&&&      &&&   &&   && &&   &&";
cout<<"\n\t  &&&   &&   && &&   && &&  &&&  &&  &&     &&&   &&   && &&   &&";
cout<<"\n\t  &&&   &&   && &&   && &&   &&  &&   &&    &&&    &&&&&   &&&&&";
cout<<"\n\n\n\t\t\tFor Entering DISHNET DTH Connection\n\t\t       May You Have A Pleasant Day Sir/Ma'am";
getch();}
