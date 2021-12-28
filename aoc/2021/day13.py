def fold(points, ins):

    fold, val = ins.split('=')
    val, fold = int(val), fold[-1]
    dim = 0 if fold == 'x' else 1
    newPoints = set()

    for point in points:
        if point[dim] < val:
            newPoints.add(point)
            continue

        # thankfully all point[dim] is not > 2*val
        newPt = list(point)
        newPt[dim] = val - (point[dim] - val)
        newPoints.add(tuple(newPt))

    return newPoints


def solve(points, instructions):

    p1 = 0
    for i, ins in enumerate(instructions):
        points = fold(points, ins)
        p1 = len(points) if i == 0 else p1

    print(p1)
    printPts(points)

def printPts(points):

    maxX, maxY= max(points, key=lambda x: x[0]), max(points, key=lambda x: x[1])
    code = [[' ' for _ in range(maxX[0]+1)] for _ in range(maxY[1]+1)]
    for point in points:
        code[point[1]][point[0]] = '#'

    for line in code:
        print(*line)

if __name__ == "__main__":
    file = open("inputs/day13", "r")
    temp, instructions = file.read().strip().split('\n\n')
    instructions = instructions.split('\n')
    points = set()
    for line in temp.split('\n'):
        x, y = map(int, line.split(','))
        points.add((x, y))

    solve(points, instructions)
