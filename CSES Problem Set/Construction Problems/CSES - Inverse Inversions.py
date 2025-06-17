"""
    CSES - Inverse Inversions
    Temática : Algebra 
    
    Idea: Se quiere generar una permutación de 1 a N que tenga exactamente K
    inversiones donde un inversion es un par (a,b) en la permutación tal que
    se cumpla las dos siguientes condiciones:
    1. a < b
    2. La posicion de a en la permutación debe ser mayor que la posicion de b
    en la permutación
    
    Para construir la permutación deseada vamos a analizar lo siguiente:
    - Si tomanos una permutación de 1 a N y ordenamos los valores de forma
    decreciente vamos a obtener una permutacion con un total de (n*(n-1))/2
    inversiones donde la expresión anterior responde a una modificación de la
    sumatoria de gauss. Por lo que si tenemos una permutación de 1 a N de forma
    creciente y invertimos todos los primeros i elementos sabremos que la cantidad 
    de inversiones responde a la expresión anterior.
    
    Apoyados en lo anterior vamos a generar una secuencia de valores ordenados 
    de forma creciente con los valores de 1 a N. Luego en el intervalo de 1 a N
    buscaremos el valor p tal que GaussSum(p)(P) sea el mayor posible pero siempre 
    menor estricto a K. Hallado el valor p podemos invertir los primeros p elementos
    de la secuencia inicial esto nos garantiza P inversiones. Bien una vez realizado
    lo anterior puede pasar dos cosas:
    1. K - P == 0 significa que no quedan inversiones pendientes y ya hemos encontrado
    la permutación solicitada
    2 K - P > 0 significa que quedan inversiones pendientes por tanto solo debemos
    tomar el ultimo valor de la permutacion actual y moverlo para adelante 
    K-P posiciones hacia adelante.
    
"""
from functools import cmp_to_key, reduce
from collections import deque

# Comparadores en Estructuras de Datos
import heapq

mov_r = [2, 2,-2,-2, 1,-1, 1,-1]
mov_c = [1,-1, 1,-1, 2, 2,-2,-2]

def gauss_sum(n):
    return (n * (n-1))//2

def main():
    n,k = map(int,input().split())
    permutations = [x for x in range (1,n+1)]
    inversions = 0
    pre = []
    index = 1    
    while gauss_sum(index+1) < k:
        index+=1
    reverse = permutations[:index][::-1]
    permutations= reverse+permutations[index:]
    
    inversions = gauss_sum(index)
    k=k-inversions
    #print(permutations,k)
    if k != 0:
        last = permutations[-1]
        permutations = permutations[:-1]
        index = ((len(permutations))-k)
        permutations.insert(index,last)
    
    answer = " ".join([ str(x) for x in permutations])
    print(answer)
    

if __name__ == '__main__':
    main()