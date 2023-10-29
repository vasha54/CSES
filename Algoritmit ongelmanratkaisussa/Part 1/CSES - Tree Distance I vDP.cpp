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
    int firstMaxPath; // Primer camino mas largo
    int secondMaxPath; // Segundo camino mas largo
    int nodeChildMaxPath; // Nodo hijo o padre que salio el camino mas largo
};

int nnodes,v,u;

vector<Node> tree;

void dfsLongestPathsChild(int v, int p){
    tree[v].firstMaxPath = 0;
    tree[v].secondMaxPath = 0;
    for (auto x : tree[v].neighborns) {
        if (x == p) continue;
        dfsLongestPathsChild(x, v);
        if (tree[x].firstMaxPath + 1 > tree[v].firstMaxPath) {
            tree[v].secondMaxPath = tree[v].firstMaxPath;
			tree[v].firstMaxPath = tree[x].firstMaxPath + 1;
            tree[v].nodeChildMaxPath = x;
        } else if (tree[x].firstMaxPath + 1  > tree[v].secondMaxPath) {
            tree[v].secondMaxPath= tree[x].firstMaxPath + 1;
        }
    }
}

void dfsLongestPathsParent(int v, int p){
    for (auto x : tree[v].neighborns) {
        if (x == p) continue;
        if (tree[v].nodeChildMaxPath == x) {
            if (tree[x].firstMaxPath < tree[v].secondMaxPath + 1) {
                tree[x].secondMaxPath = tree[x].firstMaxPath;
				tree[x].firstMaxPath = tree[v].secondMaxPath + 1;
                tree[x].nodeChildMaxPath = v;
            } else {
                tree[x].secondMaxPath = max(tree[x].secondMaxPath,tree[v].secondMaxPath + 1);
            }
        } else {
            tree[x].secondMaxPath = tree[x].firstMaxPath;
			tree[x].firstMaxPath = tree[v].firstMaxPath + 1;
            tree[x].nodeChildMaxPath = v;
        }
        dfsLongestPathsParent(x, v);
    }
}

void allLongestPathsTree(){
    dfsLongestPathsChild(1,-1);
    dfsLongestPathsParent(1,-1);
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
        cout<<tree[i].firstMaxPath;
    }
    cout<<ENDL;

    return 0;
}
