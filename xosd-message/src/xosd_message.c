#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <xosd.h>

int main (int argc, char *argv[])
{
	if(argc > 1)
	{
		xosd *osd;
		osd = xosd_create (2);
		
		if (osd == NULL)
		{
		perror ("Could not create \"osd\"");
		exit (1);
		}

	xosd_set_font (osd, "-adobe-times-*-*-normal-*-34-240-100-100-*-177-iso8859-*"); 
	xosd_set_shadow_offset (osd, 2);
	xosd_set_colour (osd, "#38e62f");
	xosd_set_outline_offset(osd, 1);
	xosd_set_outline_colour(osd, "black");
	xosd_set_shadow_offset (osd, 4);

	xosd_set_pos (osd, XOSD_bottom);
	xosd_set_vertical_offset (osd, 48);

	xosd_set_align (osd, XOSD_center);
	xosd_set_horizontal_offset (osd, 48);

	xosd_display (osd, 0, XOSD_string, argv[1]);

	sleep (8);
	xosd_destroy (osd);
	exit (0);
	}
	else
	{
		printf("usage: xosd_mesage Message\n");
		exit (0);
	}
}
