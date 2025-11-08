#include <stdio.h>

//Here's what my imagination on what happens on the X client-server 
//
//It needs things that a client can use(this is the request part).
//
//Because my basic knowledge about a client-server is all about requesting and recieving, if my understanding 
//is right about x server it handels all the requests, recieving, and sending back(what you requested). in 
//that sense it means that the things that you can request is only within the X server anymore than that will 
//lead into an error.
//
//a xserver is a full-duplex type so it can send and recieve.


void
server(const int request);

int
main(){

	int input_num = 0;
	do{ 

	//input a number and it will show which part is enabled
	//0 = disable
	//1 = enable 
	//number available is only at 1-6().
	//0 are for initialization(basically nothing)
	//7 is for reset

	server(input_num);
	scanf("%d", &input_num);
	

	}while(1);


	return 0;
}

void
server(const int request){
	
	/*
	 server_ls = ListofFOO, OR, Window, pixmap, BitMask, cursor
	*/

	static int server_ls[] = {0, 0, 0, 0, 0, 0};

	int count = 0;
	int a = 1;
	char server_things[6][10] = {"ListofFOO", "OR", "Window", "pixmap", "BitMask", "cursor"};

	switch(request){
		
		case 0: 

			break;
		case 1: 

			server_ls[0] = 1;
			break;

		case 2: 

			server_ls[1] = 1;
			break;

		case 3: 

			server_ls[2] = 1;
			break;

		case 4: 

			server_ls[3] = 1;
			break;

		case 5:

			server_ls[4] = 1;
			break;

		case 6:

			server_ls[5] = 1;
			break;
		
		case 7: 

			for(int i = 0; i <= sizeof(server_ls); i++){

				server_ls[i] = 0;

			}
			break;

		default:
			printf("error!!");
			break;

	}


	for(int i = 0; i < 6; i++){
	
		count++;

		printf("%d.%s: %d\n", count,  server_things[i], server_ls[i]);

		a++;
	}


}
