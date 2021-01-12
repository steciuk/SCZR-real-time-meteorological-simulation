import re
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

data = []
with open("log_b.txt", 'r') as f:
    for line in f:
        #data.append(line)
        words = re.split('\W+', line)
        words = words[-2]
        data.append(int(words))

num_bins = 250
n, bins, patches = plt.hist(data, num_bins, facecolor='blue', alpha=0.5)
plt.show()

data = []
with open("log_c.txt", 'r') as f:
    for line in f:
        #data.append(line)
        words = re.split('\W+', line)
        words = words[-2]
        data.append(int(words))

num_bins = 250
n, bins, patches = plt.hist(data, num_bins, facecolor='blue', alpha=0.5)
plt.show()