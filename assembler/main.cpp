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
  ;xor edx, edx;				 clear edx
  ADD  eax, c;				 add c to eax
  NEG eax;					-eax
  cdq;
 ; xor ecx, ecx;
  mov ecx, 3;
  mov esi, a;
  mov ost, eax;
  imul esi, ecx;         3*a
  idiv  esi;
  jp end
  imul edx, 2;     mutiply f compare
  cmp  esi,0
  jge ent
   cmp ost,0
   jge ent
   neg esi
  ent:
  cmp ost, 0
  jne etc
   jmp end;
  etc:
  cmp esi, edx;   //  6 vs. 8
  jnle NNegBigDiv;
  	 jmp end;
  NNegBigDiv:
    jnge NNegLessDiv;
      add eax, 1
      jmp end;
      NNegLessDiv:
    	jne NNegEqualDiv;
    	   test eax, 1
    	   jz Evn;
    	    jmp result;
    	   Evn:
              add eax, 1
              NNegEqualDiv:

  end:
  mov result, eax

  }

  return   result;
}

int main(){
  std::cout<<"a, b,y, c\n"<<">";
  int a, b, c, y;
  std::cin>>a>>b>>y>>c;
  std::cout<<Calculate(a,b,c,y);





}


