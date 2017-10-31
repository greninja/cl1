from multiprocessing.pool import ThreadPool
from time import sleep


def threaded_function():
	return 4
	
def threaded1_function():
	return 5
	
if __name__ == "__main__":
	pool = ThreadPool(processes=1)
	a = pool.apply_async(threaded_function)
	print a.get()
	print pool
	pool1 = ThreadPool(processes=1)
	b = pool1.apply_async(threaded1_function)
	print b.get()
	print pool1
