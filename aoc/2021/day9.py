import numpy as np

def expand(i, j):

    count = 0
    pts[i][j] = True
    for dx in [i+1, i-1]:
        if 0 <= dx < rows and (lines[i][j] < lines[dx][j]) and lines[dx][j] != 9 and pts[dx][j] == 0:
            pts[dx][j] = True
            count += (1 + expand(dx, j))

    for dy in [j+1, j-1]:
        if 0 <= dy < cols and (lines[i][j] < lines[i][dy]) and lines[i][dy] != 9 and pts[i][dy] == 0:
            pts[i][dy] = True
            count += (1 + expand(i, dy))

    return count


def check_adj(lines, i, j):
    ok = True
    for dx in [i+1, i-1]:
        if 0 <= dx < rows and lines[dx][j] <= lines[i][j]:
            ok = False

    for dy in [j+1, j-1]:
        if 0 <= dy < cols and lines[i][dy] <= lines[i][j]:
            ok = False

    return ok


def solve():
    part1 = 0
    part2 = 1
    lowPts = []

    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if check_adj(lines, i, j):
                lowPts.append((i, j))
                part1 += (1 + lines[i][j])


    largest = []
    for point in lowPts:
        count = expand(*point)
        largest.append(count + 1)

    largest = sorted(largest, reverse=True)
    for i in range(3):
        part2 *= largest[i]

    print(part1)
    print(part2)


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day9", "r")
    lines = [list(map(int, list(x))) for x in file.read().strip().split('\n')]
    pts = np.zeros((len(lines), len(lines[0])), dtype=np.int8)
    rows, cols = len(lines), len(lines[0])
    solve()
