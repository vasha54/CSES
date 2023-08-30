/**
 * CSES - Removing Digits
 * Temática: Programación Dinámica + Coin Change
 *
 * Idea: Dado un numero N del cual se desea calcular la cantidad de operaciones
 * mínima que se deben hacer para queel valor sea 0. Una operación consiste en
 * escoger uno de los digitos que conforman el valor y se le resta al valor
 * obteniendo uno nuevo con el cual se aplica la misma operación hasta obtener el
 * valor 0.
 * Para solucionar el problema vamos aplicar un coin change variante devolver la
 * menor cantidad de billetes posible para un valor N. Aqui la variación es que
 * las denominaciones de los billetes cambia en dependencia del N que se esta
 * analizando
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define MAX_N 1000010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int dp[MAX_N],N,coin;

set<int> descompose(int _n){
    set<int> digits;
    while(_n/10>0){
        if(_n%10 != 0) digits.insert(_n%10);
        _n/=10;
    }
    if(_n%10 != 0) digits.insert(_n%10);
    return digits;
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE

    fill(dp,dp+MAX_N,INT_MAX);
    dp[0]=0;

    for(int i=1;i<MAX_N;i++){
        set<int> coins = descompose(i);
        for(set<int>::iterator it = coins.begin();it!=coins.end();it++){
            coin = (*it);
            if(dp[i-coin]+1<dp[i] ){
              dp[i]= dp[i-coin]+1;
            }
        }
    }

    cin>>N;
    cout<<dp[N]<<ENDL;

	return 0;
}
