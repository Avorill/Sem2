.686
.model flat
.data
pi dd 180
eps dd ?
result dd 0
ct dd 1
iks dd 0
fact dd 1.0
variable dd 0
.code

_Arcsin proc
finit
fld dword ptr[esp+4]
fld dword ptr [esp+4]  ; x^2
fmul				; x^2
fld1
fsubr; -
fsqrt   ;         sqrt(1-x^2)
fld dword ptr[esp+4]; x
fxch
fpatan  ; atan
fild pi
fmul
fldpi
fdiv
FRNDINT; okruglenie
fist pi
mov eax, pi

ret
_Arcsin endp





_Calculate proc
			finit
			fld dword ptr[esp + 8]
			fld dword ptr[esp + 4]
			fstp eps
			fst variable
			fst iks
			fstp result
			finit

_begin :
			fld fact
			fld iks
			 fld variable
			 fld eps
			 fcom
			 fstsw ax
			 sahf
			 jnbe _end
			 fstp eps
			 fstp variable
			 fld dword ptr [esp+4]
			 fld dword ptr [esp +4]
			 fmulp
			 fmulp
			 fst iks
			 lea eax,iks
			 fxch
			 inc ct
			 fild  ct
			 inc ct
			 fild ct
			 fmul
			 fmul
			 fst fact 
			 fdiv 
			 fst variable
			 fld result 
			 fadd
			 fst result
			 finit 
			 jmp _begin
_end:
			fld result
			ret
			_Calculate endp
end



