.586
.model flat



public _Calculate@16
.data
 ost DWORD ?
.code
_Calculate@16 proc
		mov eax, [esp+8];				  b->eax
		xor edx, edx
		mov edx, [esp+16]
		IMUL edx; 					  eax* y
		; xor edx, edx;				 clear edx
		ADD  eax, [esp+12];				 add c to eax
		NEG eax;					-eax
		cdq;
		;xor ecx, ecx;
		mov ecx, 3;
		mov esi, [esp+4];
		mov ost, eax;
		imul esi, ecx;         3 * a
			idiv  esi;

		imul edx, 2;     mutiply f compare


			cmp  esi, 0
			jge ent
			cmp ost, 0
			jge ent
			neg esi
ent :
		cmp ost, 0
			jne etc
			jmp end1;
etc:
		cmp eax, 0
			jl negative


			cmp esi, edx;   //  6 vs. 8
		jnle NNegBigDiv;
		jmp end1;
NNegBigDiv:
		jnge NNegLessDiv;
		inc eax
			jmp end1;
NNegLessDiv:
		jne NNegEqualDiv;
		test eax, 1
			jz Evn;
		;jmp result;
Evn:
		inc eax
			NNegEqualDiv :
		jmp end1



negative:
		cmp esi, 0
			jl  after
			neg esi
after :
		cmp esi, edx;   //  6 vs. 8
		jnle NegBigDiv;
		dec eax
			jmp end1;
NegBigDiv:
		jnge NegLessDiv;
		jmp end1;
NegLessDiv:
		jne NegEqualDiv;
		test eax, 1
			jz Evn_2;
		dec eax
			jmp end1
			Evn_2 :
NegEqualDiv:
		jmp end1
end1 :
		
ret 16


_Calculate@16 endp

end
