import csv
from operator import itemgetter
from itertools import combinations
csvfile = open('dataset.csv','r')
transactions_list = list(csv.reader(csvfile))

print transactions_list
set_transactions = []
for i in range(len(transactions_list)):
	for j in range(len(transactions_list[i])):
		set_transactions.append(transactions_list[i][j])
set_transactions = set(set_transactions)
print set_transactions
combinations_transactions = []
for i in range(1,len(set_transactions)+1):
	for subset in combinations(set_transactions,i):
		combinations_transactions.append(subset)
frequency_transactions = []


#Use Frozen Sets
for i in range(len(combinations_transactions)):
	main_count = 0
	for k in range(len(transactions_list)):
		count = 0
		for j in range(len(combinations_transactions[i])):	
			if combinations_transactions[i][j] in transactions_list[k]:
				count += 1
		if count == len(combinations_transactions[i]):
			main_count += 1
	frequency_transactions.append(main_count)

threshold = 3
final_indices = []
required_set = list(set_transactions)[:]
i = len(frequency_transactions)-1
while True:
	if required_set == []:
		break
	if i == -1:
		break
	if frequency_transactions[i] >= threshold:
		for k in range(len(combinations_transactions[i])):
			if combinations_transactions[i][k] in required_set:
				final_indices.append(i)
				required_set = [x for x in required_set if x not in list(combinations_transactions[i])]	
	i -= 1	

print final_indices
for i in range(len(final_indices)):
	print combinations_transactions[final_indices[i]], frequency_transactions[final_indices[i]]





'''
dictionary_transactions = {}
for i in range(len(transactions_list)):
	for j in range(len(transactions_list[i])):
		if transactions_list[i][j] not in dictionary_transactions:
			dictionary_transactions[transactions_list[i][j]] = 1
		else:
			dictionary_transactions[transactions_list[i][j]] += 1

sorted_dictionary = sorted(dictionary_transactions.items(),key=itemgetter(1),reverse=True)
print sorted_dictionary
threshold = 3

n_objects_list = sorted_dictionary[:]
n_objects_list_threshold = [(x,y) for x,y in sorted_dictionary if y >= threshold]
print n_objects_list_threshold
while True:
'''
	
