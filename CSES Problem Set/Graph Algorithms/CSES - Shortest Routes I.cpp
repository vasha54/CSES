/*
* CSES - Shortest Routes I
* Tematica: Teoría de Grafos + Distrajk
*
* Idea: Clasico ejercicio de Distrajk
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
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

int nnodes,nedges,nA,nB,cost;

struct Node{
   int dist;
   vector<int> adj;
   vector<int> weight;
};
Node graf[MAX_N];
bool mark[MAX_N];


struct pq_entry{
   int node, dist;
   bool operator <(const pq_entry &a) const{
      if (dist != a.dist) return (dist > a.dist);
         return (node > a.node);
   }
};

inline void dijkstra(int source){
   priority_queue<pq_entry> pq;
   pq_entry P;
   for (int i=1;i<=nnodes;i++){
      if (i == source){
         graf[i].dist = 0;
         P.node = i;
         P.dist = 0;
         pq.push(P);
      }
      else graf[i].dist = INF;
   }
   while (!pq.empty()){
      pq_entry curr = pq.top();
      pq.pop();
      int nod = curr.node;
      int dis = curr.dist;

      if(graf[nod].dist < dis) continue;

      for(int i=0;i<graf[nod].adj.size();i++){
         if(!mark[graf[nod].adj[i]]){
            int nextNode = graf[nod].adj[i];
            if(dis + graf[nod].weight[i] < graf[nextNode].dist){
               graf[nextNode].dist = dis + graf[nod].weight[i];
               P.node = nextNode;
               P.dist = graf[nextNode].dist;
               pq.push(P);
            }
         }
      }
      mark[nod] = true;
   }
}


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nnodes>>nedges;
    for(int i=0;i<nedges;i++)
    {
        cin>>nA>>nB>>cost;
        graf[nA].adj.push_back(nB);
        graf[nA].weight.push_back(cost);
    }

    dijkstra(1);

    for(int i=1;i<=nnodes;i++)
    {
        if(i>1)cout<<" ";
        cout<<graf[i].dist;
    }
    cout<<ENDL;
    return 0;
}
