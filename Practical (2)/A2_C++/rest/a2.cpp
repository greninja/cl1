#include <iostream>
#include <pthread.h>
using namespace std;
int N;
struct args
{
  int* a;
  int first;
  int last;
};

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
} 
void print(int a[], const int& N)
{
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
} 
int pivot(int a[], int first, int last)
{
    int  p = first;
    int pivotElement = a[first];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement)
        {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
 
    return p;

}

void* quickSort(void* arg)
{
    args* ar=(args*)arg;
    int pivotElement;
    pthread_t threads[2];
    
 
    if(ar->first < ar->last)
    {
        pivotElement = pivot(ar->a, ar->first, ar->last);
        args array1;
        array1.a=new int[N];
        array1.a=ar->a;
        array1.first=ar->first;
        array1.last=pivotElement-1;
        args* x=&array1;
        int rc = pthread_create(&threads[0], NULL, &quickSort, (void *)x);

        args array2;
        array2.a=new int[N];
        array2.a=ar->a;
        array2.first=pivotElement+1;
        array2.last=ar->last;
        args* y=&array2;
        int rc1 = pthread_create(&threads[1], NULL, &quickSort, (void *)y);

        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);
    }
}
 


int main()
{
    
    cout<<"\nEnter number of elements in array:  ";
    cin>>N;
    int test[N]; 
    cout<<"\nNow enter Array ELements:  \n";
    for(int i=0;i<N;i++)
    {cin>>test[i];}
 
    cout << "Before sorting : " << endl;
    print(test, N);
 
    args array;
    array.a=new int[N];
    array.a=test;
    array.first=0;
    array.last=N-1;

    quickSort(&array);
 
    cout << endl << endl << "After sorting : " << endl;
    print(test, N);
     
    return 0;
}

/*#output 
#[BE@localhost codes]$ g++ a2.cpp -lpthread
#[BE@localhost codes]$ ./a.out

#Enter number of elements in array:  6

#Now enter Array ELements:  
#12
#5
#34
#22
#6
#7
#Before sorting : 
#array[0] = 12
#array[1] = 5
#array[2] = 34
#array[3] = 22
#array[4] = 6
#array[5] = 7


#After sorting : 
#array[0] = 5
#array[1] = 6
#array[2] = 7
#array[3] = 12
#array[4] = 22
#array[5] = 34
#[BE@localhost codes]$ 

*/
