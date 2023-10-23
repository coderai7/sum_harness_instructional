"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot, and saves it to a file named "myplot.png"

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt


plot_fname = "myplot.png"

fname = "sample_data_3vars.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time

problem_sizes = df[var_names[0]].values.tolist()
code1_time = df[var_names[1]].values.tolist()
code2_time = df[var_names[2]].values.tolist()
code3_time = df[var_names[3]].values.tolist()
code4_time = df[var_names[4]].values.tolist()
code5_time = df[var_names[5]].values.tolist()
code6_time = df[var_names[6]].values.tolist()
code7_time = df[var_names[7]].values.tolist()
code8_time = df[var_names[8]].values.tolist()
code9_time = df[var_names[9]].values.tolist()

#plt.figure()

#======= First Graph ==============

plt.subplot(2,2,1)
plt.title("Comparison of 3 Codes for MFLOPs")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(code1_time, "r-o")
plt.plot(code2_time, "b-x")
plt.plot(code3_time, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("runtime")

varNames = [var_names[1], var_names[2], var_names[3]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')


# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)

#========== Second Graph ============

plt.subplot(2,2,2)
plt.title("Comparison of 3 Codes Memory Bandwidth")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(code4_time, "r-o")
plt.plot(code5_time, "b-x")
plt.plot(code6_time, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("runtime")

varNames = [var_names[4], var_names[5], var_names[6]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')


# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)

#====== Third Graph =======

plt.subplot(2,2,3)
plt.title("Comparison of 3 Codes Memory Latency")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(code7_time, "r-o")
plt.plot(code8_time, "b-x")
plt.plot(code9_time, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("runtime")

varNames = [var_names[7], var_names[8], var_names[9]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)




plt.show()

# EOF
