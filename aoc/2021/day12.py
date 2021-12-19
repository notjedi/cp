from collections import defaultdict

TWICE = False
PART1 = False
VISITED = {}
count = 0

def solve(curNode):
    global TWICE, count
    for child in paths[curNode]:

        if child == 'end':
            count += 1
            continue

        if (child.islower() and not VISITED[child]):
            VISITED[child] = True
            solve(child)
            VISITED[child] = False
        elif PART1 and child.islower() and not TWICE and child not in ['start', 'end']:
            TWICE = True
            solve(child)
            TWICE = False
        elif child.isupper():
            solve(child)

if __name__ == "__main__":
    file = open("aoc/2021/inputs/day12", "r")

    paths = defaultdict(list)
    for line in file.read().strip().split('\n'):
        before, after = line.split('-')
        paths[before].append(after)
        paths[after].append(before)
        VISITED[before] = False
        VISITED[after] = False

    VISITED['start'] = True
    solve('start')
    print(count)

    count, PART1 = 0, True
    solve('start')
    print(count)
