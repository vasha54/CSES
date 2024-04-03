/**
* CSES - Point in Polygon
* Temática: Geometria Puntos con respecto a un Poligono
* Idea: Dado un poligono y una colección de puntos  determinar como se encuentran dichos puntos
* con respecto al polígono
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
using namespace std;

enum Positions {INSIDE,OUTSIDE,BOUNDARY};

struct Point {
   int X, Y;
   Point(int _x = 0, int _y = 0) : X(_x), Y(_y) {}
};

struct Vector {
   double x, y;
   Vector(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

Vector toVec(Point a, Point b){ return Vector(b.X-a.X, b.Y-a.Y); }
double dist(Point p1, Point p2){ return hypot(p1.X-p2.X, p1.Y-p2.Y); }
double dot(Vector a, Vector b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(Vector v) { return v.x * v.x + v.y * v.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
bool ccw(Point p, Point q, Point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
bool isCollinear(Point a, Point b, Point c) { return (cross(toVec(a, b), toVec(b, c)) == 0); }
bool isBetween(Point a, Point b, Point c){
  return (min(a.X, b.X) <= c.X && c.X <= max(a.X, b.X) && min(a.Y, b.Y) <= c.Y && c.Y <= max(a.Y,b.Y));}

double angle(Point a, Point o, Point b) {
   Vector oa = toVec(o,a), ob =toVec(o, b);
   return acos(dot(oa, ob) / sqrt( norm_sq(oa) * norm_sq(ob) ));
}

struct Polygon {
    vector<Point> points;
    Polygon(vector<Point> _points) { this->points = _points;}

    Positions inPolygon(Point pt) {
        if ((int) points.size() == 0) return OUTSIDE;
        double sum = 0;
        for (int i = 0; i < (int) points.size()-1; i++) {
            if(isCollinear(points[i],pt,points[i+1]) && isBetween(points[i],points[i+1],pt))return BOUNDARY;
            if(ccw(pt,points[i],points[i+1]))
                sum+=angle(points[i],pt,points[i+1]);
            else
                sum-=angle(points[i],pt,points[i+1]);
        }
        return fabs(fabs(sum) - 2 * M_PI) < EPS ? INSIDE : OUTSIDE;
    }
};

int npoints, nqueries;
Point z;
vector<Point> p;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>npoints>>nqueries;
    for(int i=0;i<npoints;i++){
        cin>>z.X>>z.Y;
        p.push_back(z);
    }
    p.push_back(p.front());
    Polygon poligon (p);

    for(int i=0;i<nqueries;i++){
        cin>>z.X>>z.Y;
        Positions q =poligon.inPolygon(z);
        cout<<( q==INSIDE ? "INSIDE" : ( q==OUTSIDE ? "OUTSIDE" : "BOUNDARY"))<<ENDL;
    }
    return 0;
}
