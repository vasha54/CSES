/**
* CSES - Line Segment Intersection
* Tematica : Geometria : Interseccion de lineas
* Idea: Dados dos segmentos definidos por sus puntos extremos definir si se
* intersectan o no
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

inline bool oppositeSides(Point a, Point b, Point c, Point d){
    return (isLeft(a, b, c) != isLeft(a, b, d));
}

inline bool isBetween(Point a, Point b, Point c){
    return (min(a.X, b.X) <= c.X && c.X <= max(a.X, b.X) && min(a.Y, b.Y) <= c.
Y && c.Y <= max(a.Y,b.Y));
}

inline bool intersect(Point a, Point b, Point c, Point d){
    if (isCollinear(a, b, c) && isBetween(a, b, c)) return true;
    if (isCollinear(a, b, d) && isBetween(a, b, d)) return true;
    if (isCollinear(c, d, a) && isBetween(c, d, a)) return true;
    if (isCollinear(c, d, b) && isBetween(c, d, b)) return true;
    return (oppositeSides(a, b,c, d) && oppositeSides(c, d, a, b));
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

    Point p1,p2,p3,p4;
    int cases;

    cin>>cases;

    while(cases--){
        cin>>p1>>p2>>p3>>p4;
        if(intersect(p1,p2,p3,p4)) cout<<"YES"<<ENDL;
        else cout<<"NO"<<ENDL;
    }
    return 0;
}
