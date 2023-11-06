/**
* CSES - Hamiltonian Flights
* Tematica : Teoria de grafos: Camino Hamilton
* Idea: Dado un grafo saber la cantidad de caminos de hamilton tal que comience
* en una ciudad en especifico y termine en otra en especifico.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 25
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long
#define uint unsigned int
#define pii pair<int,int>
#define vii vector<pii>

using namespace std ;

int nnodes,npaths,a,b;
int madj[MAX_N][MAX_N],dp[MAX_N][1<<21],path[MAX_N];
vector<int> ladj[MAX_N], vv[1<<21];;


int countHamiltonPath(){
    dp[0][1]=1;


    REP(i,0,nnodes+1) path[i] = 1<<i;

    REP(j,0,nnodes){
        REP(k,0,nnodes-1){
            if (j!=k && madj[k][j]) {
                REP(i,0,madj[k][j]) ladj[j].push_back(k);
            }
        }
    }
    REP(i,1,path[nnodes]){
        REP(j,1,nnodes){
            if (i&path[j]) vv[i].push_back(j);
        }
    }
    REP(i,1,path[nnodes]){
        for (auto j: vv[i]){
            int o = i^(path[j]);
            for (auto k: ladj[j]){
                dp[j][i]+=dp[k][o];
            }
            dp[j][i]%=MOD;
        }
        i++;
    }
    return dp[nnodes-1][path[nnodes]-1];
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
   // READ_FILE

    cin>>nnodes>>npaths;

    for(int i=0;i<nnodes;i++){
        fill(madj[i],madj[i]+MAX_N,0);
    }

    for(int i=0;i<npaths;i++){
        cin>>a>>b;
        a--;
        b--;
        madj[a][b]++;
    }

    cout<<countHamiltonPath()<<ENDL;

    return 0;
}
