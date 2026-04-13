"""
    CSES - Reading Books 

    Temática : Matemática, optimización , Búsqueda

    Idea: Kotivalo y Justiina deben leer todos los libros. Cada libro debe ser leído por 
    ambos, pero no pueden leer el mismo libro al mismo tiempo. Queremos el tiempo total 
    mínimo para que terminen.

    Observaciones:
    - Cada persona debe leer la suma total de tiempos S = sum(t_i). Por tanto,
      el tiempo total no puede ser menor que S.
    - Para un libro que toma tiempo t, como ambos lo leen y no pueden solaparse,
      ese libro por sí solo requiere al menos 2*t unidades de tiempo total
      (tiempo que pasa desde que uno empieza hasta que el otro termina).
      Luego el tiempo total es al menos 2 * max(t_i).
    - La respuesta es max(S, 2 * max(t_i)). 
      Se puede demostrar que este valor siempre es alcanzable (por ejemplo,
      ordenando los libros y asignando secuencias alternadas).

    Basta leer los tiempos, calcular suma y máximo, e imprimir el máximo
    entre la suma y el doble del máximo.

 
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
 

def solve():
    input_line = read_nonempty
    nbooks = int(input_line())
    books = list(map(int,input_line().split()))
    total = sum(books)
    max_book = max(books)
    ans = max(2*max_book, total)
    print(ans)

        
if __name__ == "__main__":
    solve()
