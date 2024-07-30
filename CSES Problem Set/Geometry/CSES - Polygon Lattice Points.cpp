/*
* CSES - Polygon Lattice Points
* Tematica: Geometria : Poligono + Area +Teorema Pick
* Idea: Dado un poligono por los puntos que conforman su verstices se pide
* hallar la cantidad de puntos con coordenadas enteras que están dentro del
* poligono ya sea dentro del poligon o sobre los bordes del poligonos.
* Para hallar la cantidad de puntos que están sobre los bordes del poligono vamos
* recorrer cada segmento y la cantidad de puntos cuyas coordenadas son enteras en un
* determinado segmento es igual a expresión :
*  gcd( abs(x[i]-x[i+1]) , abs(y[i]-y[i+1]) )
*  Sumando lo que aporta cada segmento o borde del poligono podremos calcular la cantidad de
*  puntos que están sobre el perimetro del poligono
*  Bien para hallar los puntos que cuyas coordenadas son enteras estan dentro del poligono
*  vamos apoyarnos en el teorema de Pick el cual plantea que el area del poligono es igual a
* la siguiente expresión:
*    a+b/2-1
*  Donde a es la cantidad de puntos dentro del poligono y b la cantidad de puntos en los bordes
* del poligono cuyas coordenadas son enteras. Pues podemos calular el area del poligon y con los
* puntos que estan en el borde podemos con simple despeje hallar los puntos dentro del poligono
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
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define CELL_FREE '.'
#define CELL_WALL '#'
#define PRINT_LINE cout<<ENDL;
using namespace std;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};
char mov_s [] =  {'L','R','U','D'};

struct Poligon{
    vector<Point> points;
    int p_inside,p_boundary;
    Poligon(vector<Point> _points){
        points = _points;
        p_inside = 0;
        p_boundary = 0;
    }

    int area(){
        int resArea = 0;
        for (unsigned i = 0; i < points.size(); i++) {
           Point p = i ? points[i - 1] : points.back();
           Point q = points[i];
           resArea += (p.X - q.X) * (p.Y + q.Y);
           p_boundary += gcd( abs(p.X - q.X), abs(p.Y - q.Y));
        }
        resArea = abs(resArea);
        p_inside = (resArea + 2 - p_boundary)/2;
	    return resArea/2;
    }
};

int npoints,x,y;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>npoints;
    vector<Point> points;
    for(int i=0;i<npoints;i++){
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    Poligon P =Poligon(points);
    P.area();
    cout<<P.p_inside<<" "<<P.p_boundary<<ENDL;
    return 0;
}
