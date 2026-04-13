"""
    CSES - Divisor Analysis
 
    Temática : Teoría de Numero + Divisores + Exponenciación binaria + Inverso Multiplicativo
    
    Idea: 
 
"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
import itertools
import math
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7
MODM1 = MOD - 1          # para exponentes
MOD2M1 = 2 * MODM1       # para reducir d(N) antes de dividir por 2

MAX = 10**6+10
INF = 10**9
# dp = [[0]*(MAX+5) for _ in range((MAX+5))]
 
def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()
 
def mod_pow(a, b, mod):
    res = 1
    a %= mod
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res
 
def solve():
    input_line = read_nonempty
    nfactors = int(input_line())
    
    num_div = 1            
    sum_div = 1            
    d_mod2 = 1             
    N_mod = 1              
    sqrtN_mod = 1          
    any_odd = False        
    
    for _ in range(nfactors):
        fac, exp = map(int,input_line().split())
        num_div = num_div * ((exp + 1) % MOD) % MOD

        num = (mod_pow(fac, exp + 1, MOD) - 1) % MOD
        den_inv = mod_pow(fac - 1, MOD - 2, MOD)
        contrib = num * den_inv % MOD
        sum_div = sum_div * contrib % MOD

        d_mod2 = d_mod2 * ((exp + 1) % MOD2M1) % MOD2M1
        
        N_mod = N_mod * mod_pow(fac, exp, MOD) % MOD
        
        sqrtN_mod = sqrtN_mod * mod_pow(fac, exp // 2, MOD) % MOD
        
        if exp & 1:
            any_odd = True
    
    if any_odd:
        exp = (d_mod2 // 2) % MODM1
        prod_div = mod_pow(N_mod, exp, MOD)
    else:
        exp = d_mod2 % MODM1
        prod_div = mod_pow(sqrtN_mod, exp, MOD)
    
    print(num_div, sum_div, prod_div)
 
if __name__ == "__main__":
    solve()
