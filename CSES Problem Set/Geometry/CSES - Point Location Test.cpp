/**
* CSES - Point Location Test
* Tematica : Geometria
* Idea: Dados tres puntos decir como se encuentra en tercer punto con respecto a
* la linea que se forma entre los dos primeros puntos.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 25
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

struct Point{
    int X, Y;
    Point(int x=0, int y=0){
        this->X = x;
        this->Y = y;
    }
};

inline double crossProduct(Point a, Point b, Point c){
    return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
}

inline bool isLeft(Point a, Point b, Point c){
    return (crossProduct(a, b, c) > 0);
}
inline bool isCollinear(Point a, Point b, Point c){
    return (crossProduct(a, b, c) == 0);
}

istream & operator>>(istream & in, Point & p){
    in>>p.X>>p.Y;
    return in;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    Point p1,p2,p3;
    int cases;

    cin>>cases;

    while(cases--){
        cin>>p1>>p2>>p3;
        if(isLeft(p1,p2,p3)) cout<<"LEFT"<<ENDL;
        else if(isCollinear(p1,p2,p3)) cout<<"TOUCH"<<ENDL;
        else cout<<"RIGHT"<<ENDL;
    }


    return 0;
}
