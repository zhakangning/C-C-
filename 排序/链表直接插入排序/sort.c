#include<stdio.h>
#include<stdlib.h>

typedef struct linkList{
	int num;
	struct linkList *next;
}LINKLIST;

//生成链表
LINKLIST *createLinklist()
{
	LINKLIST *h=(LINKLIST *)malloc(sizeof(LINKLIST));
	h->next=NULL;
	return h;
}

//插入数据
void insertData(LINKLIST *h,int data)
{
	LINKLIST *p=(LINKLIST *)malloc(sizeof(LINKLIST));
	p->num=data;
	p->next=h->next;
	h->next=p;
}

//打印链表
void printLinklist(LINKLIST *h)
{
	LINKLIST *p;
	p=h->next;
	while(p){
		printf("%d ",p->num);
		p=p->next;
	}
	printf("\n");
}

//直接插入排序
void insertSort(LINKLIST *h)
{
	LINKLIST *key,*bkey,*p;//bkey: before key记录key前面一个节点。bp同理
	p=h;
	bkey=h->next;
	key=bkey->next;
	
	while(key){//key从第二个节点开始遍历链表
		while(p->next!=key){
			if(key->num < p->next->num){
				bkey->next=key->next;//取出key节点，将Key节点的next节点接到bkey节点
				key->next=p->next;
				p->next=key;
				break;
			}else{
				p=p->next;
			}
		}
		//插入完一次，重置p节点的位置
		p=h;
		//key节点回到bkey的下一节点位置
		key=bkey->next;
	}
}

//直接插入排序2
void insertSort2(LINKLIST *h)
{//链表直接插入排序
	LINKLIST *p,*q,*t;
	q=h->next;
	h->next=NULL;//断开头节点
	while(q){
		t=q->next;//保存待插入节点的后一个节点
		p=h;
		
		while((p->next)&&(q->num>p->next->num))
			p=p->next;
		
		q->next=p->next;//插入到P后
		p->next=q;
		q=t;//q移到下一个节点
	}
}

void linkListIverse(LINKLIST *h)
{//链表倒置
	LINKLIST *p,*q;
	p=h->next;
	h->next=NULL;//断开头节点
	while(p){
		q=p->next;
		//重新插入一次
		p->next=h->next;
		h->next=p;
		p=q;
	}
}

int main()
{
	LINKLIST *h=createLinklist();
	int a[]={1,2,3,4,5};
	int len=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<len;i++){
		insertData(h,a[i]);
	}
	
	printf("排序前：\n");
	printLinklist(h);
	linkListIverse(h);
	printf("排序后：\n");
	printLinklist(h);
	
	free(h);
	return 0;
}
