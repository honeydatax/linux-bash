objcopy -I binary -O elf32-littlearm -B arm obj objs
g++ obj.c objs -o obj.o

printf "run ./obj.o\n"