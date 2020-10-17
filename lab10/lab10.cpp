#include "library.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
const string alphabetLC = "abcdefghijklmnopqrstuvwxyz";
const string alphabetUC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void user(string name)
	{
	const int maxItems=5;
	ifstream itemsinput;
	ofstream receipt;
	string filename=name+"_items.txt";
	itemsinput.open(filename);
	string productName[maxItems];
	int quantity[maxItems];
	double price[maxItems];
	double discount[maxItems];
	char taxeligible[maxItems];
	int i=0;
	double normalcost[maxItems];
	double discountprice[maxItems];
	double taxtreduc[maxItems];
	double finalcost[maxItems];
	int totalquantity=0;
	double totaltax=0;
	double totalnormalcost=0;
	double finalfinalcost=0;
	if(itemsinput.is_open())
		{
		while(itemsinput>>productName[i]>>quantity[i]>>price[i]>>discount[i]>>taxeligible[i])
			{
			normalcost[i]=(quantity[i]*price[i]);
			discountprice[i]=normalcost[i]-(1.0-(discount[i]/100));
			if(taxeligible[i]=='Y')
				{
				taxtreduc[i]=(discountprice[i]*0.07);
				}
			else
				{
				taxtreduc[i]=0.0;
				}
			finalcost[i]=discountprice[i]+taxtreduc[i];
			totalquantity+=quantity[i];
			totaltax+=taxtreduc[i];
			totalnormalcost+=discountprice[i];
			finalfinalcost+=finalcost[i];
			i++;
			}
		}
	string receiptfilename=name+"_receipt.txt";
	receipt.open(receiptfilename);
	if(receipt.is_open())
		{
		for(int x=0;x<5;x++)
		{
		receipt<<setprecision(2)<<fixed<<productName[x]<<"  "<<quantity[x]<<"  "<<price[x]<<"  "<<discount[x]<<"  "<<taxeligible[x]<<"   "<<normalcost[x]<<"    "<<discountprice[x]<<"   "<<taxtreduc[x]<<"     "<<finalcost[x]<<endl;
		}
		receipt<<setprecision(2)<<fixed<<"Item-Count "<<totalquantity<<endl;
		receipt<<setprecision(2)<<fixed<<"Amount $"<<totalnormalcost<<endl;
		receipt<<setprecision(2)<<fixed<<"Tax $"<<totaltax<<endl;
		receipt<<setprecision(2)<<fixed<<"TOTAL-PAYABLE $"<<finalfinalcost<<endl;
		}
	receipt.close();
	itemsinput.close();
	}
void consolidated_report()
	{
	ofstream receipt;
	receipt.open("consolidated_report.txt");
	if(receipt.is_open())
		{
		receipt<<"Total No. of items sold :"<<endl;
		receipt<<"Total Revenue (in $)     :"<<endl;
		receipt<<"Total Sales tax payable (in $)      :"<<endl;
		receipt<<"Revenue after tax (in $)   "<<endl;
		}
	receipt.close();
	}
void part1and2()
	{
	string customer_name;
	cout<<"Hello customer"<<endl<<"Welcome to our Store"<<endl;
	cout<<"Please Input your name: ";
	cin>>customer_name;
	cout<<"Do you want to continue?(Press 1 for Yes or 2 for No): "<<endl;
	int response;
	cin>>response;
	if(response==1)
		{
		user(customer_name);
		}
	else if(response==2)
		{
		consolidated_report();
		}
	}
bool primechecker(int n)
	{
    if (n <= 1)
		{
        return false; 
		}
    for (int i = 2; i < n; i++)
		{
        if (n % i == 0) 
            return false;
		}
    return true;
	}
int primesvalues(int n)
	{
	int val=0;
	for(int i=1;i<=n;i++)
		{
		if(primechecker(i))
			{
			val++;
			}
		}
	return val;
	}
