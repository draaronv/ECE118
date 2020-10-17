#include "library.h"
string month_name(int n)
	{
	switch (n)
		{
	case 1:
			{
			return("January");
			}
	case 2:
			{
			return("February");
			}
	case 3:
			{
			return("March");
			}
	case 4:
			{
			return("April");
			}
	case 5:
			{
			return("May");
			}
	case 6:
			{
			return("June");
			}
	case 7:
			{
			return("July");
			}
	case 8:
			{
			return("August");
			}
	case 9:
			{
			return("September");
			}
	case 10:
			{
			return("October");
			}
	case 11:
			{
			return("November");
			}
	case 12:
			{
			return("December");
			}
		}
	}
string week_name(int n)
{
	switch (n)
	{
	case 1:
		{
		return ("Mo");
		}
	case 2:
		{
		return ("Tu");
		}
	case 3:
		{
		return ("We");
		}
	case 4:
		{
		return ("Th");
		}
	case 5:
		{
		return ("Fr");
		}
	case 6:
		{
		return ("Sa");
		}
	case 0:
		{
		return ("Su");
		}
	}
}
bool leap_year(int year)
	{
	if((year%4)==0 && ((year %100)!=0))
		{
		return true;
		}
	else
		{
		if((year%400)==0)
			{
			return true;
			}
		else
			{
			return false;
			}
		}
	}
int days_month(int month, int year)
	{
	if(month==0)
		{
		return 0;
		}
	if(month==1)
		{
		return 31;
		}
	if(month==2 && leap_year(year))
		{
		return 29;
		}
	if(month==2 && !leap_year(year))
		{
		return 28;
		}
	if(month==3)
		{
		return 31;
		}
	if(month==4)
		{
		return 30;
		}
	if(month==5)
		{
		return 31;
		}
	if(month==6)
		{
		return 30;
		}
	if(month==7)
		{
		return 31;
		}
	if(month==8)
		{
		return 31;
		}
	if(month==9)
		{
		return 30;
		}
	if(month==10)
		{
		return 31;
		}
	if(month==11)
		{
		return 30;
		}
	if(month==12)
		{
		return 31;
		}
	}
int days_year(int year, int month, int day)
	{
	if(month==1)
		{
		return day;
		}
	else if(month>1 && month<=12)
		{
		int days= days_month(month-1, year) + days_year(year,month -1, day);
		return days;
		}
	}
int year_forever1(int year, int month, int day)
	{
	if(year==0)
		{
		return ((days_year(year,month,day))-1 );
		}
	else if(year>0)
		{
		int days= days_year(year-1,12,31) + year_forever1(year-1,month,day);
		return days;
		}
	}
int year_forever2(int year, int month, int day)
	{
	if((days_month(2,year) == 28)  && (days_year(year,month,day) >=63))
		{
		int correct_days=year_forever1(year,month,day);
		return correct_days;
		}
	else
		{
		int correct_days=year_forever1(year,month, day)+1;
		return correct_days;
		}
	}
int first_day_month(int year, int month)
	{
	int week=(year_forever2(year,month,6))%7 ;
	return week;
	}
int check(int year, int month,int day)
	{
	int week=((year_forever2(year,month,day+5)))%7 ;
	return week;
	}
void day_week_calendar(int n)
	{
	if(n<=6)
		{
		print(week_name(n));
		print("   ");
		day_week_calendar(n+1);
		}
	if(n==7)
		{
		print(week_name(0));
		print("   ");
		}
	}
void month_year_calendar(int year, int month)
	{
	print("      ");
	print(month_name(month));
	print("  ");
	print(year);
	new_line();
	print("---------------------------------");
	new_line();
	day_week_calendar(1);
	new_line();
	print("---------------------------------");
	}
void day_by_day(int year, int month, int day)
	{
	if(day>=1)
		{
		day_by_day(year,month,day-1);
		if(day<=9)
			{
			print(0);
			print(day);
			print("   ");
			}
		if(day>9)
			{
			print(day);
			print("   ");
			}
		if(leap_year(year))
			{
				if((check(year,month,day))==0)
					{
					new_line();
					}
			}
		if(!leap_year(year))
			{
			if(((year_forever2(year,month,(day+5))))%7==0)
					{
					new_line();
					}
			}
			}
		}
void starting_day(int year, int month)
	{
	int first_day=first_day_month(year,month);
		if(first_day == 0)
			{
			print("                              ");
			}
		if(first_day==6)
			{
			print("                         ");
			}
		if(first_day==5)
			{
			print("                    ");
			}
		if(first_day==4)
			{
			print("               ");
			}
		if(first_day==3)
			{
			print("          ");
			}
		if(first_day==2)
			{
			print("     ");
			}
		if(first_day==1)
			{
			print("");
			}
	}
void print_calendar(int year, int month)
	{
	month_year_calendar(year,month);
	new_line();
	starting_day(year,month);
	day_by_day(year,month,days_month(month,year));
	new_line();
	print("---------------------------------");
	}
void day_of_forever()
	{
	print("1st January 2000 was day number: ");
	print(year_forever2(2000,1,1));
	new_line();
	print("1st January 1900 was day number: ");
	print(year_forever2(1900,1,1));
	new_line();
	print("4th July 1776 was day number: ");
	print(year_forever2(1776,7,4));
	new_line();
	print("4th to 10th October 2016 are days: ");
	print(year_forever2(2016,10,4));
	print(" and ");
	print(year_forever2(2016,10,10));
	new_line();
	print("27th November 2737 will be the millionth day :  ");
	print(year_forever2(2737,11,27));
	new_line();
	print("1st January of the year 10 A.D. was day :  ");
	print(year_forever2(10,1,1));
	new_line();
	}
int main()
	{
	day_of_forever();
	new_line();
	new_line();
	new_line();
	print("Input Month: ");
	int month1=read_int();
	print("Input Year: ");
	int year1=read_int();
	print_calendar(year1,month1);
	new_line();
	new_line();
	new_line();
	print("Do you want to see other months and other years(Press any key)");
	int random=read_int();
	new_line();
	new_line();
	new_line();
	print_calendar(1992,1);
	new_line();
	new_line();
	print_calendar(1770,2);
	new_line();
	new_line();
	print_calendar(1800,3);
	new_line();
	new_line();
	print_calendar(2300,4);
	new_line();
	new_line();
	print_calendar(78,5);
	new_line();
	new_line();
	print_calendar(32,6);
	new_line();
	new_line();
	print_calendar(33,7);
	new_line();
	new_line();
	print_calendar(1540,8);
	new_line();
	new_line();
	print_calendar(1252,9);
	new_line();
	new_line();
	print_calendar(780,10);
	new_line();
	new_line();
	print_calendar(1492,11);
	new_line();
	new_line();
	print_calendar(565,12);
	new_line();
	new_line();
	}
