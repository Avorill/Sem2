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
  idiv ecx;
  mov ost, edx;
  xor ecx, ecx;
  mov ecx, a;
  cdq;
  idiv ecx;
  mov ecx, ost;
  imul edx, ecx;




  mov result, edx
  }

  return result;
}

int main(){
  std::cout<<"a, b,c, y\n"<<">";
  int a, b, c, y;
  std::cin>>a>>b>>c>>y;
  std::cout<<Calculate(a,b,c,y);





}
