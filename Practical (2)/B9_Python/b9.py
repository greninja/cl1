from math import sqrt
from math import log
from collections import Counter
from operator import itemgetter

def tf(kt,doc):
 return (doc.count(kt))

def idf(kt,all_docs):
 num=0 
 for x in all_docs:
  if kt in x:
   num=num+1
 if num>0:
  return round(float(log(float(len(all_docs))/float(num))),3)
 else:
  return 0

def tfidf(kt,doc):
 return (tf(kt,doc)*idf(kt,all_docs))

def cos_sim(infile,docs,ktrms):
 a=0
 for x in ktrms:
  a=a+tfidf(x,infile)*tfidf(x,docs)
 b=doclen(infile,ktrms)*doclen(docs,ktrms)
 if not b:
  return 0
 else:
  return (round((a/b),3))

def doclen(doc,ktrms):
 val=0
 for x in ktrms:
  val=val+pow(tfidf(x,doc),2)
 return sqrt(val)

files=[]
all_docs=[]
key_terms=[]

documents=['doc1.txt','doc2.txt','doc3.txt','doc4.txt','doc5.txt','doc6.txt']
result=[['doc1.txt','animals'],['doc2.txt','animals'],['doc3.txt','animals'],['doc4.txt','sports'],['doc5.txt','sports'],['doc6.txt','sports']]

for x in documents:
 files.append(open(x,'r').read())

for x in files:
 all_docs.append(x.lower().rstrip('\n'))

for x in all_docs:
 key_terms=key_terms+x.split()
key_terms=set(key_terms)
key_terms=list(key_terms)

filename=raw_input("Enter test file: ")
inputfile=open(filename,'r').readline().lower()

cnt=0
for x in all_docs:
 result[cnt]=result[cnt]+[cos_sim(inputfile,x,key_terms)]
 cnt=cnt+1
print result

k=3
sortedresult=sorted(result,key=itemgetter(2),reverse=True)
top_k=sortedresult[:k]
top_k[:]=(x for x in top_k if x[2]!=0)
if len(top_k)==0:
 print "Does not match"
else:
 class_count=Counter(category for (document,category,value) in top_k)
 print class_count
 classification=max(class_count,key=lambda cls:class_count[cls]) #sorted(class_count,key=itemgetter(1),reverse=True)[0]
 print "Class of test file: ",classification

'''
TF: Term Frequency, which measures how frequently a term occurs in a document. Since every document is different in length, it is possible that a term would appear much more times in long documents than shorter ones. Thus, the term frequency is often divided by the document length (aka. the total number of terms in the document) as a way of normalization: 
TF(t) = (Number of times term t appears in a document) / (Total number of terms in the document).

IDF: Inverse Document Frequency, which measures how important a term is. While computing TF, all terms are considered equally important. However it is known that certain terms, such as "is", "of", and "that", may appear a lot of times but have little importance. Thus we need to weigh down the frequent terms while scale up the rare ones, by computing the following: 
IDF(t) = log_e(Total number of documents / Number of documents with term t in it).


filename: doc1.txt
Animals live on land and water.Land animals include cats, cows.Water animals include all types of fishes.

filename: doc2.txt
Animals can be classified as herbivorous which is plant eating, carnivorous which is flesh eating and omnivorous which is eating both.

filename: doc3.txt
All land animals have two eyes and ears.They have one tail.

filename: doc4.txt
Sports are all forms of usually competitive activity which,through casual or organised participation, aim to use, maintain or improve physical ability and skills.

filename: doc5.txt
Different sport have different rules.

filename: doc6.txt
Depending on the sport, every sport has different number of players in each team.

filename: t.txt
Dog is an omnivorous creature that lives on land and has one tail.

filename: t2.txt
Football is a competitive sport with eleven players.
'''
