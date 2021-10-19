# https://projecteuler.net/overview=012
import math

def find_factors(num):
    totFactors = 0
    for i in range(1, int(math.sqrt(num) + 1)):
        if (num % i == 0):
            totFactors += 2
    return totFactors

# 76576500
num = 1
sumNums = 0
while True:
    totFacs = find_factors(sumNums)
    if totFacs > 500:
        print(sumNums)
        break
    sumNums += num
    num += 1
