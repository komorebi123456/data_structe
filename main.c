#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int Elemtype;

typedef struct List
    {
    Elemtype *data;
    int length;
    int listsize;
    }List;



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2


Status initList(List *L);
void InitList(List *L);
void Print(List L);
int ListLength(List L);
Status GetElem(List L,int i,Elemtype *e);
Status PutinList(Elemtype e,int i,List *L);
Status ListDelete(Elemtype *e,int i,List *L);
int LocatElem(List L,Elemtype e);
Status ListCombine(List *La,List Lb);


int main()
{
    List p;
    initList(&p);
    InitList(&p);
    Print(p);
    int len = ListLength(p);
    printf("元素个数为：%d\n",len);
    /*int e;
    GetElem(p,2,&e);
    printf("第三个元素是：%d\n",e);
    PutinList(78,2,&p);
    Print(p);
    printf("-----------\n");
    Elemtype de;
    ListDelete(&de,3,&p);
    Print(p);
    printf("我删掉了：%d\n",de);
    int position;
    position = LocatElem(p,4);
    printf("positon is:%d",position);*/
    printf("------------");
    List p2;
    initList(&p2);
    InitList(&p2);
    Print(p2);
    ListCombine(&p,p2);
    printf("------------\n");
    Print(p);


    return 0;

}

//操作结果：构造一个空的线性表
Status initList(List *L)
{
    L->data=(Elemtype*) malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if(!L->data)
    {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

//操作结果：用e返回L中第i个数据元素的值
Status GetElem(List L,int i,int *e)
{
    //先看表是否存在
    if(L.length == 0 )
    {
        return ERROR;
    }
    //先看i是否合理
    if(i<1 || i>L.length)
    {
        return ERROR;
    }
    else
    {
        *e=L.data[i];
        return OK;
    }
}

//初始条件：线性表已经存在
//操作结果：返回L中的数据元素个数

int ListLength(List L)
{
    return L.length;
}

//初始条件：线性表已经存在
//操作结果：表中数据已有

void InitList(List *L)
{

    int len;
    printf("请输入集合长度");
    scanf("%d",&len);
    L->length = len;
    printf("请依次输入集合中的元素");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&(L->data[i]));
    }
    return ;
}

//展示数组
void Print(List L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d\n",L.data[i]);
    }
    return ;
}

//插入操作
Status PutinList(Elemtype e,int i,List *L)
{
    if(L->length == 0 )
    {
        return ERROR;
    }
    //检测i 的合法性
    if(i<1 || i>L->length+1)
    {
        return ERROR;
    }
    //看空间是否足够
    if(L->length == L->listsize)
    {
        Elemtype *newcase = (Elemtype *)realloc(L->data,
                        (L->listsize+LISTINCREMENT)*sizeof(Elemtype));
        if(!newcase)  //如果为空的话，括号内就会显示为错
        {
            exit(OVERFLOW);

        }
        L->data = newcase;
        L->listsize+=LISTINCREMENT;
    }
    //将后面的元素（包括第i个元素）向后移一个
    for(int k=L->length;k>=i;k--)
    {
        L->data[k]=L->data[k-1];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

//操作：删除第i个位置的数据，并用e返回
Status ListDelete(Elemtype *e,int i,List *L) //e用指针：因为要带东西出去
{
    if(L->length == 0)
    {
        return ERROR;
    }
    //i is reasonable?
    if(i<1 || i>L->length)
    {
        return ERROR;
    }
    //delete
    *e=L->data[i-1];
    for(int k=i;k<=L->length;k++)
    {
        L->data[k-1] = L->data[k];
    }
    L->length--;
    return OK;
}

//write a compare function
Status compare(Elemtype e1,Elemtype e2)
{
    if(e1 == e2)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//operation:Locate 查找
int LocatElem(List L,Elemtype e)
{
    for(int i=0;i<L.length;i++)
    {
        if(compare(e,L.data[i]))
        {
            return i+1;
        }
    }
    return 0;
}

//combine two List
Status ListCombine(List *La,List Lb)
{
    //判断两表是否为空表
    if(La->length == 0 || Lb.length == 0)
    {
        return ERROR;
    }
    //合并后是否会超长
    if((La->length + Lb.length) > La->listsize)
    {

    }
    while((La->length + Lb.length) > La->listsize)
    {
        Elemtype *newcase = (Elemtype *)realloc(La->data,
                (La->listsize+LISTINCREMENT)*sizeof(Elemtype));
        if(!newcase)
        {
            exit(OVERFLOW);
        }
        La->data = newcase;
        La->listsize += LISTINCREMENT;
    }
    //表的长度合适了
    int len_a = La->length;
    int i;
    for( i=0;i<Lb.length;i++)
    {
        La->data[len_a+i] =Lb.data[i];
    }
    La->length +=Lb.length;
    return OK;
}
























