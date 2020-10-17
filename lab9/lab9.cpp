#include "library.h"
#include <fstream>
int lenmonth(int month)
{
	if (month == 1)
		{
		return 31;
		}
	else if (month == 2) 
		{
		return 28;
		}
	else if (month == 3) 
		{
		return 31;
		}
	else if (month == 4) 
		{
		return 30;
		}
	else if (month == 5)
		{
		return 31;
		}
	else if (month == 6) 
		{
		return 30;
		}
	else if (month == 7) 
		{
		return 31;
		}
	else if (month == 8) 
		{
		return 31;
		}
	else if (month == 9) 
		{
		return 30;
		}
	else if (month == 10) 
		{
		return 31;
		}
	else if (month == 11) 
		{
		return 30;
		}
	else if (month == 12)
		{
		return 31;
		}
}
int day_year(int d, int m)
{
	if (m == 1)
		{
		return d;
		}
	else if (m > 1 && m < 13)
	{
		int num = lenmonth(m - 1) + day_year(d, m - 1);
		return (num);
	}
}
void months(int x, int y, int a, int b, int c, int d)
{
set_pen_color(color::dark_grey);
string months[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
for(int i=0;i<12;i++)
	{
	move_to(a + (2*i+1)*x / 24, c + y + 14);
	write_string(months[i], direction::center);
	}
}
void y_axis(int x, int y, int a, int b, int c, int d)
{
for(int i=1;i<=12;i++)
	{
	move_to(a + ((i * x) / 12), c);
	draw_to(a + ((i* x) / 12), c + y);
	}
}
void x_axis_1(int x, int y, int a, int b, int c, int d)
{
for(int i=1;i<=10;i++)
	{
	move_to(a, c + ((i*y) / 10));
	draw_to(a + x, c + ((i*y) / 10));
	move_to(a-5, c + ((i*y) / 10));
	write_string(100-(i*10), direction::west);
	}
	move_to(a - 5, c);
	write_string(100, direction::west);

}
void grid_1(int x, int y, int a, int b, int c, int d)
{
	set_pen_color(color::dark_grey);
	move_to(a, c);
	draw_to(x + a, c);
	draw_to(x + a, y+c);
	draw_to(a, y +c);
	draw_to(a, c);
	y_axis(x, y, a, b, c, d);
	x_axis_1(x, y, a, b, c, d);
}
void x_axis_2(int x, int y, int a, int b, int c, int d)
{
for(int i=1;i<=7;i++)
	{
	move_to(a, c + ((i*y) / 7));
	draw_to(a + x, c + ((i*y) / 7));
	move_to(a - 5, c + ((i*y) /7));
	write_string(70-(i*10), direction::west);
	}
	move_to(a - 5, c);
	write_string(70, direction::west);
}
void grid_2(int x, int y, int a, int b, int c, int d)
{
set_pen_color(color::dark_grey);
	move_to(a, c);
	draw_to(x + a, c);
	draw_to(x + a, y + c);
	draw_to(a, y + c);
	draw_to(a, c);
	y_axis(x, y, a, b, c, d);
	x_axis_2(x, y, a, b, c, d);
}
void pencolor(int const col)
{
	if (col == 1) 
		set_pen_color(color::red);
	if (col == 2) 
		set_pen_color(color::blue);
	if (col == 3) 
		set_pen_color(color::orange);
	if (col == 4) 
		set_pen_color(color::green);
}
void averagetemp(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
			break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num == 242) || (num==302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
		else if ((num != 1) && (avg != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (avg*5.1)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
void minimum(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
			break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num== 242) || (num == 302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
		else if ((num != 1) && (min != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (min*5.1)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (min*5.1)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (min*5.1)) + c);
			checker = true;
		}
	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
void maximum(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
			break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num == 242) || (num == 302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
		else if ((num != 1) && (max != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (max*5.1)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (max*5.1)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (max*5.1)) + c);
			checker = true;
		}
	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
void snow(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
			break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num == 242) || (num == 302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
		else if ((num != 1) && (snow != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (snow*5.1)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (snow*5.1)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (snow*5.1)) + c);
			checker = true;
		}

	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
void rain(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
			break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num == 242) || (num == 302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);
			checker = true;
		}
		else if ((num != 1) && (rain != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (rain*7.29)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (rain*7.29)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (rain*7.29)) + c);
			checker = true;
		}
	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
void wind(int x, int y, int a, int c, int d, string p, int col)
{
	pencolor(col);
	ifstream data(p);
	if (data.fail())
	{
		cout << "An error occurred opening the file";
		exit(1);
	}
	bool checker = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		data >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (data.fail())
		{
		break;
		}
		double num = day_year(day, month);
		if ((num == 90) || (num == 242) || (num == 302))
		{
			move_to((num*2.20) + a, (y - (avg*5.1)) + c);

			checker = true;
		}
		else if( (num != 1) && ( wind != -1) && (checker == false))
		{
			draw_to(((num)*2.2) + a, (y - (wind*7.29)) + c);
			checker = false;
		}
		else if (checker == true)
		{
			move_to((num*2.20) + a, (y - (wind*7.29)) + c);
			checker = false;
		}
		else
		{
			move_to((num*2.20) + a, (y - (wind*7.29)) + c);
			checker = true;
		}
	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	data.close();
}
int options1()
	{
	int opt;
	cout << "What would you like to see?" << endl;
	cout<< "1: Average Temperature" << endl;
	cout<< "2: Minimum and Maximum Temperatures" << endl;
	cout<< "3: Inches of Snow" << endl;
	cout<< "4: Amount of Precipitation" << endl;
	cout<<"5: Wind Speed" << endl;
	cin >> opt;
	return opt;
	}
int options2()
	{
	int opt;
	cout <<"What color do you want the line to be?" << endl;
	cout <<"1: Red" << endl;
	cout <<"2: Blue" << endl;
	cout <<"3: Orange" << endl;
	cout <<"4: Green" << endl;
	cin >> opt;
	return opt;
	}
void user(int const x, int const y, int const a, int const b, int const c, int const d, string p)
{
switch(options1())
	{
case 1:
	{
		make_window(x + a + b, y + c + d);set_caption(p);
		months(x, y, a, b, c, d);
		grid_1(x, y, a, b, c, d);
		averagetemp(x, y, a, c, d,p,options2());
		months(x, y, a, b, c, d);
		break;
	}
case 2:
	{
		make_window(x + a + b, y + c + d);set_caption(p);
		grid_1(x, y, a, b, c, d);
		months(x, y, a, b, c, d);
		minimum(x, y, a, c, d,p,options2());
		maximum(x, y, a, c, d,p,options2());
		months(x, y, a, b, c, d);
		break;
	}
case 3:
	{
		make_window(x + a + b, y + c + d);set_caption(p);
		grid_1(x, y, a, b, c, d);
		months(x, y, a, b, c, d);
		snow(x, y, a, c, d,p,options2());
		months(x, y, a, b, c, d);
		break;
	}
case 4:
	{
		make_window(x + a + b, y + c + d);set_caption(p);
		grid_2(x, y, a, b, c, d);
		months(x, y, a, b, c, d);
		rain(x, y, a, c, d,p,options2());
		months(x, y, a, b, c, d);
		break;
	}
case 5:
	{
		make_window(x + a + b, y + c + d);set_caption(p);
		grid_2(x, y, a, b, c, d);
		months(x, y, a, b, c, d);
		wind(x, y, a, c, d,p,options2());
		months(x, y, a, b, c, d);
	break;
	}
default:
		{
		cout << "You should try again"<<endl;
		user(x,y,a,b,c,d,p);
		}
	}
}
void main()
{
	int const x1 = 50;
	int const y1 = 30;
	int const t1 = y1;
	int const z1 =50;
	double const w = 810;
	double const h = 500;
	string filename= open_file_pop_up("","", "Select the file");
	user(w,h,x1,y1,t1,z1,filename);
}
