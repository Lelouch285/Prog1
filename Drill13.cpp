#include "Simple_window.h"
#include "Graph.h"

int main()
{
	int max_width = 800;
	int max_height = 1000;
	Simple_window win{Point{100,100},max_width,max_height,"Ch. 13 Drill"};

	Lines grid;
	int x_size = 800;
	int x_grid = 100;

	for(int x = x_grid; x <= x_size; x+= x_grid){

		grid.add(Point{x,0}, Point{x,x_size});
		grid.add(Point{0,x}, Point{x_size,x});
	}

	win.attach(grid);

	Vector_ref<Rectangle> vr;

    for (int i = 0; i < x_size; i += y_size) 
    {
        vr.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        
        vr[rectangles.size() - 1].set_fill_color(Color::red);

        win.attach(rectangles[rectangles.size() - 1]);
    }

    Image kep1(Point(600,0),"kep1.jpeg");
    win.attach(kep1);
    Image kep2(Point(500,200),"kep2.jpeg");
    win.attach(kep2);
    Image kep3(Point(0,600),"kep3.jpeg");
    win.attach(kep3);
    win.wait_for_button();


	Image kep4 {Point{0,0}, "kep4.jpeg"};
  	kep4.set_mask(Point{300,200},100,100);
    win.attach(dog);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) 
        {
            win.wait_for_button();
            if (j<7)
            {
            	kep4.move(100, 0);
            }
            else kep4.move(-700, 100); 
		}
	}
}
