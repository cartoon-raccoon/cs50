string = "abcabcabcabc"
# pattern = []
# for j in range(len(string)):
#     testseg = ''
#     pattern.append(string[j])
#     if string[j+1] == string[0] and j > 0:
#         testseg = testseg.join(pattern)
#         lookahead = string[j+1:j+len(testseg)+1]
#         if testseg == lookahead:
#             #we have found a repeating segment
#             print(len(string)/len(testseg))
#             break

leng = len(string)    
for i in range(leng, 0, -1):
    n = int(leng/i)
    if n*i == leng:
        valid = True
        part = string[0:n]
        for j in range(1, i):
            part2 = string[j*n : j*n+n]
            if part2 != part:
                valid = False
                break
        if valid:
            print(i)
            break