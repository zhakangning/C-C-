#include <stdio.h>

void insertSort(int *a, int len)
{
	int i,j,key;
	for(i=1;i<len;i++){
		key=a[i];
		j=0;
		while(key<a[j]&&j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return ;
}

int main()
{
	return 0;
}
