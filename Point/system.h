#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

class System {
     int rez;
     long double bufer;
    // long double mera;
     //long double meraAC;
    // long double meraBC;
public:
    Point a,b,c;
    void make () {
    bufer=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    //mera=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    //meraAC=sqrt(sqr(a.x-c.x)+sqr(a.y-c.y));
    //meraBC=sqrt(sqr(b.x-c.x)+sqr(b.y-c.y));
    if(bufer>0) rez=1;
    if(bufer==0) rez=0; //  доработка
    if(bufer<0) rez=-1;
    }
    System(int x): rez(x) { }
    void SetLine(HDC dc) {
    HPEN p1=CreatePen(PS_SOLID,2,RGB(255,255,255)); //white
    p1=(HPEN)SelectObject(dc,p1);
    SetPixel(dc,a.x,a.y,RGB(255,255,255));
    SetPixel(dc,a.x+5,a.y,RGB(255,255,255));
    SetPixel(dc,a.x-5,a.y,RGB(255,255,255));
    SetPixel(dc,a.x,a.y+5,RGB(255,255,255));
    SetPixel(dc,a.x,a.y-5,RGB(255,255,255));
    MoveToEx(dc,a.x,a.y,NULL);
    LineTo(dc,b.x,b.y);
    }
    void SetC(HDC dc) { c.SetPoint(dc); }
     friend std::ostream& operator<<(std::ostream& os, const System& obj);
     friend std::istream& operator>> (std::istream& os , System& obj);
};

std::ostream& operator<<(std::ostream& os, const System& obj)
{
    switch ( obj.rez )
    {
       case 1: { os<<"Left"<<std::endl; break; }
       case 0: { os<<"On Line";
             if(obj.a==obj.c) os<<" at the point A"<<std::endl;
             else
                  if(obj.b==obj.c) os<<" at the point B"<<std::endl;
                  else
                        os<<std::endl; break; }
       case -1: { os<<"Right"<<std::endl; break;  }
       case 2: { os<<"A: "<<obj.a.x<<" "<<obj.a.y<<std::endl;
             os<<"B: "<<obj.b.x<<" "<<obj.b.y<<std::endl;
             os<<"C: "<<obj.c.x<<" "<<obj.c.y<<std::endl;      }
    }
    return os;
}

std::istream& operator>> (std::istream& os , System& obj)
{
    os>>obj.a;
    os>>obj.b;
    os>>obj.c;
    return os;
}


#endif // SYSTEM_H_INCLUDED
