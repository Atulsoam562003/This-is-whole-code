import numpy as np
import time

m1, n1, r1 = 2, 3, 4
m2, n2, r2 = 2, 3, 4

t1 = np.random.normal(0, 1, (m1, n1, r1))
t2 = np.random.uniform(m2, n2, r2)

c1, c2, c3 = 2, 3, 4

start_time = time.time()

result = c1*t1 + c2*t2 + c3

end_time = time.time()

print(result)

print("Time to perform the linear operation:", end_time - start_time)
