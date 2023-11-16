/**
* CSES - Polygon Area
* Tematica : Geometria : Area de un Poligono
* Idea: Dado los puntos que conforman los vertices de un poligono hallar el doble
* del area de este
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 1000010
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

struct Point{
    int X,Y;
    Point(int _x=0,int _y=0): X(_x), Y(_y){}
};

struct Polygon {
    vector<Point> points;
    Polygon(vector<Point> _points) { this->points = _points;}
    int area() {
        int res = 0;
        for (unsigned i = 0; i < points.size(); i++) {
            Point p = i ? points[i - 1] : points.back();
            Point q = points[i];
            res += (p.X - q.X) * (p.Y + q.Y);
        }
        return (res > 0 ? res : -1*res) ;
    }
};

istream & operator>>(istream & in, Point & p){
    in>>p.X>>p.Y;
    return in;
}

int npoint;
Point p;
vector<Point> points;


signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    cin>>npoint;
    REP(i,0,npoint){
        cin>>p;
        points.push_back(p);
    }

    Polygon polygon (points);

    cout<<polygon.area()<<ENDL;

    return 0;
}
