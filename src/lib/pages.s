; ============================================================
; File: my_avr_program.asm
; Description: Example AVR Assembly Program
; Author: Your Name
; Date: YYYY-MM-DD
; ============================================================

; ===================== Page Erase ===================================
.global page_erase
page_erase:
    movw r30, r24                     ; Copy address from r24:r25 to Z register (r30:r31)
    ldi r16, __BOOT_PAGE_ERASE        ; Load page erase command
    out _SFR_IO_ADDR(__SPM_REG), r16  ; Write to SPM control register
    spm                               ; Execute Store Program Memory

wait_spm:
    in r16, _SFR_IO_ADDR(__SPM_REG)   ; Read SPM control register
    sbrc r16, SPMEN                   ; Check if SPMEN bit is cleared
    rjmp wait_spm                     ; Wait if not cleared

    clr r1                            ; Clear r1 (as per GCC convention)
    ret                               ; Return from the function

; ===================== End of File ==================================
