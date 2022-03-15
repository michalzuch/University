# Diagonal length - 100
diagonal = 1.2

# Diagonal minus one length - 99
diagonal_minus_one = 0.2

# Diagonal plus one length - 99
diagonal_plus_one = []
for i in range(1, 100):
    diagonal_plus_one.append(0.1 / i)

# Diagonal plus two length - 98
diagonal_plus_two = []
for i in range(1, 99):
    diagonal_plus_two.append(0.4 / (i * i))

# Vector x length - 100
x = []
for i in range(1, 101):
    x.append(i)

upper = [[], [], []]
lower = []
# Lower diagonal length - 100
lower_diagonal = 1

upper[0].append(diagonal)
upper[1].append(diagonal_plus_one[0])
upper[2].append(diagonal_plus_two[0])
lower.append(diagonal_minus_one / upper[0][0])

for i in range(1, 100):
    upper[0].append(diagonal - upper[1][i - 1] * lower[i - 1])
    if i < 99:
        upper[1].append(diagonal_plus_one[i] - upper[2][i - 1] * lower[i - 1])
        lower.append(diagonal_minus_one / upper[0][i])
        if i < 98:
            upper[2].append(diagonal_plus_two[i])



# Forward substitution
temp_vector = []
temp_vector.append(x[0])
for i in range(1, 100):
    temp_vector.append(x[i] - lower[i - 1] * temp_vector[i - 1])

# Backward substitution
y = [0] * 100
y[99] = temp_vector[99] / upper[0][99]
y[98] = (temp_vector[98] - (upper[1][98] * y[99])) / upper[0][99]
for i in range(97, -1, -1):
    y[i] = (temp_vector[i] - ((upper[1][i] * y[i + 1]) + (upper[2][i] * y[i + 2]))) / upper[0][i]

detA = 1
for i in range(100):
    detA = detA * upper[0][i]


# Clear screen
print(chr(27)+'[2j')
print('\033c')
print('\x1bc')

print("-- DETERMINANT OF MATRIX A: -------")
print(detA)
print()
print("-- VECTOR Y: ----------------------")
new_line = 0
for i in y:
    if new_line < 4:
        print(f'{i: <20}'.format(i), end = " | ")
        new_line += 1
    else:
        print(f'{i: <20}'.format(i))
        new_line = 0
