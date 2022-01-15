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
    n, b = ri(), rlst_i()

    maxb, minb = -1e9, 1e9
    for beauty in b:
        maxb = max(maxb, beauty)
        minb = min(minb, beauty)
    
    nmax, nmin = 0, 0
    for beauty in b:
        if beauty == maxb:
            nmax += 1
        elif beauty == minb:
            nmin += 1

    max_diff = int(maxb - minb)
    max_diff_num_ways = int(nmax * (nmax - 1) // 2 if maxb == minb else nmax * nmin)

    print(str(max_diff) + " " + str(max_diff_num_ways))

if __name__ == '__main__':
    solve()
