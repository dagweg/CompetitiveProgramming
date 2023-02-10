class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.ps = []

        # init start values of every row
        for i in range(len(matrix)):
            tmp = []
            for j in range(len(matrix[0])):
                if j == 0:
                    tmp.append(matrix[i][j])
                else:
                    tmp.append(0)
            self.ps.append(tmp)

        # compute prefixSum
        for i in range(len(matrix)):
            for j in range(1, len(matrix[0])):
                self.ps[i][j] = self.ps[i][j-1] + matrix[i][j]


        for m in self.ps:
            print(m)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum = 0

        for i in range(row1, row2+1):
            if col1 - 1 < 0:
                sum += self.ps[i][col2]
            else:
                sum += self.ps[i][col2] - self.ps[i][col1-1]
        
        return sum


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
