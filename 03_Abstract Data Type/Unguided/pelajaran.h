#ifndef pelajaran_h
#define pelajaran_h

#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran membuat_pelajaran(string namapel, string kodepel);

void nampilin_pelajaran(pelajaran pel);

#endif