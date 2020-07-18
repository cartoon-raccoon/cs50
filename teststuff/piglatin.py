def pig_it(text):
    words = [word for word in text.split(' ')]
    newwords = [word[1:] + word[0] + 'ay' if word.isalpha() else word for word in words]
    return ' '.join(newwords)

def array_diff(a, b):
    diff = [num for num in a if num not in set(b)]
    return diff

def move_zeros(array):
    zeroless = [ele for ele in array if ele is not 0 or ele is not 0.0]
    zeroes = [int(ele) for ele in array if ele is 0 or ele == 0.0]
    zeroless.extend(zeroes)
    return zeroless

def alphabet_position(text):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    letterkeys = {}
    for i in range(1, 27):
        letterkeys[i+1] = i
    for key in letterkeys:
        print(letterkeys[key])
    codedmsg = []
    for i in range(len(text)):
        if text[i].isalpha():
            codedmsg.append(letterkeys[text[i].lower()])
    return ' '.join(codedmsg)

print(alphabet_position("The sunset sets at twelve o' clock."))