def remove(word, replaceWith):

    for letter in replaceWith:
        word = word.replace(letter, '')
    return word

def get_mappings(before):
    before = sorted(before, key=lambda x: len(x))
    mappings = {}
    eg = 'abcdefg'
    cf = ''
    bd = ''
    a = ''

    # 1: cf           2
    # 7: acf          3
    # 4: bcdf         4

    # 2: acdeg        5
    # 3: acdfg        5
    # 5: abdfg        5

    # 0: abcefg       6
    # 6: abdefg       6
    # 9: abcdfg       6

    # 8: abcdefg      7

    # 1 has C and F
    # 7 has A
    # 4 has B and D
    # 3 has G
    # 0 has B but not D
    # 6 has C but not F

    for word in before:
        word = ''.join(sorted(word))

        if len(word) == 2:
            cf = word

        elif len(word) == 3:
            word = remove(word, cf)
            assert len(word) == 1
            mappings[word] = 'a'
            a = word

        elif len(word) == 4:
            word = remove(word, cf)
            assert len(word) == 2
            bd = word

        elif len(word) == 5:
            eg = remove(eg, cf)
            eg = remove(eg, bd)
            eg = eg.replace(a, '')
            assert len(eg) == 2

        elif len(word) == 6:
            if cf[0] in word and cf[1] not in word:      # 6
                mappings[cf[0]] = 'f'
                mappings[cf[1]] = 'c'
            elif cf[1] in word and cf[0] not in word:    # 6
                mappings[cf[1]] = 'f'
                mappings[cf[0]] = 'c'

            if bd[0] in word and bd[1] not in word:     # 0
                mappings[bd[0]] = 'b'
                mappings[bd[1]] = 'd'
            elif bd[1] in word and bd[0] not in word:   # 0
                mappings[bd[1]] = 'b'
                mappings[bd[0]] = 'd'

            if eg[0] in word and eg[1] not in word:     # 9
                mappings[eg[0]] = 'g'
                mappings[eg[1]] = 'e'
            elif eg[1] in word and eg[0] not in word:   # 9
                mappings[eg[1]] = 'g'
                mappings[eg[0]] = 'e'


    assert len(set(mappings)) == 7
    assert len(set(mappings.values())) == 7
    return mappings


def solve(lines):

    part1 = 0
    part2 = 0
    values = { 'abcefg': 0,
                'cf': 1,
                'acdeg': 2,
                'acdfg':3,
                'bcdf': 4,
                'abdfg': 5,
                'abdefg': 6,
                'acf': 7,
                'abcdefg': 8,
                'abcdfg': 9  }

    for line in lines:
        before, after = line.split('|')
        after = after.strip().split(' ')
        before = before.strip().split(' ')
        mappings = get_mappings(before)

        number = ''
        for word in after:
            temp = ''
            for letter in word:
                temp += mappings[letter]
            temp = ''.join(sorted(temp))
            number += str(values[temp])
            if values[temp] in [1, 4, 7, 8]:
                part1 += 1

        part2 += int(number)

    print(part1)
    print(part2)


if __name__ == "__main__":
    file = open("aoc/2021/inputs/day8", "r")
    lines = file.read().strip().split('\n')
    solve(lines)
