#include <stdio.h>
#include <stdlib.h>
#include <plot.h>

static plPlotter *plotter;

void drawolliehead(plPlotter *, int, int, int);

void usage(const char *);

#define POINTING_RIGHT	0
#define POINTING_LEFT	1

#define JOINT_MODE_SYMM_STARTWI	0
#define JOINT_MODE_SYMM_STARTWO	1
#define JOINT_MODE_CLOSED	2
#define JOINT_MODE_OPEN		3

int drawfingers_sym_startwi(int, int, int, int, int, int);
int drawfingers_sym_startwo(int, int, int, int, int, int);

#define BEFORE_LEN	500
#define GAP_LEN		200

int
main(int argc, char **argv)
{
	int	matwidth;
	int	matthick;
	int	fingercnt;
	int	fingerlen;

	plPlotterParams *plotter_params;

	if(argc != 4) {
		usage(argv[0]);
		exit(-1);
	}

	matwidth = atoi(argv[1]) * 10;
	matthick = atoi(argv[2]) * 10;
	fingercnt = atoi(argv[3]);

	if(matwidth == 0) {
		fprintf(stderr, "Invalid material width specified.\n");
		exit(-1);
	}

	if(matthick == 0) {
		fprintf(stderr, "Invalid material thickness specified.\n");
		exit(-1);
	}

	if(fingercnt == 0) {
		fprintf(stderr, "Invalid finger count specified.\n");
		exit(-1);
	}
     
       /* set page size parameter, including viewport size and location */
       plotter_params = pl_newplparams ();
       pl_setplparam (plotter_params, "PAGESIZE",
                      "letter,xsize=8.5in,ysize=11in,xorigin=0in,yorigin=0in");
     
       /* create a Postscript Plotter with the specified parameter */
       plotter = pl_newpl_r ("ps", stdin, stdout, stderr, plotter_params);
     
       pl_openpl_r (plotter);                /* begin page of graphics */

       pl_space_r (plotter,
                    0, 0, 2159, 2794);   /* set user coor system, this time
					  * use dims convenient for tenths of
					  * mm */



	fingerlen = matwidth / (fingercnt * 2);

	(void) drawfingers_sym_startwo(0, 0, POINTING_RIGHT, fingercnt,
	    fingerlen, matthick);

	(void) drawfingers_sym_startwo(BEFORE_LEN + matthick + GAP_LEN, 0,	
	    POINTING_LEFT, fingercnt, fingerlen, matthick);



	pl_closepl_r (plotter);               /* end page of graphics */
	pl_deletepl_r (plotter);	      /* delete Plotter */

	return 0;

}


void
usage(const char *execn)
{
	printf("Usage: %s <material_width_mm> <material_thickness_mm>"
	    " <finger_count>\n", execn);
}


int
drawfingers_sym_startwi(int x, int y, int dir, int fingercnt, int fingerlen,
	int matthick)
{
	int	i;

	if(dir == POINTING_RIGHT) {
		pl_line_r(plotter,
		    x,
		    y,
		    x + BEFORE_LEN,
		    y);
		pl_line_r(plotter,
		    x,
		    y + fingercnt * 2 * fingerlen,
		    x + BEFORE_LEN,
		    y + fingercnt * 2 * fingerlen);

		for(i = 0; i < fingercnt; ++i) {

			pl_line_r(plotter,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen),
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen));

			pl_line_r(plotter,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen),
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen * 2);
		}

	} else { /* POINTING_LEFT */

		pl_line_r(plotter,
		    x + matthick,
		    y,
		    x + matthick + BEFORE_LEN,
		    y);
		pl_line_r(plotter,
		    x + matthick,
		    y + fingercnt * 2 * fingerlen,
		    x + matthick + BEFORE_LEN,
		    y + fingercnt * 2 * fingerlen);


		for(i = 0; i < fingercnt; ++i) {

			pl_line_r(plotter,
			    x + matthick,
			    y + (i * 2 * fingerlen),
			    x,
			    y + (i * 2 * fingerlen));

			pl_line_r(plotter,
			    x,
			    y + (i * 2 * fingerlen),
			    x,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen * 2);
		}
	}

	return 0;
}


int
drawfingers_sym_startwo(int x, int y, int dir, int fingercnt, int fingerlen,
	int matthick)
{
	int	i;

	if(dir == POINTING_RIGHT) {
		pl_line_r(plotter,
		    x,
		    y,
		    x + BEFORE_LEN,
		    y);
		pl_line_r(plotter,
		    x,
		    y + fingercnt * 2 * fingerlen,
		    x + BEFORE_LEN,
		    y + fingercnt * 2 * fingerlen);

		for(i = 0; i < fingercnt; ++i) {

			pl_line_r(plotter,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen),
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen * 2);

			pl_line_r(plotter,
			    x + BEFORE_LEN + matthick,
			    y + (i * 2 * fingerlen) + fingerlen * 2,
			    x + BEFORE_LEN,
			    y + (i * 2 * fingerlen) + fingerlen * 2);
		}

	} else { /* POINTING_LEFT */

		pl_line_r(plotter,
		    x + matthick,
		    y,
		    x + matthick + BEFORE_LEN,
		    y);
		pl_line_r(plotter,
		    x + matthick,
		    y + fingercnt * 2 * fingerlen,
		    x + matthick + BEFORE_LEN,
		    y + fingercnt * 2 * fingerlen);


		for(i = 0; i < fingercnt; ++i) {

			pl_line_r(plotter,
			    x + matthick,
			    y + (i * 2 * fingerlen),
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x,
			    y + (i * 2 * fingerlen) + fingerlen);

			pl_line_r(plotter,
			    x,
			    y + (i * 2 * fingerlen) + fingerlen,
			    x,
			    y + (i * 2 * fingerlen) + fingerlen * 2);

			pl_line_r(plotter,
			    x,
			    y + (i * 2 * fingerlen) + fingerlen * 2,
			    x + matthick,
			    y + (i * 2 * fingerlen) + fingerlen * 2);
		}
	}

	return 0;
}

