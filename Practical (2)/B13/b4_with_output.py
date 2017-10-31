dataset = [
# Weight, Colour, Vegetable [303, 3, "Cauliflower"],
[370, 1, "Brinjal"],
[298, 3, "Cauliflower"],
[277, 3, "Cauliflower"],
[377, 4, "Brinjal"],
[299, 3, "Cauliflower"],
[382, 1, "Brinjal"],
[374, 4, "Brinjal"],
[303, 4, "Cauliflower"],
[309, 3, "Cauliflower"],
[359, 1, "Brinjal"],
[366, 1, "Brinjal"],
[311, 3, "Cauliflower"],
[302, 3, "Cauliflower"],
[373, 4, "Brinjal"],
[305, 3, "Cauliflower"],
[371, 3, "Brinjal"],
];

unknown_vegetable = [372, 1]
def distance(vegetable1, vegetable2): 
	a = vegetable1[0] - vegetable2[0];
	b = vegetable1[1] - vegetable2[1]; c = (a**2 + b**2) ** 0.5;
	return c;
sorted_dataset = sorted(dataset, key=lambda vegetable: distance(vegetable, unknown_vegetable));
#print sorted_dataset
from collections import Counter 
top_k = sorted_dataset[:5];
print top_k
class_counts = Counter(vegetable for (weight, color, vegetable) in top_k); 
classification = max(class_counts, key=lambda cls: class_counts[cls]); 
print('The unknown vegetable is ' + classification + '.');


'''
flash@flash-GE62-6QD:~/Desktop/CL2_NLP/B4/Code$ python try_b4.py 
[[370, 1, 'Brinjal'], [371, 3, 'Brinjal'], [373, 4, 'Brinjal'], [374, 4, 'Brinjal'], [377, 4, 'Brinjal'], [366, 1, 'Brinjal'], [382, 1, 'Brinjal'], [359, 1, 'Brinjal'], [311, 3, 'Cauliflower'], [309, 3, 'Cauliflower'], [305, 3, 'Cauliflower'], [303, 4, 'Cauliflower'], [302, 3, 'Cauliflower'], [299, 3, 'Cauliflower'], [298, 3, 'Cauliflower'], [277, 3, 'Cauliflower']]
The unknown vegetable is Brinjal.
'''

