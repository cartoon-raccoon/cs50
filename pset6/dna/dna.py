import csv
import sys

if len(sys.argv) != 3:
    #check for proper usage
    print("Usage: dna.py /databasepath /sequencepath")
    sys.exit(1)

#specifying datastructs to be read into
seqlist = []
sequences = {}

#opening database file
try:
    with open(sys.argv[1], newline='') as dataset:
        print("Database found. Opening...")
        reader = csv.reader(dataset)
        seqlist = next(reader)[1:]
        #mapping names to sequences
        #while also casting each element to int
        for row in reader:
            sequences[row[0]] = [int(i) for i in row[1:]]
except:
    print("ERROR: Could not find database.")
    sys.exit(2)

print(f"STRs present: {seqlist}\n")

#specifying variable to be read into
testseq = ''

#opening test sequence file
try:
    with open(sys.argv[2], "r") as seqfile:
        print("Sequence file found. Opening...\n")
        testseq = seqfile.readline()
except:
    print("ERROR: Could not find sequence file.")
    sys.exit(3)

print("Database and sequence successfully opened.")
print("Beginning STR check.\n")

#initializing dict of seq counts
seq_counts = {}
for seq in seqlist:
    seq_counts[seq] = 0
    
#for all sequences in seqlist
for testSTR in seqlist:
    counts = [0,]
    cluster_count = 0
    print(f"Tracking: {testSTR}")
    STRlength = len(testSTR)
    #track index of STRlength ago: tracks sequence behind j
    k = 0
    
    #iterating across entire sequence
    for j in range(len(testseq)):
        #assigning a segment to be tested
        testseg = testseq[j : j + STRlength]
        #storing the segment (STRlength) letters behind j
        prevseg = testseq[k : k + STRlength]
        
        if testseg == testSTR: #match found
            #is my match the same as the previous segment?
            if testseg == prevseg:
                counts[cluster_count] += 1
            #if not, we are at the start of a cluster
            else:
                cluster_count += 1
                counts.append(0)
                counts[cluster_count] += 1
            #immediately update k to start tracking the cluster
            k = j
        
        #have i traversed the length of one testSTR yet?
        if (j - k == STRlength): #if yes, update k
            k = j
                    
    #update the seq_counts dict with the maximum STR count
    print(counts)
    seq_counts[testSTR] = max(counts)

testarr = []
print("\nLongest STR counts found:")
for seq in seqlist:
    print(seq, seq_counts[seq])
    testarr.append(seq_counts[seq])
    
print(f"\nSequence counts to test: {testarr}")

fullmatch = False
for name in sequences:
    if sequences[name] == testarr:
        fullmatch = True
        print(f"Match found: {name}")
        break

if fullmatch == False:
    print("No match found.")