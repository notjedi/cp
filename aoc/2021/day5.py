from collections import defaultdict

def part1(start, end):

    overlap = 0
    counts = defaultdict(int)

    for i in range(len(start)):
        x1, y1 = start[i]
        x2, y2 = end[i]
        if x1 == x2:
            for j in range(min(y1, y2), max(y1, y2) + 1):
                counts[(x1, j)] += 1
        elif y1 == y2:
            for j in range(min(x1, x2), max(x1, x2) + 1):
                counts[(j, y1)] += 1

    # use filter here? how?
    for i in counts:
        overlap += 1 if counts[i] >= 2 else 0
    return overlap


def part2(start, end):

    overlap = 0
    counts = defaultdict(int)

    for i in range(len(start)):
        x1, y1 = start[i]
        x2, y2 = end[i]

        if x1 == x2:
            for j in range(min(y1, y2), max(y1, y2) + 1):
                counts[(x1, j)] += 1
        elif y1 == y2:
            for j in range(min(x1, x2), max(x1, x2) + 1):
                counts[(j, y1)] += 1
        else:
            dirx = (x2 - x1) // abs(x2 - x1)
            diry = (y2 - y1) // abs(y2 - y1)
            while (True):
                if ((dirx > 0 and x1 > x2) or (dirx < 0 and x1 < x2)):
                    break
                if ((diry > 0 and y1 > y2) or (diry < 0 and y1 < y2)):
                    break

                counts[(x1, y1)] += 1
                x1 += dirx
                y1 += diry

    # use filter here? how?
    for i in counts:
        overlap += 1 if counts[i] >= 2 else 0
    return overlap


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day5", "r")
    start = []
    end = []
    for line in file.read().strip().split('\n'):
        startPoint, endPoint = line.split(' -> ')
        x1, y1 = map(int, startPoint.split(','))
        x2, y2 = map(int, endPoint.split(','))
        start.append((x1, y1))
        end.append((x2, y2))

    print(part1(start, end))
    print(part2(start, end))
