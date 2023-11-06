/**
* CSES - Factory Machines
* Tematica : Busqueda Binaria + lower bound
* Idea: Se tiene un grupos de maquinas donde de cada maquina se conoce que
* demora una cantidad de tiempo en especifico. Se desea conocer la minima cantidad
* de tiempo a esperar para que entre todas las maquinas realicen k productos. Realizar
* una busqueda binaria por el intervalo de tiempo de forma que se pueda hallar un
* instante de tiempo minimo x que la suma de la cantidad  de productos realizados por las
* maquinas sea al menos igual a k.
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

uint nmachines,nproduct,delay,bestDelay;
vector<uint> machines;

bool factory(uint timesLimit){
    uint tFactory =0;
    for(int i=0;i<nmachines && tFactory < nproduct ;i++){
        tFactory += (timesLimit/machines[i]);
    }
    return ((tFactory>=nproduct) ? true : false);
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>nmachines>>nproduct;
    REP(i,0,nmachines){
        cin>>delay;
        machines.push_back(delay);
    }
    sort(machines.begin(),machines.end());

    bestDelay = LONG_MAX;
    uint beginT = 0, endT = machines[nmachines-1]*nproduct+2, pivot;

    while(beginT<=endT){
        pivot =(beginT+endT)/2;
        if(factory(pivot)){
            bestDelay = min(bestDelay,pivot);
            endT = pivot-1;
        }else
            beginT = pivot+1;
    }

    cout<<bestDelay<<ENDL;
    return 0;
}
