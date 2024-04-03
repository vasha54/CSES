/**
* CSES - Convex Hull
* Temática: Geometria Convex Hull
* Idea: Dada una colección de puntos  determinar la envoltura convexa que contiene
* todos los puntos
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

struct Point {
    double x, y;
};

int orientation(Point a, Point b, Point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; //en sentido de las agujas del reloj
    if (v > 0) return +1; //en sentido contrario a las agujas del reloj
    return 0;
}

bool cw(Point a, Point b, Point c, bool includeCollinear) {
    int o = orientation(a, b, c);
    return o < 0 || (includeCollinear && o == 0);
}

bool ccw(Point a, Point b, Point c, bool includeCollinear) {
    int o = orientation(a, b, c);
    return o > 0 || (includeCollinear && o == 0);
}

vector<Point> monotoneChain(vector<Point>& a, bool includeCollinear = false) {
    vector<Point> st;
    if(a.size() == 1) return st;
    sort(a.begin(),a.end(),[](Point a, Point b){
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    Point p1=a[0], p2=a.back();
    vector<Point> up, down;
    up.push_back(p1); down.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++) {
        if(i==a.size()-1 || cw(p1,a[i],p2,includeCollinear)){
            while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],a[i],includeCollinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i==a.size()-1 || ccw(p1,a[i],p2,includeCollinear)){
            while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i],includeCollinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    if(includeCollinear && up.size()==a.size()){
        reverse(a.begin(),a.end()); st=a; return st;
    }
    for (int i = 0; i < (int)up.size(); i++) st.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--) st.push_back(down[i]);
    return st;
}

int npoints;

vector<Point> p;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>npoints;
    p.resize(npoints);
    for(int i=0;i<npoints;i++) cin>>p[i].x>>p[i].y;
    vector<Point> ch = monotoneChain(p,true);
    npoints = ch.size();
    cout<<npoints<<ENDL;
    for(int i=0;i<npoints;i++){
        cout<<ch[i].x<<" "<<ch[i].y<<ENDL;
    }

    return 0;
}
