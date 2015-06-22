// derived classes
#include <iostream>
using namespace std;


class Polygon{
  protected:
    int width, height;

  public:
    Polygon();
    Polygon(int width, int height);
    virtual ~Polygon(){};

    void set_values(int a, int b);
    int get_width();
    int get_height();
    virtual int area()=0;

 };


class Rectangle: public Polygon{
  public:
     virtual int area ();
 };


class Triangle: public Polygon{
  public:
	virtual int area ();
  };
