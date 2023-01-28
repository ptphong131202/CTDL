/*Su dung DS con tro tron 2 DS duoc sap thu tu tang*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
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
Position Locate(ElementType X, List L)
{	Position P;
	int Found = 0;
	P = L;
	while ((P->Next != NULL) && (Found == 0))
		if (P->Next->Element == X) Found = 1;
		else P = P->Next;
	return P;
}
//Chen phan tu o cuoi
void Insert_List(ElementType X,Position P, List *L)
 {
        Position T;
		T=(struct Node*)malloc(sizeof(struct Node));
		T->Element=X;
		T->Next=P->Next;
		P->Next=T;
}
Position OrderLocate(ElementType X, List L)
{
    Position P;
    //int found=0;
    P=First(L);
    while ((P!=EndList(L)) && (Retrieve(P,L)<X))
    {
       P=Next(P,L);
    }
    return P;
}
//Chen phan tu vao dung vi tri de danh sach tang
void Insert_OrderList(ElementType X,List *L)
 {
     Position P=OrderLocate(X,*L);
	 Insert_List(X,P,L);
}

void Delete_List(Position P, List *L)
{ Position Temp;
	 if (P->Next!=NULL)
   {  Temp=P->Next;

		P->Next=Temp->Next;

		free(Temp);
	  }
}

void Delete_Same(List *L)
{
    Position p,q;
    p=First(*L);
    while(p!=EndList(*L))
    {
        q=Next(p,*L);
        while(q!=EndList(*L))
        {
             if(Retrieve(p,*L)==Retrieve(q,*L))
                Delete_List(q,L);
            else
                q=Next(q,*L);
        }
       p=Next(p,*L);
    }
}
ElementType Retrieve(Position P, List L)
{
	if (P->Next!=NULL)
		return P->Next->Element;
 }

void Read_List(List *L)
{
    ElementType x;
    Position p;
    int i,n,t;
    MakeNull_List(L);
    p=First(*L);
    printf("\nSo phan tu trong danh sach:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nNhap phan tu thu %d:",i);
        scanf("%d",&x);
        //Insert_List(x,EndList(*L),L);
        Insert_OrderList(x,L);//Chen dung vi tri tang
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
List Mix_List(List L1, List L2)
{
    List L3;
    Position p1,p2;
    p1=L1; p2=L2;
	MakeNull_List(&L3);
	while((p1->Next!=NULL) && (p2->Next!=NULL)){
		if(p1->Next->Element<=p2->Next->Element){
			Insert_List(p1->Next->Element,EndList(L3),L3);
			p1=p1->Next;
		}
		else{
			Insert_List(p2->Next->Element,EndList(L3),L3);
			p2=p2->Next;
		}
	}

	if(p1->Next!=NULL){
		while (p1->Next!=NULL){
			Insert_List(p1->Next->Element,EndList(L3),L3);
			p1=p1->Next;
		}
	}
	else if(p2->Next!=NULL){
		while (p2->Next!=NULL){
			Insert_List(p2->Next->Element,EndList(L3),L3);
			p2=p2->Next;
		}
	}
	return L3;
}

List Mix_List_1(List L1, List L2)
{
    List L3;
    Position p1,p2;
    p1=L1; p2=L2;
	MakeNull_List(&L3);

	while((p1->Next!=NULL)){
			Insert_List(p1->Next->Element,EndList(L3),&L3);
			p1=p1->Next;
		}

    while (p2->Next!=NULL){
			Insert_OrderList(p2->Next->Element,&L3);
			p2=p2->Next;
		}

	return L3;
}
void main(){
	//clrscr();
	List L1, L2, L3;
	List p1, p2;
    int n;

	printf("Nhap vao danh sach 1 co thu tu tang:\n");
	Read_List(&L1);
	printf("\nDS 1 vua nhap vao:\n");
	PrintList(L1);

	printf("\nNhap vao danh sach 2 co thu tu tang:");
	Read_List(&L2);
    printf("\nDS 2 vua nhap vao:\n");
	PrintList(L2);

    L3 = Mix_List(L1,L2);
	printf("\nDS ket qua tron tu DS1 va DS2:\n");
	PrintList(L3);
    printf("\nNhap phan tu can xac dinh trong danh sach sau khi tron:");
    scanf("%d",&n);
    printf("\n So luong phan tu %d  la: %d phan tu",n,Quantity_X(n,L3));
    Delete_Same(&L3);
    printf("\nDS 3 sau khi bo cac gia tri trung:\n");
	PrintList(L3);
	getch();
}
