#define Maxlength 40
typedef int Position; 
struct SinhVien{
    char MSSV[10];
    char HoTen[50];
    float DLT;
    float DiemTH1;
    float DiemTH2;
} ;
typedef struct {
	struct SinhVien A[Maxlength];
	Position    n;
} DanhSach; 

DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
}

int ktRong(DanhSach L){
    return L.n==0;
}

void chenCuoi(struct SinhVien s, DanhSach *pL){
    if (pL->n==Maxlength)
        printf("Loi! Danh sach day!");
    else {
        pL->A[pL->n]=s;
        pL->n++;
    }    
}

int tim(char mssv[], DanhSach L){
    int p=1;
    int found=0;
    while (p!=L.n+1 && !found){
        if (strcmp(L.A[p-1].MSSV,mssv)==0)
            found=1;
        else
            p++;
    }
    return p;
}

void hienthi(DanhSach L){
    int p=1;
    struct SinhVien s;
    while(p!=L.n+1){
        s=L.A[p-1];
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",s.MSSV, s.HoTen, s.DLT, s.DiemTH1, s.DiemTH2, s.DLT+s.DiemTH1+s.DiemTH2);
        p++;
    }
}

DanhSach nhap(){
    DanhSach L;
    struct SinhVien sv;
    L=dsRong();
    int N,i;
    char ms[10];
    char ht[50];
    scanf("%d ", &N);
    for (i=1; i<=N; i++){
        fgets(ms,10,stdin);
        if (ms[strlen(ms)-1]=='\n')
           ms[strlen(ms)-1]='\0';
        strcpy(sv.MSSV,ms);
        fgets(ht,50,stdin);
        if (ht[strlen(ht)-1]=='\n')
           ht[strlen(ht)-1]='\0';       
        strcpy(sv.HoTen,ht);
        scanf("%f%f%f ",&sv.DLT,&sv.DiemTH1,&sv.DiemTH2);       
         if (tim(ms,L)==L.n+1){
            chenCuoi(sv,&L);
        }
    }
    return L;
}

void xoaTai(int p, DanhSach *pL){
    if (pL->n==0)
        printf("Danh sach rong");
    else if (p<1 || p>pL->n)
        printf("Vi tri khong hop le");
    else {
        int Q;
        for(Q=p-1; Q<pL->n-1; Q++){
            pL->A[Q] = pL->A[Q+1];
        }
        pL->n--;
    }
}

void xoaSinhVien(char ms[], DanhSach *pL){
    int p;
    p=tim(ms,*pL);
    if (p!=pL->n+1){
        xoaTai(p,pL);
    }
}

void hienthiDat(DanhSach L){
    int p=1;
    float tdiem;
    while (p!=L.n+1){
        tdiem=L.A[p-1].DLT+L.A[p-1].DiemTH1+L.A[p-1].DiemTH2;
        if (tdiem>=4){
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[p-1].MSSV, L.A[p-1].HoTen, L.A[p-1].DLT, L.A[p-1].DiemTH1, L.A[p-1].DiemTH2, tdiem); 
        }
        p++;
    }
}

DanhSach chepKhongDat(DanhSach L){
    DanhSach L1;
    L1=dsRong();
    int p=1;
    float tdiem;
    while (p!=L.n+1){
        tdiem=L.A[p-1].DLT+L.A[p-1].DiemTH1+L.A[p-1].DiemTH2;
        if (tdiem<4){
            chenCuoi(L.A[p-1],&L1);
        }
        p++;
    }
    return L1;
}


