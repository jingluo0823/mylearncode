#include<stdio.h>
#include<assert.h>
#include<string.h>
int BF(char *s,char *t,int pos)//���ַ���s�����posλ���ҵ���һ���ַ���t
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
	while(i<lens&&j<lent)
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			j=0;//i�����ˣ�j���ˣ�
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
void Show(char *s)
{
	assert(s!=NULL);
	int i=0;
	int lens=strlen(s);
	for(;i<lens;i++)
	{
		printf("%c ",s[i]);
	}
}
int main()
{
	char *s="ababcabcdabcde";
	char *t="abcd";
	int n=BF(s,t,0);
	printf("%d\n",n);
	Show(s);
}