def part1(course):
    hor = 0
    depth = 0
    for line in course:
        x = int(line.split()[1])
        if "forward" in line:
            hor += x
        elif "down" in line:
            depth += x
        elif "up" in line:
            depth -= x

    print(depth * hor)


def part2(course):
    hor = 0
    depth = 0
    aim = 0
    for line in course:
        x = int(line.split()[1])
        if "forward" in line:
            hor += x
            depth += (aim * x)
        elif "down" in line:
            aim += x
        elif "up" in line:
            aim -= x

    print(depth * hor)


if __name__ == '__main__':
    file = open("aoc/2021/inputs/day2", "r")
    dist = list(file.read().strip().split('\n'))

    part1(dist)
    part2(dist)
