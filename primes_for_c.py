limit = 0x1 << 26
primes = [4, 2]

p = 3
lp = 2
while p < limit:
    i = 0
    while i < lp and (p % primes[i+1] != 0):
        if p < primes[i]:
            i=lp
            break
        i += 2

    if i == lp:
        primes.append(p*p)
        primes.append(p)
        lp += 2
        if lp % 20000 == 0:
            print( lp//2, p)
    p += 2

print("#primes", limit, lp//2)
