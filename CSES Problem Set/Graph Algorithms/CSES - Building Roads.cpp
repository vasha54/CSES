/*
* CSES - Building Roads
* Tematica: Teoría de grafos : Componentes conexa
* Idea: Hallar la cantidad de componentes conexa de un grafo dado para asi conocer la
* cantidad minima de carreteras tiene que construir para conectar todas la ciudades;
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
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

struct Node{
    vector<int> neighborns;
    bool visited;

    Node(){
        visited =false;
        neighborns.clear();
    }
};

int ncitys, nroads,cityA, cityB;

Node graphs[MAX_N];
vector<int> roots;

void bfs(int node){
    queue<int> visit;
    graphs[node].visited=true;
    visit.push(node);

    while(!visit.empty()){
        node = visit.front();
        visit.pop();
        for(int y : graphs[node].neighborns){
            if(!graphs[y].visited){
                graphs[y].visited = true;
                visit.push(y);
            }
        }
    }
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>ncitys>>nroads;
    for(int i=0;i<=ncitys;i++) graphs[i] = Node();
    for(int i=1;i<=nroads;i++){
        cin>>cityA>>cityB;
        graphs[cityA].neighborns.push_back(cityB);
        graphs[cityB].neighborns.push_back(cityA);
    }
    for(int i=1;i<=ncitys;i++){
        if(!graphs[i].visited){
            roots.push_back(i);
            bfs(i);
        }
    }
    cout<<roots.size()-1<<ENDL;
    for(int i=0;i<roots.size()-1;i++){
        cout<<roots[i]<<" "<<roots[i+1]<<ENDL;
    }
    return 0;
}
