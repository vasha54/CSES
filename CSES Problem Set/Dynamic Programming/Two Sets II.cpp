/*
    CSES - Two Sets II
    Temática : Programación Dinámico
    
    Idea: El problema pide contar el número de formas de dividir el conjunto
     {1,2,…,n} en dos subconjuntos disjuntos que tengan la misma suma.
 
    Sea S = 1+2+…+n = n(n+1)/2 la suma total. Para que sea posible la 
    partición, S debe ser par, ya que cada subconjunto debe sumar S/2. Si S es
    impar, la respuesta es 0.
 
    Supongamos S par y definamos T = S/2. Entonces necesitamos contar cuántos
    subconjuntos de {1,…,n} tienen suma exactamente T. Cada partición en dos 
    subconjuntos {A, B} aparece dos veces en ese conteo: una vez cuando tomamos 
    A y otra cuando tomamos B (pues ambos suman T). Como ningún subconjunto no 
    vacío puede ser igual a su complemento, cada partición se cuenta 
    exactamente dos veces. Por lo tanto, el número de particiones buscado es la 
    mitad del número de subconjuntos con suma T.
 
    El problema se reduce entonces a contar subconjuntos de números distintos 
    del 1 al n que sumen T. Esto es un problema clásico de "subset sum" que 
    puede resolverse con programación dinámica. Vamos a construir una matrix
    unidimensional donde [i] alamacenaremos la cantidad de formar subconjuntos
    que sumen i.
*/

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const long long INV2 = 500000004; // modular inverse of 2 modulo MOD

int main() {
    int n;
    cin >> n;
    
    long long total = (long long)n * (n + 1) / 2;
    long long answer = 0;
    
    if (total % 2 == 0) {
        long long target = total / 2;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (long long s = target; s >= i; --s) {
                dp[s] = (dp[s] + dp[s - i]) % MOD;
            }
        }
        
        answer = dp[target] * INV2 % MOD;
    }
    
    cout << answer << endl;
    
    return 0;
}