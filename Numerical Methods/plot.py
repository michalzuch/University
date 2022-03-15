import matplotlib.pyplot as plt

def draw_single_plot(h, e, title, filename):
    plt.title(title)
    plt.plot(h, e)
    plt.grid()
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel('ln h')
    plt.ylabel('ln E(h)')
    plt.savefig(filename, format="svg")
    plt.show()


def draw_double_plot(h, e_a, e_b, title, filename):
    plt.title(title)
    plt.plot(h, e_a)
    plt.plot(h, e_b)
    plt.grid()
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel('ln h')
    plt.ylabel('ln E(h)')
    plt.legend(["Formula A", "Formula B"])
    plt.savefig(filename, format="svg")
    plt.show()
