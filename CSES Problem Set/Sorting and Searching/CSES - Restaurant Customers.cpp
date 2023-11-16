/**
* CSES - Restaurant Customers
* Tematica : Programación dinámica: Suma de prefijo + Orddenamiento
* Idea: Dado un serie de eventos de los cuales se sabe el tiempo de inicio y final
* hallar la maxima cantidad de eventos que se efectuan al mismo tiempo.
* Almacenamos todos los instantes de tiempos (junto con los tiempos guardamos si
* es una entrada o salida) y los ordenamos por su valor en caso
* de similar valor tiene mayor procedencia el tiempo asociado a una entrada. Luego
* recorremos los eventos por cada tiempo de entrada o inicio sumamos 1 y por cada
* evento de salida o fin decrementamos en uno una variable. La respuesta final será
* el maximo valor que puede alcanzar esa variable en cualquier momento.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 1000010
#define EPS 1e-9
#define INF 1LL<<60
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

enum TYPE {ENTER=1, LEAVE=-1};

int n,sums,a,b,best;

struct Event{
    int timestamp;
    TYPE type;

    Event(int t, TYPE x):timestamp(t),type(x){}
};

bool operator<(Event a, Event b){
    if(a.timestamp < b.timestamp) return true;
    else if (a.timestamp > b.timestamp) return false;
    else{
        if(a.type == b.type || a.type == ENTER) return true;
        else return false;
    }
}

vector<Event> events;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    cin>>n;
    events.clear();
    sums = 0;
    best =0 ;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        events.push_back(Event(a,ENTER));
        events.push_back(Event(b,LEAVE));
    }

    sort(events.begin(),events.end());

    for( Event x : events) {
        sums += x.type;
        best = max(best,sums);
    }
    cout<<best<<ENDL;
    return 0;
}
