def part1(dist):
    count = 0
    last = dist[0]

    for num in dist:
        if (last < num):
            count+=1;
        last = int(num)

    print(count)


def part2(dist):
    last = -1
    count = 0

    for i in range(len(dist) - 2):
        s = dist[i] + dist[i+1] + dist[i+2]
        if (s > last):
            count += 1
        last = s
    print(count - 1)


if __name__ == '__main__':
    file = open("aoc/2021/inputs/day1", "r")
    dist = list(map(int, file.read().strip().split('\n')))

    part1(dist)
    part2(dist)
