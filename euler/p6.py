# https://projecteuler.net/problem=6

def sum(n):
    return (n * (n+1))//2

def square_sum(n):
    return (n * (n+1) * (2 * n + 1))//6

number = 100

square_of_sum =  sum(number) * sum(number)
sum_of_squares = square_sum(number)

print(square_of_sum - sum_of_squares)

# (1 + 2 + 3 + 4 + 5) ^ 2 - (1 + 4 + 9 + 16 + 25)
# 225 - 55
# 3025 - 385
