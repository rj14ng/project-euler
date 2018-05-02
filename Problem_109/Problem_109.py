# Project Euler Problem 109
# Author: Ben Wang
# Code cleaned up slightly and tweaked for Python 3 by Rocco :)


# Returns the number of ways to hit 'score' in the first two darts
def ways_first_two_darts(score):
    singles = list(range(1, 21, 1))
    singles.append(25)
    # Include 0 since if dart_2 == 0
    # Number of ways to hit score with 1 dart will be counted
    # Leading to the number of two-dart checkouts
    # Also, if score == 0
    # The function returns 1 (number of ways to hit 0 with 0 darts)
    # Leading to the number of one-dart checkouts
    singles.append(0)
    doubles = list(range(2, 41, 2))
    doubles.append(50)
    triples = list(range(3, 61, 3))
    # The number of appearances of a number in this list indicates
    # The number of ways to hit that score with one dart
    counting_list = singles + doubles + triples
    # Initialising:
    ways_to_make = 0
    dart_1 = score
    dart_2 = 0
    while dart_1 >= dart_2:
        # Crossing the possibilities
        ways = counting_list.count(dart_1) * counting_list.count(dart_2)
        ways_to_make += ways
        if dart_1 == dart_2 and counting_list.count(dart_1) == 2:
            ways_to_make -= 1
        elif dart_1 == dart_2 and counting_list.count(dart_1) == 3:
            ways_to_make -= 3
        dart_1 -= 1
        dart_2 += 1
    return ways_to_make

# Note that for 12 = 6+6
# The actual cases are T2T2, D3D3, S6S6, T2D3, D3S6, T2S6
# We over counted D3T2, S6D3, S6T2
# We can count the number of times we overcounted
# Let n = m+m
# For m appearing in counting_list twice, overcounted by 1
# and appearing thrice, overcount by 3.


def ways_all(score):
    doubles = list(range(2, 41, 2))
    doubles.append(50)
    ways = 0
    for checkout in doubles:
        ways += ways_first_two_darts(score - checkout)
    return ways


def sum_up(score):
    total = 0
    for i in range(1, score + 1):
        total += ways_all(i)
    return total


# print(sum_up(170))  # Checked against provided answer; correct
print(sum_up(99))
