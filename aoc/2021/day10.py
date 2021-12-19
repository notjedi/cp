from collections import defaultdict


def validate(line):
    stack = []
    for char in line:
        if char in pairs:
            stack.append(char)
        else:
            if len(stack) > 0 and char == pairs[stack[-1]]:
                stack.pop()
            else:
                return [], points[char]

    return stack, 0


def solve():
    incomplete = []
    points = 0

    for line in lines:
        stack, val = validate(line)
        if val == 0:
            incomplete.append(stack)
        points += val

    scores = []
    for stack in incomplete:
        score = 0
        for char in stack[::-1]:
            score = (score * 5) + stackScore[char]

        scores.append(score)

    scores.sort()
    print(points)
    print(scores[len(scores) // 2])

if __name__ == "__main__":
    file = open("aoc/2021/inputs/day10", "r")
    # file = open("aoc/2021/inputs/samp", "r")
    lines  = [line.strip() for line in file.read().strip().split('\n')]

    points = {')': 3, ']': 57, '}': 1197, '>': 25137 }
    stackScore = {'(': 1, '[': 2, '{': 3, '<': 4 }
    pairs = {'(': ')', '[': ']', '<': '>', '{': '}' }

    solve()
