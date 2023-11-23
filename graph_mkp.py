import matplotlib.pyplot as plt
import math
import numpy

with open('C:/Users/79245/Desktop/orders/laba_mkp.txt', 'r') as file:
    lines = [line for line in file]
with open('C:/Users/79245/Desktop/orders/laba_mkp1.txt', 'r') as file:
    lines1 = [line for line in file]
with open('C:/Users/79245/Desktop/orders/laba_mkp2.txt', 'r') as file:
    lines2 = [line for line in file]
with open('C:/Users/79245/Desktop/orders/laba_mkp3.txt', 'r') as file:
    lines3 = [line for line in file]

t = 43201
x = [0] * t
for i in range(t):
    x[i] = i
    
M = [0] * t
gh = [0] * t
n = ((6.6743 * (10**-11)) * (0.33 * (10**24))  / (5250**3))**0.5
for i in range(t):
    M[i] = n * i
    gh[i] = math.atan(math.sqrt((1 + 0.96) / (1 - 0.96)) * math.tan(float(lines1[i])) / 2)

fig, axs = plt.subplots(nrows= 3 , ncols= 2 )
fig. suptitle('Plots Stacked Vertically')
axs[0, 0].plot(lines, x, label = "E iteration")
axs[1, 0].plot(lines1, x, label = "E divisiom")
axs[2, 0].plot(lines2, x, label = "E golden")
axs[0, 1].plot(lines3, x, label = "E Newton")
axs[1, 1].plot(M, x, label = "M")
axs[2, 1].plot(gh, x, label = "IST")
plt.legend()
plt.show()