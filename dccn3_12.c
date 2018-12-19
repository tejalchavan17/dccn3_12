#include<stdio.h>
void encode(int n,int bits[]);
void decode(int n,int encode[]);
void main()
{
	int n,i,bits[20];
	printf("\nManchester Encoding and Decoding");
	printf("\nEnter no. of bits:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&bits[i]);
	encode(n,bits);
}
void encode(int n,int bits[])
{
	int i,x=0,y=1,encode[50];
	for(i=0;i<n;i++)
	{
		if(bits[i]==1)
		{
			encode[x]=0;
			encode[y]=1;
			x=x+2;
			y=y+2;
		}
		else
		{
			encode[x]=1;
			encode[y]=0;
			x=x+2;
			y=y+2;
		}
	}
	printf("\nEncoding:\n");
	for(i=0;i<(2*n);i++)
		printf("%d ",encode[i]);
	decode(n,encode);
}
void decode(int n,int encode[])
{
	int i,x=0,y=1,decode[50];
	for(i=0;i<(2*n);i++)
	{
		if(encode[x]==0&&encode[y]==1)
		{
			decode[i]=1;
			x=x+2;
			y=y+2;
		}
		else
		{
			decode[i]=0;
			x=x+2;
			y=y+2;
		}
	}
	printf("\nDecoding:\n");
	for(i=0;i<n;i++)
		printf("%d ",decode[i]);
}
/*Output
students@CE-Lab3-603-U19:~/Desktop$ gcc dccn3.c
students@CE-Lab3-603-U19:~/Desktop$ ./a.out

Manchester Encoding and Decoding
Enter no. of bits:8

Enter elements:0 1 0 0 1 1 1 0

Encoding:
1 0 0 1 1 0 1 0 0 1 0 1 0 1 1 0 
Decoding:
0 1 0 0 1 1 1 0 
*/
