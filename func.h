#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
using namespace std;
typedef long double ld;
extern Point answer;
extern bool flag;
void Prob ( ) {
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}


const double EPS = 1E-9;
void SetA(HDC dc,const Point& ob)
{
    Point obj=ob;
    obj+=10;
    MoveToEx(dc,obj.x,obj.y,NULL);
    LineTo(dc,obj.x+8,obj.y-24);
    LineTo(dc,obj.x+16,obj.y);
    MoveToEx(dc,obj.x+4,obj.y-8,NULL);
    LineTo(dc,obj.x+13,obj.y-8);
}

inline ld det (ld a, ld b, ld c, ld d) {
	return a * d - b * c;
}

inline bool between (ld a, ld b, ld c) {
	return min(a,b) <= c + EPS && c <= max(a,b) + EPS;
}

inline bool inter (ld a, ld b, ld c, ld d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool ans (Point a, Point b, Point c, Point d) {
	ld A1 = a.y-b.y,  B1 = b.x-a.x,  C1 = -A1*a.x - B1*a.y;
	ld A2 = c.y-d.y,  B2 = d.x-c.x,  C2 = -A2*c.x - B2*c.y;
	ld zn = det (A1, B1, A2, B2);
	if (zn != 0) {
		answer.x = - det (C1, B1, C2, B2) * 1. / zn;
		answer.y = - det (A1, C1, A2, C2) * 1. / zn;
		return between (a.x, b.x, answer.x) && between (a.y, b.y, answer.y)
			&& between (c.x, d.x, answer.x) && between (c.y, d.y, answer.y);
	}
	else {
        flag=1;
		return det (A1, C1, A2, C2) == 0 && det (B1, C1, B2, C2) == 0
			&& inter (a.x, b.x, c.x, d.x)
			&& inter (a.y, b.y, c.y, d.y); }
}
#endif // FUNC_H_INCLUDED
