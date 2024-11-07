#include <iostream>
#include "queue_vaksinasi.h"

void createQueue(Queue &Q) {
 head(Q) = nill;
 tail(Q) = nill;
};

bool isEmpty(Queue Q) {
 return head(Q) == nill;
};

ElemQ* createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean) {
 ElemQ *P = new ElemQ;
 info(P).nama = nama;
 info(P).usia = usia;
 info(P).pekerjaan = pekerjaan;
 info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
 info(P).nomor_antrean = nomor_antrean;
 info(P).kondisi_darurat = false;
 next(P) = nill;
 return P;
};

void enqueue(Queue &Q, ElemQ *P) {
 if (isEmpty(Q)) {
 head(Q) = P;
 tail(Q) = P;
 } else if (info(P).prioritas) {
 if (!info(head(Q)).prioritas) {
 next(P) = head(Q);
 head(Q) = P;
 } else {
 ElemQ *temp = head(Q);
 while (next(temp) != nill &&
info(next(temp)).prioritas) {
 temp = next(temp);
 }
 next(P) = next(temp);
 next(temp) = P;
 if (next(P) == nill) {
 tail(Q) = P;
 }
 }
 } else {
 next(tail(Q)) = P;
 tail(Q) = P;
 }
};


void dequeue(Queue &Q, ElemQ *&P) {
 if (isEmpty(Q)) {
 P = nill;
 cout << "Semua warga telah terlayani."
<< endl;
 } else {
 P = head(Q);
 head(Q) = next(head(Q));
 if (head(Q) == nill) {
 tail(Q) = nill;
 }
 next(P) = nill;
 }
};

ElemQ* front(Queue Q) {
 return head(Q);
};


ElemQ* back(Queue Q) {
 return tail(Q);
};

int size(Queue Q) {
 int count = 0;
 ElemQ *temp = head(Q);
 while (temp != nill) {
 count++;
 temp = next(temp);
 }
 return count;
};

void printInfo_1030123000339(Queue Q){
  ElemQ *p = head(Q);
  if (p == nill){
    cout << "Antrean Kosong." << endl << endl;
    return;
  }
  while (p != nill){
    cout << "Nama:  " << info(p).nama << endl;
    cout << "Usia:  " << info(p).usia << endl;
    cout << "Pekerjaan:  " << info(p).pekerjaan << endl;
    cout << "Nomor Antrian:   " << info(p).nomor_antrean << endl;
    cout << "Status:   " << (info(p).prioritas ? "Prioritas" : "Normal") << endl;
    cout << "Kondisi Darurat:   " << (info(p).kondisi_darurat ? "Ya" : "Tidak") << endl;
    cout << "------------------------------------" << endl;
    p =  next(p);
  }
}

void serveQueue_103012300339(Queue &Q) {
  ElemQ *p = head(Q);
  int served = 0;
  while (p != nill && served < 100){
    cout << "Melayani Warga: " << endl;
    cout << "Nama:  " << info(p).nama << endl;
    cout << "Usia:  " << info(p).usia << endl;
    cout << "Pekerjaan:  " << info(p).pekerjaan << endl;
        cout << "Nomor Antrian:   " << info(p).nomor_antrean << endl;
    cout << "Status:  " << (info(p).prioritas ? "Prioritas" : "Normal") << endl;
    cout << "Kondisi Darurat:  " << (info(p).kondisi_darurat ? "Ya" : "Tidak") << endl;
    cout << "Vaksinasi berhasil." << endl;
    cout << "------------------------------------" << endl;
    ElemQ *tmp;
    dequeue(Q, tmp);
    served += 1;
    p =  head(Q);
  }
   if (served >= 100) {
        cout << "Kapasitas harian telah penuh!" << endl;
    }
    if (!isEmpty(Q)) {
        cout << "Warga yang belum terlayani diminta kembali besok." << endl;
    }
  cout << endl;
}
void reassignQueue_103012300339(Queue &Q) {
  Queue tempQ;
  createQueue(tempQ);

  while (!isEmpty(Q)){
    ElemQ *p;
    dequeue(Q, p);
    if (p != nill){
        info(p).prioritas = info(p).usia >= 60 || info(p).pekerjaan == "tenaga kesehatan";
        enqueue(tempQ, p);
    }
  }
  Q = tempQ;
}
void checkWaitingTime_1030123000339(Queue &Q, int waktu_sekarang){
  if(waktu_sekarang > 120){
    ElemQ *p = head(Q);
    while (p != nill){
        info(p).prioritas = true;
        p = next(p);
    }
  }
}
void emergencyHandle_1030123000339(Queue &Q, int nomor_antrean ){
  ElemQ *p = findAndRemove_1030123000339(Q, nomor_antrean);

  if (p != nill){
    info(p).kondisi_darurat = true;
    info(p).prioritas = true;
    next(p) = head(Q);
    head(Q) = p;
    cout << "Warga " << info(p).nama << " dipindahkan ke awal antrean karena kondisi darurat." << endl;
  }

}

void updatePriority_1030123000339(Queue &Q){
 Queue tempQ;
 createQueue(tempQ);

 ElemQ* temp = head(Q);
 while (temp != nill){
    if (info(temp).kondisi_darurat){
        ElemQ *emergency = findAndRemove_1030123000339(Q, info(temp).nomor_antrean);
        enqueue(tempQ, emergency);
    }
    temp  = next(temp);
 }

 temp = head(Q);
 while (temp != nill){
    if(info(temp).prioritas && !info(temp).kondisi_darurat){
        ElemQ *prioritas = findAndRemove_1030123000339(Q, info(temp).nomor_antrean);
        enqueue(tempQ, prioritas);
    }
    temp = next(temp);
 }

 while (!isEmpty(Q)){
    ElemQ *p;
    dequeue(Q, p);
    if (p != nill){
        enqueue(tempQ, p);
    }
 }
 Q = tempQ;
}

ElemQ* findAndRemove_1030123000339(Queue &Q, int nomor_antrean){
  Queue tmpQ;
  ElemQ *p = head(Q);
  ElemQ *p2;
  ElemQ *finded = nill;
  createQueue(tmpQ);
  while (p != nill){
    if(info(p).nomor_antrean != nomor_antrean){
        dequeue(Q, p2);
        enqueue(tmpQ, p2);
    } else {
      finded = p;
    }
    p = next(p);
  }
  Q = tmpQ;
  if (finded == nill){
    cout << "Nomor antrean tersebut tidak ditemukan" << endl << endl;
  }
  return finded;
}


