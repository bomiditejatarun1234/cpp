#include<stdio.h>
void read(int[], int);
void display(int[], int);
int largest(int[], int);
int digits(int);
void radix(int a[], int);
void read(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
void display(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
int largest(int a[], int n)
{
	int i,l=a[0];
	for(i=0;i<n;i++)
	{
		if(l<a[i])
		l=a[i];
	}
	return l;
}
int digits(int n)
{
	int d=0;
	while(n!=0)
	{
		d++;
		n=n/10;
	}
	return d;
}
void radix(int a[], int n)
{
	int i,j,k,s,d,l,div=1,count[10],b[10][n];
	l=largest(a,n);
	d=digits(l);
	for(s=0;s<d;s++)
	{
		for(i=0;i<10;i++)
		count[i]=0;
		for(i=0;i<n;i++)
		{
			int pos=(a[i]/div)%10;
			b[pos][count[pos]]=a[i];
			count[pos]++;
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<count[i];j++)
			{
				a[k]=b[i][j];
				k++;
			}
		}
		div=div*10;
	}
}
int main()
{
	int a[10],n;
	printf("Enter number of elemets:");
	scanf("%d",&n);
	printf("Enter array elements:");
	read(a,n);
	printf(" elements before sorting:");
	display(a,n);
	radix(a,n);
	printf("\n");
	printf("After sorting:");
	display(a,n);
	return 0;
}

