numMovies = int(input())
showTime = []
count = 0

for _ in range(numMovies):
    start, end = map(int, input().split())
    showTime.append((start, end))

showTime = sorted(showTime, key=lambda x: x[1])
endLastMovie = -1

for i in range(numMovies):
    start, end = showTime[i]
    if (start >= endLastMovie):
        endLastMovie = end
        count += 1;

print(count)
