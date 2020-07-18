string = input("Text: ")
lettercount = 0
wordcount = 1 #starting count from 1 because last word is not accounted for
sentencecount = 0

#iterating across entire string and checking char type
for char in string:
    if char.isalpha():
        lettercount += 1
    elif char == " ":
        wordcount += 1
    elif char == "." or char == '!' or char == '?':
        sentencecount += 1

#calculating index
L = (float(lettercount) / float(wordcount)) * 100.0
S = (float(sentencecount) / float(wordcount)) * 100.0
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Below Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")