//1.	На вход подаются длины трёх отрезков a, b, c(0 < a, b, c < 232).
//	Определить, можно ли из них составить невырожденный треугольник(вернуть 1, если да, 0, если нет).
//	Типовые данные для проверки :
//a = 5, b = 3, c = 4 -> true
//a = 3000000000, b = 3000000000, c = 2000000000 -> true
//a = 1000000000, b = 2000000000, c = 3000000000 -> false
////Если нужно упростить задачу, то можете считать, что a ≤ b ≤ c.
//Примечание : используйте unsigned int.
#include <iostream>
 int Triangle(unsigned int a, unsigned int b, unsigned int c) {
   int result;
   unsigned int max;
   _asm{
       mov eax, a
	   cmp eax, b
	   jg gr1
	   mov edx, a
	   mov eax, b
	   gr1 :; в eax максимум a и b
	   cmp eax, c
	   jg gr2
	   add edx, b
	   mov eax, c
	   gr2 :; в eax максимум трех
	   mov max, eax
	   cmp edx, max  ; проверка на равенство величин( как проверить, если carry равно )
	   je end
	   jle tr
	   mov result, 0
	   tr:
	   mov result, 1
	   jmp ex
       end:
       mov result, 0
       ex:
   }

   return result;
 }
 void True_or_False(int result){
  if(result == 0)
    std::cout << "false" << std::endl;
  else
    std::cout << "true" << std::endl;
}



int main() {
  unsigned int a, b, c;
  std::cout << "a,b,c" << std::endl;
  std::cin >> a >> b >> c;
  True_or_False(Triangle(a, b, c));




  return 0;
}