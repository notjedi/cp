def sumN(x):
    return (x * (x+1)) // 2

def solve(pos):

    pos = sorted(pos)
    median, mean = len(pos) // 2, sum(pos) // len(pos)
    p1, p2 = 0, 0

    for x in pos:
        p1 += abs(x - pos[median])
        p2 += sumN(abs(x - mean))

    print(p1)
    print(p2)


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day7", "r")
    pos = list(map(int, file.read().strip().split(',')))

    solve(pos)

"""
saw Jonathan Paulson's video and went on to reason about the 2nd part and here it is:

def:
    sumN(n) = (n * (n+1)) / 2

For a target T, the score is sum(sumN(|x - T|) for x in positions))
So if the target is to be moved by +1, the score changes by (sumN(m) - sumN(n)), where n = (|x - T|) and m = (|x - T| + 1) = (n + 1) (essentially for the new T)


# Move T to left
oldT = T
T = T-1
for x in positions:
    if x < oldT: # for all x < oldT
        cost -= (oldT - x)
    else: # for all x >= oldT
        cost += (x - oldT)

It's the exact opposite for T+1

The cost decreases by (T - x) for x < T and increases by (x - T) for x >= T.
So the delta is: |sum(x - T) for x in positions if x < T| ~== |sum(x - T) for x in positions if x >= T|
So what can T be? We can choose T as the mean of all the numbers.
chossing T = min(positions) would be an advantage for all starting postions
chossing T = max(positions) would be an advantage for all ending postions
chossing T = median of positions would be okay if it's a normal distribution, but that's not the case here and a number can occur any number of times.

Let's see an example:
    Consider the following positions 1, 1, 1, 2, 5, 8
    Let's say that you choose T to be the median, which is 2, then the cost = 30
    Now, let's take T to be equal to the mean, which is 2, then the cost = 28
    the positions are distributed more towards the left
"""
