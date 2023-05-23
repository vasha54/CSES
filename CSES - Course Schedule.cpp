/**
 * CSES - Course Schedule
 * Temáticas: Teoria de Grafo + Ordenamiento Topplógico
 *
 * Idea: Dado un grupo de cursos donde para pasar un posible curso se debe haber
 * pasado antriormente un grupo curso. Dada la relacion de precedencia entre los
 * cursos hallar una posible secuencia de ser posible en la que se pueda cursar
 * todos los cursos. Si modelamos la precedencia entre los cursos como un grafo
 * donde los cursos son los nodos y existe una arista de del curso A al curso B
 * si para cursar el curso B se necesita cursar el curso A primero obtenemos un
 * grafo dirigido. Para que exista un ordenamiento topologico basta con comprobar
 * que no existe ciclos en el grafo. Para comprobar esto basta realizar un dfs
 * recursivo e ir almacenado los nodos visitados en una pila. El dfs nos va ayudar
 * a detectar un ciclo con la estrategia de pintado del nodo segun el estado de
 * la visita y a su vez en caso de no existir ciclo ya nos propone un ordenamiento
 * topologico.
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

vector<int> graph[MAX_N];
vector<int> visit(MAX_N, 0);
int n, m;
stack<int> s;

void topologicalsort(int i) {
	visit[i] = 1;
	for (int j = 0; j < graph[i].size(); j++) {
		if (!visit[graph[i][j]])
			topologicalsort(graph[i][j]);
		else if (visit[graph[i][j]] == 1) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
	}
	visit[i] = 2;
	s.push(i);
}

int main() {
	OPTIMIZAR_IO
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i])
			topologicalsort(i);
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}

