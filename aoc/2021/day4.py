def checkBoard(board):

    # check columns
    for i in range(5):
        # print(board[i::5])
        if all(board[i::5]):
            return True

    # check rows
    for i in range(0, 25, 5):
        # print(board[i:i+5])
        if all(board[i: i+5]):
            return True

    return False

def sumBoard(board, mask):

    boardSum = 0
    for i, j in zip(board, mask):
        if j == 0:
            boardSum += i

    return boardSum

def part1(nums, boards):
    mask = [[0 for _ in range(25)] for _ in range(len(boards))]
    ans1, ans2 = None, None
    boardWin = [0 for _ in range(len(boards))]

    for num in nums:
        for i, board in enumerate(boards):
            if num not in board:
                continue
            mask[i][board.index(num)] = 1
            if (checkBoard(mask[i])):
                boardSum = sumBoard(board, mask[i])
                if (ans1 is None):
                    ans1 = num * boardSum
                if (boardWin[i] == 0):
                    boardWin[i] = 1
                    ans2 = num * boardSum

    print(ans1)
    print(ans2)


if __name__ == '__main__':
    file = open("aoc/2021/inputs/day4", "r")
    # file = open("aoc/2021/inputs/samp", "r")
    nums = list(map(int, file.readline().strip().split(',')))
    boards = []
    for board in file.read().strip().split('\n\n'):
        X = []
        for line in board.split('\n'):
            for num in line.split(' '):
                if num != "":
                    X.append(int(num.strip()))
        assert len(X) == 25
        boards.append(X)

    part1(nums, boards)
