from itertools import combinations
from operator import itemgetter
val = [60, 100, 120,100,70, 75 , 150]
wt = [10, 20, 30, 10, 5, 6, 25]
W = 100

new_val = []
new_wt = []
#score_density = []
for i in range(len(wt)):
	if wt[i] <= W:
		new_wt.append(wt[i])
		new_val.append(val[i])
		#score_density.append(float(val[i])/wt[i])

#dict_score = {v: k for v, k in enumerate(score_density)}
#sorted_dict_score = sorted(dict_score.items(),key=itemgetter(1),reverse=True)
index_list = [i for i in range(len(new_wt))]
total_combinations = [] #list for indices of items
for i in range(1,len(new_wt)+1):
	for subset in combinations(index_list,i):
		total_combinations.append(subset)

max_val = 0
max_indices = 0 #required item indices i.e. elements of total_combinations not indices of total_combinations
for i in range(len(total_combinations)):
	count = 0
	sum_val = 0
	flag = 0
	for j in range(len(total_combinations[i])):
		count += new_wt[total_combinations[i][j]]
		sum_val += new_val[total_combinations[i][j]]
		if count > W:
			flag = 1
			break
	if flag == 1:
		continue
	if sum_val > max_val:
		max_val = sum_val
		max_indices = total_combinations[i]


total_weight = 0
total_profit = 0
for i in range(len(max_indices)):
	total_weight += new_wt[max_indices[i]]
	total_profit += new_val[max_indices[i]]
	
print max_val, max_indices, total_weight, total_profit	
