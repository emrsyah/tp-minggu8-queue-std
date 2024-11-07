#ifndef QUEUE_VAKSINASI_H_INCLUDED
#define QUEUE_VAKSINASI_H_INCLUDED
#define head(q) q.head
#define tail(q) q.tail
#define info(P) (P)->info
#define next(P) (P)->next
#define nill NULL
using namespace std;

struct Infotype {
 string nama;
 int usia;
 string pekerjaan;
 bool prioritas;
 int nomor_antrean;
 bool kondisi_darurat;
};

struct ElemQ {
 Infotype info;
 ElemQ *next;
};

struct Queue {
 ElemQ *head;
 ElemQ *tail;
};

void createQueue(Queue &Q) ;
bool isEmpty(Queue Q) ;
ElemQ* createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean) ;
void enqueue(Queue &Q, ElemQ *P) ;
void dequeue(Queue &Q, ElemQ *&P);
ElemQ* front(Queue Q) ;
ElemQ* back(Queue Q) ;
int size(Queue Q) ;
void printInfo_1030123000339(Queue Q);
void serveQueue_103012300339(Queue &Q) ;
void reassignQueue_103012300339(Queue &Q) ;
void checkWaitingTime_1030123000339(Queue &Q, int waktu_sekarang);
void emergencyHandle_1030123000339(Queue &Q, int nomor_antrean );
void updatePriority_1030123000339(Queue &Q);
ElemQ* findAndRemove_1030123000339(Queue &Q, int nomor_antrean);

#endif // QUEUE_VAKSINASI_H_INCLUDED
