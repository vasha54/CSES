/**
* CSES - Tree Diameter
* Tematica : Teoria de Grafos + Diametro del arbol
* Idea: Problema clasico de calcular el diametro de un árbol utilizando dfs
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

struct Node{

  int m_dist;
  vector<int> m_neighbors;
  int m_dfs;

  Node(){
    m_neighbors.clear();
    m_dfs=0;
    m_dist=0;
  }
};

Node graphs[MAX_N];
int nnodes,a,b;

int diameterTree(int _nodeStart){
  int tDiameter=0;
  int nextNode,currentNode,farthestNode=_nodeStart;
  graphs[_nodeStart].m_dist=0;
  graphs[_nodeStart].m_dfs=1;

  stack<int> visit;
  visit.push(_nodeStart);

  while(!visit.empty()){
    currentNode=visit.top();
    visit.pop();
    if(graphs[currentNode].m_dist>tDiameter){
      tDiameter=graphs[currentNode].m_dist;
      farthestNode=currentNode;
    }

    int tNeighbors=graphs[currentNode].m_neighbors.size();
    for(int i=0;i<tNeighbors;i++){
      int nextNode=graphs[currentNode].m_neighbors[i];
      if(graphs[nextNode].m_dfs<1){
        graphs[nextNode].m_dfs=1;
        graphs[nextNode].m_dist=graphs[currentNode].m_dist+1;
        if(graphs[nextNode].m_dist>tDiameter){
          tDiameter=graphs[nextNode].m_dist;
          farthestNode=nextNode;
        }
		visit.push(nextNode);
	  }
	}
  }

  graphs[farthestNode].m_dist=0;
  graphs[farthestNode].m_dfs=2;
  tDiameter=0;

  visit.push(farthestNode);

  while(!visit.empty()){
    currentNode=visit.top();
    visit.pop();
    if(graphs[currentNode].m_dist>tDiameter){
      tDiameter=graphs[currentNode].m_dist;
      farthestNode=currentNode;
	}

    int tNeighbors=graphs[currentNode].m_neighbors.size();
    for(int i=0;i<tNeighbors;i++){
      int nextNode=graphs[currentNode].m_neighbors[i];
      if(graphs[nextNode].m_dfs<2){
        graphs[nextNode].m_dfs=2;
		graphs[nextNode].m_dist=graphs[currentNode].m_dist+1;
		if(graphs[nextNode].m_dist>tDiameter){
          tDiameter=graphs[nextNode].m_dist;
		  farthestNode=nextNode;
		}
		visit.push(nextNode);
      }
    }
  }
  return tDiameter;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    cin>>nnodes;
    for(int i=1;i<nnodes;i++){
        cin>>a>>b;
        graphs[a].m_neighbors.push_back(b);
        graphs[b].m_neighbors.push_back(a);
    }

    cout<<diameterTree(1)<<ENDL;

    return 0;
}
