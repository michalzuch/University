import numpy
import random
import matplotlib.pyplot as plt

# Predefined values
λ = 4
defined_range = 1000
results = []
expected = []

# Perform Poisson algorithm for specific amount of times and add results to array
# My implementation
for i in range(defined_range):
    q = numpy.exp(-λ)
    k = 0
    p = 1

    k += 1
    u = random.uniform(0, 1)
    p *= u

    while p > q:
        k += 1
        u = random.uniform(0, 1)
        p *= u

    results.append(k)

# Numpy implementation (reference)
for i in range(defined_range):
    expected.append(numpy.random.poisson(λ))

plt.hist(results)
plt.hist(expected)
plt.title("Comparison of algorithims' results")
plt.legend(["My implementation", "Numpy"])
plt.grid()
plt.savefig("poisson_results.svg", format="svg")
plt.show()