// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>

class point {
  public:
    //default consructor sets point to 0,0
    point() { x=0; y=0; angle = 0; }
    
    //manually assign point
    point(int xin, int yin) { x=xin; y=yin; angle = 0; }
    
    //other constructors
    point(const point &p) { x = p.x; y = p.y; angle = p.angle; }
    point &operator=(const point &p) { x = p.x; y = p.y; angle = p.angle; return *this; }
    
    
    //get angle between this point and another
    double get_angle(point &p) {
        //check to make sure the angle won't be "0"
        if(p.x == this->x) { return 0; }
        
        //cast to double, or risk losing precision
        return( atan( double(p.y - this->y) / double(p.x - this->x) ) );
    }

    //for sorting based on angles
    bool operator<(const point &p) const {
        return(angle < p.angle);
    }

    
    //and then there's these things
    void set_x(int xin) { x = xin; }
    void set_y(int yin) { y = yin; }
    void set_angle(double d) { angle = d; }
    
    int get_x() const { return x; }
    int get_y() const { return y; }
    double get_angle() const { return angle; }
  
  private:
    int x;
    int y;
    double angle;
};

//-----------------------------------------------------------------------------
    
//makes printing points easier
std::ostream &operator<<(std::ostream &os, const point &p) {
    os << "x: " << p.get_x() << "\ty: " << p.get_y() << "\tangle: " << p.get_angle();
    return os;
}

//=============================================================================

int main()
{
    //create a vector for points - vectors can use std::sort
    std::vector<point> points;
   
    point new_p(0, 0);
    for(int i=0; i<10; i++) {
        //fill the array with some random points
        //your actual data goes here - if you are using random points, don't
        //forget to seed the rng
        
        points.push_back(point(rand() % 100, rand() % 100));
    }
    
    
    //pick a random point to be the center
    //your data also goes here - the center doesn't have to be in the list
    point center = points[2];
    
    std::cout << "center\n" << center << std::endl << std::endl;
    
    //sort all points by polar angle
    //be sure to use &references, otherwise your changes won't go through
    for(point &p : points) {
        double angle = center.get_angle(p);
        p.set_angle(angle);
    }

    //sort the points using overloaded < operator
    std::sort(points.begin(), points.end());


    //tadaa!
    for(point &p : points) {
        std::cout << p << std::endl;
    }
}

