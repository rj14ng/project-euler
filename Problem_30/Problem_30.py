def digit_nth_powers(n):
    total_sum = 0
    # The result of 5, 6, and 7 nines was the same
    # Therefore only iterating up to 9^5 * 5
    for num in range(2, 9**n * n):
        sum = 0
        for digit in str(num):
            sum += int(digit)**n
        if sum == num:
            total_sum += num

    return total_sum


print(digit_nth_powers(5))
