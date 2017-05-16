#cd build_gcc_cov
afl-cov/afl-cov -d ~/fuzzy_testing/ip_2016_fuzzy/output --live --coverage-cmd "~/fuzzy_testing/ip_2016_fuzzy/build_gcc_cov/app < AFL_FILE" --code-dir ~/fuzzy_testing/ip_2016_fuzzy/build_gcc_cov --overwrite
