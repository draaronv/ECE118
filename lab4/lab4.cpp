#include "library.h"
const double g=32.174;
const double pi = acos(-1.0);
int window_width=1000;
int window_height=1000;
int randomp=random_in_range(0,1000);
int bunk_x=1000;
bool c_float(float x, float y, float epsilon = 0.00001f){
   if(fabs(x - y) < epsilon)
      return true; //they are same
      return false; //they are not same
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
double projectile_height(double v, double t, double d1)
	{
	double ra= ((d1*pi)/180.0);
	double h = (v*t*cos(ra))-((0.5)*g*t*t);
	return h;
	}
double projectile_distance(double v, double t , double d1)
	{
	double ra= ((d1*pi)/180.0);
	double distance=v*t*sin(ra);
	return distance;
	}
void trajectory_check2(double v, double t, double d1,double initial_x, double initial_y)
	{
	if(!(c_float(0,t)))
		{
		trajectory_check2(v,t-0.001,d1,initial_x,initial_y ) ;
		double x =(projectile_distance(v,t,d1))+initial_x;
		double y=(window_height - projectile_height(v,t,d1))-(window_height - initial_y) ;
		double distance=projectile_distance(v,t,d1);
		double height=projectile_height(v,t,d1);
		double bunker_x=bunk_x;
		double bunker_y=randomp;
		double distance_from_bunker=sqrt(((x - bunker_x)*(x - bunker_x))+((y - bunker_y)*(y - bunker_y)));
		if(distance_from_bunker<100)
			{
			move_to(300,300);
			write_string("You won");
			return;
			}
		else if(distance_from_bunker>100)
			{
			move_to(300,300);
			write_string("You won");
			return;
			}
		}
	}
void trajectory_check1(double v, double t, double d1,double initial_x, double initial_y)
	{
	if(!(c_float(0,t)))
		{
		trajectory_check1(v,t-0.001,d1,initial_x,initial_y ) ;
		set_pen_color(color::red);
		set_pen_width(10);
		double x=get_x_position();
		double y=get_y_position();
		double distance=projectile_distance(v,t,d1);
		double height=projectile_height(v,t,d1);
		double bunker_x=bunk_x;
		double bunker_y=randomp;
		double distance_from_bunker=sqrt(((x - bunker_x)*(x - bunker_x))+((y - bunker_y)*(y - bunker_y)));
		if(distance_from_bunker>100)
			{
			double pos_x =(projectile_distance(v,t,d1))+initial_x;
			double pos_y=(window_height - projectile_height(v,t,d1))-(window_height - initial_y) ;
			draw_point(pos_x,pos_y);
			return;
			}
		}
	}
void cannon(int x, int y, int rad, int ang, double v1)
	{
	set_pen_width(4);
	circle(x,y,rad);
	// Converts degrees to radians since it is easier when drawing the first and last line of the canon
	double w = ((ang)-2)*pi * (1.0/180.0);
	set_heading_degrees(0);
	move_to(x + (rad * sin(w)), y - (rad * cos(w)));
	turn_right_by_radians(w);
	draw_distance(3.7 * rad);
	set_heading_degrees(ang-90);
	draw_distance((1.25 * rad)/2.0);
	double x1=get_x_position();
	double y2=get_y_position();
	draw_distance((1.25 * rad)/2.0);
	set_heading_degrees(ang-175.25);
	draw_distance(6.5 * rad);
	set_heading_degrees(ang-270);
	draw_distance(2 * rad);
	draw_to(x - (rad * sin(w)), y + (rad * cos(w)));
	trajectory_check1(v1,12,ang,x1, y2);
	trajectory_check2(v1,12,ang,x1, y2);
	}
void bunker(int x, int y)
	{
	circle(x,y,100);
	}
void game(int n)
	{
	make_window(window_width,window_height);
	bunker(bunk_x,randomp);
	if (n<3)
		{
		print("Please enter the initial velocity(0- 250): ");
		double v1=read_double();
	if(v1<0)
		{
		new_line();
		print("Try Again");
		new_line();
		game(n-1);
		}
		print("Angle of the cannon(0-90):");
		double d1=read_double();
	if(d1<0)
		{
		new_line();
		print("Try Again");
		new_line();
		game(n-1);
		}
		cannon(60,970,30,90-d1,v1);
		}
	game(n+1);
	return;
	}
void main()
	{
	print("Welcome to the Cannon Game");
	new_line();
	game(0);
	}
