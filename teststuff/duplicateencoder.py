def duplicate_encode(word):
    #ignoring case
    word = word.lower()
    wordDict = {}
    #populating dict
    for char in word:
        wordDict[char] = 0
    #encoding letter counts
    for char in word:
        wordDict[char] += 1
    #constructing new string
    newword = []
    for i in range(len(word)):
        if wordDict[word[i]] > 1:
            newword.append(")")
        else:
            newword.append("(")
    newword = ''.join(newword)
    return str(newword)

word = duplicate_encode("success")
print(word)