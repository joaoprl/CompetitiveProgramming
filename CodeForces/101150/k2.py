
# K2. Fair Warning

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

n = int(input())

list = []
while len(list) < n:
    numbers = input().split()
    list += [int(x) for x in numbers]
list.sort()

list2 = [list[0]]
for i in list:
    if i != list2[-1]:
        list2 += [i]

diff = list2[1] - list2[0]
for i in range(0, len(list2)):
    for j in range(i + 1, len(list2)):
        diff = gcd(diff, list2[j] - list2[i])

ba = diff - list2[0] % diff
if list2[0] % diff == 0:
    ba = 0

print(ba)
