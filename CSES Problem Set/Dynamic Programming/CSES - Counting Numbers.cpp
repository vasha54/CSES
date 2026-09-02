/**
 * CSES - Counting Numbers
 * Temática: Digit DP
 *
 * Idea: Primero simplifiquemos el problema a una sola variable. Definimos una función
 * count(x) que sea igual a la cantidad de enteros en el intervalo [0, x] que no
 * tienen dos dígitos iguales adyacentes. La respuesta se obtiene entonces
 * calculando count(b) - count(a - 1).
 * 
 * Calcularemos la función eligiendo recursivamente un dígito del entero a la vez.
 * Los parámetros de la función recursiva, o el contexto necesario para calcular
 * la cantidad total de enteros que aún se pueden elegir, son:
 * 
 *      - i: La posición del siguiente dígito, comenzando desde 0 en el dígito más
 * significativo de x.
 *      - prev: El dígito anterior elegido (si corresponde).
 *      - equal: Si todos los dígitos elegidos hasta ahora son iguales a los respectivos
 * dígitos en x. Esto debe saberse para que no se cuenten enteros mayores que x.
 * Después del primer dígito no igual, no hay límite para el resto de los dígitos
 * que se pueden elegir.
 *      - empty: Si todavía no se ha elegido ningún dígito distinto de cero, lo que
 * significa que el prefijo está vacío. Cualquier cantidad de ceros puede ser
 * adyacente entre sí antes del inicio propiamente dicho del entero.
 * 
 * Luego probamos cada opción para el siguiente dígito, 0,...,9, verificamos que el
 * entero total no supere x y aseguramos que el dígito no sea igual al anterior.
 * Los parámetros se actualizan adecuadamente y entonces recursamos al siguiente
 * dígito y sumamos el resultado al total.
 * 
 * El caso i = n, donde n es la cantidad de dígitos en x, significa que hemos
 * establecido todos los dígitos con éxito y encontrado un entero válido.
 * 
 * Los resultados de la función se memorizan en una tabla de búsqueda. Hay como
 * máximo (n+1) * 10 * 2 * 2 combinaciones diferentes de parámetros para la
 * función, por lo que la complejidad temporal al usar un std::map para la tabla
 * de búsqueda es O(log x log log x).
 */
#include <bits/stdc++.h>

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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 20
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

int dp[20][11][2][2];  

string s;
map<array<int, 4>, int> lookup;

int recurse(int i, int prev, bool equal, bool empty) {
    if (i == (int)s.size()) return 1;

    array<int, 4> params{i, prev, equal, empty};
    if (lookup.count(params)) return lookup[params];

    int result = 0;
    for (int d = 0; d < 10; ++d) {
        if (equal && d > s[i] - '0') break;
        if (!empty && d == prev) continue;
        result += recurse(i + 1, d, equal && d == s[i] - '0', empty && d == 0);
    }

    lookup[params] = result;
    return result;
}

int count(int x) {
    if (x < 0) return 0;
    s = to_string(x);
    lookup.clear();
    return recurse(0, 0, true, true);
}

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int a, b;
    cin >> a >> b;

    int ans = count(b) - count(a - 1);
    cout << ans << ENDL;

    return 0;
}