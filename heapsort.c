#include<stdio.h>


int delete(int a[], int n, int pos)
{	int i=pos;
	for(;i<n;i++)
	{                          
		a[i]=a[i+1];
	}
	heap_sort(a,n-1);
	return n-1;
}

int insert(int a[], int n, int element)
{	a[n+1]=element;
	n++;
	heap_sort(a,n);
	return n;
}	

	 
void max_heapify(int a[],int i, int n)
{	
	int l=2*i,r=2*i+1,largest=i;
	if(l<=n && a[l]>a[largest])
	{	largest=l;	}
	if(r<=n && a[r]>a[largest])
	{	largest=r;	}
	if(largest != i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest,n);
	}
}

void build_max_heap(int a[],int n)
{		int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n);
		
	}
}

void heap_sort(int a[],int n)
{	
	build_max_heap(a,n);
	int i;
	for(i=n;i>1;i--)
	{	
		int temp=a[1];	count++;
		a[1]=a[i];count++;
		a[i]=temp;count++;
		max_heapify(a,1,i-1);
	}
}

int main()
{
	int i,a[10000],n,element,pos;
	int ch;
	printf("Enter 1 for max heap or press any other key:");
	scanf("%d",&ch);
	printf("Enter the number of elements ");
	scanf("%d",&n);
	
	printf("Enter the elements :");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heap_sort(a,n);
	if(ch!=1)
	{
		for(i=1;i<=n;i++)
			printf("%d\t",a[i]);
	}
	else
	{
		for(i=n;i>=1;i--)
			printf("%d\t",a[i]);
	}
	printf("Enter an element to insert :");
	scanf("%d",&element);
	n=insert(a,n,element);
	if(ch!=1)
	{
		for(i=1;i<=n;i++)
			printf("%d\t",a[i]);
	}
	else
	{
		for(i=n;i>=1;i--)
			printf("%d\t",a[i]);
	}
	printf("Enter the position of element to delete :");
	scanf("%d",&pos);
	
	n=delete(a,n,pos);if(ch!=1)
	{
		for(i=1;i<=n;i++)
			printf("%d\t",a[i]);
	}
	else
	{
		for(i=n;i>=1;i--)
			printf("%d\t",a[i]);
	}
			
}
