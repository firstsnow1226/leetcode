class Spreadsheet:

    def __init__(self, rows: int):
        self.grid = [[0 for _ in range(26)] for _ in range(rows+1)]
        
    def setCell(self, cell: str, value: int) -> None:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1:])
        self.grid[row][col] = value
        return

    def resetCell(self, cell: str) -> None:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1:])
        self.grid[row][col] = 0
        return

    def getValue(self, formula: str) -> int:
        new_formula = formula[1:]
        blocks = new_formula.split('+')
        cnt = 0
        for x in blocks:
            if x[0].isalpha():
                col = ord(x[0]) - ord('A')
                row = int(x[1:])
                cnt += self.grid[row][col]
            else:
                cnt += int(x)     

        return cnt
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
