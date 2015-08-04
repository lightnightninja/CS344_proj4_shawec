CC = icc
CXX = icpc
CFLAGS = -std=c99 -g
TARGET = primes
SOURCE = happyprimes.c

default: compile pdf

compile: ${SOURCE} ${INCLUDES}
	${CC} ${CFLAGS} ${SOURCE} -o ${TARGET} ${LDFLAGS}


TARGET2=writeup4
 
dvi: ${TARGET2}.tex 
	latex ${TARGET2}.tex
#	you can also have a bibtex line here
#	bibtex $(TARGET2)
	latex $(TARGET2).tex

ps: dvi
	dvips -R -Poutline -t letter ${TARGET2}.dvi -o ${TARGET2}.ps

pdf: ps
	ps2pdf ${TARGET2}.ps

clean-dvi:
	rm -f ${TARGET2}.aux
	rm -f ${TARGET2}.log
	rm -f ${TARGET2}.dvi
	rm -f ${TARGET2}.out

clean-ps: clean-dvi
	rm -f ${TARGET2}.ps

clean-pdf: clean-ps
	rm -f ${TARGET2}.pdf

clean: clean-ps
	rm -f $(TARGET) *.o *~ 
