import math
line = input()
line = line.split()
a = int(line[0])
b = int(line[1])
v = int(line[2])
per = a - b
day = math.ceil((v - a) / per) + 1
print(int(day))
