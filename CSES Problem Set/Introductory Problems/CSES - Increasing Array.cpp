/**
 * CSES - Increasing Array
 * Temática: Add - Hoc
 *
 * Idea: Dado una colección de valores se quiere realizar un grupo de operaciones
 * tal que cualquier elemento de la colección sea mayor o igual que el elemento que
 * le precede. Una operación consiste en escoger un elemento de la colección y
 * aumentar su valor en uno. Dado los valores se quiere hallar la mínima cantidad
 * de operaciones. La solución radica en sumas las diferencias entre dos valores
 * consecutivos siempre y cuando el primero sea mayor que el segundo. Cuando esto
 * ocurre el segundo toma el valor del primero ya que en la próxima iteracción será
 * el primero del par a analizar.
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE
    int nvalues;
    LL answers = 0 ;
    cin>>nvalues;

    vector<LL> values(nvalues);

    for(int i=0;i<nvalues;i++){
        cin>>values[i];
    }

    for(int i=1;i<nvalues;i++){
        if(values[i-1]>values[i]){
            answers+=(values[i-1] - values[i]);
            values[i] = values[i-1];
        }
    }

    cout<<answers<<ENDL;
	return 0;
}
