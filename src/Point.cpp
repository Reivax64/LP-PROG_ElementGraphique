#include "Point.h"

Point::Point():
    m_x(0),
    m_y(0)
{
}

Point::Point(int x,int y):
    m_x(x),
    m_y(y)
{
}

Point::Point(const Point& p):
    m_x(p.x()),
    m_y(p.y())
{
}

Point::~Point()
{
    //dtor
}

int Point::x() const{
    return this->m_x;
}

int Point::y() const{
    return this->m_y;
}

void Point::placer(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

Point& Point::operator= (const Point& p){
    if(&p != this){
        this->placer(p.x(),p.y());
    }
    return *this;
}

bool Point::operator== (const Point& p){
    return (this->x() == p.x() && this->y() == p.y());
}
