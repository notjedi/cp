from collections import defaultdict

LIMIT = 100000
isPrime = defaultdict(lambda : True)

for i in range(2, LIMIT):
    if not isPrime[i]:
        continue
    for j in range(i * i, LIMIT, i):
        isPrime[j] = False

for num in permutations("56**3"):
    curr = [''.join(list(num).replace('*', str(i))) for i in range(10)]
    for i in range(10):
        cur.num
