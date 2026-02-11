"""
    CSES - Raab Game I
    Temática : Simulación + Algoritmo constructivo
    
    Idea: Dado dos jugadores A y B con cartas con los valores de 1 a N se juega
    N rodas donde en cada ronda el jugador con la carta mas grande gana un punto s
    si ambas cartas tienen el mismo valor se considera empate y no hay puntos para los
    jugadores en esa ronda. Dado el valor de N y los puntos ganados por A y B de una 
    secuencia valida del juego si existe de no existir imprimir NO. Vamos analizar 
    el juego para determinar las condiciones de existencia de una posible solución
    Condiciones de existencia:
        - a + b <= n: La suma de los puntos no puede exceder el número de rondas.
        - No puede haber un jugador con 0 puntos y el otro con puntos positivos 
        (excepto cuando ambos tienen 0).
    Construcción del juego:
        - Si ambos tienen 0 puntos: Ambos jugadores juegan las cartas en el mismo 
        orden (todos empates).
        - Caso general: Se calcula k = n - a - b (número de empates).
        - Jugador A:
            - Primero las k cartas para empates (1..k).
            - Luego las a cartas más grandes para sus victorias.
            - Finalmente las cartas restantes.
 
        - Jugador B:
            - Primero las mismas k cartas para empates (1..k).
            - Luego las a cartas más pequeñas de las restantes (para las victorias de A).
            - Finalmente las b cartas más grandes (para sus propias victorias).
 
 
 
"""
from functools import cmp_to_key, reduce
from collections import deque
 
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
    line = input_line()
    t = int(line)
    for _ in range(t):
        n, a, b = map(int, input().split())
 
        # Condiciones para que exista un juego válido
        if a + b > n or ( a == 0 and b > 0 ) or (b == 0 and a > 0 ) :
            print("NO")
            continue
 
        print("YES")
 
        # Caso especial: ambos jugadores tienen puntaje 0 (todos empates)
        if a == 0 and b == 0:
            A = list(range(1, n + 1))
            B = list(range(1, n + 1))
        else:
            
            ties = n - (a + b) 
            A = (
                list(range(1, ties + 1))
                + list(range(n - a + 1, n + 1))
                + list(range(ties + 1, n - a + 1))
            )
            B = (
                list(range(1, ties + 1))
                + list(range(ties + 1, ties + a + 1))
                + list(range(ties + a + 1, n + 1))
            )
 
        print(*A)
        print(*B)
 
 
if __name__ == "__main__":
    solve()