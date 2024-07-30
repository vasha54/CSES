/*
* CSES - Subordinates
* Tematica: Estructuras de Datos + Arboles recorrido
* Idea: Dado los trabajadores de una empresa y conociendo el jefe inmediato
* de cada trabajador se quiere conocer para cada trabajador cuando subordinados
* tiene este. Un subordinado es cualquier persona que sea dirigido directamente
* o indirectamente a traves de un subordinado directo o indirecto. Se toma al trabajador
* 1 como el único y gran jefe de todos los trabajadores.
* Si construimos el árbol represente la estructura organizativa y aplicamos un recorrido
* con enfoque posorden podremos calcular para cada trabajador la cantidad de subordindados
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 200010
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
#define PRINT_LINE cout<<ENDL;
using namespace std;

struct Node{
    vector<int> soons;
    int nsoons;
};
int nnodes,parent;
Node tree[MAX_N];

void posorden(int node){
    tree[node].nsoons=0;
    for(auto x : tree[node].soons){
        posorden(x);
        tree[node].nsoons += (tree[x].nsoons+1);
    }
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nnodes;
    for(int i=2;i<=nnodes;i++){
        cin>>parent;
        tree[parent].soons.push_back(i);
    }
    posorden(1);
    for(int i=1;i<=nnodes;i++){
        if(i!=1)cout<<" ";
        cout<<tree[i].nsoons;
    }
    cout<<ENDL;
    return 0;
}
