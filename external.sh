objcopy -I binary -O elf32-littlearm -B arm external.bmp externals
g++ external.c externals -o external -lSDL

printf "run ./externals\n"