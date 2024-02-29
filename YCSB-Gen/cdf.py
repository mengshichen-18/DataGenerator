
import pandas as pd
import seaborn as sns
import math
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1.inset_locator import inset_axes
import sys
import tqdm
import random
import numpy as np

datalist = []

distlist = ["random", "segment", "longitude", "longlat", "books", "fb", "wiki"]

plt.rcParams['font.family'] = 'Times New Roman'
plt.rcParams['font.size'] = 30

fig= plt.figure(figsize=(30, 10))
axs = []

# Add subplots in the first row
for i in range(4):
    ax = fig.add_axes([0.05 + 0.2*i, 0.55, 0.15, 0.45])
    axs.append(ax)

# Add subplots in the second row
for i in range(3):
    ax = fig.add_axes([0.126 + 0.2*i, 0.01, 0.15, 0.45])
    axs.append(ax)

count = 0
for i, dist in enumerate(distlist):
    datalist = []
    for line in open("/home/ubuntu/code/dataset/data_gen/YCSB-Gen/build/" + dist + "_write_64000000.dat"): 
    # Split the line on the space character and keep only the last part
        last_part = line.split()[-1]
        datalist.append(int(last_part))
        # count += 1
        # if (count % 100 == 0):
        #     datalist.append(int(last_part))


    sorted_data = np.sort(datalist)
    stat = "proportion"  # or proportion

    # Determine the subplot to use
    ax = axs[i]

    # Plot the ECDF on the subplot
    sns.ecdfplot(sorted_data, stat=stat, ax=ax, linewidth=4)
    ax.set_title(dist.capitalize(),fontsize=42)
    ax.set_xticklabels([])

    # Create an inset axes object with a width and height of 30% of the parent axes' bounding box
    # and move it a little bit higher

    if(dist == "wiki" or dist == "longitude" or dist == "longlat"):
        axins = inset_axes(ax, width="40%", height="40%", loc=2, bbox_to_anchor=(0,0,1,1), bbox_transform=ax.transAxes)
    else:
        axins = inset_axes(ax, width="40%", height="40%", loc=3, bbox_to_anchor=(0.5,0.1,1,1), bbox_transform=ax.transAxes)
    axins.tick_params(axis='both', which='major', labelsize=20)
    # axins.set_ylabel('')
    axins.set_xticklabels([])
    axins.set_yticklabels([])
    sns.ecdfplot(sorted_data, stat=stat, ax=axins, linewidth=3)
    axins.set_ylabel('')
    # On the inset axes, plot the same ECDF but with a different y limit
    # sns.ecdfplot(datalist, stat=stat, ax=axins)

    if (dist == "longlat"):
        x_min = sorted_data[1000]  # 1st data point
        x_max = sorted_data[1999]  # 1000th data point

        # Calculating y_min and y_max for the corresponding CDF values
        y_min = np.searchsorted(sorted_data, x_min, side='left') / len(sorted_data)
        y_max = np.searchsorted(sorted_data, x_max, side='right') / len(sorted_data)
        axins.set_ylim(y_min, y_max)  # Adjust this to your desired zoom level
        axins.set_xlim(x_min, x_max)  
    elif (dist == 'segment'):
        
        axins.set_ylim(0, 15e-7)  # Adjust this to your desired zoom level
        axins.set_xlim(0, 1000)

    else:
        x_min = sorted_data[0]  # 1st data point
        x_max = sorted_data[999]  # 1000th data point

        # Calculating y_min and y_max for the corresponding CDF values
        y_min = np.searchsorted(sorted_data, x_min, side='left') / len(sorted_data)
        y_max = np.searchsorted(sorted_data, x_max, side='right') / len(sorted_data)
        axins.set_ylim(y_min, y_max)  # Adjust this to your desired zoom level
        axins.set_xlim(x_min, x_max)     

plt.subplots_adjust(hspace=0.4, wspace=0.4)
plt.savefig("allCDF.pdf", format='pdf', bbox_inches='tight')