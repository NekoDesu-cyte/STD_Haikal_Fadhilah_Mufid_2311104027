#include "pelajaran.h"
#include <iostream>

using namespace std;

int main () {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = membuat_pelajaran(namapel, kodepel);
    nampilin_pelajaran(pel);

    return 0;

}