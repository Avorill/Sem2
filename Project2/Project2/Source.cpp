
#include <iostream>
int main() {
    int result[3] = { 0, 0, 0 };
    std::cout << "Size of arrays:" << std::endl;
    int n;
    std::cin >> n;
    int* a_arr = new int[n];
    int* b_arr = new int[n];
    std::cout << std::endl << "First array elements:" << std::endl;
    for (int i = 0; i < n; ++i) {

        std::cin >> a_arr[i];

    }
    std::cout << std::endl;
    std::cout << std::endl << "Second array elements:" << std::endl;
    for (int l = 0; l < n; ++l) {

        std::cin >> b_arr[l];

    }
  
    __asm {
        mov edi, a_arr
        mov esi, b_arr

        XOR ECX, ECX;
    ForBegin1:
        CMP ECX, n;
        JE ForEnd1;
        mov ebx, dword ptr[edi]; // ai
        add edi, 4;          // edi[++i]
        mov eax, dword ptr[esi]; // bi
        add esi, 4;         // esi[++i]
        imul ebx;           // edx:eax = ai * bi
        XOR edx, edx;
        add[result], eax
            adc[result + 4], edx
            adc[result + 8], 0
            INC ECX;
        JMP ForBegin1;
    ForEnd1:
    
    }
    
    std::cout << std::endl <<result[0];
    return 0;
}