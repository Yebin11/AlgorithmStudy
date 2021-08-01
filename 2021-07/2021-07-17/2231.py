n = int(input())
flag = False
res = 0
for i in range(n//2, n):
    sum = i
    tmp = i
    while tmp > 0:
        sum += tmp % 10
        tmp //= 10
    if sum == n:
        res = i
        break
print(res)