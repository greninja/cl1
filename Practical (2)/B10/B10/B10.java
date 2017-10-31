import java.util.*; 
public class B10{ 
	public static void main(String[] args) { 
		Scanner sc=new Scanner(System.in); 
		B10 x=new B10(); 
		Vector<String> v=new Vector<String>(), temp=new Vector<String>(), prev=new Vector<String>(); 
		System.out.println("Enter no. of items:"); 
		int p=1, n=sc.nextInt(); 
		System.out.println("Enter no. of transactions:"); 
		int t=sc.nextInt(); 
		String s[]=new String[t]; 
		for(int i=0;i<t;i++) 
		{ 
			System.out.print("Transaction "+(i+1)+": "); 
			s[i]=sc.next(); 
		} 
		System.out.println("Enter value for minimum support: "); 
		int minSupp=sc.nextInt(); 
		System.out.println("\nInitial count:\nItem\tCount"); 
		for(int i=0;i<n;i++) 
		{ 
			System.out.println((i+1)+"\t"+x.count(s, (i+1)+"")); 
			if(x.count(s, (i+1)+"")>=minSupp) 
				v.add((i+1)+""); 
			temp.add(i+""); 
		} 
		System.out.println("\nFrequent "+(p++)+" itemsets: "+v); 
		do{ 
			temp.removeAllElements(); 
			prev.removeAllElements(); 
			for(int i=0;i<v.size();i++) 
			prev.add(v.elementAt(i)); 
			for(int i=0;i<v.size();i++) 
				for(int j=i+1;j<v.size();j++) 
				{ 
					String str=v.elementAt(i)+v.elementAt(j); 
					if(x.count(s, str)>=minSupp) 
					temp.add(x.removeDuplicates(str)); 
				} 
			v.removeAllElements(); 
			for(int i=0;i<temp.size();i++) 
				v.add(temp.elementAt(i)); 
			x.removeRepeated(v); 
			v = new Vector(new LinkedHashSet(v)); 
			if(!v.isEmpty()) 
			System.out.println("Frequent "+(p++)+" itemsets: "+v); 
		}
		while(!v.isEmpty()); 
	} 


int count(String[] a, String s) 
{ 
	int count=0; 
	for(int i=0;i<a.length;i++) 
		if(intersect(s, a[i])) 
			count++; 
	return count; 
} 


boolean intersect(String s1, String s2) 
{ 
	boolean b=true; 
	for(int i=0;i<s1.length();i++) 
		if(s2.indexOf(s1.charAt(i)+"")==-1) 
		{ 
			b=false; 
			break; 
		} 
	return b; 
} 



String removeDuplicates(String s) 
{ 
	StringBuilder noDupes = new StringBuilder(); 
	for (int i = 0; i < s.length(); i++) 
	{ 
		String si = s.substring(i, i+1); 
		if (!si.equals(",") && noDupes.indexOf(si) == -1) 
		noDupes.append(si); 
	} 
	return noDupes.toString(); 
} 


Vector<String> removeRepeated(Vector<String> vect) 
{ 
	for(int i=0;i<vect.size();i++) 
	{ 
		char[] chars = vect.elementAt(i).toCharArray(); 
		Arrays.sort(chars); 
		vect.removeElementAt(i); 
		vect.add(i, new String(chars)); 
	} 
	return vect; 
} 
}
