nasm -f win64 asmFile.asm
gcc -c cFile.c -o cFile.obj -m64
gcc cFile.obj asmFile.obj -o cFile.exe -m64
cFile.exe
