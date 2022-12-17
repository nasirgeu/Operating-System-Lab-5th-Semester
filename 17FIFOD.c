#include<stdio.h>
#include<math.h>
int main()
{
    int inpos;
    printf("Input Initial R/W header Position :");
    scanf("%d",&inpos);
    int n;
    printf("Input size :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int sum=abs(inpos-arr[0]);
    for(int i=1; i<n; i++)
        sum+=abs(arr[i-1]-arr[i]);
    printf("ans is :%d",sum);
    return 0;
}