#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int,int);
        Point(const Point&);
        virtual ~Point();

        Point& operator= (const Point&);
        bool operator== (const Point&);

        int x() const;
        int y() const;
        void placer(int,int);

    protected:

    private:
        int m_x;
        int m_y;
};

#endif // POINT_H
