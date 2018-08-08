#include <iostream>
#include <ctime>

using namespace std;

int main() {
    clock_t begin;
    int arr[1024];
    cout << "Comenzando a medir Tiempo\n" << endl;
    begin = clock();
    for(int i = 0; i<1024; i++){
        arr[i] = i;
    }
    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Tardo: " << elapsed_secs << "\n" << std::endl;
    return 0;
}