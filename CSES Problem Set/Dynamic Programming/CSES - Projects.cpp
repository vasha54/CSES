/**
 * CSES - Projects
 * Temática: Programación Dinámica + Ordenamiento + Búsqueda Binaria
 *
 * Idea: Weighted Interval Scheduling. Se deben elegir proyectos no solapados
 * que maximicen la recompensa total. Dos proyectos son compatibles si el
 * día de finalización de uno es ESTRICTAMENTE MENOR que el día de inicio
 * del otro (finish < start).
 *
 * - Se ordena por día de finalización.
 * - dp[i] = máxima recompensa usando un subconjunto de los primeros i proyectos.
 * - Para cada proyecto i se busca el último j con finish < start_i.
 * - Transición: dp[i] = max(dp[i-1], dp[j] + reward_i).
 * - Complejidad: O(n log n) en tiempo, O(n) en memoria.
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
#define MAX_N 1000001
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;


struct Job {
    int start, finish, weight;
};

bool compareByFinish(const Job &a, const Job &b) {
    return a.finish < b.finish;
}

// Retorna el índice del último trabajo con finish < start_i
int lastCompatible(const vector<Job> &jobs, int i) {
    int lo = 0, hi = i - 1;
    int start_i = jobs[i].start;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (jobs[mid].finish < start_i) {          // <-- estricto
            if (mid == hi || jobs[mid + 1].finish >= start_i)
                return mid;                        // último compatible
            else
                lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1; // ningún trabajo compatible
}

int weightedIntervalScheduling(vector<Job> &jobs) {
    int n = jobs.size();
    if (n == 0) return 0;

    sort(jobs.begin(), jobs.end(), compareByFinish);

    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        p[i] = lastCompatible(jobs, i);
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int incl = jobs[i - 1].weight;
        if (p[i - 1] != -1)
            incl += dp[p[i - 1] + 1];
        dp[i] = max(dp[i - 1], incl);
    }
    return dp[n];
}

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].weight;
    }

    cout << weightedIntervalScheduling(jobs) << ENDL;
    return 0;
}