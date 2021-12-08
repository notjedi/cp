from collections import Counter, defaultdict

def progression(x):
    return (x * (x+1)) // 2

def solve(pos):

    minPos = min(pos)
    maxPos = max(pos)
    p1 = defaultdict(int)
    p2 = defaultdict(int)

    for i in range(minPos, maxPos + 1):
        for k in pos:
            p1[i] += abs(i - k)
            p2[i] += progression(abs(i - k))

    print(min(p1.values()))
    print(min(p2.values()))


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day7", "r")
    pos = list(map(int, file.read().strip().split(',')))

    solve(pos)
