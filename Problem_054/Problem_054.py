# Project Euler Problem 54
# Authors: Ben Wang, Rocco Jiang, Alen Alshinbayev
# With the great help of Mr Smith

# Has to have the provided p054_poker.txt in the same directory as the .py file

input_list = []

# Takes the input and makes a nested array
# Each inner array holds the hand of player 1 and 2 for each round
hands = open("p054_poker.txt", "r")
for line in hands:
    input_list.append([line[:14], line[15:-1]])
hands.close()


# Returns a list of the 5 integer numbers in the hand (assumes aces to be 14)
def numbers(hand):
    letter_number = hand[::3]
    integer_number = []
    for letter in letter_number:
        if letter == 'T':
            integer_number.append(10)
        elif letter == 'J':
            integer_number.append(11)
        elif letter == 'Q':
            integer_number.append(12)
        elif letter == 'K':
            integer_number.append(13)
        elif letter == 'A':
            integer_number.append(14)
        else:
            integer_number.append(int(letter))
    return integer_number


# Returns a string of the 5 suits in the hand
def suits(hand):
    suits_hand = hand[1::3]
    return suits_hand


# Search functions
# Return true if the hand has the required attributes for AT LEAST the hand
# Note that, for example, is_pair won't exclude full houses

def is_pair(sorted_numbers):
    # Iterating over the first to second-last members in sorted_numbers
    for number in sorted_numbers[:-1]:
        # If two consecutive numbers are the same
        number_2 = sorted_numbers[sorted_numbers.index(number) + 1]
        if number == number_2:
            return True
    return False


def is_three(sorted_numbers):
    # For each of the first to third-last numbers in sorted_numbers
    for number in sorted_numbers[:-2]:
        # If three consecutive numbers are the same
        number_2 = sorted_numbers[sorted_numbers.index(number) + 1]
        number_3 = sorted_numbers[sorted_numbers.index(number) + 2]
        if number == number_2 and number == number_3:
            return True
    return False


def is_fullhouse(sorted_numbers):
    if sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[0] == sorted_numbers[2] and \
      sorted_numbers[3] == sorted_numbers[4] or \
      sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[2] == sorted_numbers[3] and \
      sorted_numbers[2] == sorted_numbers[4]:
        return True
    return False


def is_four(sorted_numbers):
    # For each of the first to fourth-last numbers in sorted_numbers
    for number in sorted_numbers[:-3]:
        # If four consecutive numbers are the same
        number_2 = sorted_numbers[sorted_numbers.index(number) + 1]
        number_3 = sorted_numbers[sorted_numbers.index(number) + 2]
        number_4 = sorted_numbers[sorted_numbers.index(number) + 3]
        if number == number_2 and number == number_3 and number == number_4:
            return True
    return False


def is_twopairs(sorted_numbers):
    if sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[2] == sorted_numbers[3] or \
      sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[3] == sorted_numbers[4] or \
      sorted_numbers[1] == sorted_numbers[2] and \
      sorted_numbers[3] == sorted_numbers[4]:
        return True
    return False


def is_straight(sorted_numbers):
    # All other cases have already been discarded in hand_rank
    # So there are no pairs, threes, etc.
    # In a normal case (5 consecutive numbers without an ace):
    #   the last number minus the first number equals to 4
    # In the special case (Ace, 2, 3, 4, 5):
    #   ace will be equal to 14, so check for 14 - 5 = 9
    if sorted_numbers[-1] - sorted_numbers[0] == 4 or \
      sorted_numbers[-1] - sorted_numbers[-2] == 9:
        return True
    return False


def is_flush(hand):
    if len(set(suits(hand))) == 1:  # If all suits are the same
        return True
    else:
        return False


# Hand rank function
# Finds the rank of the current hand
# Input in the form "8C 7S 6H 4H AH", output numbers for the following ranks:
'''
1 High Card
2 One Pair
3 Two Pairs
4 Three of a Kind
5 Straight
6 Flush
7 Full House
8 Four of a Kind
9 Straight Flush
'''


def hand_rank(hand):
    sorted_numbers = sorted(numbers(hand))
    if is_pair(sorted_numbers):
        if is_three(sorted_numbers):
            if is_fullhouse(sorted_numbers):
                return 7
            elif is_four(sorted_numbers):
                return 8
            else:
                return 4
        elif is_twopairs(sorted_numbers):
            return 3
        else:
            return 2
    elif is_straight(sorted_numbers):
        if is_flush(hand):
            return 9
        else:
            return 5
    elif is_flush(hand):
        return 6
    else:
        return 1


'''
# Test cases
print(hand_rank('KC 6C 7H AS 9C'))  # high card, returns 1
print(hand_rank('KC 6C 7H 6S 9C'))  # one pair, returns 2
print(hand_rank('KC 6C 7H 6S 6C'))  # three of a kind, returns 4
print(hand_rank('KC 6C 6H 6S 6C'))  # four of a kind, returns 8
print(hand_rank('KC KC 6H 6S 6C'))  # full house, returns 7
print(hand_rank('KC KC 7H 6S 6C'))  # two pairs, returns 3
print(hand_rank('3C 4C 5C 6C 7H'))  # straight (normal case), returns 5
print(hand_rank('AC 2C 3C 4C 5H'))  # straight (with an ace), returns 5
print(hand_rank('3C 4C 5C 6C 7C'))  # straight flush (normal case), returns 9
print(hand_rank('AC 2C 3C 4C 5C'))  # straight flush (with an ace), returns 9
print(hand_rank('7C 2C 3C 4C 5C'))  # flush, returns 6
'''

