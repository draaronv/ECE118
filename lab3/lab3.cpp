// Aaron Valdes
//Lab 3
#include "library.h"
// I used this library to be able to set the precision of the float number in Part A
#include <iomanip>
const double pi = acos(-1.0);
void canada_trip1(int n, int x,int y, int z)
    {
    if(n==x)
		{
		n=x;
		print("If I am planning to take a ");
		print(n);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=z;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((n/z)*1.276);
		// I used the common method for printing values in c since this was the most efficient methods for setting the precision
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = n * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		}
	if(n>x)
		{
		print("If I am planning to take a ");
		print(x);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=z;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((x/z)*1.276);
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = x * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		canada_trip1(n,x+y,y,z);
		}
	if(n<x)
		{
		print("If I am planning to take a ");
		print(n);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=z;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((n/z)*1.276);
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = n * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		canada_trip1(n+y,x,y,z);
		}
	}
void canada_trip2(int n, int x, int y, int z)
	{
	if(n==x)
		{
		print("If I am planning to take a ");
		print(z);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=n;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((z/n)*1.276);
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = z * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		}
	if(n>x)
		{
		print("If I am planning to take a ");
		print(z);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=x;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((z/x)*1.276);
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = z * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		canada_trip2(n,x+y,y,z);
		}
	if(n<x)
		{
		print("If I am planning to take a ");
		print(z);
		print(" km road trip, in Canada, in a car with a fuel efficiency of ");
		int kmpl=n;
		print(kmpl);
		print(" kmpl, I need to spend ");
		float cad=((z/n)*1.276);
		std::cout<<fixed<<setprecision(2)<<cad;
		print(" CA$ for fuel. i.e, a ");
		int mile = z * 0.62137119;
		print(mile);
		print(" mile road trip in Canada will cost me ");
		float usd=(cad/1.23);
		std::cout<<fixed<<setprecision(2)<<usd;
		print(" USD in a car with a fuel efficiency of ");
		float fuel=kmpl*2.35214583;
		std::cout<<fixed<<setprecision(2)<<fuel;
		print(" mpg");
		new_line();
		new_line();
		canada_trip2(n+y,x,y,z);
		}
	}
void row_stars(int n)
	{
	if(n>0)
		{
		print("*");
		row_stars(n-1);
		}
	}
void row_dots(int n)
	{
	if(n>0)
		{
		print(".");
		row_dots(n-1);
		}
	}
void dotsstars(int n, int x)
	{
	row_stars(x);
	row_dots(n);
	new_line();
	}
void sequence(int n, int x)
	{
	if(n>0)
		{
	dotsstars(n,x);
	sequence(n-1,x+1);
		}
	}
void circle_draw(int a, int rad)
{
   if(a<=360)
   {
   double arcd=2*pi * (1.0 / 360.0)*rad;
   draw_distance(arcd);
   turn_right_by_degrees(1);
   circle_draw(a+1,rad);
   }
}
void circle(double x,int y,double rad)
{
    move_to(x , y - rad);
	set_heading_degrees(90);
    circle_draw(0,rad);
}
void cannon(int x, int y, int rad, int ang)
	{
	circle(x,y,rad);
	// Converts degrees to radians since it is easier when drawing the first and last line of the canon
	double w = (ang-2)*pi * (1.0/180.0);
	set_heading_degrees(0);
	move_to(x + (rad * sin(w)), y - (rad * cos(w)));
	turn_right_by_radians(w);
	draw_distance(3.7 * rad);
	set_heading_degrees(ang-90);
	draw_distance(1.25 * rad);
	set_heading_degrees(ang-175.25);
	draw_distance(6.5 * rad);
	set_heading_degrees(ang-270);
	draw_distance(2 * rad);
	draw_to(x - (rad * sin(w)), y + (rad * cos(w)));
	}
void main()
	{
// Part A
// I created two functions to print them
canada_trip1(1000,5000,1000,29);
canada_trip2(40,20,5,5000);
// Part B
sequence(5,1);
// Part C
make_window(1300,600,0,30);
cannon(300,500,100,60);
	}
