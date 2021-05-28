#include <iostream>
using namespace std;
extern "C" bool __cdecl Polyndrom(char* s);
int main(){

    cout << " line: " << endl;

    char c[10000];
    cin >> c;

    if (Polyndrom(c)) {
        cout << "+" << endl;
    }
    else {
        cout << "-" << endl;
    }

return 0;
}
