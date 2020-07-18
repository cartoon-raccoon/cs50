def iq_test(numbers):
    numberlist = [int(char) for char in numbers.split(' ')]
    odd = [num for num in numberlist if num % 2 != 0]
    even = [num for num in numberlist if num % 2 == 0]
    if len(odd) == 1:
        return numberlist.index(odd[0])+1
    elif len(even) == 1:
        return numberlist.index(even[0])+1
        
print(iq_test("2 4 7 8 10"))