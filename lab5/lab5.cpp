#include "library.h"
const double pi = acos(-1.0);
int c_y;
int c_x;
void draw_rectangle(double x2,double y2,double w2, double h2, int rc)
	{
	start_shape();
	move_to(x2,y2);
	note_position();
	move_to(x2+w2,y2);
	note_position();
	move_to(x2+w2,y2+h2);
	note_position();
	move_to(x2,y2+h2);
	note_position();
	move_to(x2,y2);
	set_pen_color(rc);
	set_pen_width(1);
	fill_shape();
	}
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
string day_ending(int n)
	{
	switch (n)
	{
	case 1:
		{
		return("st");
		}
	case 2:
		{
		return("nd");
		}
	case 3:
		{
		return("rd");
		}
	case 21:
		{
		return("st");
		}
	case 22:
		{
		return("nd");
		}
	case 23:
		{
		return("rd");
		}
	case 31:
		{
		return("st");
		}
	default:
		{
		return("th");
		}
	}
	}
int year()
{
	int year=(get_calendar_date())/10000;
	return(year);
}
int month()
{
	int month =((get_calendar_date())/100)%100;
	return(month);
}
int day()
{
	int day = (get_calendar_date()) % 100;
	return(day);
}
int hour()
{
	int hour = (get_clock_time()) / 10000;
	if (hour > 12)
	{
		return(hour - 12);
	}
	else if(hour==0)
		{
		return(12);
		}
	else
	{
		return(hour);
	}
}
int ampm()
{
	int hour = (get_clock_time()) / 10000;
	if (hour > 12)
	{
		return(hour - 12);
	}
	else
	{
		return(hour);
	}
}
bool ampm(int n)
	{
	if(n==0)
		{
		return true;
		}
	else if (n==12)
		{
		return false;
		}
	else if (n>12)
		{
		return false;
		}
	else if (n<12)
		{
		return true;
		}
	}
int minute()
{
	int minute = ((get_clock_time()) / 100) % 100;
	return(minute);
}
int second()
{
	int second = (get_clock_time())% 100;
	return(second);
}
void circle_draw(int a, int rad, int n)
{
   if(a<=363)
   {
   set_pen_width(2);
   double arcd=2*pi * (1.0 / 360.0)*rad;
   draw_distance(arcd);
   double x= get_x_position();
   double y= get_y_position();
   int hd=get_heading_degrees();
   if(0==(hd%30))
	   {
	   n++;
	   set_pen_width(6);
	   turn_left_by_degrees(90);
	   draw_distance(-10);
	   draw_distance(20);
	   move_to(x,y);
	   set_heading_degrees(hd);
	   set_pen_width(2);
	   }
   if(0==(hd%6))
	   {
	   set_pen_width(4);
	   turn_left_by_degrees(90);
	   draw_distance(-20);
	   move_to(x,y);
	   set_heading_degrees(hd);
	   set_pen_width(2);
	   }
   turn_right_by_degrees(1);
   circle_draw(a+1,rad,n);
   }
}
void circle(double x,int y,double rad)
{
    move_to(x , y - rad);
	set_heading_degrees(90);
    circle_draw(0,rad,0);
}
void rectangle(int x, int y, int w, int h,int color)
	{
	set_pen_color(color);
	set_pen_width(6);
	move_to(x,y);
	draw_to((x+(w/2)),y);
	int x2=get_x_position();
	c_x=x2;
	draw_to((x+w),y);
	draw_to(x+w,(y+(h/2)));
	int y2=get_y_position();
	c_y=y2;
	draw_to(x+w,(y+h));
	draw_to(x,y+h);
	draw_to(x,y);
	circle(c_x,c_y,130);
	}
void clock_background()
	{
	rectangle(50,50,300,300,color::black);
	}
void section2()
	{
	print("Year: ");
	print(year());
	new_line();
	print("Month: ");
	print(month());
	new_line();
	print("Day: ");
	print(day());
	new_line();
	print("Hour: ");
	print(hour());
	if(ampm(ampm()))
		{
		print(" AM");
		}
	else
		{
		print(" PM");
		}
	new_line();
	print("Minute: ");
	print(minute());
	new_line();
	print("Second: ");
	print(second());
	new_line();
	}
void digital()
	{
	set_pen_color(color::black);
	set_font_size(40);
	move_to(50,400);
	write_string(hour());
	write_string(":");
	if(minute()>=10)
		{
		write_string(minute());
		}
	else if(minute()<10)
		{
		write_string("0");
		write_string(minute());
		}
	write_string(":");
	if(second()>=10)
		{
		write_string(second());
		}
	else if(second()<10)
		{
		write_string("0");
		write_string(second());
		}
	write_string(" ");
	if(ampm(ampm()))
		{
		write_string("AM");
		move_to(50,430);
		}
	else
		{
		write_string("PM");
		move_to(50,430);
		}
	write_string(day());
	write_string(day_ending(day()));
	write_string(" ");
	write_string(month_name(month()));
	write_string(" ");
	write_string(year());
	}
void hour_hand()
	{
	move_to(200,200);
	double hour_degree=30.0*((hour())+(minute())/60.0 +(second())/3600.0);
	set_heading_degrees(hour_degree);
	set_pen_width(6);
	set_pen_color(color::red);
	draw_distance(75);
	}
void minute_hand()
	{
	move_to(200,200);
	double minute_degree=(6.0 * ((minute()) + ((second()) / 60.0)));
	set_heading_degrees(minute_degree);
	set_pen_width(4);
	set_pen_color(color::blue);
	draw_distance(100);
	}
void second_hand()
	{
	move_to(200,200);
	double second_degree=(6.0*second());
	set_heading_degrees(second_degree);
	set_pen_width(2);
	set_pen_color(color::green);
	draw_distance(110);
	}
void main()
	{
	make_window(400,500,500,30);
	clock_background();
	section2();
	while(true)
		{
		digital();
		hour_hand();
		minute_hand();
		second_hand();
		wait(0.1);
		set_pen_color(color::white);
		set_pen_width(230);
		draw_point(c_x,c_y);
		draw_rectangle(0,375,500,200,color::white);
		}
	}
