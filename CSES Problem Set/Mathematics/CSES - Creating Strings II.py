"""
    CSES - Creating Strings II

    Temática : Combinatoria + Permutación con repetición + Inverso multiplicativo
    
    Idea: Se nos da una cadena de caracteres (solo letras minúsculas ‘a’–‘z’) de 
    longitud hasta n ( n <= 10^6). Queremos contar cuántas cadenas distintas 
    podemos formar reordenando sus caracteres. Es decir, se trata de contar el 
    número de permutaciones distintas de la cadena, teniendo en cuenta que 
    algunos caracteres pueden repetirse.

    Si todos los caracteres fueran distintos, la cantidad de permutaciones sería 
    n!. Sin embargo, cuando hay letras repetidas, muchas permutaciones son 
    idénticas. Para una letra que aparece f! permutaciones internas no generan 
    cadenas diferentes. Por tanto, el número total de cadenas distintas viene 
    dado por la fórmula de permutaciones con repetición.

"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
import itertools
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7
INV2 = (MOD + 1) // 2   # inverso modular de 2
MAX = 10**6+10
INF = 10**9
# dp = [[0]*(MAX+5) for _ in range((MAX+5))]

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()


def solve():
    input_line = read_nonempty
    
    string = input_line()
    n = len(string)
    
    freq = [0] * 26
    for ch in string:
        freq[ord(ch) - 97] += 1

    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i-1] * i % MOD

    inv_fact = [1] * (n + 1)
    inv_fact[n] = pow(fact[n], MOD-2, MOD)
    for i in range(n, 0, -1):
        inv_fact[i-1] = inv_fact[i] * i % MOD

    ans = fact[n]
    for cnt in freq:
        if cnt > 0:
            ans = ans * inv_fact[cnt] % MOD

    print(ans)

if __name__ == "__main__":
    solve()

