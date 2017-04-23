printf "im love marina." > bin.out
xxd -p bin.out > bin.txt
xxd -p -r < bin.txt > bin.dat
cat bin.dat

