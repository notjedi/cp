def progression(x):
    return (x * (x+1)) // 2

def solve(pos):

    pos = sorted(pos)
    minPos = min(pos)
    maxPos = max(pos)
    mid = len(pos) // 2
    p1, p2 = 0, 1e9

    for x in pos:
        p1 += abs(x - pos[mid])

    for i in range(minPos, maxPos + 1):
        score = 0
        for k in pos:
            score += progression(abs(i - k))
        if score < p2:
            p2 = score

    print(p1)
    print(p2)


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day7", "r")
    pos = list(map(int, file.read().strip().split(',')))

    solve(pos)
