height = 0
while height < 1 or height > 9:
    height = int(input("height: "))

for i in range(1, height + 1):
    whitespace = ' '*(height-i)
    hashes = '#'*(height-(height-i))
    print(f"{whitespace}{hashes}  {hashes}")