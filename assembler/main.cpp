//1.	Дана функция 3ax + by + c = 0. Вычислить значение x по данным целым значениям a, b, c, y.

#include <iostream>

int Calculate(int a, int b, int c, int y)
{
  int result;
	int ost;
  __asm
  {
  mov eax, b;				  b -> eax
  IMUL y; 					  eax*y
  xor edx, edx;				 clear edx
  ADD  eax, c;				 add c to eax
  NEG eax;					-eax
  cdq;
  xor ecx, ecx;
  mov ecx, 3;
  mov esi, a;
  imul esi, ecx;         3*a
  idiv  esi;
  imul edx, 2;     mutiply f compare
  cmp esi, edx
  jl end;
  jg plusend;
  je equal;
  equal:
    test eax,1;
	jnz   O;
	jz    Even
    jmp end;
  plusend:
    add eax,1;
  end:
  mov result, eax
  }

  return result;
}

int main(){
  std::cout<<"a, b,c, y\n"<<">";
  int a, b, c, y;
  std::cin>>a>>b>>c>>y;
  std::cout<<Calculate(a,b,c,y);





}
