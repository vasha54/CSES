/**
* CSES - Tree Diameter
* Tematica : Teoria de Grafos + Diametro del arbol
* Idea: Problema clasico de calcular el diametro de un árbol utilizando
* programacion dinamica
*/

#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200010
#define READ_FILE freopen("Input.txt","r",stdin);


const int MOD = 1e9+7;

int nnodes,a,b, diameter;
struct Node {
    vector<int> children;
    int f,toLeaft;
    Node(){
        children.clear();
        f=toLeaft=0;
    }
};

vector<Node> tree;

void diameterTree(int node ,int par, int * diameter){
	vector<int> childList;

	for(int child : tree[node].children)
        if(child != par){
           diameterTree(child , node, diameter);
		   tree[node].f = max(tree[node].f , tree[child].f + 1);
           childList.push_back(tree[child].f);
	    }
    *diameter = max(*diameter , tree[node].f);

	sort(childList.begin() , childList.end());
	if(childList.size() >= 2)
	{
		tree[node].toLeaft = 2 + childList[childList.size()-1] + childList[childList.size()-2];
		*diameter = max(*diameter , tree[node].toLeaft);
	}
}

signed main(){
    OPTIMIZAR_IO
    //READ_FILE
    cin>>nnodes;
    tree.resize(nnodes+3);
    for(int i=1;i<nnodes;i++){
        cin>>a>>b;
        tree[a].children.push_back(b);
        tree[b].children.push_back(a);
    }
    diameterTree(1,-1,&diameter);
    cout<<diameter<<ENDL;
    return 0;
}

