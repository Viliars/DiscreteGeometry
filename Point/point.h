#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class Bool;

class Point {
public:
    long double x,y;
    bool operator != ( const Point& obj) const { return !((x==obj.x)&&(y==obj.y)); }
    bool operator == ( const Point& obj) const { return (x==obj.x)&&(y==obj.y); }
    Point operator - ()
    {
        Point bufer;
        bufer.x=-x;
        bufer.y=-y;
        return bufer;
    }
    void SetPoint ( HDC dc ) {
        //HPEN p1=CreatePen(PS_SOLID,2,RGB(255,255,255)); //white
        SetPixel(dc,x,y,RGB(255,255,255));
        SetPixel(dc,x+1,y,RGB(255,255,255));
        SetPixel(dc,x-1,y,RGB(255,255,255));
        SetPixel(dc,x,y+1,RGB(255,255,255));
        SetPixel(dc,x,y-1,RGB(255,255,255));

        SetPixel(dc,x+3,y,RGB(255,255,255));
        SetPixel(dc,x-3,y,RGB(255,255,255));
        SetPixel(dc,x,y+3,RGB(255,255,255));
        SetPixel(dc,x,y-3,RGB(255,255,255));
    }
    Point& operator += (const int& f) { x+=f; y+=f; return *this; }
    Point& operator = (const Point& obj) { x=obj.x; y=obj.y; return *this; }
    Point operator * ( const long double mul) { Point bufer; bufer.x=x*mul; bufer.y=y*mul; return bufer; }
    friend std::istream& operator >> ( std::istream& os, Point& obj);
};

std::istream& operator >> ( std::istream& os, Point& obj)
{
    os>>obj.x>>obj.y;
    return os;
}

#endif // POINT_H_INCLUDED
