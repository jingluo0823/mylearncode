#include<stdio.h>
#include<assert.h>
#include<string.h>
#define SIZE 20
typedef struct Str
{
	char elem[SIZE];//串长度
	int length;//有效长度
}Str;

void StrAssign(Str *s,const char *t)//用字符串t初始化串s
{
	int i=0;
	for(;*t!='\0';i++)
	{
		s->elem[i]=*t++;
	}
	s->length=i;
}
void StrCpy(Str *s,Str *t)//将串t拷到串s里
{
	assert(t!=NULL);
	int i=0;
	for(;i<t->length;i++)
	{
		s->elem[i]=t->elem[i];
	}
	s->length=i;
}

bool IsEmpty(Str *s)//判断串s是否为空
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
int GetLength(Str *s)//得到串的长度
{
	return s->length;
}

void Clear(Str *s)//清空串s
{
	s->length=0;

}
bool SubStr(Str *s,Str *t,int pos,int len)//从串t的pos位置提取len个长度字符放到串s
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
bool Insert(Str *s,int pos,Str *t)//在串s的pos位置插入串t，串spos位置之后的值不覆盖
{
	assert(s!=NULL);
	assert(t!=NULL);
	if(pos<0||pos>s->length||pos+t->length>SIZE)
	{
		return false;
	}
	int len=t->length;
	for(int i=s->length;i>=pos;i--)//从串尾依次到pos位置向后挪len个长度
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
int BF(Str *s,Str *t,int pos)//从串s里面第pos个位置开始第一个找到串t,pos位置是自己给的
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
bool DeletePos(Str *s,int pos,int len)//从s的pos位置删除len个字节
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
bool Delete(Str *s,int pos,Str *t)//从pos位置开始删除子串t
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
bool Replace(Str *s,Str *t,Str *v,int pos)//用v替换串s的pos位置开始的第一个串t
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
bool ReplaceAll(Str *s,Str *t,Str *v)//将所有的串t替换成v
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
