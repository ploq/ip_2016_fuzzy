rm output/out.min
rm outputfile.txt
touch outputfile.txt
rm -f input/*
rm -f raw_input/*
#generate testcase
dd if=/dev/random of=raw_input/testfile1.bin bs=64 count=1
#minimize testcases
afl-cmin -i raw_input/ -o input/ ./a.out 
~/afl-2.35b/afl-clang-fast++ binarytest.cpp

#screen afl-fuzz -i input -o sync_dir/ -M fuzzer1 ./a.out
#screen afl-fuzz -i input -o sync_dir/ -S fuzzer2 ./a.out
afl-fuzz -i input/ -o output/ ./a.out

