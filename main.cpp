#include <iostream>
//#include "stdafx.h"
#include <cstring>
using namespace std;

const double PI = 3.1415926535897932384626433832799;

class shape {
    int abscissa, ordinate;

    public:
     shape();
     shape(int x, int y);
     virtual ~shape();

     void move(int x, int y);
     virtual void draw()=0;
};

shape::shape() : abscissa(0), ordinate(0){

}

shape::shape(int x, int y) : abscissa(x), ordinate(y){

}

shape::~shape(){

}

void shape::move(int x, int y){
    abscissa = x;
    ordinate = y;
}

class Circle : public shape {

float radius;

public:
 Circle(float rad);
 Circle(float rad, int newAbscissa, int newOrdinate);
 ~Circle();

 void setRadius(float newRadius);
 float getRadius() const;
 float getArea() const;
 float getPerimeter() const;
 int isEqual(Circle c) const;
 void setNewLocation(int newAbscissa, int newOrdinate);
 void draw(); 
};

Circle::Circle(float rad) : shape(), radius(rad){
    
}

Circle::Circle(float rad, int newAbscissa, int newOrdinate) : shape(newAbscissa, newOrdinate), radius(rad){
    
}

Circle::~Circle(){

}

void Circle::setRadius(float newRadius){
    radius = newRadius;
}

float Circle::getRadius() const{
    return radius;
}

float Circle::getArea() const{
    return PI*radius*radius;
}

float Circle::getPerimeter() const{
    return 2*radius*PI;
}

int Circle::isEqual(Circle c) const{
    return(c.getArea()==getArea());
}

void Circle::setNewLocation(int newAbscissa, int newOrdinate){
    move(newAbscissa, newOrdinate);
}

void Circle::draw(){
    cout<<"Круг с радиусом: " << radius <<endl << "Площадь: " << getArea() << endl <<
    "Периметр: " << getPerimeter() << endl;
}
int main (int argc, char* argv[]) {
Circle *c = new Circle(10);
shape *s;

s = c;

s->draw();
Circle c2 = Circle(10,11,34);
Circle c3 = Circle(10,11,34);
if(c2.isEqual(c3)){
    cout << "Окружности равны!" << endl;
} 
else {
    cout << "Окружности разные!" << endl;
} 
return 0;
}