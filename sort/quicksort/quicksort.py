# Quicksort implementation
import random


def quicksort(seq):
    # Trivially sorted sequence
    if len(seq) <= 1:
        return seq
    
    pivot  = random.choice(seq)

    left   = filter(lambda x: x < pivot, seq)
    middle = filter(lambda x: x == pivot, seq)
    right  = filter(lambda x: x > pivot, seq)

    return quicksort(list(left)) + list(middle) + quicksort(list(right))


if __name__ == '__main__':
    print(quicksort([60, 8, 19, 11, 13, 2, 0, 15]))
