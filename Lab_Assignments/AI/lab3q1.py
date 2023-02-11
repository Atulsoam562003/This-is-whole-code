class node:
    
    def __init__(self,l,r) :
        self.l=l
        self.r=r
        
        
a=node(['m','w','s','c'],[0,0,0,0])
b=node([0,'w',0,'c'],['m',0,'s',0])
c=node([0,0,'s','c'],['m','w',0,0])
d=node([0,'w','s',0],['m',0,0,'c'])
e=node(['m','w',0,'c'],[0,0,'s',0])
f=node([0,0,0,'c'],['m','w','s',0])
g=node([0,'w',0,0],['m',0,'s','c'])
h=node(['m',0,'s','c'],[0,'w',0,0])
i=node(['m',0,0,'c'],[0,'w','s',0])
j=node(['m','w','s',0],[0,0,0,'c'])
k=node(['m','w',0,0],[0,0,'s','c'])
l=node([0,0,'s',0],['m','w',0,'c'])
m=node([0,0,'s',0],['m','w',0,'c'])
n=node(['m',0,'s',0],[0,'w',0,'c'])
o=node(['m','w','s',0],[0,0,0,'c'])
p=node(['m',0,'s',0],[0,'w',0,'c'])
q=node([0,0,0,0],['m','w','s','c'])
r=node(['m','w',0,0],[0,0,'s','c'])
s=node([0,0,0,0],['m','w','s','c'])


A={a:[b,c,d],
   b:[e,a],
   c:[a],
   d:[a],
   e:[f,g,b],
   f:[h,i,e],
   g:[j,k,e],
   h:[l,f],
   i:[f],
   j:[m,g],
   k:[g],
   l:[n,o,h],
   m:[p,j],
   n:[q,l],
   o:[r,l],
   p:[s,m],
   q:[n],
   r:[o],
   s:[p] 
}
# visited=set()

# found=0

# def DFS(A,visited,node):
#     global found
#     if( found==0):
#          if(node==s or node==q): 
#            print("goal")
#            print(node.l, node.r)
#            found=1
#            return 
#          elif node not in visited:
#             print(node.l,node.r)
#             visited.add(node)
#             for neighbour in A[node]:
#                DFS(A,visited,neighbour)
# #DFS(A,visited,a)


# visited2=[]
# queue=[]
# global found2
# found2=0
# def BFS(A,visited2,node ):
#     visited2.append(node)
#     queue.append(node)
#     global found2
#     while queue and found2==0:
#         m=queue.pop(0)
#         print(m.l,m.r)
#         if(m==q or m==s):
#             found2=1

#         for neighbour in A[m]:
#             if neighbour not in visited2:
#                 visited2.append(neighbour)
#                 queue.append(neighbour)  
# BFS(A,visited2,a)

# visited3 =set()
# global found3
# found3=0
# global depth
# depth=0
# def DLS(A,visited3,node): 
#     global found3
#     global depth
#     if(found3==0 and depth<4):
#         if(node==q or node==s):
#             print("goal")
#             print(node.l,node.r)
#             found3=1
#             return
#         elif node not in visited3:
#             print(node.l,node.r)
#             visited3.add(node)
#             depth=depth+1
#             for neighbour in A[node]:
#                 DLS(A,visited3,neighbour)
#             depth=depth-1
# DLS(A,visited3,a)
# if found3==0 :
#     print("goal not found")


# global found4
# found4=0
# global d1
# d1=0

# def IDDFS(A,visited4,node,reach):    
#         #print("visited4 is",len(visited4))
#         global found4
#         global d1
        
#         if(found4==0 and d1<reach):
#             #print("d is ",d1,"depth is ",reach)
#             if(node==q or node==s):
#                 #print("hiiii")
#                 print("goal")
#                 print(node.l,node.r)
#                 found4=1
#                 return
#             elif node not in visited4:
#                 #print("heya")
#                 print(node.l,node.r)
#                 visited4.add(node)
#                 d1=d1+1
#                 for neighbour in A[node]:
                    
#                     IDDFS(A,visited4,neighbour,reach)
#                 d1=d1-1
            

# def IDDFS_call(A,node):
#     global found4
#     global d1
#     count=0
#     k=10
#     while(found4==0):
#         print("depth is ",count)
#         visited4=set()
#         d1=0  
#         IDDFS(A,visited4,node,count)
#         count=count+1        

# IDDFS_call(A,a) 


#Bidirectional BFS 
node=[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s]
queue5=[]
queue6=[]
global inter_node
def Bi_Dir(A,start,goal,visited5,visited6):
    global inter_node
    queue5.append(start)


    queue6.append(goal)
    visited5.add(start)
    visited6.add(goal)
    intersect=1
    while(queue5 and queue6 and intersect):
        for n in node:
            if n in visited5 and n in visited6:
                inter_node=n
                intersect=0
                return
                
        m=queue5.pop(0)
        print("from start",m.l,m.r)
        visited5.add(m)
        
        
        for neighbour in A[m] :
            if neighbour not in visited5:
                queue5.append(neighbour)

        n=queue6.pop(0)
        print("from end",n.l,n.r)
        visited6.add(n)

        for neighbour in A[n]:
            if neighbour not in visited6:
                queue6.append(neighbour)

visited5=set()
visited6=set()
Bi_Dir(A,a,q,visited5,visited6)
if inter_node!= None:
    print("meet at ",inter_node.l,inter_node.r)











        















   