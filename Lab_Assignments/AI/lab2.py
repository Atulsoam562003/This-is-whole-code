import numpy as np
import time
import math
# from scipy.spatial.distance import cdist
import scipy.stats as stats
import matplotlib.pyplot as plt
from decimal import Decimal
from scipy.spatial import distance



P = np.random.randn(100,10);
Q = np.random.randn(100,10);

Q = Q.T
result = np.random.rand(100,100)

def mul(P,Q) :
    for i in range(len(P)):
        for j in range(len(Q[0])):
            for k in range(len(Q)):
                result[i][j] += P[i][k] * Q[k][j]
    return result


start_time = time.time()
mul(P,Q)
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
result = P.dot(Q);
print("--- %s seconds ---" % (time.time() - start_time))


# 2nd question starts

a = np.random.random(10);
b = np.random.random(10);

dist = np.linalg.norm(a - b);
print(dist)

corr = np.corrcoef(a,b)
print(corr)


# third started

u = np.array([2,1,2])
v = np.array([1,1,1])

def dotproduct(u, v):
  return sum((a*b) for a, b in zip(u, v))

def length(v):
  return math.sqrt(dotproduct(v, v))

def angle(u, v):
  return math.acos(dotproduct(u, v) / (length(u) * length(v)))

print(angle(u,v))

# 4th started

AB = mul(P,Q)
BA = mul(Q,P)

val , vec = np.linalg.eig(AB);
print(val)
val , vec = np.linalg.eig(BA);
print(val)


#5th started

def get_manhattan_distance(p, q):
    """
    Return the manhattan distance between points p and q
    assuming both to have the same number of dimensions
    """
    # sum of absolute difference between coordinates
    distance = 0
    for p_i,q_i in zip(p,q):
        distance += abs(p_i - q_i)

    return distance

# out = cdist(P, Q, metric='cityblock')
print(get_manhattan_distance(u,v))

def spiralOrder(matrix):
    ans = []

    if (len(matrix) == 0):
        return ans

    m = len(matrix)
    n = len(matrix[0])
    seen = [[0 for i in range(n)] for j in range(m)]
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]
    x = 0
    y = 0
    di = 0

    # Iterate from 0 to R * C - 1
    for i in range(m * n):
        ans.append(matrix[x][y])
        seen[x][y] = True
        cr = x + dr[di]
        cc = y + dc[di]

        if (0 <= cr and cr < m and 0 <= cc and cc < n and not(seen[cr][cc])):
            x = cr
            y = cc
        else:
            di = (di + 1) % 4
            x += dr[di]
            y += dc[di]
    return ans

arr = np.array([[1,2,3],[4,5,6],[7,8,9]])
print(spiralOrder(arr))

# 6th started
mu = 0
variance = 1
sigma = math.sqrt(variance)
x = np.linspace(mu - 3 * sigma, mu + 3 * sigma, 100)
plt.plot(x, stats.norm.pdf(x, mu, sigma))
# plt.show()

# 7th started

numbers = np.random.randint(0,10 , 5)
# print(numbers)
standard = np.std(numbers)
print(standard)

# 8th started
X = np.random.randn(4,4);
inverse = np.linalg.inv(X)
print(inverse)

#9 the started

def p_root(value, root):

    root_value = 1 / float(root)
    return round (Decimal(value) **
             Decimal(root_value), 3)

def minkowski_distance(x, y, p_value):

    # pass the p_root function to calculate
    # all the value of vector parallelly
    return (p_root(sum(pow(abs(a-b), p_value)
            for a, b in zip(x, y)), p_value))


vector1 = [0,2,3,4]
vector2 = [2,4,3,7]
p = 3
# print(minkowski_distance(vector1,vector2,p))
print(distance.minkowski(vector1, vector2, p))


# 11 is started

def normalize_rows(x: np.ndarray):
    return x/np.linalg.norm(x, ord=2, axis=1, keepdims=True)

# print(normalize_rows(X))
row_sums = X.sum(axis=1)
new_matrix = X / row_sums[:, np.newaxis]
print(new_matrix)


#12 started

x1=np.array([9, 2, 5, 0, 0, 7, 5, 0, 0, 0, 9, 2, 5, 0, 0])
x2=np.array([9, 2, 2, 9, 0, 9, 2, 5, 0, 0, 9, 2, 5, 0, 0])

print(np.dot(x1,x2))
print(np.outer(x1,x2))
print(np.multiply(x1,x2))
print(np.sum(x1 * x2 ,axis = 0))