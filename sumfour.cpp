#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000001
using namespace  std;
int binarySearch(int);
int n;
int absum[MAX],cdsum[MAX],a[4001],b[4001],c[4001],d[4001];
int main(int argc, char const *argv[])
{
        cin>>n;
		int index=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i]>>b[i]>>c[i]>>d[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    absum[index++]=(a[i]+b[j]);
            }
        }
		sort(absum,absum+(n*n));
		index=0;
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<n;j++)
		    {
		        cdsum[index++]=(c[i]+d[j]);
		    }
		}
		sort(cdsum,cdsum+(n*n));
		int sum=0;
		for (int i = 0; i < (n*n); )
		{
			int temp=absum[i];
			int size1=1;
			i++;
			while(temp==absum[i] && i<(n*n))
			{
				i++;
				size1++;
			}
			int size2=binarySearch(temp*(-1));
			//cout<<size1<<" "<<size2<<" "<<binary_search(check.begin(),check.end(),(temp*(-1)))<<endl;
			if(size2!=0)
			{
				sum+=(size1*size2);
			}

		}
	cout<<sum<<endl;
	return 0;
}
int binarySearch(int value)
{
	int high=(n*n-1),low=0,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(cdsum[mid]==value)
		{
			int index=mid-1;
			int size=1;
			while(cdsum[index]==value && index>=0)
			{
			    size++;
			    index--;
			}
			index=mid+1;
			while(cdsum[index]==value && index<(n*n))
            {
                index++;
                size++;
            }

			return size;

		}
		else if(cdsum[mid]>value)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return 0;
}
