"""
    CSES - Next Prime

    Temática : Teoría Número + Test probabilisticos de primos
    
    Idea: Dado un numero N determinar el siguiente numero de N que sea número 
    primo. Con la aplicación del test probailistico de Miller–Rabin.

    Sea π(n) la cantidad de números primos entre 1 y n. Se sabe que π(n) ≈ n / log n
    y en la práctica, las brechas entre dos números primos sucesivos no son muy grandes. 
    Por esta razón, podemos resolver este problema simplemente iterando sobre los números mayores 
    que n hasta encontrar el primer número primo. La brecha más grande entre primos entre 1 y 10^{12} es 
    540, la cual ocurre entre los números primos 738832927927 y 738832928467.

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
MAX = 10**4
INF = 10**9

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()


def is_prime(n):
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False

    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1

    for a in (2, 3, 5, 7, 11, 13):
        if a >= n:
            continue
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(s - 1):
            x = (x * x) % n
            if x == n - 1:
                break
        else:
            return False
    return True


def next_prime(n):
    if n < 2:
        return 2
    cand = n + 1
    if cand > 2 and cand % 2 == 0:
        cand += 1         
    while True:
        if is_prime(cand):
            return cand
        cand += 2  

def solve():
    input_line = read_nonempty
    cases = int(input_line())
    while cases > 0:
        cases -= 1
        n = int(input_line())
        print(next_prime(n))


if __name__ == "__main__":
    solve()
