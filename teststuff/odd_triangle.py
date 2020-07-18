def add_consecutive(n):
    if n <= 1:
        return 1
    return n + add_consecutive(n-1)

def row_sum_odd_numbers(n):
    if n == 1:
        return 1
    prev = add_consecutive(n-1)
    row = [((2*prev+1)+2*i) for i in range(n)]
    return sum(row)

print(row_sum_odd_numbers(13))

#bruh im stoopid
#this calculates n^3
#and i chose to implement TWO functions and recursion to solve it
#kill me