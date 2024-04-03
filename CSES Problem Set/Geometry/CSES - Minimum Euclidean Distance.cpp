/**
* CSES - Minimum Euclidean Distance
* Temática: Geometria Puntos más cercanos
* Idea: Dada una colección de puntos  determinar la menor distancia entre cualquier
* par de puntos de la colección dicho resultado imprimirlo al cuadrado
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
#define Point pair<int, int>
#define X first
#define Y second
using namespace std;

int distancePointToPoint(Point p1, Point p2){
  int deltaX=p1.X-p2.X;
  int deltaY=p1.Y-p2.Y;
  deltaX*=deltaX;
  deltaY*=deltaY;
  return deltaX+deltaY;
}

int closestPair(vector<Point> _points, int _npoint){
    sort(_points.begin(), _points.end());
    set<Point> s = {{_points[0].Y, _points[0].X}};
    int j = 0;
    int d = LLONG_MAX;
    for (int i = 1; i < _npoint; i++) {
        auto it = s.begin();
        int dd = ceil(sqrt(d));
        while (j < i && _points[j].X < _points[i].X - dd) {
            s.erase({_points[j].Y, _points[j].X});
            j++;
        }
        auto l = s.lower_bound({_points[i].Y - dd, 0});
        auto r = s.upper_bound({_points[i].Y + dd, 0});
        for (auto it = l; it != r; it++) {
            d = min(d, distancePointToPoint({it->Y, it->X}, _points[i]));
        }
        s.insert({_points[i].Y, _points[i].X});
    }
    return d;
}

int npoints;
Point z;
vector<Point> p;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>npoints;
    for(int i=0;i<npoints;i++){
        cin>>z.X>>z.Y;
        p.push_back(z);
    }
    cout<<closestPair(p, npoints)<<ENDL;
    return 0;
}
