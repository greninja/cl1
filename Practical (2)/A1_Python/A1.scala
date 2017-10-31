object BinarySearch{
	def binsearch(nos:Array[Int], srno: Int,l:Int,r:Int) :Int ={
		var mid=(l+r)/2
		if(l>r) {return -1;}
		else if(nos(mid)==srno)
			{return mid}
		else if(nos(mid)>srno)
			{binsearch(nos,srno,l,mid-1)}
		else
			{binsearch(nos,srno,mid+1,r)}
	}


def main(args:Array[String]){
	println("Enter no of elements in array: ")
	var n:Int=Console.readInt
	var nos= new Array[Int](n)
	println("Now enter array elements: ")
	for(i <- 0 to n-1) {
		nos(i)=Console.readInt
	}
	nos=nos.sorted
	println("sorted array: ")
	for(i <- 0 to n-1) {
		print(nos(i) + " ")
	}
	println(" ")
	println("Enter number to be searched for: ")
	var srno=Console.readInt
	var posn:Int=binsearch(nos,srno,0,n-1)
	if(posn == -1)
		{println("Not found")}
	else
		{println("Found at position "+(posn+1)+" in sorted array")}
	}
}
