def countDistinct(arr, k):
    from collections import defaultdict
    
    mp = defaultdict(int)
    ans = []

    # first window
    for i in range(k):
        mp[arr[i]] += 1

    ans.append(len(mp))

    # slide window
    for i in range(k, len(arr)):
        outgoing = arr[i - k]
        mp[outgoing] -= 1
        if mp[outgoing] == 0:
            del mp[outgoing]

        mp[arr[i]] += 1
        ans.append(len(mp))

    return ans
