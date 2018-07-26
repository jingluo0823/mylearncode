#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>
void GetNext(char *t,int *next,int pos)//得到j的退回位置
{
	assert(t!=NULL);
	int lent=strlen(t);
	int i=2;
	int j=0;
	next[0]=-1;
	next[1]=0;
	while(i<lent)
	{
		if((j==-1)||t[i-1]==t[j])
		{
			t[i]=j+1;
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
}
int KMP(char *s,char *t,int pos)//在字符串s里第pos位置找到的第一个字符串t
{
	assert(s!=NULL);
	assert(t!=NULL);
	int lens=strlen(s);
	int lent=strlen(t);
	if(pos<0||pos>lens)
	{
		return -1;
	}
	int i=pos;
	int j=0;
	int *next=(int *)malloc(sizeof(int)* lent);
	GetNext(t,next,pos);
	while(i<lens&&j<lent)
	{
		if((j==-1)||s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j>=lent)
	{
		return i-j;
	}
	else
	{
		return -1;
	}

}

int main()
{
	char *s="ababcabcdabcde";
	char *t="abcd";
	int n=KMP(s,t,0);
	printf("%d\n",n);
	return 0;
}