P = joineryplotter
OBJS = main.o
CFLAGS = -g -Wall -Wstrict-prototypes -Werror
LDLIBS = -lb -lplot

$(P): $(OBJS)
	$(CC) -o $(P) $(LDFLAGS) $(OBJS) $(LDLIBS)

clean:
	rm -f *o; rm -f $(P)

pic: $(P)
	./gnuplottest > out.ps && open out.ps
