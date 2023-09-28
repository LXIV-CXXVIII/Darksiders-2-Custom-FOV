.data
EXTERN rFOV1:QWORD
EXTERN rFOV2:QWORD
EXTERN fov_setting:REAL4

.code

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

xFOV1 PROC

 ;mov [rcx+06Ch], eax
 ;add rsp, 020h
 ;jmp [rFOV1]
 push rbx
 mov ebx, [fov_setting]
 mov [rcx+06Ch], ebx
 pop rbx
 add rsp, 020h
 jmp [rFOV1]

xFOV1 ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

xFOV2 PROC

 ;movss DWORD PTR [rax+06Ch], xmm0
 ;jmp [rFOV2]
 ;xorps xmm0, xmm0
 movss xmm0, [fov_setting]
 movss DWORD PTR [rax+06Ch], xmm0
 jmp [rFOV2]

xFOV2 ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

END