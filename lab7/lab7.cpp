#include "library.h"
const double pi = acos(-1.0);
int building_color(int n)
	{
	int color=make_color_hls((n/360.0),0.7,0.4);
	return color;
	}
int window_color(int n)
	{
	int color=make_color_hls((42.0/360.0),0.7,(n/100.0));
	return color;
	}
int car_color(int n)
	{
	int color=make_color_hls((n/360.0),0.5,0.5);
	return color;
	}
void semicircle_draw(int a, int rad)
{
   if(a<=180)
   {
   double arcd=2*pi * (1.0 / 360.0)*rad;
   note_position();
   draw_distance(arcd);
   turn_right_by_degrees(1);
   semicircle_draw(a+1,rad);
   }
}
void semicircle(double x,int y,double rad)
{
    move_to(x , y - rad);
	set_heading_degrees(0);
	start_shape();
    semicircle_draw(0,rad);
	fill_shape();
}
void circle_draw(int a, int rad)
{
   if(a<=360)
   {
   double arcd=2*pi * (1.0 / 360.0)*rad;
   note_position();
   draw_distance(arcd);
   turn_right_by_degrees(1);
   circle_draw(a+1,rad);
   }
}
void circle(double x,int y,double rad)
{
    move_to(x , y - rad);
	set_heading_degrees(90);
	start_shape();
    circle_draw(0,rad);
	fill_shape();
}
void drawcircle(int x, int y)
{
	int s = random_in_range(30, 75);
	int t = random_in_range(30, 75);
	int rand_red=random_in_range(0,100);
	if(rand_red%71 ==0)
		{
		int col= make_color_hls(0.0,0.6,0.9);
		set_pen_color(col);
		}
	else
		{
		int col= make_color_hls(131/360.0, s/100.0, t/100.0);
		set_pen_color(col);
		}
	int r = random_in_range(2, 9);
	set_pen_width(r);
	draw_point(x, y);	
}
void treebody(double n, int x,int y, int h, int  w)
{
	if (n > 0 )
	{
		int p = random_in_range(x-40, x + 40+w);
		int m = random_in_range(y-20-h-h,y-20-h);
		drawcircle(p,m);
		treebody(n - 0.5, x,y, h, w);
	}
}
void tree(int x, int y,int h,int w)
{
		fill_rectangle(x, y - h - 20, w, h, color::brown);
		treebody(380, x,y, h, w);
}
void trees(int n)
{
if(n>0)
	{
	int x=random_in_range(30,1000);
	tree(x,1010,50,10);
	trees(n-1);
	}
}
void draw_bush(double n, int x,int y, int h, int  w)
{
	if (n > 0 )
	{
		int p = random_in_range(x-20, x + 10+w);
		int m = random_in_range(y-20-h-h,y-20-h);
		drawcircle(p,m);
		draw_bush(n - 0.5, x,y, h, w);
	}
}
void bush(int x, int y,int h,int w)
{
		draw_bush(300, x,y, h, w);
}
void bushes(int n)
{
if(n>0)
	{
	int x=random_in_range(10,1000);
	bush(x,1050,50,10);
	bushes(n-1);
	}
}
void background(int win_x,int win_y,int time_bg,int y_build)
	{
	make_window(win_x,win_y);
	set_pen_color_hls(0.6,0.0+(time_bg/100.0),1.0);
	fill_rectangle(0,0,win_x,win_y);
	if(time_bg>=0 && time_bg <=40)
		{
		set_pen_color(color::white);
		circle(win_x-100,100,50);
		}
	if(time_bg>40 && time_bg <=90)
		{
		set_pen_color(color::yellow);
		circle(win_x-100,100,50);
		}
	fill_rectangle(0,y_build-10,win_x,win_y-y_build,color::light_green);
	fill_rectangle(0,y_build,win_x,win_y-y_build,color::dark_green);
	}
void draw_window(int x, int y, int w, int h,int color)
	{
	set_pen_width(30);
	fill_rectangle(x-1,y-1,w+2,h+2,color::black);
	set_pen_width(1);
	fill_rectangle(x,y,w,h,color);
	}
void building_windows(int x,int x1,int y,int y1,int w, int h, int color, int win_w, int win_h)
	{
	if(x<(w+x1-win_w-5))
		{
	draw_window(x,y,win_w,win_h,color);
	building_windows(x+(2*win_w),x1,y,y1,w,h,color,win_w,win_h);
		}
	else if(y<(y1-(4*win_h)))
		{
		building_windows(x1+5,x1,y+(3*win_h),y1,w,h,color,win_w,win_h);
		}
	else
		{
		return;
		}
	}
void curtains(int x, int y, int w, int h)
{
	fill_rectangle(x, y, w, h, color::black);
	set_pen_color(color::red);
	start_shape();
	move_to(x,y);
	note_position();
	move_to(x+10,y);
	note_position();
	move_to(x+4,y+14);
	note_position();
	move_to(x+10,y+h-1);
	note_position();
	move_to(x, y + h-1);
	note_position();
	set_pen_width(1);
	fill_shape();
	start_shape();
	move_to(x+w, y);
	note_position();
	move_to(x +w- 10, y);
	note_position();
	move_to(x + w-4, y + 14);
	note_position();
	move_to(x+w - 10, y + h - 1);
	note_position();
	move_to(x+w, y + h - 1);
	note_position();
	set_pen_width(1);
	fill_shape();
}

