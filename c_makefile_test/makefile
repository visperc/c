objs = main.o logger.o

app : $(objs)
	cc -o app $(objs)

main.o : main.c logger.h

logger.o : logger.c logger.h

.PHONY : clean
clean :
	rm app $(objs)