void part3()
	{
	ifstream numbers;
	ofstream primes;
	primes.open("prime_frequency.txt");
	numbers.open("numbers.txt");
	int j=0;
	int upperprimes[6];
	if(numbers.is_open())
		{
		while(numbers>>upperprimes[j])
			{
			if(primes.is_open())
				{
				primes<<primesvalues(upperprimes[j])<<endl;
				}
			j++;
			}
	}
	numbers.close();
	primes.close();
}
void part4()
	{
	ifstream words;
	ofstream alphabet;
	words.open("words.txt");
	alphabet.open("frequency_one.txt");
	string wor[5];
	string bigword;
	int n=0;
	if(words.is_open())
		{
		while(words>>wor[n])
			{
			bigword+=wor[n];
			n++;
			}
		}
	int upperCounter[26];
	int lowerCounter[26];
	for(int i = 0;i<26;i++)
	{
		upperCounter[i] = 0;
	}

	for(int i = 0;i<26;i++)
	{
		lowerCounter[i] = 0;
	}
	for(int i=0;i<bigword.size();i++)
			{
				for(int j=0;j<alphabetLC.size();j++)
				{
					if(bigword[i] == alphabetLC[j])
					{ 
						lowerCounter[j] ++;
					}
				}
		}
	for(int i=0;i<bigword.size();i++)
			{
				for(int j=0;j<alphabetUC.size();j++)
				{
					if(bigword[i] == alphabetUC[j])
					{ 
						upperCounter[j] ++;
					}
				}
		}
	if(alphabet.is_open())
		{
	for(int i = 0;i<26;i++)
	{
	if(upperCounter[i]!=0)
		{
	alphabet<<alphabetUC[i]<<" "<<upperCounter[i]<<endl;
		}
	}
	for(int i = 0;i<26;i++)
	{
	if(lowerCounter[i]!=0)
		{
	alphabet<<alphabetLC[i]<<"  "<<lowerCounter[i]<<endl;
		}
		}
	}
	words.close();
	alphabet.close();
	}
void part4cont()
	{
	ifstream file2;
	ofstream file3;
	file2.open("frequency_one.txt");
	file3.open("frequency_two.txt");
	char letter[15];
	char letter2[15];
	int num[15];
	if(file2.is_open())
		{
		int d=0;
		while(file2>>letter[d]>>num[d])
			{
			letter2[d]=toupper(letter[d]);
			d++;
			}
		}
	int counter[26];
	for(int i = 0;i<26;i++)
	{
		counter[i] = 0;
	}
	for(int i=0;i<15;i++)
			{
				for(int j=0;j<alphabetUC.size();j++)
				{
					if(letter2[i] == alphabetUC[j])
					{ 
						counter[j]+=num[i];
					}
					}
		}
		if(file3.is_open())
			{
			for(int v=0;v<26;v++)
				{
				if(counter[v]!=0)
					{
				file3<<alphabetUC[v]<<" "<<counter[v]<<endl;
					}
				}
			}
	file2.close();
	file3.close();
	}
void part5()
	{
	ifstream file5;
	ofstream westcoast;
	ofstream eastcoast;
	file5.open("people.txt");
	eastcoast.open("east_coast.txt");
	westcoast.open("west_coast.txt");
	int birthday[5];
	string firstName[5];
	string lastName[5];
	int height[5];
	int weight[5];
	string state[5];
	string person;
	int numperson=0;
	if(file5.is_open())
		{
		while(getline(file5,person))
			{
			numperson++;
			}
		}
	file5.close();
	file5.open("people.txt");
	cout<<"Total Number of People: "<<numperson<<endl;
	if(file5.is_open())
		{
		int i=0;
		while(file5>>birthday[i]>>firstName[i]>>lastName[i]>>height[i]>>weight[i]>>state[i])
			{
			if((state[i].compare("CA")==0)||(state[i].compare("OR")==0)||(state[i].compare("WA")==0))
				{
				if(westcoast.is_open())
					{
					westcoast<<birthday[i]<<" "<<firstName[i]<<"  "<<lastName[i]<<"  "<<height[i]<<"  "<<weight[i]<<"  "<<state[i]<<endl;
					}
				}
			else
				{
				if(eastcoast.is_open())
					{
					eastcoast<<birthday[i]<<" "<<firstName[i]<<"  "<<lastName[i]<<"  "<<height[i]<<"  "<<weight[i]<<"  "<<state[i]<<endl;
					}
				}
			i++;
			}
		}
	eastcoast.close();
	westcoast.close();
	for(int k=0;k<5;k++)
		{
		for(int q=k+1;q<5;q++)
			{
			if(height[k]>height[q])
				{
				int tempheight=height[k];
				height[k]=height[q];
				height[q]=tempheight;
				string tempfirstName=firstName[k];
				firstName[k]=firstName[q];
				firstName[q]=tempfirstName;
				string templastName=lastName[k];
				lastName[k]=lastName[q];
				lastName[q]=templastName;
				}
			}
		}
	cout<<"The two shortest people are"<<endl;
	for(int hh=0;hh<2;hh++)
		{
		cout<<firstName[hh]<<"   "<<lastName[hh]<<"   "<<height[hh]<<endl;
		}
	}
void main()
	{
	part5();
	}

