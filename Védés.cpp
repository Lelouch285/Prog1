//Ch12.cpp
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {

	Point pont{ 100,100 };

	int xmaxi = 600;
	int ymaxi = 400;

	Simple_window win{ pont,xmaxi,ymaxi,"Ablak" };

	Axis xa{ Axis::x, Point{70,349}, 400, 23, "x axis" };
	Axis ya{ Axis::y, Point{25,348}, 399, 17, "y axis" };

	Function szinusz { sin,0,50,Point{20,150},1000,20,40 };

	Polygon poly;
	poly.add(Point{ 120, 160 });
	poly.add(Point{ 250, 200 });
	poly.add(Point{ 10, 200 });
	poly.set_style(Line_style(Line_style::dash,4));
	poly.set_color(Color::blue);

	Rectangle rec{ Point{350,250}, 110, 70 };
	rec.set_fill_color(Color::cyan);

	Text proba{ Point{420, 200}, "teszt" };
	proba.set_font_size(55);
	

	Image kep1 {Point{100,50},"kep1.jpeg"};
        
  
	Circle kor{ Point{350,275}, 50 };
	kor.set_fill_color(Color::red);
	
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);

	win.attach(e);
	win.attach(xa);
	win.attach(ya);
	win.attach(szinusz);
	win.attach(poly);
	win.attach(rec);
	win.attach(proba);
	win.attach(kor);
	win.attach(kep1);
	win.wait_for_button();
}



// Ch13.cpp

#include "Simple_window.h"
#include "Graph.h"

int main()
{

//1
	int max_width = 800;
	int max_height = 1000;
	Simple_window win{Point{100,100},max_width,max_height,"Ch. 13 Drill"};


//2
	Lines grid;
    int grid_max = 800;
    int grid_size = 100;
    for (int i = grid_size; i<=grid_max; i+=grid_size) {
        grid.add(Point(i,0),Point(i,grid_max));
        grid.add(Point(0,i),Point(grid_max,i));
    }
    win.attach(grid);
//3
	Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i)
    {
    	vr.push_back(new Rectangle(Point{i*grid_size, i*grid_size}, grid_size, grid_size));
    	vr[vr.size()-1].set_fill_color(Color::red);
    	win.attach( vr[vr.size() -1] );
    }
//4
   
    int kep_m = 200;

    Image kep1(Point(600,200),"kep1.jpeg");
    kep1.set_mask(Point(0,200), kep_m, kep_m);
    win.attach(kep1);

    Image kep2(Point(200,600),"kep1.jpeg");
    kep2.set_mask(Point(0,200), kep_m, kep_m);
    win.attach(kep2);

    Image kep3(Point(400,0),"kep1.jpeg");
    kep3.set_mask(Point(0,200), kep_m, kep_m);
    win.attach(kep3);

    win.wait_for_button();

	int kep_m100=100;
    Image pic_round(Point(0,0),"badge.jpg");
    pic_round.set_mask(Point(200,0),kep_m100,kep_m100);
    win.attach(pic_round);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		win.wait_for_button();
    		if (j < 7) pic_round.move(100,0);
    		else pic_round.move(-700,100);
    	}
    }
}
