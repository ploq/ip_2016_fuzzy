echo 0 > crashdata.txt
rm log*
../../../afl-2.33b/afl-fuzz -i input/ -o output/ -d build/app_code/app
