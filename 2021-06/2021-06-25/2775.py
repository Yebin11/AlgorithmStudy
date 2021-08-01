t = int(input())
arr = []
for i in range(0, 15):
    line = []
    if i != 0:
        line.append(1)
        for j in range(1, 14):
            line.append(line[j-1] + arr[i-1][j])
    else:
        for j in range(1, 15):
            line.append(j)
    arr.append(line)

for _ in range(0, t):
    k = int(input())
    n = int(input())
    print(arr[k][n - 1])