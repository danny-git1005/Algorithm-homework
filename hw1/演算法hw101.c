#include <stdio.h>

typedef struct fabani_term 
{
	unsigned long long term00;
	unsigned long long term01;
	unsigned long long term10;
	unsigned long long term11;
}term;

term new_seq(term b,unsigned long long f);
unsigned long long fast_cal(term a, unsigned long long b, unsigned long long c, unsigned long long f);
term matrixmulti(term a,term b);
void print(term q);

int main ()
{
	unsigned long long a1=0,a2=0,x=0,y=0,n=0;
	term initial ;
	
	scanf("%lu",&a1);
	scanf("%lu",&a2);
	scanf("%lu",&x);
	scanf("%lu",&y);
	scanf("%lu",&n);
	
	initial.term00 = x;
	initial.term01 = y;
	initial.term10 = 1;
	initial.term11 = 0;
	
	printf("\noutput = %llu",fast_cal(initial,a1,a2,n));
	
	return 0;
 } 
 
 unsigned long long fast_cal(term a, unsigned long long b, unsigned long long c, unsigned long long f)
{
	unsigned long long count = 1;
	unsigned long long temp = 0;
	term ans;
	ans.term00 = 1;
	ans.term01 = 0;
	ans.term10 = 0;
	ans.term11 = 1;
	f-=2;
	
	while( f != 0)
	{
		if( f&1 )
		{
			ans = matrixmulti(ans,a);
			/*
			ans.term00 = ans.term00;
			ans.term01 = ans.term01;
			ans.term10 = ans.term10;
			ans.term11 = ans.term11;
			*/
		}
		
		count *= 2;
		f>>=1;
		a = matrixmulti(a,a);
		
	}
	
	printf("ans = \n");
	print(ans);
	printf("c = %llu, b = %llu\n",c , b);
	printf("an = %llu, an-1 = %llu \n",ans.term00,ans.term01);
	printf("an + an-1 = %llu\n", ans.term00*c+ans.term01*b);
	
	temp = ((ans.term00*c+ans.term01*b)%1000000007);
	return temp;
}
 
 
 
 term matrixmulti(term a,term b)
 {
 	term c ;
 	
 	c.term00 = (a.term00*b.term00+a.term01*b.term10)%1000000007;
 	c.term01 = (a.term00*b.term01+a.term01*b.term11)%1000000007;
 	c.term10 = (a.term10*b.term00+a.term11*b.term10)%1000000007;
 	c.term11 = (a.term10*b.term01+a.term11*b.term11)%1000000007;
 	
 	return c;
 }
 
 void print(term q)
 {
 	printf("%lld\t",q.term00);
 	printf("%lld\n",q.term01);
 	printf("%lld\t",q.term10);
 	printf("%lld\n",q.term11);
 	
 	return;
 }
 
 
 
