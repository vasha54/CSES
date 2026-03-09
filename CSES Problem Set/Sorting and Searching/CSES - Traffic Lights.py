"""
    CSES - Traffic Lights
    Temática : Ordenamiento + OffLine Query
    
    Idea:Dada una carretera de longitud D a oscura se van colocando luces en 
    determinadas posiciones de la carreteras sin repetir las posiciones y se 
    quiere saber para cuando se coloque la inesima luz cual es la mayor distancia 
    de la carretera sin luz.

    Para resolver el problema vamos a procesar toda la entrada y responder las 
    preguntas en orden inverso al que se hicieron. Lo primero es ubicar todas 
    las luces sobre la carretera de forma que cada luz sepa cual es la posición
    de la luz a su derecha y a su izquierda siempre que existan una vez realizado
    esto podemos iterar sobre las luces en orden de la posición y hallar el tramo 
    mas oscuro que sería la distancia mayor entre dos luces consecutivas dicho 
    resultado sería la respuesta a la última luz que se pone ya que estarían todas
    las luces puesta sobre la carretera.

    Para resovlver el resto de preguntas vas ir retirando las luces en orden inverso 
    a como fueron colocando cada vez que retiro una luz actualizo sus luces izquierda 
    y derecha si existen con la nuevas luces mas próximas y calculo la distancia 
    entre ellas si es mayor a la distancia de mayor oscuridad hasta ese momento 
    actualizo el valor y meto el valor a la lista de respuesta sino vuelvo adiccionar 
    el ultimo elemento adicionado a la lista de respuestas ya que la maxima distnacia 
    a oscura sera siendo la misma. Luego solo tengo que imprimir la lista de respuesta 
    en orden inverso.  
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
MAX = 10**5
INF = 10**9

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def solve():
    input_line = read_nonempty
    distance, nligths = map(int, input_line().split())
    p = list(map(int, input_line().split()))

    pos = sorted(p)
    pos = [0] + pos + [distance]
    
    prev = {}
    nxt = {}
    for i in range(len(pos)):
        if i > 0:
            prev[pos[i]] = pos[i-1]
        if i < len(pos)-1:
            nxt[pos[i]] = pos[i+1]
    
    distances = [pos[i+1] - pos[i] for i in range(len(pos)-1)]
    freq = {}
    heap = []
    for d in distances:
        freq[d] = freq.get(d, 0) + 1
        heapq.heappush(heap, -d)
    
    
    answer = []
    while heap and freq.get(-heap[0], 0) == 0:
        heapq.heappop(heap)
    best_current = -heap[0]
    answer.append(str(best_current))
    
    for luz in reversed(p):
        left = prev[luz]
        right = nxt[luz]
        
        d1 = luz - left
        d2 = right - luz
        freq[d1] -= 1
        freq[d2] -= 1
        
        d_new = right - left
        freq[d_new] = freq.get(d_new, 0) + 1
        heapq.heappush(heap, -d_new)
        
        nxt[left] = right
        prev[right] = left
        
        while heap and freq.get(-heap[0], 0) == 0:
            heapq.heappop(heap)
        
        best_current = -heap[0]
        answer.append(str(best_current))
    
    answer.pop()
    print(" ".join(reversed(answer)))

if __name__ == "__main__":
    solve()