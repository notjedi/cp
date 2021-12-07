from collections import Counter, defaultdict

def solve(days, timer):

    cnt = Counter(timer)
    for _ in range(days):
        temp = cnt
        cnt = defaultdict(int)
        for i in temp:
            if i > 0:
                cnt[i-1] = temp[i]

        reset = temp[0]
        cnt[6] += reset
        cnt[8] += reset

    fishes = sum([cnt[k] for k in cnt])
    print(fishes)


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day6", "r")
    timer = list(map(int, file.read().strip().split(',')))

    solve(80, timer)
    solve(256, timer)
