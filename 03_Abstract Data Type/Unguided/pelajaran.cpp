#include "pelajaran.h"
#include <iostream>


using namespace std;

pelajaran membuat_pelajaran (string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void nampilin_pelajaran (pelajaran pel) {
    cout << "Nama pelajaran = " << pel.namaMapel << endl;
    cout << "Kode pelajaran = " << pel.kodeMapel << endl;
}
