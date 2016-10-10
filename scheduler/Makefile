CXX=g++ #Should be changed to AFL-clang
CXXFLAGS=-std=c++03 -c
CXXSTD=-std=c++03
LIBDIR=lib/
OUTDIR=temp/
MKDIR_P=mkdir -p



all: directories program
	rm -rf $(OUTDIR)
program: scheduler.o afllib
	$(CXX) $(CXXSTD) $(OUTDIR)scheduler.o $(LIBDIR)afllib.a -o scheduler

scheduler.o: scheduler.cpp
	$(CXX) $(CXXFLAGS) scheduler.cpp -o $(OUTDIR)scheduler.o

afllib.o: afllib.cpp
	$(CXX) $(CXXFLAGS) afllib.cpp -o $(OUTDIR)afllib.o

afllib: afllib.o
	ar rvs $(LIBDIR)afllib.a $(OUTDIR)afllib.o 

.PHONY: directories

directories: ${OUTDIR} ${LIBDIR}

${OUTDIR}:
	${MKDIR_P} ${OUTDIR}
		
${LIBDIR}:
	${MKDIR_P} ${LIBDIR}
clean:
	rm -rf $(OUTDIR)
	rm -rf $(LIBDIR)
	rm -f *.o