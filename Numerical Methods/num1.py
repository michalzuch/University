# IMPORTS
import math
from numpy import float32
from numpy import float64
import plot

# VARIABLES AND STARTING VALUES
x_binary32 = float32(0.3)
x_binary64 = float64(0.3)
h_binary32 = float32(1.0)
h_binary64 = float64(1.0)
h32_values = []
h64_values = []
form_a32_values = []
form_a64_values = []
form_b32_values = []
form_b64_values = []


# FUNCTIONS
def f(value):  # Function used as a example
    return math.cos(value)


# Formula A for calculating derivative approximation
def formula_a(value, h):
    return (f(value + h) - f(value)) / h


# Formula B for calculating derivative approximation
def formula_b(value, h):
    return (f(value + h) - f(value - h)) / (2 * h)


# Function that calculates the approximation error by subtracting the exact
# value of derivative from the one calculated with Formula A
def error_a(value, h):
    return abs(formula_a(value, h) - (-math.sin(value)))


# Function that calculates the approximation error by subtracting the exact
# value of derivative from the one calculated with Formula B
def error_b(value, h):
    return abs(formula_b(value, h) - (-math.sin(value)))


# Function that prepares data for analysis with plots
# collecting errors depending on parameter h as float
def analysis_binary32(h):
    i = 0
    while h > float32(pow(2, -23)):
        form_a32_values.append(error_a(x_binary32, h))
        form_b32_values.append(error_b(x_binary32, h))
        h32_values.append(h)
        h = float32(pow(2, (-1) * i))
        i += float32(0.0001)


# Function that prepares data for analysis with plots
# collecting errors depending on parameter h as double
def analysis_binary64(h):
    i = 0
    while h > float64(pow(2, -52)):
        form_a64_values.append(error_a(x_binary64, h))
        form_b64_values.append(error_b(x_binary64, h))
        h64_values.append(h)
        h = float64(pow(2, (-1) * i))
        i += float64(0.0001)


# MAIN BODY
print("f(x) = cos(x)")
x = float(input("x = "))
print("Formula A, Binary32: f'(x) = " + str(formula_a(float32(x), h_binary32)))
print("Formula A, Binary64: f'(x) = " + str(formula_a(float64(x), h_binary64)))
print("Formula B, Binary32: f'(x) = " + str(formula_b(float32(x), h_binary32)))
print("Formula B, Binary64: f'(x) = " + str(formula_b(float64(x), h_binary64)))

question = input("Do you want to perform analysis? ( y / n ) : ")

if True if question == 'y' else False:
    print("Analysis is performed for x = 0.3")
    analysis_binary32(h_binary32)
    analysis_binary64(h_binary64)
    print("Analysis done.")

    question = input("Do you want to export results to file? ( y / n ) : ")

    if True if question == 'y' else False:
        with open("FA32.txt", 'w') as file:
            file.write("Formula A Binary32\n" + str(form_a32_values))
        with open("FA64.txt", 'w') as file:
            file.write("Formula A Binary64\n" + str(form_a64_values))
        with open("FB32.txt", 'w') as file:
            file.write("Formula B Binary32\n" + str(form_b32_values))
        with open("FB64.txt", 'w') as file:
            file.write("Formula B Binary64\n" + str(form_b64_values))
        print("Results exported to FA32.txt, FA64.txt, FB32.txt, FB64.txt.")

    question = input("Do you want to draw plots? ( y / n ) : ")

    if True if question == 'y' else False:
        plot.draw_single_plot(h32_values,
                              form_a32_values,
                              "Formula A Binary32",
                              "plotFA32.svg")
        plot.draw_single_plot(h64_values,
                              form_a64_values,
                              "Formula A Binary64",
                              "plotFA64.svg")
        plot.draw_single_plot(h32_values,
                              form_b32_values,
                              "Formula B Binary32",
                              "plotFB32.svg")
        plot.draw_single_plot(h64_values,
                              form_b64_values,
                              "Formula B Binary64",
                              "plotFB64.svg")
        plot.draw_double_plot(h32_values,
                              form_a32_values,
                              form_b32_values,
                              "Binary32",
                              "plotBin32.svg")
        plot.draw_double_plot(h64_values,
                              form_a64_values,
                              form_b64_values,
                              "Binary64",
                              "plotBin64.svg")
        print("Plots exported to plotFA32.svg, plotFA64.svg, plotFB32.svg, "
              "plotFB64.svg, plotBin32.svg, plotBin64.svg.")