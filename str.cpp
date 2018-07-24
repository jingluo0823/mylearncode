#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"str.h"
void StrAssign(Str *s,const char *t)//���ַ���t��ʼ����s
{
	int i=0;
	for(;*t!='\0';i++)
	{
		s->elem[i]=*t++;
	}
	s->length=i;
}
void StrCpy(Str *s,Str *t)//����t������s��
{
	assert(t!=NULL);
	int i=0;
	for(;i<t->length;i++)
	{
		s->elem[i]=t->elem[i];
	}
	s->length=i;
}

bool IsEmpty(Str *s)//�жϴ�s�Ƿ�Ϊ��
{
	if(s->length=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int GetLength(Str *s)//�õ����ĳ���
{
	return s->length;
}

void Clear(Str *s)//��մ�s
{
	s->length=0;

}
bool SubStr(Str *s,Str *t,int pos,int len)//�Ӵ�t��posλ����ȡlen�������ַ��ŵ���s
{
	assert(t!=NULL);
	if(pos<0||pos>t->length||len>t->length)
	{
		return false;
	}
	for(int i=0;i<len;i++)
	{
		s->elem[i]=t->elem[pos+i];
	}
	s->length=len;
	return true;
}
bool Insert(Str *s,int pos,Str *t)//�ڴ�s��posλ�ò��봮t����sposλ��֮���ֵ������
{
	assert(s!=NULL);
	assert(t!=NULL);
	if(pos<0||pos>s->length||pos+t->length>SIZE)
	{
		return false;
	}
	int len=t->length;
	for(int i=s->length;i>=pos;i--)//�Ӵ�β���ε�posλ�����Ųlen������
	{
		s->elem[i+len]=s->elem[i];
	}
	for(int j=0;j<len;j++)
	{
		s->elem[pos+j]=t->elem[j];
	}
	s->length+=len;
	return true;
}
int BF(Str *s,Str *t,int pos)//�Ӵ�s�����pos��λ�ÿ�ʼ��һ���ҵ���t,posλ�����Լ�����
{
	int i=pos;
	int j=0;
	int lens=s->length;
	int lent=t->length;
	while(i<lens&&j<lent)
	{
		if(s->elem[i]==t->elem[j])
		{
			j++;
			i++;
		}
		else
		{
			i=i-j+1;
			j=0;
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
bool DeletePos(Str *s,int pos,int len)//��s��posλ��ɾ��len���ֽ�
{
	assert(s!=NULL);
	if(pos<0||pos>s->length||pos+len>s->length)
	{
		return false;
	}
	for(int i=pos+len;i<s->length;i++)
	{
		s->elem[i-len]=s->elem[i];
	}
	s->length-=len;
	return true;
}
bool Delete(Str *s,int pos,Str *t)//��posλ�ÿ�ʼɾ���Ӵ�t
{
	assert(s!=NULL);
	assert(t!=NULL);
	int n=BF(s,t,0);
	if(n<0)
	{
		return false;
	}
	DeletePos(s,n,t->length);
	return true;
}
bool Replace(Str *s,Str *t,Str *v,int pos)//��v�滻��s��posλ�ÿ�ʼ�ĵ�һ����t
{
	assert(s!=NULL);
	assert(v!=NULL);
	int n=BF(s,t,0);
	if(n<0)
	{
		return false;
	}
	DeletePos(s,n,t->length);
	Insert(s,n,v);
	return true;
}
bool ReplaceAll(Str *s,Str *t,Str *v)//�����еĴ�t�滻��v
{	assert(s!=NULL);
	assert(t!=NULL);
	while(Replace(s,t,v,0));
	return true;
}
void Show(Str *s)
{
	assert(s!=NULL);
	int i=0;
	for(;i<s->length;i++)
	{
		printf("%c ",s->elem[i]);
	}
}
int main()
{
	Str s;
	Str t;
	Str v;
	char *b="xi";
	char *a="woxijigj";
	char *c="vv";
	StrAssign(&v,c);
	StrAssign(&s,a);
	StrAssign(&t,b);
	//StrCpy(&s,&t);
	Show(&s);
	printf("\n");
	/*if(IsEmpty(&s)==0)
	{
		printf("Str s is not empty!\n");
	}*/
	int n=GetLength(&t);
	printf("%d\n",n);
	//SubStr(&s,&t,2,3);
	//Clear( &s);
	//Insert(&s,7,&t);
	int m=BF(&s,&t,0);
	printf("%d\n",m);
	//DeletePos(&s,2,4);
	//Delete(&s,0,&t);
	Replace(&s,&t,&v,0);
	//ReplaceAll(&s,&t,&v);
	Show(&s);
}