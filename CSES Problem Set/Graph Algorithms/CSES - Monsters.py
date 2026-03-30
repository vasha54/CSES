"""
    CSES - Monsters

    Temática : Teoría de Grafos + BFS + FloodFill
    
    Idea: Dado una mapa de forma matricial en donde existen mounstruos, obstaculos 
    y tu tienes una posición inicial hallar si existe una forma de escapar del mapa
    (alcanzar unos de los bordes del mapa) sin ser capturado por uno de los 
    mounstruos. En caso de existir se debe decir la minima cantidad de pasos e 
    imprimir el recorrido. En cada paso solo te puedes mover una casilla en la 
    horizontal o verctical. Para solucionar el problema vamos a calcular para
    cada celda de la matriz accesible la mínima cantidad de pasos que se necesita 
    para que algunos de los mounstruos la alcance. Con esta informacion vamos 
    haremos los mismo a partir de mi posición inicial con la condición que solo
    puedo acceder a la celda Z si mi tiempo o cantidad de pasos es menor que el 
    tiempo o pasos minimo que necesita cualquier mounstruos para acceder a ella.
    En este procedimiento voy marcando para cada celda que acceda a partir de la 
    cual pude acceder.

    Luego solo chequear si algunas de las celdas que pude acceder estan el borde
    del mapa y quedarme con la menor cantidad de pasos y luego reconstruir el 
    camino de forma inversa es decir del final al principio.

"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
from math import inf as oo
 
# Comparadores en Estructuras de Datos
import heapq
import sys
import itertools

 
mov_r = [1,   -1,  0,   0, 2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [0,    0,  1,  -1, 1, -1, 1, -1, 2, 2, -2, -2]
mov_p = ['D' ,'U','R', 'L']
 
MOD = 10**9 + 7
INV2 = (MOD + 1) // 2   # inverso modular de 2
MAX = 10**6+10
# dp = [[0]*(MAX+5) for _ in range((MAX+5))]
# matrix = [[0]*(columns) for _ in range((rows))]

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def solve():
    input = sys.stdin.readline
    rows, cols = map(int, input().split())
    grid = [input().rstrip() for _ in range(rows)]

    INF = 10**9
    distM = [[INF]*cols for _ in range(rows)]
    q = deque()

    # Inicializar BFS de monstruos
    for r in range(rows):
        row = grid[r]
        for c in range(cols):
            ch = row[c]
            if ch == 'M':
                distM[r][c] = 0
                q.append((r,c))
            elif ch == '#':
                distM[r][c] = -1  # pared

    # 4 direcciones
    dr = [1,-1,0,0]
    dc = [0,0,1,-1]

    # BFS multi-origen (monstruos)
    while q:
        r,c = q.popleft()
        d = distM[r][c] + 1
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < rows and 0 <= nc < cols and distM[nr][nc] != -1:
                if distM[nr][nc] > d:
                    distM[nr][nc] = d
                    q.append((nr,nc))

    # Encontrar inicio
    start = None
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 'A':
                start = (r,c)
                break
        if start: break

    # Si inicio en borde -> escape inmediato
    sr, sc = start
    if sr == 0 or sr == rows-1 or sc == 0 or sc == cols-1:
        print("YES")
        print(0)
        print("")  # camino vacío
        return

    # BFS desde A con restricción distA + 1 < distM[next]
    distA = [[INF]*cols for _ in range(rows)]
    parent = [['']*cols for _ in range(rows)]  # store move from parent -> child: 'U','D','L','R'
    q = deque()
    distA[sr][sc] = 0
    q.append((sr,sc))

    end = None
    # mapping de índices a letras (movimiento desde padre hacia hijo)
    moves = [(1,0,'D'),(-1,0,'U'),(0,1,'R'),(0,-1,'L')]

    while q and end is None:
        r,c = q.popleft()
        curd = distA[r][c]
        for dr_, dc_, ch in moves:
            nr, nc = r + dr_, c + dc_
            nd = curd + 1
            if 0 <= nr < rows and 0 <= nc < cols:
                if grid[nr][nc] == '#': 
                    continue
                # distM[nr][nc] == -1 => pared, ya filtrado; INF => monstruo nunca llega
                monster_time = distM[nr][nc]
                if nd < distA[nr][nc] and (monster_time == INF or nd < monster_time):
                    distA[nr][nc] = nd
                    parent[nr][nc] = ch
                    q.append((nr,nc))
                    # si llegamos al borde, terminamos
                    if nr == 0 or nr == rows-1 or nc == 0 or nc == cols-1:
                        end = (nr,nc)
                        break

    if end is None:
        print("NO")
        return

    # Reconstruir camino desde end hasta start
    path_chars = []
    r,c = end
    while (r,c) != (sr,sc):
        ch = parent[r][c]
        path_chars.append(ch)
        # mover en sentido inverso para ir al padre
        if ch == 'U':
            r += 1
        elif ch == 'D':
            r -= 1
        elif ch == 'L':
            c += 1
        elif ch == 'R':
            c -= 1

    path_chars.reverse()
    print("YES")
    print(len(path_chars))
    print(''.join(path_chars))

if __name__ == "__main__":
    solve()
