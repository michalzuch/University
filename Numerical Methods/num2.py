from numpy import linalg

# DATA
A1 = [
    [2.40827208, -0.36066254, 0.80575445, 0.46309511, 1.20708553],
    [-0.36066254, 1.14839502, 0.02576113, 0.02672584, -1.03949556],
    [0.80575445, 0.02576113, 2.45964907, 0.13824088, 0.0472749],
    [0.46309511, 0.02672584, 0.13824088, 2.05614464, -0.9434493],
    [1.20708553, -1.03949556, 0.0472749, -0.9434493, 1.92753926]
]

A2 = [
    [2.61370745, -0.6334453, 0.76061329, 0.24938964, 0.82783473],
    [-0.6334453, 1.51060349, 0.08570081, 0.31048984, -0.53591589],
    [0.76061329, 0.08570081, 2.46956812, 0.18519926, 0.13060923],
    [0.24938964, 0.31048984, 0.18519926, 2.27845311, -0.54893124],
    [0.82783473, -0.53591589, 0.13060923, -0.54893124, 2.6276678]
]

b = [
    [5.40780228],
    [3.67008677],
    [3.12306266],
    [-1.11187948],
    [0.54437218]
]

bPrime = [
    [b[0][0] + pow(10, -5)],
    [b[1][0] + 0],
    [b[2][0] + 0],
    [b[3][0] + 0],
    [b[4][0] + 0]
]

# Calculate matrix condition
a1_condition = linalg.cond(A1, None)
a2_condition = linalg.cond(A2, None)

# Solve equations Ai yi = b
y1 = linalg.solve(A1, b)
y1Prime = linalg.solve(A1, bPrime)

y2 = linalg.solve(A2, b)
y2Prime = linalg.solve(A2, bPrime)

# Calculate the difference when used b and b'
delta1 = linalg.norm(y1 - y1Prime, 2)
delta2 = linalg.norm(y2 - y2Prime, 2)

# Clear screen
print(chr(27)+'[2j')
print('\033c')
print('\x1bc')

print("-- A1 CONDITION: ----")
print(a1_condition)
print()

print("-- A2 CONDITION: ----")
print(a2_condition)
print()

print("-- Y1 VALUE: --------")
print(y1)
print()

print("-- Y1' VALUE: -------")
print(y1Prime)
print()

print("-- Y2 VALUE: --------")
print(y2)
print()

print("-- Y2' VALUE: -------")
print(y2Prime)
print()

print("-- ∆1 VALUE: --------")
print(delta1)
print()

print("-- ∆2 VALUE: --------")
print(delta2)
print()