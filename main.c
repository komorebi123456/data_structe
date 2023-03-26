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
    printf("Ԫ�ظ���Ϊ��%d\n",len);
    /*int e;
    GetElem(p,2,&e);
    printf("������Ԫ���ǣ�%d\n",e);
    PutinList(78,2,&p);
    Print(p);
    printf("-----------\n");
    Elemtype de;
    ListDelete(&de,3,&p);
    Print(p);
    printf("��ɾ���ˣ�%d\n",de);
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

//�������������һ���յ����Ա�
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

//�����������e����L�е�i������Ԫ�ص�ֵ
Status GetElem(List L,int i,int *e)
{
    //�ȿ����Ƿ����
    if(L.length == 0 )
    {
        return ERROR;
    }
    //�ȿ�i�Ƿ����
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

//��ʼ���������Ա��Ѿ�����
//�������������L�е�����Ԫ�ظ���

int ListLength(List L)
{
    return L.length;
}

//��ʼ���������Ա��Ѿ�����
//���������������������

void InitList(List *L)
{

    int len;
    printf("�����뼯�ϳ���");
    scanf("%d",&len);
    L->length = len;
    printf("���������뼯���е�Ԫ��");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&(L->data[i]));
    }
    return ;
}

//չʾ����
void Print(List L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d\n",L.data[i]);
    }
    return ;
}

//�������
Status PutinList(Elemtype e,int i,List *L)
{
    if(L->length == 0 )
    {
        return ERROR;
    }
    //���i �ĺϷ���
    if(i<1 || i>L->length+1)
    {
        return ERROR;
    }
    //���ռ��Ƿ��㹻
    if(L->length == L->listsize)
    {
        Elemtype *newcase = (Elemtype *)realloc(L->data,
                        (L->listsize+LISTINCREMENT)*sizeof(Elemtype));
        if(!newcase)  //���Ϊ�յĻ��������ھͻ���ʾΪ��
        {
            exit(OVERFLOW);

        }
        L->data = newcase;
        L->listsize+=LISTINCREMENT;
    }
    //�������Ԫ�أ�������i��Ԫ�أ������һ��
    for(int k=L->length;k>=i;k--)
    {
        L->data[k]=L->data[k-1];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

//������ɾ����i��λ�õ����ݣ�����e����
Status ListDelete(Elemtype *e,int i,List *L) //e��ָ�룺��ΪҪ��������ȥ
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

//operation:Locate ����
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
    //�ж������Ƿ�Ϊ�ձ�
    if(La->length == 0 || Lb.length == 0)
    {
        return ERROR;
    }
    //�ϲ����Ƿ�ᳬ��
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
    //��ĳ��Ⱥ�����
    int len_a = La->length;
    int i;
    for( i=0;i<Lb.length;i++)
    {
        La->data[len_a+i] =Lb.data[i];
    }
    La->length +=Lb.length;
    return OK;
}
























