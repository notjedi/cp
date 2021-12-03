import numpy as np


def part1(diag):
    mat = []
    gamma = ''
    epsilon = ''

    for line in diag:
        mat.append([int(i) for i in line])

    mat = np.array(mat)
    mat = mat.transpose()

    for line in mat:
        zeros = list(line).count(0)
        ones = list(line).count(1)
        if (zeros > ones):
            gamma += '0'
            epsilon += '1'
        else:
            gamma += '1'
            epsilon += '0'

    gamma = int(gamma, 2)
    epsilon = int(epsilon, 2)
    print(gamma * epsilon)


def part2(diag):
    mat = []

    for line in diag:
        mat.append([int(i) for i in line])

    oxygen = mat
    co2 = mat

    for i in range(len(mat[0])):

        if len(oxygen) > 1:
            count0 = len([x for x in oxygen if x[i] == 0])
            count1 = len([x for x in oxygen if x[i] == 1])

            if (count1 >= count0):
                oxygen = [x for x in oxygen if x[i] == 1]
            else:
                oxygen = [x for x in oxygen if x[i] == 0]

        if len(co2) > 1:
            count0 = len([x for x in co2 if x[i] == 0])
            count1 = len([x for x in co2 if x[i] == 1])

            if (count1 >= count0):
                co2 = [x for x in co2 if x[i] == 0]
            else:
                co2 = [x for x in co2 if x[i] == 1]

    oxygen = ''.join([str(i) for i in oxygen[0]])
    co2 = ''.join([str(i) for i in co2[0]])
    print(int(oxygen, 2) * int(co2, 2))


if __name__ == '__main__':
    file = open("aoc/2021/inputs/day3", "r")
    diag = list(file.read().strip().split('\n'))

    part1(diag)
    part2(diag)
