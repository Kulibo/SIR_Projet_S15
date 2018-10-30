#include "mcqueen.hpp"
#include <iostream>
#include <random>
#include <cmath>

struct Point
{
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}
};

std::ostream& operator<<(std::ostream& flux, Point p)
{
    flux << p.x << " " << p.y << std::endl;
    return flux;
}

Point operator+(const Point& p1, const Point& p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(const Point& p1, const Point& p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

double norme(const Point p1){
    return sqrt(p1.x*p1.x + p1.y*p1.y);
}

int main(){
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    Point p1(0.0, 0.0);
    Point p2(0.0, 2.0);
    Point p3(2.0, 0.0);
    Point p4(2.0, 2.0);
    Mcqueen<Point> learner(4, &norme); 
    for(unsigned int i(0); i < 100; i++){
        learner.update(p1 + Point( distribution(generator), distribution(generator)));
        learner.update(p2 + Point( distribution(generator), distribution(generator)));
        learner.update(p3 + Point( distribution(generator), distribution(generator)));
        learner.update(p4 + Point( distribution(generator), distribution(generator)));
    }
    
    for(auto proto : learner.prototypes())
    {
        std::cout << proto << "\n";
    }
    std::cout << std::endl;
}
