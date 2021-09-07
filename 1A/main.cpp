#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{ 
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1 > x2)
    {
        double t1=x1,t2=y1;
        x1=x2;
        y1=y2;
        x2=t1;
        y2=t2;
    }
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(10);
    double X1,X2;
    double D = sqrt(((2*x1*y2*y2 - 2*x2*y1*y1))*((2*x1*y2*y2 - 2*x2*y1*y1))- 4*(y2*y2-y1*y1)*(x1*x1*y2*y2-x2*x2*y1*y1));
    X1=((2*x1*y2*y2 - 2*x2*y1*y1)+D)/(2*((y2*y2-y1*y1)));
    X2=((2*x1*y2*y2 - 2*x2*y1*y1)-D)/(2*((y2*y2-y1*y1)));
    if( X1 > x1 && X1 < x2)
    {
        cout << X1 << '\n';
        return 0;
    }
    else
    {
        cout << X2 << '\n';
        return 0;
    }
    return 0;
}