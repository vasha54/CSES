"""
 CSES - Building Teams (https://cses.fi/problemset/task/1668/)
 Tematica : Teoria de grafos: Grafo Bipartido
 Idea: Dado un grupo de personas y la relación de amistades que existen entre dichas personas
 se desea saber si se pueden conformar dos grupos con la condicíon de que las personas que conformen
 el mismo grupo no exista un par que sean amigos. Si modelamos el problema como un grafo donde las personas
 sean los nodos del grafo y va exisitir una arista entre dos nodos si esas personas son amigas la solución
 al problema ver si con el grafo que se construye dicho grafo es bipartido
"""
from collections import deque
		

if __name__ == "__main__":
  [npersons,relations] = input().split()
  npersons = int(npersons)
  relations = int(relations)	
  ady = [ [] for _ in range(npersons)]
  for _ in range(relations):
      [a,b]=input().split()
      a = int(a)
      b = int(b) 
      a -= 1
      b -= 1
      ady[a].append(b)
      ady[b].append(a)
      
  bipartide = True
  sides = [-1 for _ in range(npersons) ]
  
  queue = deque()
  
  for node in range(0,npersons):
      if sides[node] == -1:
          sides[node] = 0
          queue.append(node)
          while len(queue)>0:
              curr = queue.popleft()
              for i in range(0,len(ady[curr])):
                  ne = ady[curr][i]
                  if sides[ne] == -1:
                      sides[ne] = 1 ^ sides[curr]
                      queue.append(ne)
                  else:
                      bipartide = bipartide and (sides[ne] != sides[curr])
   
  sides = [str(x+1) for x in sides] 
  print(" ".join(sides)) if bipartide else print("IMPOSSIBLE")
    
