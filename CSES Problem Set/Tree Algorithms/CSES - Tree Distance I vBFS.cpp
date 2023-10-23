/**
* CSES - Tree Distance I
* Tematica : Estructura de árbol: Camino mas largo para cada nodo
* Idea: Dado un árbol determinar la distancia del camino mas largo para cada nodo
* donde el es uno de lo extremos.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200010
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;


struct Node {
    vector<int> neighborns;
    int maxPath = LONG_MIN;
};

int nnodes,v,u;

vector<Node> tree;

int bfs(int src) {
	int top;
	queue<int> q;
	vector<int> d(nnodes+1, -1);
	d[src] = 0;
	tree[src].maxPath = max(tree[src].maxPath, d[src]);
	q.push(src);

	while(!q.empty()) {
		top = q.front();
		q.pop();

		for(int v: tree[top].neighborns) {
			if(d[v] == -1) {
				q.push(v);
				d[v] = d[top] + 1;
				tree[v].maxPath = max(tree[v].maxPath, d[v]);
			}
		}
	}
	return top;
}

void allLongestPathsTree(){
    int diam_end_1 = bfs(1);
	int diam_end_2 = bfs(diam_end_1);
	bfs(diam_end_2);
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>nnodes;
    tree.resize(nnodes+2);

    for(int i=0;i<nnodes-1;i++){
        cin>>u>>v;
        tree[u].neighborns.push_back(v);
        tree[v].neighborns.push_back(u);
    }

    allLongestPathsTree();

    for(int i=1;i<=nnodes;i++){
        if(i>1) cout<<" ";
        cout<<tree[i].maxPath;
    }
    cout<<ENDL;

    return 0;
}
