/*
Автор: Михаил Притугин 241 группа
МГУ ВМК 17.02.2018-19.02.2018
*/
#define _WIN32_WINNT 0x0500
#include "windows.h"
#include <iostream>
#include <cmath>
#include "point.h"
#include "func.h"
#include "system.h"
#include <string>
#include <fstream>
#include <conio.h>
#include "geom.h"
#include <algorithm>
#include <ctime>
using namespace std;
Point answer;
bool flag;
int main(){
   /* System var(2);
     // refresh
        cin>>var;
        var.make();
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    UpdateWindow(myconsole);
     // main
      var.SetC(mydc);
      var.SetLine(mydc);
      SetA(mydc,var.a);
      // end main
      Prob();
      cout<<var;
    getch();
     ReleaseDC(myconsole, mydc);
    cin.ignore();
*/
/*
   ifstream in("IN.txt", ios_base::in);
   ofstream out("OUT.txt", ios_base::out | ios_base::trunc );
   out.precision(80);
   string str;
     Point a,b,c,d;
  while(in>>str>>a>>b>>c>>d) {
      if(a==b&&b==c&&c==d) { out<<str<<" "<<"YES "<<a.x<<" "<<a.y<<endl; return 0; }
     if(a==b&&c==d&&a!=c) { out<<str<<" "<<"NO "<<endl; return 0; }
   if(ans(a,b,c,d)) {
        if(flag) { out<<str<<" "<<"YES "<<endl; }
        else { out<<str<<" "<<"YES "<<answer.x<<" "<<answer.y<<endl; }
        }
    else { out<<str<<" "<<"NO "<<endl; }
   flag=0;
  }
  */
int n=20000;
srand (time(NULL));
//time_t start=time(NULL);
for(int i=0;i<n;i++){
double p1 = (double)(rand()%500/100.0);
double p2 = (double)(rand()%500/100.0);
a[i].x=p1;
a[i].y=p2;
a[i].id=i;
}
cout<<endl;
//time_t end=time(NULL);
//cout<<"Time of random generation = "<<(end-start)<<endl;
sort (a, a+n, &cmp_x);
mindist = 1E20;
rec (0, n-1);
cout<<"A: "<<a[ansa].x<<" "<<a[ansa].y<<" B: "<<a[ansb].x<<" "<<a[ansb].y;
return 0;
}
