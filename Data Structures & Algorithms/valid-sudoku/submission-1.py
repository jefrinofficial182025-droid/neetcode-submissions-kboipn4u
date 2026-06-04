class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for r in range(9): 
            visited=set()
            for c in range(9): 
                if board[r][c]=='.': 
                    continue
                elif board[r][c] in visited: 
                    return False 
                visited.add(board[r][c])

        for c in range(9): 
            visited=set()
            for r in range(9): 
                if board[r][c]=='.': 
                    continue
                elif board[r][c] in visited: 
                    return False 
                visited.add(board[r][c])        


        for r in range(0,9,3): 
            
            for c in range(0,9,3): 
                visited=set()
                for rs in range(r,r+3): 
                    for cs in range(c,c+3): 
                        if board[rs][cs]=='.': 
                            continue
                        elif board[rs][cs] in visited: 
                            return False 
                        visited.add(board[rs][cs])
        return True
                