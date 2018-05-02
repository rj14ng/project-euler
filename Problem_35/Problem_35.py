def rotate(n):
    str_n = str(n)
    result = str_n[1:] + str_n[:1]
    return int(result)


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


count = 2  # must contain 2 and 5 already due to optimisation below

for num in range(1000000):
    prime_count = 0
    num_const = num
    for rotations in range(1, len(str(num_const)) + 1):
        # Primes that contain 0, 2, 4, 5, 6, or 8 can't be a circular prime
        # Since one rotation would exist where that digit is at the end
        if ('0' in str(num)) or ('2' in str(num)) or \
           ('4' in str(num)) or ('5' in str(num)) or \
           ('6' in str(num)) or ('8' in str(num)):
            break
        elif is_prime(num):
            prime_count += 1
        else:
            break
        num = rotate(num)
    if prime_count == len(str(num_const)):
        count += 1

print(count)
