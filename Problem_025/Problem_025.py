def fibonacci_length(length):
    fibonacci = [1, 1]
    fib_n = 0

    while len(str(fib_n)) < 1000:
        fib_1 = fibonacci[len(fibonacci) - 1]
        fib_2 = fibonacci[len(fibonacci) - 2]
        fib_n = fib_1 + fib_2

        fibonacci.append(fib_n)

    return fibonacci.index(fib_n) + 1    # remember, array indexes start at 0


print(fibonacci_length(1000))
