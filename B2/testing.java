import java.util.*;

public class TSP implements Runnable
{
	int size;
	int routes[][]; // edges
	int cities[]; //vertices

	 Thread runners[];
	 int threadCompleteCount;

	 String solution;
	 int totalDistance;

	 TSP()
	 {
	 	try
	 	{
	 		int i,j;
	 		String choice;

	 		Scanner scan = new Scanner(System.in);
	 		System.out.println("Enter the number of cities");

	 		size = scan.nextInt();
	 		scan.skip("\n");

	 		cities = new String[size];
	 		routes = new int[size][size];

	 		System.out.println("Set City names");
	 		for(int i=0; i < size; i++)
	 		{
	 			System.out.println("City " + (i+1));
	 			cities[i] = scan.nextLine();

	 		}
	 	
	 		System.out.println("Set interconnecting routes");
	 		for(int i=0; i<size; i++)
	 		{
	 			for(j=i+1; j<size; j++)
	 			{
	 				System.out.println("Is there a route between "+ cities[i] + " and " + cities[j] + "(y/n) : ");
	 				choice = scan.nextLine();
	 				if(choice.equalsIgnoreCase("y"))
	 				{
	 					System.out.println("Enter the distance : ");
	 					routes[i][j] = routes[j][i] = scan.nextInt();
	 					scan.skip("\n");
					}
					else
					{
						routes[i][j] = routes[j][i] = 999;
					}
				}
	 		}
	 	
	 		threadCompleteCount = 0;
	 		solution =  "Nearest Neighbour Algo could not form a tour to visit all cities";
			totalDistance = 999;

			runners = new Thread[size];
			for(int i=0; i<size; i++)
			{
				runners[i] = new Thread(this, String.valueof(i));
				runners[i].start();
			}
		}
	 	catch(Exception ex)
	 	{
	 		System.out.println("Error : " + ex);
	 	}
	} // TSP

	void display()
	{
		int i, j;
		for(i=0; i < size; i++)
		{
			System.out.println();
			System.out.println(cities[i] + " : ");
			for(j=0; j < size; j++)
			{
				System.out.print( cities[j] + "(" + routes[i][j] + ")");
			}

		}
		System.out.prinln();
	}
	
	public void run()
	{
		int sPos = Integer.parseInt(Thread.currentThread().getname());
		solveTSPUsingNearestNeighbour(sPos);
		threadCompleteCount++;
	}

	
}