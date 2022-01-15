import sys

reader = sys.stdin.readline

def ri():
    return int(reader())

def rlst_i():
    return list(map(int, reader().split()))

def rstr():
    s = reader()
    return list(s[:len(s) - 1])

def solve():
    n = ri()
    score = rlst_i()

    score.sort()

    needed = 0
    i = 0
    while i < n:
        j = i + 1
        while j < n and score[j] == score[i]:
            j += 1
        num_copies = j - i - 1
        needed += num_copies * (num_copies + 1) // 2
        if i == j:
            i += 1
        else:
            score[j - 1] += num_copies
            i = j

    print(needed)

if __name__ == '__main__':
    solve()
