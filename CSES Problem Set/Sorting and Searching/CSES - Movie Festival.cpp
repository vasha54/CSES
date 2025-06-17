/*
* CSES - Movie Festival
* Tematica: Ordenamiento
*
* Idea: Se tiene una colección de peliculas de las cuales se conoce el tiempo de
* inicio y tiempo de finalización se quiere saber la maxima cantidad de peliculas
* completas que se puede ver.
* 
* Para resolver el problema vamos primero ordenar las peliculas tomando como primer
* criterio el tiempo de finalización y como segundo el tiempo de inicio (si ambos 
* coinciden entonces utilizamos el orden de entrada de la peliculas), una vez ordenadas.
* comenzaremos a recorrer cada película con la idea de que cuando lleguemos a la 
* pelicula i ya hemos calculado para todos las peliculas en el rango de 0 a i-1 
* la máxima cantidad de peliculas que se pueden ver teniendo a esa pelicula como 
* la última vista. 
* Luego solo tenemos que ver que pelicula nos permite ver más peliculas lo cual
* podemos determinar cada vez que procesamos la pelicula i.
*/
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MAX_TREE (MAX_N << 2)
#define MOD  10000
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
#define mid (l+r)/2
 
const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;
 
struct Movie
{
    int timeBegin;
    int timeEnd;
    int id;
    int showPrevius;
};
 
int nmovies,answer, last;
 
bool cmpMovie(Movie a , Movie b)
{
    if(a.timeEnd < b.timeEnd) return true;
	else if(a.timeEnd > b.timeEnd) return false;
    else if(a.timeEnd == b.timeEnd && a.timeBegin < b.timeBegin) return true;
	else if(a.timeEnd == b.timeEnd && a.timeBegin > b.timeBegin) return false;
    else if(a.timeBegin == b.timeBegin && a.timeEnd == b.timeEnd) return (a.id < b.id);
    else return false;
}
  
signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    answer = 0;
	last = 0;
    cin>>nmovies;
    vector<Movie> movies(nmovies);
 
    for(int i=0;i<nmovies;i++)
    {
        cin>>movies[i].timeBegin>>movies[i].timeEnd;
        movies[i].id=i+1;
        movies[i].showPrevius = 0;
    }
 
    sort(movies.begin(),movies.end(),cmpMovie);
 
    for(int i=0;i<nmovies;i++)
    {
        if (movies[i].timeBegin >= last) {
			++answer;
			last = movies[i].timeEnd;
		}
    }
 
    cout<<answer<<ENDL;
    return 0;
}