from collections import deque, defaultdict

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(s):
    if len(s) == 0 or s[0] == 'N':
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    queue = deque([root])
    
    i = 1
    while queue and i < len(ip):
        currNode = queue.popleft()
        
        currVal = ip[i]
        if currVal != 'N':
            currNode.left = Node(int(currVal))
            queue.append(currNode.left)
        
        i += 1
        if i >= len(ip):
            break
        
        currVal = ip[i]
        if currVal != 'N':
            currNode.right = Node(int(currVal))
            queue.append(currNode.right)
        
        i += 1
    
    return root

def findTargetNode(root, target, parentMap):
    queue = deque([root])
    targetNode = None
    
    while queue:
        curr = queue.popleft()
        if curr.data == target:
            targetNode = curr
        if curr.left:
            parentMap[curr.left] = curr
            queue.append(curr.left)
        if curr.right:
            parentMap[curr.right] = curr
            queue.append(curr.right)
    
    return targetNode

def minTime(root, target):
    parentMap = {}
    targetNode = findTargetNode(root, target, parentMap)
    
    queue = deque([targetNode])
    visited = set([targetNode])
    
    time = 0
    
    while queue:
        size = len(queue)
        flag = False
        
        for _ in range(size):
            curr = queue.popleft()
            
            if curr.left and curr.left not in visited:
                visited.add(curr.left)
                queue.append(curr.left)
                flag = True
                
            if curr.right and curr.right not in visited:
                visited.add(curr.right)
                queue.append(curr.right)
                flag = True
            
            if curr in parentMap and parentMap[curr] not in visited:
                visited.add(parentMap[curr])
                queue.append(parentMap[curr])
                flag = True
        
        if flag:
            time += 1
    
    return time

# Helper functions for testing

def printInorder(root):
    if root is None:
        return
    printInorder(root.left)
    print(root.data, end=" ")
    printInorder(root.right)

if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        s = input()
        target = int(input())
        root = buildTree(s)
        print(minTime(root, target))
