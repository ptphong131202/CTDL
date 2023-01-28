#include <stdio.h>
#include<conio.h>

typedef int ElementType;
	typedef struct Node
	 {
	     ElementType Element;
        struct Node* Next;
      };
  typedef struct Node* Position;

  typedef Position List;

  void MakeNull_List(List *Header)
	{
		(*Header)=(struct Node*)malloc(sizeof(struct Node));
		(*Header)->Next=NULL;
	}
int Empty_List(List L)
	{
		  return (L->Next==NULL);
	}
void Insert_List(ElementType X,Position P, List *L)
 {	Position T;
        // Buoc 1
		T=(struct Node*)malloc(sizeof(struct Node));

		// Buoc 2
		T->Element=X;

		// Buoc 3
		T->Next=P->Next;

		// Buoc 4
		P->Next=T;
	}
P
void Delete_List(Position P, List *L)
{ Position Temp;
	 if (P->Next!=NULL)
   {  Temp=P->Next;

		P->Next=Temp->Next;

		free(Temp);
	  }
}
Position Locate(ElementType X, List L)
{	Position P;
	int Found = 0;
	P = L;
	while ((P->Next != NULL) && (Found == 0))
		if (P->Next->Element == X) Found = 1;
		else P = P->Next;
	return P;
}
ElementType Retrieve(Position P, List L)
{
	if (P->Next!=NULL)
		return P->Next->Element;
 }
Position First(List L)
{
    return L;
}
Position EndList(List L)
{
	Position P;
	P=First(L);
	while (P->Next!=NULL) P=P->Next;
	return P;
}
Position Next(Position P, List L)
{
    return P->Next;
}
void Read_List(List *L)
{
    ElementType x;
    Position p;
    int i,n,t;
    p=First(*L);
    printf("So phan tu trong danh sach:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Nhap phan tu thu %d:",i);
        scanf("%d",&x);
        Insert_List(x,EndList(*L),L);
    }
}
void PrintList(List L)
{
	Position P;
	P = First(L);
	while (P != EndList(L))
	{
		printf("%d ",Retrieve(P,L));
		P = Next(P, L);
	}
	printf("\n");
}
int Quantity_X(ElementType x, List L)
{
    Position P=First(L);
    int count=0;
    while(P!=EndList(L))
    {
        if(Retrieve(P,L)==x)
            count++;
        P=Next(P,L);
    }
    return count;
}

void main()
{
    List L;
    int n;
    MakeNull_List(&L);
    Read_List(&L);
    printf("Danh sach la:");
    PrintList(L);
    printf("Nhap phan tu can xac dinh:");
    scanf("%d",&n);
    printf("\n So luong phan tu co noi dung %d can tim la:%d",n,Quantity_X(n,L));
}


