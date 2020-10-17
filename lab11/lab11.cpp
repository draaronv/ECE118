include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <sys/resource.h>
using namespace std;
struct birth
{
	int day;
	int month;
	int year;
};
struct prov
{
		string states;
		int counter=0;
};

struct people
{
string fname;
string lname;
birth birthday;
string state;
int social;
double balance;
};


double get_cpu_time()
{
struct rusage ruse;
getrusage(RUSAGE_SELF, &ruse);
return ruse.ru_utime.tv_sec+ruse.ru_utime.tv_usec/1000000.0 +
ruse.ru_stime.tv_sec+ruse.ru_stime.tv_usec/1000000.0; 
}


bool comparison(string s1,string s2)
{
transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
if(s1.compare(s2)==0)
{
return true;
}
else
{
	return false;
}
}
int concat(int a, int b, int c) 
{
    int t1=1;
	while(t1<=b)
		{
		t1*=100;
		}
	int sum=a*t1 +b;
	int t2=1;
	while(t2<=c)
		{
		t2*=100;
		}
	int d=sum*t2 +c;
    return d;	
} 

void personsearch(string findname,people person[],int n)
{
for(int g=0;g<n;g++)
{
if((comparison(findname,person[g].fname))||(comparison(findname,person[g].lname)))
	{
	cout<<person[g].fname <<"	"<<person[g].lname<<"	"<<person[g].birthday.year<<"		"<<person[g].birthday.month<<"		"<<person[g].birthday.day<<"		"<<person[g].state<<"	"<<person[g].social<<"	"<<person[g].balance<<endl;
	}
}

}

void findrichest(people person2[],int n,int n1)
{
ofstream output;
stringstream s1;
s1<<"richest"<<n1<<".txt";
string nameoffile1;
s1>>nameoffile1;
output.open(nameoffile1);

for(int q=0;q<n;q++)
{
		for(int f=q+1;f<n;f++)
		{
				if(person2[q].state >= person2[f].state)
				{
					people tempperson=person2[q];
					person2[q]=person2[f];
					person2[f]=tempperson;

				}
		}
}
for(int x=0;x<n;x++)
	{
		for(int y=x+1;y<n;y++)
		{
			if(person2[x].state == person2[y].state)	
				{
				if(person2[x].balance<person2[y].balance)
						{
						people tempperson=person2[x];
						person2[x]=person2[y];
						person2[y]=tempperson;
						}
				}
		}
	}
bool counter=true;
if(output.is_open())
{
output<<"State"<<"      "<<"First Name"<<"      "<<"Last Name"<<"      "<<"      "<<"Bank Balance"<<endl;
for(int g=0;g<n;g++)
{
if((person2[g].state == person2[g+1].state)&&counter)
{
output<<person2[g].state<<"      "<<person2[g].fname<<"      "<<person2[g].lname<<"      "<<person2[g].balance<<endl;
counter=false;
}
else if((person2[g].state != person2[g+1].state))
{
		counter=true;
}
}
}
output.close();
}
void findoldest(people person2[], int n,int n1)
{
ofstream output;
stringstream s1;
s1<<"oldest"<<n1<<".txt";
string nameoffile1;
s1>>nameoffile1;
output.open(nameoffile1);
double time1=get_cpu_time();
double time2;
for(int x=0;x<n;x++)
{
		for(int y=x+1;y<n;y++)
		{
		int year1=concat(person2[x].birthday.year,person2[x].birthday.month,person2[x].birthday.day);
		int year2=concat(person2[y].birthday.year,person2[y].birthday.month,person2[y].birthday.day);
		if(year1>year2)
				{
						people tempperson=person2[x];
						person2[x]=person2[y];
						person2[y]=tempperson;
				}
		}
}
time2=get_cpu_time();
cout<<"Time to  sort: "<<(time2-time1)<<endl;
if(output.is_open())
	{
output<<"First Name"<<"      "<<"Last Name"<<"      "<<"Year"<<"      "<<"Month"<<"      "<<"Day"<<"      "<<"State"<<"      "<<"Social"<<"      "<<"Balance"<<endl;
for(int g=0;g<n;g++)
{
output<<person2[g].fname<<"      "<<person2[g].lname<<"      "<<person2[g].birthday.year<<"      "<<person2[g].birthday.month<<"      "<<person2[g].birthday.day<<"      "<<person2[g].state<<"      "<<person2[g].social<<"      "<<person2[g].balance<<endl;
}
	}
output.close();
}
void sortingage()
{
int const amount[9]={1,2,3,5,10,20,30,50,100};
for(int f=0;f<9;f++)
{
		ifstream file;	
		stringstream ss;
		ss<<"./data/data"<<amount[f]<<".txt";
		string nameoffile;
		ss>>nameoffile;
		file.open(nameoffile);
		cout<<nameoffile<<endl;
		people person[100000];
		int i=0;
		if(file.is_open())
		{
		while(file>>person[i].fname>>person[i].lname>>person[i].birthday.year>>person[i].birthday.month>>person[i].birthday.day>>person[i].state>>person[i].social>>person[i].balance)
			{
				i++;
			}
		}
		findoldest(person,(amount[f]*1000),amount[f]);
		cout<<"good"<<endl;
		file.close();
}

}
void sortingbalance()
{
int const amount[9]={1,2,3,5,10,20,30,50,100};
for(int f=0;f<9;f++)
{
		ifstream file;	
		stringstream ss;
		ss<<"./data/data"<<amount[f]<<".txt";
		string nameoffile;
		ss>>nameoffile;
		file.open(nameoffile);
		cout<<nameoffile<<endl;
		people person[100000];
		int i=0;
		if(file.is_open())
		{
		while(file>>person[i].fname>>person[i].lname>>person[i].birthday.year>>person[i].birthday.month>>person[i].birthday.day>>person[i].state>>person[i].social>>person[i].balance)
			{
				i++;
			}
		}
		findrichest(person,(amount[f]*1000),amount[f]);
		cout<<"good"<<endl;
		file.close();
}
}
void searchingeverything()
{
cout<< "Please Enter the Name of the Person You are looking for: "<<endl;
string findname;
cin>>findname;
int const amount[9]={1,2,3,5,10,20,30,50,100};
for(int f=0;f<9;f++)
{
		ifstream file;	
		stringstream ss;
		ss<<"./data/data"<<amount[f]<<".txt";
		string nameoffile;
		ss>>nameoffile;
		file.open(nameoffile);
		cout<<nameoffile<<endl;
		people person[100000];
		int i=0;
		if(file.is_open())
		{
		while(file>>person[i].fname>>person[i].lname>>person[i].birthday.year>>person[i].birthday.month>>person[i].birthday.day>>person[i].state>>person[i].social>>person[i].balance)
			{
				i++;
			}
		}
		personsearch(findname,person,(amount[f]*1000));
		findrichest(person,(amount[f]*1000),amount[f]);
		cout<<"good"<<endl;
		file.close();
}

}
int  main()
{
//searchingeverything();
//sortingage();
//sortingbalance();
return 1;
}
