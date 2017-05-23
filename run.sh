../../afl-2.35b/afl-fuzz -t 10000 -m none -i input/ -o output/ -M SESSION000 -- build/app
../../afl-2.35b/afl-fuzz -t 10000 -m none -i input/ -o output/ -S SESSION001 -- build/app
