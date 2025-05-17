def calculate(x, A, B, C):
    return A * x * x + B * x + C

def sort_array(arr, A, B, C):
    n = len(arr)
    sorted_arr = [0] * n
    left, right = 0, n - 1
    index = n - 1 if A >= 0 else 0

    while left <= right:
        val_left = calculate(arr[left], A, B, C)
        val_right = calculate(arr[right], A, B, C)

        if A >= 0:
            if val_left > val_right:
                sorted_arr[index] = val_left
                left += 1
            else:
                sorted_arr[index] = val_right
                right -= 1
            index -= 1
        else:
            if val_left < val_right:
                sorted_arr[index] = val_left
                left += 1
            else:
                sorted_arr[index] = val_right
                right -= 1
            index += 1

    return sorted_arr

# Driver code
t = int(input())
for _ in range(t):
    arr = list(map(int, input().strip().split()))
    A = int(input())
    B = int(input())
    C = int(input())
    result = sort_array(arr, A, B, C)
    print(' '.join(map(str, result)))
    print("~")
