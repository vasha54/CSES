/*
* CSES - Minimal Grid Path
* 
* Temática : Programación Dinamica + BFS
*    
* Idea: El problema consiste en encontrar la cadena lexicográficamente mínima 
* que se obtiene al recorrer una cuadrícula de n×n desde la esquina superior 
* izquierda hasta la inferior derecha, moviéndose solo hacia la derecha o 
* hacia abajo. Cada celda contiene una letra mayúscula.
* 
* La solución se basa en construir la cadena paso a paso, considerando en 
* cada etapa las posiciones alcanzables y eligiendo la letra más pequeña 
* posible. 
* 
* El algoritmo consta de 2n-2 rondas que construyen la cadena mínima 
* correspondiente a un camino desde la esquina superior izquierda hasta la 
* esquina inferior derecha. Durante todo el proceso, se mantiene un prefijo 
* de esta cadena mínima.
* 
* En cada ronda, examinamos todas las posibles posiciones finales de los 
* caminos que corresponden al prefijo actual. El prefijo se extiende agregando 
* una nueva letra. Desde cada posición final, consideramos moverse un paso 
* hacia la derecha y un paso hacia abajo para determinar la siguiente letra 
* que se agregará al camino.
* 
* Es importante asegurarse de que la lista de posiciones finales contenga solo 
* posiciones distintas después de cada ronda. De lo contrario, el algoritmo 
* podría procesar las mismas posiciones finales múltiples veces, haciéndolo 
* ineficiente.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define CELL_FREE '.'
#define CELL_WALL '#'
#define PRINT_LINE cout<<ENDL;
using namespace std;
using namespace __gnu_pbds;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};
 

 
signed main()
{
    //OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<pair<int, int>> current = {{0, 0}};
    string result;
    
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int step = 0;
    
    for (int len = 0; len < 2 * n - 1; ++len) {
        char min_char = 'Z';
        for (auto [i, j] : current) {
            if (grid[i][j] < min_char) {
                min_char = grid[i][j];
            }
        }
        result.push_back(min_char);

        step++;  
        vector<pair<int, int>> next;
        for (auto [i, j] : current) {
            if (grid[i][j] == min_char) {
                if (i + 1 < n && visited[i + 1][j] != step) {
                    visited[i + 1][j] = step;
                    next.emplace_back(i + 1, j);
                }
                if (j + 1 < n && visited[i][j + 1] != step) {
                    visited[i][j + 1] = step;
                    next.emplace_back(i, j + 1);
                }
            }
        }
        current.swap(next);  
    }

    cout << result << ENDL;
    return 0;
}