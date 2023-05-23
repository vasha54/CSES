/**
 * CSES - Longest Flight Route
 * Temáticas: Teoria de Grafo + Ordenamiento Topológico
 *
 * Idea: Se tiene un grupo de ciudades y se quiere realizar un viaje de la ciudad
 * 1 a la ciudad N pasando por la mayor cantidad de ciudades si se conoce las
 * rutas de viajes disponible entre ciudades. Lo primero es chequear si de 1 se
 * puede llegar a N simple conectividad que con bfs o dfs se resuelve. Ahora
 * demostrado que existe un camino como coger el camino mas largo. Sencillo hacemos
 * un ordenamiento topológico de 1 en adelante lo que permite organizar las ciudades
 * por un orden topologico siendo la ciudad 1 orden 0 mientras una ciudad j su orden
 * topologico es una unidad mayor que el maximo orden topologico de todas las ciudades
 * que tienen una ruta hacia la ciudad j. Una vez sacado el orden topologico para
 * todas la ciudades es sencillo saber cuantas componen el camino :
 * ordenTopologico[N]-ordenTopologico[1]+1
 * Para saber la ciudades solo debemos reconstruir el camino de final al principio
 * (de N a 1) Si estoy en la ciudad j su predecesor será una ciudad que su orden
 * topologico es menor en una unidad y tiene una ruta hacia la ciudad j. Podemos
 * usuar una idea de parent de disktraj.
 *
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
using namespace std;

vector<int> graph[MAX_N], rg[MAX_N], visited(MAX_N, 0), dist(MAX_N, 0), parent(
		MAX_N, 0);
stack<int> path;

void toposort(int v) {
	visited[v] = 1;
	for (auto &i : graph[v]) {
		if (!visited[i]) {
			dist[i] = dist[v] + 1;
			parent[i] = v;
			toposort(i);
		}
	}
	path.push(v);
}

int main() {
	OPTIMIZAR_IO
	int nnodes, npaths, a, b;
	cin >> nnodes >> npaths;
	for (int i = 1; i <= npaths; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		rg[b].push_back(a);
	}
	toposort(1);
	if (!visited[nnodes])
		return cout << "IMPOSSIBLE\n";
	else {
		while (!path.empty()) {
			int v = path.top();
			path.pop();
			for (auto &i : rg[v]) {
				if (dist[v] < dist[i] + 1 && v != 1) {
					parent[v] = i;
					dist[v] = dist[i] + 1;
				}
			}
		}
		cout << dist[nnodes] - dist[1]+ 1 << "\n";
		stack<int> ans;
		ans.push(nnodes);
		int pv = parent[nnodes];
		while (pv != 0) {
			ans.push(pv);
			pv = parent[pv];
		}
		while (!ans.empty()) {
			cout << ans.top() << " ";
			ans.pop();
		}
	}
	return 0;
}

