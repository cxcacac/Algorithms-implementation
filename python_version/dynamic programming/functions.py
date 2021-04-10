import time

def specialized_nw(x, y, simMatrix, gapPenalty, alphabet_converse):
    # Using Needleman-Wunsch algorithm in minimum unit of divide conquer algorithm
    n, m = len(x), len(y)
    mat = []
    for i in range(n + 1):
        mat.append([0] * (m + 1))
    for j in range(1, m + 1):
        mat[0][j] = mat[0][j - 1] + gapPenalty[alphabet_converse[y[j - 1]]]
    for i in range(1, n + 1):
        mat[i][0] = mat[i - 1][0] + gapPenalty[alphabet_converse[x[i - 1]]]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            mat[i][j] = min(mat[i - 1][j - 1] + simMatrix[alphabet_converse[x[i - 1]]][alphabet_converse[y[j - 1]]],
                            mat[i - 1][j] + gapPenalty[alphabet_converse[x[i - 1]]],
                            mat[i][j - 1] + gapPenalty[alphabet_converse[y[j - 1]]])

    alignment_x = ""
    alignment_y = ""
    i, j = n, m

    while i and j:
        if mat[i][j] == mat[i - 1][j - 1] + simMatrix[alphabet_converse[x[i - 1]]][alphabet_converse[y[j - 1]]]:
            alignment_x = x[i - 1] + alignment_x
            alignment_y = y[j - 1] + alignment_y
            i = i - 1
            j = j - 1
        elif mat[i][j] == mat[i - 1][j] + gapPenalty[alphabet_converse[x[i - 1]]]:
            alignment_x = x[i - 1] + alignment_x
            alignment_y = '-' + alignment_y
            i = i - 1
        elif mat[i][j] == mat[i][j - 1] + gapPenalty[alphabet_converse[y[j - 1]]]:
            alignment_x = '-' + alignment_x
            alignment_y = y[j - 1] + alignment_y
            j = j - 1
    while i:
        alignment_x = x[i - 1] + alignment_x
        alignment_y = '-' + alignment_y
        i = i - 1
    while j:
        alignment_x = '-' + alignment_x
        alignment_y = y[j - 1] + alignment_y
        j = j - 1
    return alignment_x, alignment_y

def forwards(x, y, simMatrix, gapPenalty, alphabet_converse):
    n, m = len(x), len(y)
    mat = []
    mat.append([0] * (m + 1))
    for j in range(1, m + 1):
        mat[0][j] = mat[0][j - 1] + gapPenalty[alphabet_converse[y[j - 1]]]
    for i in range(1, n + 1):
    for i in range(1, n + 1):
        mat.append([0] * (m + 1))
        mat[i][0] = mat[i - 1][0] + gapPenalty[alphabet_converse[x[i - 1]]]
        for j in range(1, m + 1):
            mat[i][j] = min(mat[i - 1][j - 1] + simMatrix[alphabet_converse[x[i - 1]]][alphabet_converse[y[j - 1]]],
                            mat[i - 1][j] + gapPenalty[alphabet_converse[x[i - 1]]],
                            mat[i][j - 1] + gapPenalty[alphabet_converse[y[j - 1]]])
            mat[i-1][j-1] = []  # clear memory of former x[i-1][j-1] that will not be used later.
        mat[i-1] = []  # clear memory of former row.
    return mat[n]

def backwards(x, y, simMatrix, gapPenalty, alphabet_converse):
    # This is the backwards subroutine.
    n, m = len(x), len(y)
    mat = []
    mat.append([0] * (m + 1))
    for j in range(1, m + 1):
        mat[0][j] = mat[0][j-1] + gapPenalty[alphabet_converse[y[j - 1]]]
    for i in range(1, n + 1):
        mat.append([0] * (m + 1))
        mat[i][0] = mat[i - 1][0] + gapPenalty[alphabet_converse[x[i - 1]]]
        for j in range(1, m + 1):
            mat[i][j] = min(mat[i - 1][j - 1] + simMatrix[alphabet_converse[x[n - i]]][alphabet_converse[y[m - j]]],
                            mat[i - 1][j] + gapPenalty[alphabet_converse[x[n - i]]],
                            mat[i][j - 1] + gapPenalty[alphabet_converse[y[m - j]]])
            mat[i-1][j-1] = []  # clear memory of former one that will not be used later.
        mat[i-1] = [] # clear memory of former row.
    return mat[n]

def hirschberg(x, y, simMatrix, gapPenalty, alphabet_converse):
    # main hirschberg algorithm.
    n, m = len(x), len(y)
    if n == 1:
        return specialized_nw(x, y, simMatrix, gapPenalty, alphabet_converse)
    else:
        # Make partitions, call subroutines.
        forward = forwards(x[:int(n / 2)], y, simMatrix, gapPenalty, alphabet_converse)
        backward = backwards(x[int(n / 2):], y, simMatrix, gapPenalty, alphabet_converse)

        partition = [forward[j] + backward[m - j] for j in range(m + 1)]
        edit_distance = min(partition)
        cut = partition.index(edit_distance)

        forward, backward, partition = [], [], []
        # Make recursive calls.
        left = hirschberg(x[:int(n / 2)], y[:cut], simMatrix, gapPenalty, alphabet_converse)
        right = hirschberg(x[int(n / 2):], y[cut:], simMatrix, gapPenalty, alphabet_converse)
        return left[0] + right[0], left[1] + right[1], edit_distance
