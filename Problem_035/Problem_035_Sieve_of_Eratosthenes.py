def sieve(n):
    # Sieve of Eratosthenes
    # Includes a common optimisation
    # Enumerating multiples of each prime from i to i^2
    primes = [True] * n
    primes[0] = False
    primes[1] = False
    sqr = int(n**0.5) + 1
    for i in range(2, sqr):
        if primes[i]:
            for j in range(i**2, n, i):
                primes[j] = False
    return primes


def rotate(n):
    str_n = str(n)
    result = str_n[1:] + str_n[:1]
    return int(result)


count = 0

primes = sieve(1000000)

for i, p in enumerate(primes):
    if p:
        num = i
        prime_count = 1
        for rotations in range(1, len(str(i))):
            # Primes that contain 0, 2, 4, 5, 6, or 8 can't be a circular prime
            # Since one rotation would exist where that digit is at the end
            if ('0' in str(num)) or ('2' in str(num)) or \
               ('4' in str(num)) or ('5' in str(num)) or \
               ('6' in str(num)) or ('8' in str(num)):
                break
            num = rotate(num)
            if primes[num]:
                prime_count += 1
            else:
                break
        if prime_count == len(str(i)):
            count += 1

print(count)
