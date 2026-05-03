 /**
 * CSES - Fligth Discount 
 * Temática: Teoría de grafo + Distrakj
 * 
 * Idea: Dado un grupo de ciudades interconectados por carreteras direccional 
 * se quiere ir de la ciudad 1 a la ciudad N por la menor ruta más corta con la 
 * condición que se puede tomar una carretera que conecta dos ciudades por la mitad
 * de su distancia. Usando un distrakj conesta modificación se puede resolver el problema.
 *
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
 
#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
 
using namespace std;
using namespace __gnu_pbds;

struct Node{
    vector< pii >adjs;
    int dist;
    int dist_cupon;
    bool mark;
    bool mark_cupon;
};

Node graph[MAX_N];
int nnodes, nroads;

void solve(int source){
    for(int i=1;i<=nnodes;i++){
        if(i == source){
            graph[i].dist=0;
            graph[i].dist_cupon=0;
        }else{
            graph[i].dist = LONG_MAX;
            graph[i].dist_cupon = LONG_MAX;
        }
        graph[i].mark = false;
        graph[i].mark_cupon = false;
    }
    priority_queue< tiib > visits;
    visits.push({-0,source,false});

    while(!visits.empty()){
        tiib current = visits.top();
        visits.pop();
        int d = -get<0>(current);
        int node = get<1>(current);
        bool cupon = get<2>(current);

        if(!cupon && graph[node].mark) continue;
        if(cupon && graph[node].mark_cupon) continue;

        //cout<<"Node:"<<node<<" distance:"<<d<<" cupon:"<<cupon<<ENDL;
        for(auto edge: graph[node].adjs){
            int nextV = edge.first;
            int nextD = edge.second;
            //cout<<" --->v"<<nextV<<"  d"<<nextD<<ENDL;             
            if(!cupon){
              if(graph[nextV].dist > d+nextD ){
                graph[nextV].dist = d+nextD;
                visits.push({-(d+nextD),nextV,false});
               
              }
              nextD = nextD/2;
            }
            if(graph[nextV].dist_cupon > d+nextD){
              graph[nextV].dist_cupon = d+nextD;
              visits.push({-(d+nextD),nextV,true});
             
            }
        }

        if(!cupon) graph[node].mark = true;
        if(cupon) graph[node].mark_cupon = true;

    }
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int a,b,c;
    cin>>nnodes>>nroads;
    for(int i=0;i<nroads;i++){
        cin>>a>>b>>c;
        graph[a].adjs.push_back({b,c});
    }
    solve(1);
    cout<<min(graph[nnodes].dist,graph[nnodes].dist_cupon)<<ENDL;
    return 0;
}

