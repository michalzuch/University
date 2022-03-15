import matplotlib.pyplot as plot

data_amount = [1000, 5000, 10000, 25000, 50000, 75000, 100000, 500000]
bubble = [0.00134942, 0.0282725, 0.0845376, 0.647958, 2.92225, 6.72295, 12.1095, 308.779]
selection = [0.00312113, 0.0432167, 0.103628, 0.636707, 2.55629, 5.74453, 10.1983, 256.601]
insertion = [0.000395, 0.0066145, 0.0169481, 0.0739717, 0.309076, 0.693088, 1.213, 30.0521]

plot.title("Time depending on amount data.")
plot.plot(data_amount, bubble)
plot.plot(data_amount, selection)
plot.plot(data_amount, insertion)
plot.grid()
plot.xlabel("Amount of data in vector")
plot.ylabel("Time")
plot.legend(["Bubble Sort", "Selection Sort", "Insertion Sort"])
plot.savefig("results_plot.png", format="png")