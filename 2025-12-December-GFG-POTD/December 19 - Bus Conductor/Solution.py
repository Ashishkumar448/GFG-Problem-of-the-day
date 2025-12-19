class Solution:
    def findMoves(self, chairs, passengers):
        # Sort both arrays
        chairs.sort()
        passengers.sort()
        
        moves = 0
        
        # Sum absolute differences
        for i in range(len(chairs)):
            moves += abs(chairs[i] - passengers[i])
        
        return moves
