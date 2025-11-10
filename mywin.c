#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include <stdio.h>
#include <unistd.h>

//typedef uint32_t xcb_window_t; 

void xwindow(void);

int main(){

    
    xwindow();


    return 0;
}

void xwindow(void){
    
    //window size's
    int16_t x = 0;
    int16_t y = 0;
    uint16_t width = 1000;
    uint16_t height = 1000;
    uint16_t boarder_width = 10;
    
    //some constant(i don't know)
    uint8_t depth = XCB_COPY_FROM_PARENT;
    
    //what type of window is this(just like file descripter)
    uint16_t class = 1;

    //this is like the settings about the backround?
    uint32_t value_mask = 0;

    //connection to the X server.
    char *xdisplayname = NULL;
    int *screenp = NULL;
    xcb_connection_t *xconnection;	
    xconnection = xcb_connect(xdisplayname, screenp);

    //Creating Xwindow ID
    uint32_t xid = xcb_generate_id(xconnection);
     
    //Screen, I don't know how this works...it's like passing a struct in to another struct then point it to 
    //the another struct.
    xcb_screen_iterator_t iterator;
    const xcb_setup_t *setup;
    setup = xcb_get_setup(xconnection);
    iterator = xcb_setup_roots_iterator(setup);
    xcb_screen_t *xscreen = iterator.data; 

    //xWindow
    xcb_create_window(

	xconnection,
	depth,
	xid,
	xscreen->root,
	x,
	y,
	width,
	height,
	boarder_width,
	class,
	xscreen->root_visual,
	value_mask, NULL

    );

    xcb_map_window(xconnection, xid);
    xcb_flush(xconnection);
    pause();

}
