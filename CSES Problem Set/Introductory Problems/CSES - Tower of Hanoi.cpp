/**
* CSES - Tower of Hanoi
* Tematica : Recursividad
* Idea: Como la cantidad de disco es pequeña se puede simular el proceso de
* forma recursiva
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;


void towerOfHanoi(int disk, int from, int to, int aux){
   if (disk == 1){
      cout<<from<<" "<<to<<ENDL;
   }else{
      towerOfHanoi(disk - 1, from, aux, to);
	  cout<<from<<" "<<to<<ENDL;
	  towerOfHanoi(disk - 1, aux, to, from);
   }
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    int n;
    cin>>n;
    cout<<(1<<n)-1<<ENDL;
    towerOfHanoi(n,1,3,2);
    return 0;
}
