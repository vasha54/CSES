/**
 * CSES - Hidden Permutation
 * Temática: Problemas Interactivos + Merge Sort
 * 
 * Idea: Se nos presenta una permutación oculta a[1..n] de los números 1..n.
 * Podemos hacer consultas del tipo "? i j" que devuelven YES si a_i < a_j.
 * El objetivo es descubrir la permutación con a lo sumo 10^4 consultas, n ≤ 1000.
 *
 * La observación clave es que si logramos ordenar los índices 1..n según
 * el valor de a_i, automáticamente conoceremos la permutación: el índice
 * que quede primero (el de menor a_i) corresponde al valor 1, el siguiente
 * al 2, ..., y el último al valor n.
 *
 * Por lo tanto, el problema se reduce a ordenar un arreglo de índices
 * usando un comparador interactivo. Merge sort (ordenamiento por mezcla)
 * es ideal aquí porque garantiza O(n log n) comparaciones. Para n=1000,
 * el peor caso ronda las 8976 consultas, muy por debajo de 10^4.
 *
 * Estrategia:
 * 1. Leer n.
 * 2. Crear vector idx = [1, 2, ..., n].
 * 3. Ordenar idx con merge sort, usando una función que pregunta al juez
 *    "? i j" para decidir si idx[i] debe ir antes que idx[j] (a_i < a_j).
 * 4. Una vez ordenado idx, asignar: ans[idx[0]] = 1, ans[idx[1]] = 2, ..., 
 *    ans[idx[n-1]] = n.
 * 5. Imprimir "! a_1 a_2 ... a_n".
 *
 * Cuidados interactivos:
 * - Imprimir cada línea con endl para forzar el flush.
 * - Leer las respuestas como string: "YES" o "NO".
 * - No exceder el límite de consultas.
 */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define MAX_N 200010
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;

bool question(int i, int j) {
    cout << "? " << i << " " << j << ENDL;
    string response;
    cin >> response;
    return response == "YES";
}

void merge(vector<int>& indexs, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (question(indexs[i], indexs[j])) {
            temp[k++] = indexs[i++];
        } else {
            temp[k++] = indexs[j++];
        }
    }
    while (i <= m) temp[k++] = indexs[i++];
    while (j <= r) temp[k++] = indexs[j++];
    for (i = 0; i < (int)temp.size(); ++i)
        indexs[l + i] = temp[i];
}

void mergeSort(vector<int>& indexs, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(indexs, l, m);
    mergeSort(indexs, m + 1, r);
    merge(indexs, l, m, r);
}


signed main()
{
    //OPTIMIZAR_IO
    //PRESICION(2)
    //READ_FILE
    //WRITE_FILE

    int n;
    cin >> n;

    vector<int> indexs(n);
    for (int i = 0; i < n; ++i)
        indexs[i] = i + 1;

    mergeSort(indexs, 0, n - 1);

    vector<int> permutation(n + 1);  
    for (int k = 0; k < n; ++k) {
        permutation[indexs[k]] = k + 1;
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << permutation[i];
    }
    cout << ENDL;

    
    return 0;
}