import time


t1 = time.time_ns()/1000000

sum = 0
for i in range(0,100000000):
	sum^=i
print(sum)
t2 = time.time_ns()/1000000
print(t2-t1)