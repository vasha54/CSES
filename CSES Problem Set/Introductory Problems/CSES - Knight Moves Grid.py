"""
    CSES - Knight Moves Grid
    Temática : BFS
    
    Idea: Dado un tablero de NxN y una pieza de ajedrez de tipo caballo colocado
    en la esquina superior izquierda del tablero calcular la minima cantidad de
    pasos para desde esa posición llegar a cualquier celda del tablero . Como
    el costo de pasar de una celda a otras es igual (1) podemos aplicar un BFS
    que visite todas las celdas del tablero y calcular el camino mínimo de la
    celda (0,0) hacia todas las demás.
    
"""
from functools import cmp_to_key
from collections import deque

# Comparadores en Estructuras de Datos
import heapq

mov_r = [2, 2,-2,-2, 1,-1, 1,-1]
mov_c = [1,-1, 1,-1, 2, 2,-2,-2]

def valid_cell(r, c, n):
    return (0<= c and c<n and 0<=r and r< n)

def main():
    n = int(input())
    matrix = [ [ n*n+100 for i in range(n) ] for i in range(n)  ]
    
    matrix[0][0]=0
    
    bfs = deque()
    
    bfs.append([0,0])
    
    while bfs:
        row,column = bfs.popleft()
        
        for i in range(8):
            nr = row + mov_r[i]
            nc = column + mov_c[i]
            if valid_cell(nr, nc, n) and matrix[nr][nc] > matrix[row][column]+1:
                matrix[nr][nc] = matrix[row][column]+1
                bfs.append([nr,nc])
    
    for row in matrix:
        for v in row:
            print(v,end=" ")
        print()
   
   

if __name__ == '__main__':
    main()