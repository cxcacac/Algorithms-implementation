from functions import hirschberg
import time

start=time.clock()
# Read alphabet and scores from text file
f = open("scores.txt", 'r')
letter = f.readline()
letter = letter.replace('\n', '')
# Create a 1-1 mapping from characters to integers
alphabet_converse = dict([(letter[i], i) for i in range(len(letter))])
gapPenalty_0 = f.readline()
gapPenalty_1 = gapPenalty_0.replace('\n', '')
# gap penalty should be a list.
gapPenalty = []
for i in gapPenalty_1.split():
    gapPenalty.append(int(i))
# Establish the similarity matrix.
simMatrix = []
line = f.readline()
while (line):
    row = list(int(x) for x in line.split())
    simMatrix.append(row)
    line = f.readline()
f.close()

# Load input sequences
A = open("a.input", 'r')
B = open("b.input", 'r')
a_string = A.read().replace('\n', '')
b_string = B.read().replace('\n', '')
g = open("alignments.txt", 'w')

# Run the Hirschberg algorithm
outputs = hirschberg(a_string, b_string, simMatrix, gapPenalty, alphabet_converse)

alignment_a = outputs[0]
alignment_b = outputs[1]
edit_distance = outputs[2]
m = len(alignment_a)

i = 0

while i + 30 < m:
    g.write(alignment_a[i:i + 30]+'\n')
    g.write(alignment_b[i:i + 30]+'\n')
    g.write('\n')
    i=i + 30

g.write(alignment_a[i:-1]+'\n')
g.write(alignment_b[i:-1]+'\n')
g.write('the edit distance of two DNA is '+ str(edit_distance)+'\n')
end = time.clock()
g.write('running time: %s seconds' % (end - start))

# Close the files and finish
A.close()
B.close()
g.close()

