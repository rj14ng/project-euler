def binary(n):
    return int(format(n, 'b'))


def palindrome(n):
    if str(n) == str(n)[::-1]:
        return True
    else:
        return False


answer = 0

for i in range(1, 1000000):
    if palindrome(i) and palindrome(binary(i)):
        answer += i

print(answer)
