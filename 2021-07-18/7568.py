from operator import itemgetter

n = int(input())
people = []

for i in range(n):
    line = input().split()
    line = [int(value) for value in line]
    people.append(line)

for i in range(n):
    cnt = 0
    for j in range(n):
        if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
            cnt += 1
    print(cnt + 1, end=' ')