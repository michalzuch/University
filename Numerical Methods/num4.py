import numpy

diagonal = 9
diagonal_plus_one = 7
b = 5

u = 1
v = 1

y = [0] * 50
z = [0] * 50
zPrime = [0] * 50

# Backward substitution for vector z
z[49] = b / diagonal
z[48] = (b - diagonal_plus_one * z[49]) / diagonal
for i in range(47, -1, -1):
    z[i] = (b - diagonal_plus_one * z[i + 1]) / diagonal

# Backward substitution for vector z'
zPrime[49] = u / diagonal
zPrime[48] = (u - diagonal_plus_one * zPrime[49]) / diagonal
for i in range(47, -1, -1):
    zPrime[i] = (u - diagonal_plus_one * zPrime[i + 1]) / diagonal

# Count the value of y
# y = z - (z' * vT * z) / (1 + vT * z')
v = [1] * 50
zPrime_v = numpy.dot(zPrime, v)
v_zPrime = numpy.dot(v, zPrime)
nominator = numpy.dot(zPrime_v, z)
denominator = numpy.add(1, zPrime_v)
fraction = numpy.divide(nominator, denominator)
y = numpy.subtract(z, fraction)

# Clear screen
print(chr(27)+'[2j')
print('\033c')
print('\x1bc')
print("Y:  -----------------------------------------------------------------------------------------------------------")
new_line = 0
for i in y:
    if new_line < 4:
        print(f'{i: <20}'.format(i), end = " | ")
        new_line += 1
    else:
        print(f'{i: <20}'.format(i))
        new_line = 0
print("---------------------------------------------------------------------------------------------------------------")

