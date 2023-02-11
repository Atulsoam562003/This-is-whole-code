class node:
    def __init__(self,a):
        self.list=a

a=node([1,1,1,1])
b=node([0,0,1,1])
c=node([0,1,0,1])
d=node([0,1,1,0])
e=node([1,1,1,0])
f=node([0,1,0,0])
g=node([1,1,0,0])
h=node([1,1,0,1])
i=node([0,0,0,1])
j=node([1,0,0,1])
k=node([1,0,1,1])
l=node([0,0,0,0])
m=node([0,0,1,0])
n=node([1,0,1,1])
o=node([1,0,1,0])

logic={ a:[b,c,d],
        b:[],
        c:[],
        d:[a,e],
        e:[d,f,m],
        f:[g,h,e],
        g:[],
        h:[i,f],
        i:[h,j,k],
        j:[i,l],
        k:[],
        l:[],
        m:[e,n,o],
        n:[m,i],
        o:[]
        }
# BFS
visited = []
queue = []
global found
found=0
def bfs(visited,logic, node):
  visited.append(node)
  queue.append(node)
  global found
  while queue and found==0:
    m = queue.pop(0)
    print(m.list)
    if(m==l):
        visited=1



for neighbour in logic[m]:
  if neighbour not in visited:
      visited.append(neighbour)
      queue.append(neighbour)


bfs(visited, logic, a)

## DFS
# visited2 = set()
# global found2
# found2=0
# def dfs(visited2, graph, node):
#     global found2
#     if node not in visited2 :
#         if(found2==0):
#           print (node.list)
#           visited2.add(node)
#           if(node==l):
#             found2=1
#           for neighbour in graph[node]:
#               dfs(visited2, graph, neighbour)
# dfs(visited2, logic, a)

# # DLS
# visited2 = set()
# global found2
# found2=0
# global depth
# depth=0
# def dfs(visited2, graph, node,limit):
#     global found2
#     global depth
#     if node not in visited2 and depth<=limit:
#         if(found2==0):
#           print (node.list)
#           visited2.add(node)
#           if(node==l):
#             found2=1
#           depth=depth+1
#           for neighbour in graph[node]:
#               dfs(visited2, graph, neighbour,limit)
#           depth=depth-1
# dfs(visited2, logic, a,3)
# if(found2==0):
#     print("Solution not found")

## IDDLS


# global found2
# found2=0
# global depth
# depth=0
# global x
# x=0
# def dfs(visited2, graph, node,limit):
#     global found2
#     global depth
#     if node not in visited2 and depth<=limit:
#         if(found2==0):
#           print (node.list)
#           visited2.add(node)
#           if(node==l):
#             found2=1
#           else :

#             depth=depth+1
#             for neighbour in graph[node]:
#                 dfs(visited2, graph, neighbour,limit)
#             depth=depth-1


# while(found2!=1):
#     visited2 = set()
#     dfs(visited2,logic,a,x)
#     #print("hello")
#     x=x+1


# print("Solution found at level:",x-1)