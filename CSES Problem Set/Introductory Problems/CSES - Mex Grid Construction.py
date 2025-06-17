"""
    CSES - Mex Grid Construction
    Temática : Matrices + Busqueda completa
    
    Idea: Dado un valor N crear una matriz donde cada valor en la celda [i,j] 
    debe ser el menor valor entero no negativo que no se repita con los valores
    en la misma fila hacia su izquierda y en su misma columna hacia arriba. Dado
    que la N es pequeña se puede realizar una búsqueda completa para cada celda.
    
    Si i es igual j el valor en esa celda será simepre 0 para cualquier otro par
    (i,j) se buscará el elemento que corresponde.
    
    
"""
# Módulo functools y cmp_to_key
from functools import cmp_to_key

# Comparadores en Estructuras de Datos
import heapq

def search(_matrix, _row, _column, n):
    _candidates = [i for i in range(1,n*2)]
    irow = _row
    icolumn = _column
    while icolumn>=0:
        if _matrix[_row][icolumn] in _candidates:
            _candidates.remove(_matrix[_row][icolumn])
        icolumn-=1
    while irow>=0:
        if _matrix[irow][_column] in _candidates:
            _candidates.remove(_matrix[irow][_column]) 
        irow-=1
        
    return _candidates[0];

def main():
    n = int(input())
    matrix = [ [ 0 for i in range(n) ] for i in range(n)  ]
    
    for i in range(1,n):
        matrix[i][0] = matrix[0][i] = i
    
    for i in range(1,n):
        for j in range(1,n):
            if i != j:
                matrix[i][j] = search(matrix,i,j,n)
                
    for row in matrix:
        for v in row:
            print(v,end=" ")
        print()
   
   

if __name__ == '__main__':
    main()