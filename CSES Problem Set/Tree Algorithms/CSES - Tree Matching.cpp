/**
* CSES - Tree Matching
* Tematica : Teoria de grafos: Recorridos en arboles Postorden
* Idea: Dado un árbol se quiere sacar la mayor cantidad de parejas de nodos tal
* que los nodos parejas sean dos nodos unidos por una arista del árbol. Un nodo
* solo puede participar en una pareja. Para generar la mayor cantidad de pareja 
* vamos utilizar una estragegía un poco greedy de ir sacando pareja utilizando
* primero aquellos nodos hojas con sus padres y asi ir subiendo en el árbol y siempre
* que encontremos un nodo que ni él y padre no haya sido utilizado aún para formar
* una pareja lo contamos como una pareja.  
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 2000010
#define EPS 1e-9
#define INF 1LL<<60
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

struct Node{
    vector<int> neighborns;
    bool used;
};

int nnodes, matching,nA,nB;
Node tree[MAX_N];

void visitPostOrden(int node,int parent=-1){
    for(int u: tree[node].neighborns){
        if(u != parent){
            visitPostOrden(u,node);
        }
    }
    if(parent!=-1 && !tree[parent].used && !tree[node].used){
        matching++;
        tree[parent].used = tree[node].used = true; 
    }
} 

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nnodes;
    for(int i=0;i<nnodes-1;i++){
        cin>>nA>>nB;
        tree[nA].neighborns.push_back(nB);
        tree[nB].neighborns.push_back(nA);
        tree[nA].used = false;
        tree[nB].used =false;
    }

    matching =0;
    visitPostOrden(1);
    cout<<matching<<ENDL;        

    return 0;
}
