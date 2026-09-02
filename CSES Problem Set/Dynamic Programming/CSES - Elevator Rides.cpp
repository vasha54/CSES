/**
 * CSES - Elevator Rides
 * Temática: Programación Dinámica + Mascara de Bits
 *
 * Idea: 
 * ## Enfoques greedy erróneos
 * 
 * Inicialmente podría parecer que un enfoque greedy podría resolver el problema:
 * elegir personas para un viaje en el ascensor mientras quepan. Sin embargo,
 * no se conoce una forma simple de elegir a la siguiente persona que funcione
 * de manera óptima en todos los casos.
 * 
 * Por ejemplo, considere la entrada
 * 
 * x = 8
 * w = 4, 3, 3, 2, 2, 2.
 * 
 * Ni una estrategia que siempre elija a la persona más pesada que aún quepa en
 * el ascensor, ni la que elige a la más liviana, pueden encontrar la solución
 * óptima, que son dos ascensores llenos:
 * 
 * (4, 2, 2), (3, 3, 2)
 * 
 * ## Permutaciones
 * 
 * Iterar sobre todas las permutaciones de las personas es suficiente para
 * resolver el problema. La idea es agregar personas al ascensor una por una
 * mientras la siguiente persona quepa, y comenzar un nuevo viaje en caso
 * contrario. Cualquier asignación de ascensores corresponderá a alguna
 * permutación a partir de la cual se pueda reconstruir la solución.
 * 
 * Hay como máximo 20! ≈ 10^18 permutaciones diferentes, por lo que no se puede
 * verificar cada una individualmente. La idea se puede optimizar haciendo
 * programación dinámica sobre subconjuntos de personas, también llamada
 * programación dinámica con máscara de bits.
 * 
 * ## De permutaciones a subconjuntos
 * 
 * Al elegir personas una por una, la única información que se necesita
 * considerar es el *subconjunto* de personas que ya han sido asignadas a
 * viajes en el ascensor. El orden en que se eligieron las personas anteriores
 * no importa siempre que sea óptimo.
 * 
 * Sea la función best cuyos valores son de la forma best(S) = (r, l), donde el
 * par (r, l) describe el número óptimo de viajes en ascensor r y el peso ya
 * utilizado en el último viaje l para cualquier subconjunto S de personas.
 * Entre soluciones con la misma cantidad de viajes, se considera mejor la que
 * tenga el menor l.
 * 
 * La función se puede calcular recursivamente probando individualmente a cada
 * persona en el subconjunto como la última persona a considerar.
 * 
 * dp_mask(S) = min_{p∈S} add(dp_mask(S \ {p}), w_p)
 * 
 * Aquí, add((r, l), w_p) intenta agregar a la persona p al último viaje del
 * ascensor como (r, l + w_p), o establece un nuevo viaje como (r+1, w_p)
 * si l + w_p > x.
 * 
 * Establecemos best(∅) = (1, 0) como caso base para que el resto de los valores
 * sean correctos aunque técnicamente se necesiten cero viajes.
 * 
 * Sería posible hacer que la cantidad de viajes en ascensor sea una variable
 * de la función, como best(S, r) = l, y minimizar solo el peso total del
 * último viaje. Sin embargo, esto no es necesario porque nunca hay ambigüedad
 * al comparar pares (r, l). Es decir, un par con menos viajes siempre es
 * estrictamente mejor que uno con más. Esto nos permite encontrar el par
 * óptimo de manera similar a como se puede optimizar un solo número con
 * programación dinámica. De hecho, los operadores de comparación por defecto
 * de std::pair funcionan de la manera correcta.
 * 
 * El subconjunto S se representa convenientemente como una máscara de bits en
 * la solución a continuación. Iterar sobre las máscaras de bits en el orden
 * correspondiente a sus valores numéricos garantiza que todos los subconjuntos
 * más pequeños se calculen antes que el actual. La solución tiene una
 * complejidad temporal de O(n 2^n).
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

int nweight, max_weight;
pii dp_mask[1 << MAX_N];

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    cin>>nweight>>max_weight;

    vector<int> weights(nweight);

    for(int i=0;i<nweight;i++) cin>>weights[i];

    dp_mask[0] = {1, 0};
    for (int s = 1; s < (1 << nweight); ++s) {
        dp_mask[s] = {nweight + 1, 0};

        for (int p = 0; p < nweight; ++p) {
            if (s & (1 << p)) {
                auto [rider, weight] = dp_mask[s ^ (1 << p)];
                pii added;
                if (weight + weights[p] <= max_weight) {
                    added = {rider, weight + weights[p]};
                } else {
                    added = {rider + 1, weights[p]};
                }
                dp_mask[s] = min(dp_mask[s], added);
            }
        }
    }

    cout << dp_mask[(1 << nweight) - 1].first << ENDL;

    return 0;
}