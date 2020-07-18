number = ''

while number.isdigit() == False:
    number = input("Number: ")

# declaring variables
# 2 arrays for each half
valid = False
arr1 = []
arr2 = []
for digit in number[-2::-2]:
    arr1.append(2 * int(digit))

for digit in number[::-2]:
    arr2.append(int(digit))

#print(arr1)
#print(arr2)

sum = 0;
# adding digits in arr1
for digit in arr1:
    if (digit < 10):
        sum += digit
    else:
        tempsum = 0
        remain = 0
        while digit != 0:
            remain = digit % 10
            tempsum += remain
            digit = (digit - remain)/10
        sum += tempsum

for digit in arr2:
    sum += digit

#print(sum)
if sum % 10 == 0:
    valid = True

# flowchart to print card issuer
if valid and len(number) > 10:
    if number[0] == '3':
        if number[1] == '4' or number[1] == '7':
            print("AMEX")
        else:
            print("INVALID")
    elif number[0] == '4':
        print("VISA")
    elif number[0] == '5' or number[0] == '2':
        if int(number[1]) <= 5:
            print("MASTERCARD")
        else:
            print("INVALID")
    elif number[0] == '6':
        print("DISCOVER")
    else:
        print("VALID")
else:
    print("INVALID")