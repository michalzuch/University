import math
import numpy
import matplotlib.pyplot as plt

def rotation(argument):
    temp = []
    for i in argument:
        if 0 < i <= 1/6:
            temp.append(math.sqrt(6 * i) - 1)
        elif 1/6 < i <= 5/6:
            temp.append(3 * i - 1/2)
        elif 5/6 < i <= 1:
            temp.append(3 - math.sqrt(6 - 6 * i))
    return temp

x_theory = [-1, 0, 2, 3]
y_theory = [0, 1/3, 1/3, 0]
sizes = []
for i in range(8):
    sizes.append(10**i)

for i in range(len(sizes)):
    y = numpy.random.uniform(0, 1, sizes[i])
    x = rotation(y)
    plt.plot(x_theory, y_theory)
    plt.hist(x, density=True, bins=60)
    plt.title("Comparison for " + str(sizes[i]))
    plt.legend(["Theoretical function", "Experimental function"])
    plt.grid()
    plt.savefig("size" + str(sizes[i]) + ".svg", format="svg")
    plt.clf()
