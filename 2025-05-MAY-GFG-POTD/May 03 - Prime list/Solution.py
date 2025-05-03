MAX = 100010
is_prime = [True] * MAX

# Sieve of Eratosthenes
def sieve():
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(MAX**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, MAX, i):
                is_prime[j] = False

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def nearest_prime(num):
    if is_prime[num]:
        return num
    left = num - 1
    right = num + 1
    while left >= 2 or right < MAX:
        if left >= 2 and is_prime[left]:
            return left
        if right < MAX and is_prime[right]:
            return right
        left -= 1
        right += 1
    return 2

def prime_list(head):
    curr = head
    while curr:
        curr.val = nearest_prime(curr.val)
        curr = curr.next
    return head