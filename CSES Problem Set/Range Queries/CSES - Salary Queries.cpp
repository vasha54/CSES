/*
* CSES - Salary Queries
* Tematica: Estructura de datos + Estructuras de datos basado en políticas
*
* Idea: Dado el salario de un grupo de trabajadores sobre los cuales se realiza
* dos operaciones:
*  - Dado el trabaador i se actualiza su salario con x cantidad
*  - Dado los valores a y b encontrar la cantidad de trabajadores su salario este
*  en ese rango.
* Clásico problema de utilizanción de esta estructura
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

tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> Tree;
int nemployees, nqueries, a, b;
char operation;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nemployees>>nqueries;
    vector<int> employees(nemployees+5);

    for(int i=1;i<=nemployees;i++){
        cin>>employees[i];
        Tree.insert({employees[i], i});
    }

    for(int i=0;i<nqueries;i++){
        cin>>operation;
        switch(operation){
            case '!':
                cin>>a>>b;
                Tree.erase({employees[a], a});
                Tree.insert({b, a});
                employees[a] = b;
            break;
            case '?':
                cin>>a>>b;
                cout<<Tree.order_of_key({b+1, 0}) - Tree.order_of_key({a, 0})<<ENDL;
            break;
        }
    }
    return 0;
}
