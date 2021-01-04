 #include <stdio.h>
     #include <plot.h>

void drawolliehead(plPlotter *, int, int, int);

int
main(int argc, char **argv)
{
	int	mat_width;
	int	finger_count;

	plPlotter *plotter;
	plPlotterParams *plotter_params;

	if(argc != 3) {
		usage();
		exit(-1);
	}
     
       /* set page size parameter, including viewport size and location */
       plotter_params = pl_newplparams ();
       pl_setplparam (plotter_params, "PAGESIZE",
                      "letter,xsize=8.5in,ysize=11in,xorigin=0in,yorigin=0in");
     
       /* create a Postscript Plotter with the specified parameter */
       plotter = pl_newpl_r ("png", stdin, stdout, stderr, plotter_params);
     
       pl_openpl_r (plotter);                /* begin page of graphics */

       pl_space_r (plotter,
                    0, 0, 2159, 2794);   /* set user coor system, this time
					  * use dims convenient for tenths of
					  * mm */


#if 0
     
       pl_fontname_r (plotter, "Times-Bold");
       pl_ffontsize_r (plotter, 0.5);        /* font size = 0.5in = 36pt */
     
       pl_fmove_r (plotter, 1.0, 10.0);
       pl_alabel_r (plotter, 'l', 'x', "One inch below the top");
       pl_fline_r (plotter, 1.0, 10.0, 7.5, 10.0);
     
       pl_fmove_r (plotter, 7.5, 1.0);
       pl_alabel_r (plotter, 'r', 'x', "One inch above the bottom");
       pl_fline_r (plotter, 1.0, 1.0, 7.5, 1.0);

#endif


	drawolliehead(plotter, 1500, 1500, 1500);


       pl_closepl_r (plotter);               /* end page of graphics */
       pl_deletepl_r (plotter);              /* delete Plotter */
       return 0;
     }


void
drawolliehead(plPlotter *p, int x, int y, int siz)
{



	pl_move_r(p, x, y);
	pl_linerel_r(p, 0, 0, siz * 0.60, 0);
	pl_linerel_r(p, 0, 0, siz * 0.25, siz * 0.20);
	pl_linerel_r(p, 0, 0, -siz * .05, siz * 0.55);
	pl_linerel_r(p, 0, 0, siz * .05, siz * 0.45);
	pl_linerel_r(p, 0, 0, -siz * .30, -siz * 0.30);
	pl_linerel_r(p, 0, 0, -siz * .50, 0);
	pl_linerel_r(p, 0, 0, -siz * .30, siz * 0.30);
	pl_linerel_r(p, 0, 0, siz * .05, -siz * 0.45);
	pl_linerel_r(p, 0, 0, -siz * .05, -siz * 0.55);
	pl_linerel_r(p, 0, 0, siz * 0.25, -siz * 0.20);
	pl_endpath_r(p);


	pl_move_r(p, x, y);
	pl_circlerel_r(p, siz * 0.05, siz * 0.60, siz / 12);

	pl_move_r(p, x, y);
	pl_circlerel_r(p, siz * 0.55, siz * 0.60, siz / 12);

		
	pl_move_r(p, x, y);
	pl_linerel_r(p, siz * .29, siz * .3, siz * 0.21, siz * 0.37);
	pl_linerel_r(p, 0, 0, siz * 0.03, siz * 0.03);
	pl_linerel_r(p, 0, 0, siz * 0.05, -siz * 0.03);
	pl_linerel_r(p, 0, 0, siz * 0.05, siz * 0.03);
	pl_linerel_r(p, 0, 0, siz * 0.03, -siz * 0.03);
	pl_linerel_r(p, 0, 0, -siz * 0.08, -siz * 0.07);

	pl_move_r(p, x, y);
	pl_linerel_r(p, siz * .28, siz * .28, siz * 0.27, siz * 0.20);
	pl_linerel_r(p, 0, 0, -siz * 0.10, 0);
//	pl_linerel_r(p, 0, 0, -siz * 0.01, siz * .01);

	pl_move_r(p, x, y);
	pl_linerel_r(p, siz * .30, siz * .28, siz * 0.31, siz * 0.20);
	pl_linerel_r(p, 0, 0, siz * 0.10, 0);
//	pl_linerel_r(p, 0, 0, siz * 0.01, siz * .01);

	pl_move_r(p, x, y);
	pl_linerel_r(p, siz * .15, siz * .28, -siz * 0.40, siz * .26);

	pl_move_r(p, x, y);
	pl_linerel_r(p, siz * .18, siz * .25, -siz * 0.20, -siz * .06);


//	pl_box_r(p, x, y, x+siz, y+siz);


}


