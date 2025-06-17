"""
    CSES - Sliding Window Sum
    Temática : Sliding Window variante deque
    
    Idea: Dada una lista de valores se quiere calcular la suma de cada sublista 
    de k elementos consecutivos, de izquierda a derecha. y con dichas sumas 
    obtener la operación xor entre dichos valores. Para solucionar el problemas 
    vamos aplicar la técnica de Ventana Deslizante (Sliding Window) con el uso
    de una deque donde vamos almacenar en orden los elementos y generando los
    subarreglos de k elementos y una variable P que llevara la suma de los elementos
    que estan dentro del deque. Cada vez que se procesa un valor de la lista 
    puede pasar lo siguiente:
         - La cantidad de elementos del deque es menor que k por tanto se suma 
        el valor a P y se adiciona al final del deque.
        - La cantidad de elementos en deque es igual k por tanto tengo un subarreglo
        de longitud k por tanto guardo el valor de P en la colección donde se van
        almacenar las sumas de los subarreglos. A P le resto el primer elemento del 
        deque el cual elimino del deque y se repite el proceso de sumar 
        el nuevo valor a P y adicionar al final del deque.
        
    Luego con colección de sumas de los subarreglos podemos aplicar un XOR con 
    todos los elementos
    
"""
from functools import cmp_to_key, reduce
from collections import deque

# Comparadores en Estructuras de Datos
import heapq

mov_r = [2, 2,-2,-2, 1,-1, 1,-1]
mov_c = [1,-1, 1,-1, 2, 2,-2,-2]


def main():
    n,k = map(int,input().split())
    x,a,b,c = map(int,input().split())
    arr = [0]*n
    arr[0] = x
 
    for i in range(1 , n):
        arr[i] = (a * arr[i-1] + b) % c
    
    window = sum(arr[:k])
    xor = window
 
    for i in range(k , n):
        window += arr[i] - arr[i - k]
        xor ^= window
 
    print(xor)
    

if __name__ == '__main__':
    main()