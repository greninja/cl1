#from multiprocessing.pool import ThreadPool
#def func_for_calculating_feature_probabilities()
#thread_for_nth_feature = ThreadPool(processes=1)
#calculation_for_nth_feature  = thread_for_nth_feature.apply_async(func_for_calculating_feature_probabilities())
#calculation_for_nth_feature.get() gives the probability




from multiprocessing.pool import ThreadPool
from time import sleep


def threaded_function():
	return 4
	

if __name__ == "__main__":
	pool = ThreadPool(processes=1)
	a = pool.apply_async(threaded_function)
	print a.get()
	