void building_windows1(int x,int x1,int y,int y1,int w, int h, int color, int win_w, int win_h)
	{
	int ran_cur=random_in_range(1,100);
	if(x<(w+x1-win_w-5))
		{
		if(ran_cur%2 ==0)
			{
		curtains(x,y,win_w,win_h);
			}
		else
			{
			draw_window(x,y,win_w,win_h,color);
			}
	building_windows(x+(2*win_w),x1,y,y1,w,h,color,win_w,win_h);
		}
	else if(y<(y1-(4*win_h)))
		{
		building_windows(x1,x1,y+(3*win_h),y1,w,h,color,win_w,win_h);
		}
	else
		{
		return;
		}
	}
void roof(double x,double y,double w, double h)
	{
	set_pen_color(color::brown);
	start_shape();
	move_to(x + (w/2.0), y-h-(0.4*h));
	note_position();
	move_to(x + (w/(20.0))+w, y - h);
	note_position();
	move_to(x - (w/20.0), y - h);
	note_position();
	fill_shape();
	}
void roof2(double x,double y,double w, double h)
	{
	set_pen_color(color::brown);
	start_shape();
	move_to(x,y-h);
	note_position();
	move_to(x+w,y-h);
	note_position();
	move_to(x+w-(w/6.0),y-h-20);
	note_position();
	int x1=get_x_position();
	int y1=get_y_position();
	move_to(x,y-h);
	note_position();
	move_to(x+(w/6.0),y-h-20);
	note_position();
	move_to(x+(w/6.0),y-h-20);
	note_position();
	draw_to(x1,y1);
	note_position();
	fill_shape();
	}
void window2(int x, int y, int w, int h)
	{
	building_windows1(x+15,x-5+15,y-h+5,y-105,w,h,color::blue,40,40);
	}
void house(int x,int y,int w,int h)
	{
	int rand_roof=random_in_range(0,1);
	fill_rectangle(x,y-h,w,h,color::sodium_d);
	if(rand_roof==0)
		{
		roof2(x,y,w,h);
		}
	else
		{
		roof(x,y,w,h);
		}
	if(h>110)
		{
		fill_rectangle(x+(w/2)-(20),y,40,-100,color::light_green);
		window2(x,y,w,h);
		}
	else
		{
		fill_rectangle(x+(w/2)-20,y,40,-45,color::light_green);
		window2(x,y,w,h);
		}
	}
void main_building(int x, int y, int w, int h)
	{
	int rbc=random_in_range(0,360);
	int rwc=random_in_range(0,100);
	int win_w=random_in_range(10,20);
	int win_h=random_in_range(10,20);
	fill_rectangle(x,y,w,-h,building_color(rbc));
	building_windows(x+5,x,y-h+5,y,w,h,window_color(rwc),win_w,win_h);
	}
void buildings(int x,int x1, int y,int n, int w)
	{
	int build_height=random_in_range(200,700);
	int build_width=random_in_range(200,300);
	int builorhouse=random_in_range(0,1);
	if(n>0 && w>x1)
		{
		if(builorhouse==0)
			{
			main_building(x,y,build_width,build_height);
			buildings(x+build_width+20,x1,y,n-1,w-build_width-(20*n)-x1);
			}
		if(builorhouse==1)
			{
			house(x+build_width+20,y,150,100);
			buildings(x+build_width+20,x1,y,n-1,w-build_width-(20*n)-x1);
			}
		}
	}
void road_stripes(int x,int y_build, int w)
	{
	int x_pos=get_x_position();
	if(w>x )
		{
		move_to(x,y_build + 100);
		draw_distance(10);
		road_stripes(x+20,y_build,w);
		}
	}
void road(int x, int y, int y_build)
	{
	fill_rectangle(0,y_build + 50,x,100,color::black);
	set_pen_color(color::yellow);
	move_to(0,y_build + 55);
	draw_to(x,y_build + 55);
	move_to(0,y_build + 145);
	draw_to(x,y_build + 145);
	road_stripes(0,y_build,x);
	}
void truck_car(int x, int y,int color)
	{
	set_pen_color(color);
	fill_rectangle(x,y,40,27);
	fill_rectangle(x+42,y+27-20,20,20);
	fill_rectangle(x+30,y+27,30,-10);
	set_pen_color(color::light_blue);
	fill_rectangle(x+45,y+27-20+2,10,7);
	set_pen_width(3);
	set_pen_color(color::dark_grey);
	circle(x+40+8,y+27,4);
	circle(x+40+5-20,y+27,5);
	circle(x+40+5-40,y+27,5);
	}
void modern_car(int x, int y, int color)
	{
	set_pen_width(3);
	set_pen_color(color);
	semicircle(x,y,35);
	set_pen_color(color::dark_grey);
	circle(x+10,y-30,7);
	circle(x+55,y-30,7);
	set_pen_color(color::light_blue);
	semicircle(x+15,y-25,20);
	fill_rectangle(x+35,y-66,5,26,color);
	}
void cars(int num_car, int y_build, int x, int w )
	{
	int car_type=random_in_range(0,1);
	int car_co=car_color(random_in_range(1,360));
	//1 is modern and 0 is truck
	if(x<w)
		{
	if(num_car>0 && car_type==1)
		{
	modern_car(x,y_build+80,car_co);
	cars(num_car-1,y_build,x+100,w);
		}
	if(num_car>0 && car_type==0)
		{
	truck_car(x,y_build+70,car_co);
	cars(num_car-1,y_build,x+100,w );
		}
		}
	}
void main()
	{
	int time_bg=random_in_range(0,90);
	int num_buil=random_in_range(3,6);
	int y_build=800;
	int win_x=1000;
	int win_y=1000;
	int num_car=random_in_range(4,15);
	background(win_x,win_y,time_bg,y_build);
	buildings(30,30,800,num_buil,1000);
	road(win_x,win_y-25,y_build-25);
	cars(num_car,y_build,0,1000);
	int tree_num=random_in_range(2,15);
	int bush_num=random_in_range(2,5);
	trees(tree_num);
	bushes(bush_num);

	}