# Tiebreak functions
# Returns True if hand1 wins the tiebreak
# The 'rank' input is the equal rank of hand1 and hand2.
'''
Kinds of sorts:
1 High Card
2 One Pair
3 Two Pairs
4 Three of a Kind
5 Straight
6 Flush
7 Full House
8 Four of a Kind
9 Straight Flush
'''


# Tiebreak for high cards
def tiebreak_highcard(sorted_numbers_1, sorted_numbers_2):
    # Iterating from largest to smallest values
    for i in range(len(sorted_numbers_1) - 1, 0, -1):
        if sorted_numbers_1[i] > sorted_numbers_2[i]:
            return True
        elif sorted_numbers_1[i] < sorted_numbers_2[i]:
            return False


# Returns the number in a pair
def pair_num(sorted_numbers):
    # Iterating over the first to second-last members in sorted_numbers
    for number in sorted_numbers[:-1]:
        # If two consecutive numbers are the same
        number_2 = sorted_numbers[sorted_numbers.index(number) + 1]
        if number == number_2:
            return number


# Tiebreak for pairs
def tiebreak_pair(sorted_numbers_1, sorted_numbers_2):
    if pair_num(sorted_numbers_1) > pair_num(sorted_numbers_2):
        return True
    elif pair_num(sorted_numbers_1) < pair_num(sorted_numbers_2):
        return False
    # Tiebreak for high card if the pair is equal
    else:
        return tiebreak_highcard(sorted_numbers_1, sorted_numbers_2)


# Returns the numbers in the two pairs
def twopair_num(sorted_numbers):
    if sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[2] == sorted_numbers[3]:
        return sorted_numbers[0], sorted_numbers[2]
    elif sorted_numbers[0] == sorted_numbers[1] and \
      sorted_numbers[3] == sorted_numbers[4]:
        return sorted_numbers[0], sorted_numbers[3]
    elif sorted_numbers[1] == sorted_numbers[2] and \
      sorted_numbers[3] == sorted_numbers[4]:
        return sorted_numbers[1], sorted_numbers[3]


# Tiebreak for two pairs
def tiebreak_twopairs(sorted_numbers_1, sorted_numbers_2):
    if twopair_num(sorted_numbers_1)[1] > twopair_num(sorted_numbers_2)[1]:
        return True
    elif twopair_num(sorted_numbers_1)[1] < twopair_num(sorted_numbers_2)[1]:
        return False
    elif twopair_num(sorted_numbers_1)[0] > twopair_num(sorted_numbers_2)[0]:
        return True
    elif twopair_num(sorted_numbers_1)[0] < twopair_num(sorted_numbers_2)[0]:
        return False
    else:
        return tiebreak_highcard(sorted_numbers_1, sorted_numbers_2)


# Tiebreak for three of a kind, full house and four of a kind
# Checks for the middle value and then uses highcard if they are equal
def tiebreak_mid_then_highcard(sorted_numbers_1, sorted_numbers_2):
    if sorted_numbers_1[2] > sorted_numbers_2[2]:
        return True
    if sorted_numbers_1[2] < sorted_numbers_2[2]:
        return False
    else:
        return tiebreak_highcard(sorted_numbers_1, sorted_numbers_2)


# Returns the highest card in a straight
def straight_num(sorted_numbers):
    # If there is an ace
    # Since it will be interpreted as 14 even though it should be 1
    if sorted_numbers[-1] - sorted_numbers[-2] == 9:
        return 5
    else:
        return sorted_numbers[-1]


# Tiebreak for straights
def tiebreak_straight(sorted_numbers_1, sorted_numbers_2):
    if straight_num(sorted_numbers_1) > straight_num(sorted_numbers_2):
        return True
    elif straight_num(sorted_numbers_1) < straight_num(sorted_numbers_2):
        return False


# Main tiebreak function
def tiebreak(rank, hand_1, hand_2):
    sorted_numbers_1 = sorted(numbers(hand_1))
    sorted_numbers_2 = sorted(numbers(hand_2))
    if rank == 1 or rank == 6:
        return tiebreak_highcard(sorted_numbers_1, sorted_numbers_2)
    elif rank == 2:
        return tiebreak_pair(sorted_numbers_1, sorted_numbers_2)
    elif rank == 3:
        return tiebreak_twopairs(sorted_numbers_1, sorted_numbers_2)
    elif rank == 4 or rank == 7 or rank == 8:
        return tiebreak_mid_then_highcard(sorted_numbers_1, sorted_numbers_2)
    elif rank == 5 or rank == 9:
        return tiebreak_straight(sorted_numbers_1, sorted_numbers_2)


# Counts the number of times each player wins the matchup
# Output as a tuple in the form (player_1_wins, player_2_wins)
def win_count(input_list):
    player_1_wins = 0
    player_2_wins = 0
    for hand in input_list:
        hand1 = hand[0]
        hand2 = hand[1]
        if hand_rank(hand1) > hand_rank(hand2):
            player_1_wins += 1
        elif hand_rank(hand1) < hand_rank(hand2):
            player_2_wins += 1
        elif tiebreak(hand_rank(hand1), hand1, hand2):
                player_1_wins += 1
        else:
                player_2_wins += 1
    return player_1_wins, player_2_wins


print(win_count(input_list))  # Outputs (376, 624) - Correct!
