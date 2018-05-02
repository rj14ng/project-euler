import itertools


# UNUSED CODE FOR FINDING IF AN INTEGER IS PANDIGITAL
def is_pandigital(n):
    str_n = str(n)
    N = [int(i) for i in str_n]
    list = [i for i in range(1, len(str_n) + 1)]
    if N[0] == 0:    # Checks if n starts with a 0
        return False
    N.sort()
    if N == list:
        return True
    else:
        return False


def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(n**0.5) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            return False

    return True


# Only pandigitals with length 4 and 7 can be prime
# We can figure this out using the divisibility rule for 3
# To find the largest pandigital prime, iterate over all 7-digit pandigitals

seven_digit_pandigitals = []
# Creates a list of permutations in the form of tuples using itertools
permutations = list(itertools.permutations('1234567'))
for i in permutations:
    # Changes the tuples into integers
    seven_digit_pandigitals.append(int(''.join(i)))

answer = 0

for i in seven_digit_pandigitals:
    if is_prime(i):
        answer = i

print(answer)
