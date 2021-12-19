SEEN = set()
count = 0

def increase():
    global limits
    limits = [[x + 1 for x in limit] for limit in limits]

def reset():
    for x, y in SEEN:
        limits[x][y] = 0
    SEEN.clear()

def flash(i, j):
    global count
    SEEN.add((i, j))
    count += 1

    for dx in [1, 0, -1]:
        for dy in [1, 0, -1]:
            newX, newY = i+dx, j+dy
            if 0 <= newX < R and 0 <= newY < C and (newX, newY) not in SEEN:
                limits[newX][newY] += 1
                if limits[newX][newY] > 9:
                    flash(newX, newY)


def solve():

    timestep = 0
    while True:

        timestep += 1
        increase()
        for i in range(R):
            for j in range(C):
                if limits[i][j] > 9 and (i, j) not in SEEN:
                    flash(i, j)

        if len(SEEN) == R * C:
            print(timestep)
            break
        elif timestep == 100:
            print(count)

        reset()



if __name__ == "__main__":
    file = open("aoc/2021/inputs/day11", "r")
    # file = open("aoc/2021/inputs/samp", "r")
    limits = [list(map(int, list(line))) for line in file.read().strip().split('\n')]
    R, C = len(limits), len(limits[0])
    solve()
