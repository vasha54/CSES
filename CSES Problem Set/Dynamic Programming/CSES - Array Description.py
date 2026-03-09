"""
    CSES - Array Description
    Temática : Programación Dinamica 
    
    Idea: Tenemos un arreglo de n enteros entre 1 y m, donde la diferencia 
        absoluta entre valores adyacentes es como máximo 1. Algunos valores 
        pueden ser desconocidos (representados por 0). Debemos contar cuántos 
        arreglos diferentes cumplen con la descripción. 

        Para resolver el problema vamos a crear una matriz dp[i][v] la cual
        almacenará para cada [i][v] la cantidad de veces que se puede llegar
        a la posición i con el valor v. La solución para las primeras i posiciones 
        depende de la solución para las primeras i-1 posiciones. Si conocemos 
        cómo llegar a la posición i-1 con cada valor posible, podemos determinar 
        cómo llegar a la posición i
           
        Para calcular dp[i][v] necesitamos dp[i-1][v-1], dp[i-1][v], dp[i-1][v+1]
    
        dp[i][v] = número de formas de construir un arreglo válido desde 
                   la posición 0 hasta la posición i, terminando con el 
                   valor v en la posición i
        Donde:
        - i ∈ [0, n-1] (índice en el arreglo)
        - v ∈ [1, m] (valor posible en esa posición)
        
        - Necesitamos saber el valor actual para aplicar la restricción 
          con la siguiente posición
        - No necesitamos valores anteriores porque la restricción es solo 
          entre adyacentes
    
        Para llegar a la posición i con valor v, la posición i-1 podía 
        tener tres valores posibles que cumplen |v - valor_anterior| ≤ 1:
        
        dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]
        
        Explicación de cada término:
        - dp[i-1][v-1]: el anterior era v-1 (diferencia = 1)
        - dp[i-1][v]:   el anterior era v (diferencia = 0)  
        - dp[i-1][v+1]: el anterior era v+1 (diferencia = 1)
        
"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def solve():
    input_line = read_nonempty
    MOD = 10**9 + 7
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    
    dp = [[0] * (m + 2) for _ in range(n)]
    
    if arr[0] == 0:
        for v in range(1, m + 1):
            dp[0][v] = 1
    else:
        dp[0][arr[0]] = 1
    
    for i in range(1, n):
        if arr[i] == 0:
            for v in range(1, m + 1):
                dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD
        else:
            v = arr[i]
            dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD
    
    if arr[-1] == 0:
        answer = sum(dp[n-1][1:m+1]) % MOD
    else:
        answer = dp[n-1][arr[-1]]
    
    print(answer)

if __name__ == "__main__":
    solve()