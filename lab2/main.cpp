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
  int result = 0;
  _asm{
      mov eax, a
	  cmp eax, b ;сравниваем a и b
	  jg a_more_b ; если a больше b
	  mov edx, b ;edx = макс из трех = b
	  jmp after_first_cmp
a_more_b:
      mov edx, eax ; edx = макс из трех = a
      mov eax, b ; eax = мин из трех = b

after_first_cmp: ; проверяем наши a и b с третьей переменной c
      cmp c, edx ;сравниваем
      jg max_ab_more_c ; если c больше максимума из (a, b) и прыгаем на нашу метку

      cmp c, eax ; когда c меньше max(a,b) и сравниваем c с min(a,b)
	  jg set_av
	  ; когда c меньше, чем все остальные
	  mov ecx, eax
	  mov eax, c
	  jmp main_condition
set_av:
      mov ecx, c ; c среднее среди всех, а макс и мин уже стоят в правильных регистрах
	  jmp main_condition

max_ab_more_c: ; прыгаем сюда, т.к.С больше обоих(a,b) и просто ставим соответственно мин ср и макс
	  mov ecx, edx
	  mov edx, c
	  jmp main_condition

main_condition:
	add eax, ecx ; min + av
	jc return_true ; если переполнилось то всегда правда
	cmp eax, edx ; сравниваем min + av и max
	jg return_true
	mov result, 0
	jmp to_end
return_true:
    mov result, 1
to_end:

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
//  unsigned int a, b, c;
//  std::cout << "a,b,c" << std::endl;
//  std::cin >> a >> b >> c;
	True_or_False(Triangle(5, 7, 8));
 	True_or_False(Triangle(3, 3, 10));
 	True_or_False(Triangle(3, 3, 2));
 	True_or_False(Triangle(3'000'000'000, 3'000'000'000, 2000000000));
	True_or_False(Triangle(1000000000, 2000000000, 3000000000));

  return 0;
}