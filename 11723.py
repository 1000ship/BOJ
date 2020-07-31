import sys
M = int(sys.stdin.readline())
S = set()

for m in range(M):
    line = sys.stdin.readline().strip()
    if line == 'all':
        S = set([i+1 for i in range(20)])
    elif line == 'empty':
        S = set([])
    else:
        inst, x = line.split()
        x = int(x)
        if inst == 'add':
            S.add(x)
        elif inst == 'remove':
            if x in S:
                S.remove(x)
        elif inst == 'check':
            sys.stdout.write(f'{1 if x in S else 0}\n')
        elif inst == 'toggle':
            if x in S:
                S.remove(x)
            else:
                S.add(x)
