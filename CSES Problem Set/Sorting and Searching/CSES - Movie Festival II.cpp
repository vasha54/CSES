/*
CSES - Movie Festival II

    Temática : Ordenamiento + MultiSet

    Idea: El problema consiste en maximizar la cantidad total de películas que
    pueden ver completamente los k miembros de un club, dado un conjunto de n 
    películas con sus tiempos de inicio a y fin b. Cada miembro puede ver una 
    secuencia de películas no solapadas (una película termina en b y la 
    siguiente puede comenzar en b o después). Se trata de un problema de 
    planificación de intervalos en k máquinas idénticas (los miembros).

    Se ordena las películas primero por el inicio y luego por el final. Se recorre las peliculas 
    ordenada. Por cada pelicula i se tiene que:
        - Si existen miembros disponibles sin ver películas entonces se cuenta
    la pelicula y se almacena en una cola con prioridad el tiempo de finalización de la pelicula i
        - Mientras el tiempo de finalización de la peliculas vistas (tope de 
    cola de prioridad ) es menor o igual al comienzo de la pelicula i entonces
    actualizar la cantidad de miembros disponibles y eleminas de la pila.
        - En cualquier otro caso no se podra ver la pelicula por tanto se
    omite.  

    En C++ usar un multiset con k ceros (disponibilidades iniciales) y, tras 
    ordenar las películas por tiempo de fin, para cada película busca el mayor 
    tiempo de fin ≤ inicio (usando upper_bound y retrocediendo 1). Si existe, 
    reemplaza esa disponibilidad por el nuevo tiempo de fin y cuenta la 
    película. Es una implementación estándar de interval scheduling con 
    máquinas.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
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
using namespace __gnu_pbds;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

signed main()
{
    //OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n, k;
	cin >> n >> k;
	vector<pair<int, int>> movies(n);
	for (int i = 0; i < n; i++)
		cin >> movies[i].second >> movies[i].first;
	sort(begin(movies), end(movies));

	int shows = 0;
	multiset<int> end_times;
	for (int i = 0; i < k; ++i) end_times.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(movies[i].second);
		if (it == begin(end_times)) continue;
		end_times.erase(--it);
		end_times.insert(movies[i].first);
		++shows;
	}

	cout << shows;
    return 0;
}