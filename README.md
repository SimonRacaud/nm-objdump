# nm-objdump
ELF executable file analyser

Rewriting of nm and objdump shell commands.

- nm : List symbols from object file
- objdump : Display information from object file (header + sections content)

# Usage
```
$> make
$> ./my_nm -h
usage: ./my_nm [FILE]...

$> ./my_objdump -h
usage: ./my_objdump [FILE]...
```

# Example

```
$> ./my_nm src/nm/main.o src/elf/load_file.o

src/nm/main.o:
setlocal error
0000000000000000 D DEFAULT_FILENAME
0000000000000033 t argv_launcher
00000000000000a0 T main
                 U my_nm
                 U printf
                 U strcmp
0000000000000000 t usage

src/elf/load_file.o:
setlocal error
                 U __errno_location
                 U __stack_chk_fail
                 U close
0000000000000292 T close_file
                 U fprintf
                 U fputc
                 U free
                 U fstat
                 U fwrite
0000000000000165 T load_file
                 U mmap
                 U open
0000000000000000 t open_error_manager
00000000000000b2 t open_file
                 U stderr
                 U strdup
```

```
$> ./my_objdump /bin/ls | head -n 20

/bin/ls:     file format elf64-x86-64
architecture: i386:x86-64, flags 0x00000150:
HAS_SYMS, DYNAMIC, D_PAGED
start address 0x0000000000006ab0

Contents of section .interp:
 0318 2f6c6962 36342f6c 642d6c69 6e75782d  /lib64/ld-linux-
 0328 7838362d 36342e73 6f2e3200           x86-64.so.2.    
Contents of section .note.gnu.property:
 0338 04000000 20000000 05000000 474e5500  .... .......GNU.
 0348 020000c0 04000000 03000000 00000000  ................
 0358 028000c0 04000000 01000000 00000000  ................
Contents of section .note.gnu.build-id:
 0368 04000000 14000000 03000000 474e5500  ............GNU.
 0378 897f49ca fa98c11d 63e619e7 e40352f8  ..I.....c.....R.
 0388 55249c13                             U$..            
Contents of section .note.ABI-tag:
 038c 04000000 10000000 01000000 474e5500  ............GNU.
 039c 00000000 03000000 02000000 00000000  ................
```
