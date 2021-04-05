

#include <iostream>
extern "C" int _stdcall Calculate(int a, int b, int c, int y);


int main() {
	std::cout << "a, b,y, c\n" << ">";
	int a, b, c, y;
	std::cin >> a >> b >> y >> c;
	std::cout << Calculate(a, b, c, y);
}


//int Calculate(int a, int b, int c, int y)
//{
//	int result;
//	int ost;
//	__asm
//	{
//		mov eax, b;				  b->eax
//		IMUL y; 					  eax* y
//		; xor edx, edx;				 clear edx
//		ADD  eax, c;				 add c to eax
//		NEG eax;					-eax
//		cdq;
//		;xor ecx, ecx;
//		mov ecx, 3;
//		mov esi, a;
//		mov ost, eax;
//		imul esi, ecx;         3 * a
//			idiv  esi;
//
//		imul edx, 2;     mutiply f compare
//
//
//			cmp  esi, 0
//			jge ent
//			cmp ost, 0
//			jge ent
//			neg esi
//			ent :
//		cmp ost, 0
//			jne etc
//			jmp end;
//	etc:
//		cmp eax, 0
//			jl negative
//
//
//			cmp esi, edx;   //  6 vs. 8
//		jnle NNegBigDiv;
//		jmp end;
//	NNegBigDiv:
//		jnge NNegLessDiv;
//		inc eax
//			jmp end;
//	NNegLessDiv:
//		jne NNegEqualDiv;
//		test eax, 1
//			jz Evn;
//		jmp result;
//	Evn:
//		inc eax
//			NNegEqualDiv :
//		jmp end
//
//
//
//		negative:
//		cmp esi, 0
//			jl  after
//			neg esi
//			after :
//		cmp esi, edx;   //  6 vs. 8
//		jnle NegBigDiv;
//		dec eax
//			jmp end;
//	NegBigDiv:
//		jnge NegLessDiv;
//		jmp end;
//	NegLessDiv:
//		jne NegEqualDiv;
//		test eax, 1
//			jz Evn_2;
//		dec eax
//			jmp end
//			Evn_2 :
//	NegEqualDiv:
//		jmp end
//			end :
//		mov result, eax
//
//	}
//
//	return   result;
//}