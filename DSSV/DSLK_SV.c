#include <stdio.h>
#include<conio.h>

struct Sinhvien
{
    char masv[20];
    char hoten[50];
    char malop[20];
    float diemTB; 
};

typedef struct Sinhvien SV;

typedef struct Node{
    SV Element;
    struct Node *next;
};

typedef struct Node* Position;
typedef Position List;

void MakeNull_List(List *Header)
{
	(*Header) = (struct Node*)malloc(sizeof(struct Node));
	(*Header)->next = NULL;
}
int Empty_List(List L)
{
    return (L->next==NULL);
}

void Insert_List(SV X,Position P, List *L)
{
    Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element = X;
	T->next=P->next;
	P->next = T;
}

Position First(List L)
{
    return L;
}

Position Next(Position P, List L)
{
    return P->next;
}

Position EndList(List L)
{
	Position P;
	P=First(L);
	while (P->next!=NULL) P = P->next;
	return P;
}

void Read_List(List *L)
{
    SV x;
    Position p;
    int i,n,t;
    p = First(*L);
    printf("So phan tu trong danh sach: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Nhap masv thu %d: ",i);
        fflush(stdin);
    	gets(x.masv);
		printf("Nhap ten sv thu %d: ",i);
        fflush(stdin);
    	gets(x.hoten);
    	printf("Nhap ma lop sv thu %d: ",i);
        fflush(stdin);
    	gets(x.malop);
    	printf("Nhap diem tb sv thu %d: ",i);
        scanf("%f", &x.diemTB);
		
        Insert_List(x, EndList(*L), L);
    }
}

SV Retrieve(Position P, List L)
{
    if (P->next!=NULL)
        return P->next->Element;
}

void PrintList(List L)
{
	Position P;
	P = First(L);
	while (P != EndList(L))
	{
		SV x = Retrieve(P,L);
		printf("\n masv: %s ",x.masv);
		printf("\n ho ten: %s ",x.hoten);
		printf("\n lop: %s ",x.malop);
		printf("\n masv: %f ",x.diemTB);
		P = Next(P, L);
	}
	printf("\n\n");
}

void Delete_List(Position P, List *L)
{
    Position Temp;
	if (P->next!=NULL)
    {
        Temp=P->next;
		P->next=Temp->next;
		free(Temp);
    }
}

void Delete_SV(List *L)
{
	Position P;
	P = First(*L);
	while (P != EndList(*L))
	{
		SV x = Retrieve(P, *L);
		
		if(x.diemTB < 5)
			Delete_List(P, L);
			
		P = P->next;
	}
}

void Sort_SV(List *L)
{
	Position i, j;
	for(i = First(*L);i != EndList(*L); i = i->next)
		for(j = i->next; j != EndList(*L); j=j->next)
		{
			SV sv1 = Retrieve(i, L);
			SV sv2 = Retrieve(j, L);
			if(sv1.diemTB > sv2.diemTB)
			{
				SV temp = sv1;
				printf("%f", i->next->Element.diemTB);
				
				strcpy(i->next->Element.masv, j->next->Element.masv);
				strcpy(i->next->Element.hoten, j->next->Element.hoten);
				strcpy(i->next->Element.malop, j->next->Element.malop);
				i->next->Element.diemTB = j->next->Element.diemTB;
				
				strcpy(j->next->Element.masv, sv1.masv);
				strcpy(j->next->Element.hoten, sv1.hoten);
				strcpy(j->next->Element.malop, sv1.malop);
				j->next->Element.diemTB = sv1.diemTB;				
			}
		}
}

int main()
{
	List L;
    int n;
    MakeNull_List(&L);
    Read_List(&L);
    Delete_SV(&L);
    Sort_SV(&L);
    printf("\nDanh sach la: ");
    PrintList(L);
	return 0;
}

