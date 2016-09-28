rm output/out.min
rm outputfile.txt
rm input/~testfile.bin
afl-fuzz -i input/ -o output/ -n ./a.out @@
less outputfile.txt
