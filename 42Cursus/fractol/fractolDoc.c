********************************************************* 42Cursus *********************************************************


------------------------------------Fractol-----------------------------------

Sources:
https://cdn.intra.42.fr/pdf/pdf/23990/en.subject.pdf
https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx
https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events
https://harm-smits.github.io/42docs/
https://github.com/GlThibault/Fractol
https://github.com/nikGrape/FDF
https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html
https://github.com/jraleman/42_Fractol


vim modifications: 
vim ~/.vimrc

syntax on
set nu
set ruler
set mouse=a

X------------------CONCEITOS IMPORTANTES PARA A IMPLEMENTACAO A FUNCAO------------------X

X-----> Introduction to MinilibX <-----X

Abaixo segue a descricao do MANUAL sobre a MiniLibX

NAME
       MiniLibX - Simple Window Interface Library for students

SYNOPSYS
       #include <mlx.h>

       void *
       mlx_init ();

DESCRIPTION
       MiniLibX  is  an  easy  way to create graphical software, without any X-Window/X11 programming knowledge under Unix/Linux, nor any AppKit 
       programming knowledge under MacOS. It provides simple window creation, a drawing tool, image and basic events management.

Unix/Linux: X-WINDOW CONCEPT
       X-Window is a network-oriented graphical system for Unix.  It is based on two main parts:
       On one side, your software wants to draw something on the screen and/or get keyboard & mouse entries.
       On the other side, the X-Server manages the screen, keyboard and mouse (It is often refered to as a "display").
       A network connection must be established between these two entities to send drawing orders (from the software to the X-Server), 
       and keyboard/mouse events  (from the X-Server to the software).
       Nowadays, most of the time, both run on the same computer.

MacOS: WINDOW SERVER AND GPU
       Your  software  interacts directly with the Window server who handles the cohabitation on the screen with other software and the event system, a
       nd interacts with the GPU to handle all drawing stuff.

INCLUDE FILE
       mlx.h should be included for a correct use of the MiniLibX API.  It only contains function prototypes, no structure is needed.

LIBRARY FUNCTIONS
       First of all, you need to initialize the connection between your software and the display.  Once this connection is established, youll be able 
       to use other MiniLibX functions to send and receive the messages from the display, 
       like "I want to draw a yellow pixel in this window" or "did the user hit a key?".

       The  mlx_init function will create this connection. No parameters are needed, ant it will return a void * identifier, 
       used for further calls to the library routines.

       All other MiniLibX functions are described in the following man pages:

       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

       mlx_new_image       : manipulate images


       mlx_loop            : handle keyboard or mouse events

LINKING MiniLibX
       To use MiniLibX functions, you may need to link your software with several libraries, including the MiniLibX library itself.  O
       n Unix/Linux, simply add the following arguments at linking time:

       -lmlx -lXext -lX11

       On MacOS, the dynamic Metal library will find on its own the missing components:

       -lmlx

       and still on MacOS, the static OpenGL version will need:

       -lmlx -framework OpenGL -framework AppKit -lz

       You may also need to specify the path to these libraries, using the -L flag.

RETURN VALUES
       If mlx_init() fails to set up the connection to the display, it will return NULL, otherwise a non-null pointer is returned as a connection 
       identifier.

---> MinilibX Resumida <---

Basicamente a MiniLibX eh uma biblioteca que permite que utilizemos uma interface grafica, cuja pode aceitar comandos de entrada do teclado/mouse
sem que nos tenhamos quaisquer conhecimentos sobre como utilizar os conceitos de Unix/Linux X-Window ou GPU, basicamente em nossa pasta INCLUDES devemos
ter a biblioteca mlx.h adicionada, visto que no subject do projeto ja sao disponibilizados todos os arquivos da MiniLibx.
Nesses arquivos tambem foram disponibilizados os manuais para gerenciar janelas, desenhar dentro das janelas, manipular imagens e gerenciar 
comandos teclado/mouse.

	   mlx.3			   : general manual 

       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

       mlx_new_image       : manipulate images

       mlx_loop            : handle keyboard or mouse events


 ---> mlx_new_window <---

 Iremos criar um simples programa para poder abrir uma nova janela utilizando o mlx_new_window, ja teremos a nossa biblioteca mlx.h incluida, 
 em nosso manual temos que:

NAME
       MiniLibX - Managing windows

SYNOPSYS
       void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

       int
       mlx_clear_window ( void *mlx_ptr, void *win_ptr );

       int
       mlx_destroy_window ( void *mlx_ptr, void *win_ptr );

DESCRIPTION
       The mlx_new_window () function creates a new window on the screen, using the size_x and size_y parameters to determine its size, and title as 
       the text that should be displayed in the windows title bar.  The mlx_ptr parameter is the connection identifier returned by mlx_init () 
       (see the mlx man page).  mlx_new_window () returns a void * window identifier that can be used by other MiniLibX calls.  
       Note that the MiniLibX can handle an arbitrary number of separate windows.

       mlx_clear_window  ()  and mlx_destroy_window () respectively clear (in black) and destroy the given window. 
       They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a window identifier.

RETURN VALUES
       If mlx_new_window() fails to create a new window (for wathever reason), it will return NULL, otherwise a  
       non-null  pointer  is  returned  as  a  window  identifier.
       mlx_clear_window and mlx_destroy_window right now return nothing.

Entao para criarmos um programa simples apenas para abrir uma nova janela faremos:

Agora, os requisitos para que uma nova janela seja aberta, de acordo com nosso manual sao

void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

 Ou seja, precisamos de um ponteiro que eh o identificador da conexao para o servidor grafico, o tamanho em Pixels da tela de acordo 
 com os eixos X/Y e por fim o nome da janela.

 #include "mlx.h"

int main ()
{
	void *mlx_ptr;

	mlx_ptr = mlx_init(); // para que possamos executar a nossa interface MiniLibX devemos sempre dar um mlx_init()
	mlx_new_window(mlx_ptr, 500, 500, "My First MiniLibX"); 
	/*Acima chamamos a funcao para abrir uma interface grafica, como ja sabemos devemos passar os 4 argumentos necessarios,
	entao o identificador eh o nosso ponteiro, que recebe o mlx_init para iniciar a MiniLibX, o tamanho de 500 width and length e 
	o nome da nossa janela*/
	mlx_loop(mlx_ptr); // mlx_loop serve para que podamos executar comandos com o teclado ou mouse
}

O programa acima apenas ira exibir uma janela em branco e nao poderemos fazer nada com a mesma, porem com a utilizacao de outras funcoes da MiniLibX
podemos fazer com que seja possivel desenhar dentro da janela, por exemplo usando 


--->? Como executar arquivos que usam MinilibX ?<---

Conforme o exemplo acima, executaremos o main.c e devemos incluir o local onde a biblioteca mlx.h se encontra, seguido de 
"-lmlx -framework OpenGL -framework AppKit -lz && ./a.out"

gcc main.c -I includes/ -lmlx -framework OpenGL -framework AppKit -lz && ./a.out


X----->  MinilibX EVENTS <-----X

O que sao EVENTS na MinilibX? 
Eh quando o usuario usa ou o teclado ou o mouse para obter a informacao do nosso programa.
Continuaremos com o programa que haviamos criado anteriormente para exemplificar.

Primeiro, vamos tentar tornar possivel realizar um desenho em nossa janela, para isso verificaremos nossa funcao que permite
realizar desenhos no manual: mlx_pixel_put 


NAME
       MiniLibX - Drawing inside windows

SYNOPSYS
       int
       mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

       int
       mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
       mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );

DESCRIPTION
       The  mlx_pixel_put  ()  function draws a defined pixel in the window win_ptr using the ( x , y ) coordinates, and the specified color. 
       The origin (0,0) is the upper left corner of the window, the x and y axis respectively pointing right and down. 
       The connection identifier, mlx_ptr , is needed (see the mlx man page).

       Parameters for mlx_string_put () have the same meaning. Instead of a simple pixel, the specified string will be displayed at ( x , y ).

       Both functions will discard any display outside the window. This makes mlx_pixel_put slow. Consider using images instead.

COLOR MANAGEMENT
       The color parameter has an integer type. The displayed color needs to be encoded in this integer, following a defined scheme. 
       All displayable colors can be split  in 3  basic  colors: red, green and blue. Three associated values, in the 0-255 range, 
       represent how much of each color is mixed up to create the original color. Theses three values must be set inside the integer to 
       display the right color. The three least significant bytes of this integer are filled as shown in the picture below:

               | 0 | R | G | B |   color integer
               +---+---+---+---+

       While filling the integer, make sure you avoid endian problems. Remember that the "blue" byte should always be the least significant one.

       Depending on hardware capabilities, the most significant bit can handle transparency. 
       Beware, at the opposite of the OpenGL classics, it does not represent  opacity.

Events are the foundation of writing interactive applications in MiniLibX. It is therefore of essence that you fully comprehend this chapter as 
this will be of use in your future graphical projects.

All hooks in MiniLibX are nothing more than a function that gets called whenever a event is triggered. Mastering all these events won’t be neccessary, 
however, we will quickly go over each X11 event accordingly.

X11 events
X11 is the library that is used alongside of MiniLibX. It therefore is no secret that this header is very useful for finding all the according events of 
MiniLibX. There are a number of events to which you may describe.

Key	Event
02	KeyPress
03	KeyRelease
04	ButtonPress
05	ButtonRelease
06	MotionNotify
07	EnterNotify
08	LeaveNotify
09	FocusIn
10	FocusOut
11	KeymapNotify
12	Expose
13	GraphicsExpose
14	NoExpose
15	VisibilityNotify
16	CreateNotify
17	DestroyNotify
18	UnmapNotify
19	MapNotify
20	MapRequest
21	ReparentNotify
22	ConfigureNotify
23	ConfigureRequest
24	GravityNotify
25	ResizeRequest
26	CirculateNotify
27	CirculateRequest
28	PropertyNotify
29	SelectionClear
30	SelectionRequest
31	SelectionNotify
32	ColormapNotify
33	ClientMessage
34	MappingNotify
35	GenericEvent
36	LASTEvent
If you can’t figure out what some events are, don’t worry, because you probably won’t need them. If you do, go read the documentation of each X11 function.

X11 masks
Each X11 event, also has a according mask. This way you can register to only one key when it triggers, or to all keys if you leave your mask to the default. 
Key masks therefore allow you to whitelist / blacklist events from your event subscriptions. The following masks are allowed:

Mask		Description
0L			NoEventMask
(1L<<0)		KeyPressMask
(1L<<1)		KeyReleaseMask
(1L<<2)		ButtonPressMask
(1L<<3)		ButtonReleaseMask
(1L<<4)		EnterWindowMask
(1L<<5)		LeaveWindowMask
(1L<<6)		PointerMotionMask
(1L<<7)		PointerMotionHintMask
(1L<<8)		Button1MotionMask
(1L<<9)		Button2MotionMask
(1L<<10)	Button3MotionMask
(1L<<11)	Button4MotionMask
(1L<<12)	Button5MotionMask
(1L<<13)	ButtonMotionMask
(1L<<14)	KeymapStateMask
(1L<<15)	ExposureMask
(1L<<16)	VisibilityChangeMask
(1L<<17)	StructureNotifyMask
(1L<<18)	ResizeRedirectMask
(1L<<19)	SubstructureNotifyMask
(1L<<20)	SubstructureRedirectMask
(1L<<21)	FocusChangeMask
(1L<<22)	PropertyChangeMask
(1L<<23)	ColormapChangeMask
(1L<<24)	OwnerGrabButtonMask


Hooking into events is one of the most powerful tools that MiniLibX provides. It allows you to register to any of the aforementioned events with the call of a simple hook registration function. For example instead of calling mlx_key_hook, we can also register to the KeyPress and KeyRelease events.

To achieve this, we call the function mlx_hook. Lets take a look:

#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	/*A funcao CLOSE foi criada para fechar a janela aberta anteriormente, */
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	/*Quando chamamos a funcao mlx_hook passamos como parametro vars.win que abre a janela, o evento X11 de numero 2 (KeyPress)
	que indica que uma tecla foi pressionada e a mask 1L<<0 que tambem indica uma tecla presionada, que eh a mask equivalente ao X11 numero 2*/
	mlx_loop(vars.mlx);
}


X----->  Color Management <-----X

Colors are presented in an int format. It therefore requires some tricky things in order to obtain an int which can contain the ARGB values.

The color integer standard
We shift bits to use the TRGB format. To define a color, we initialize it as follows: 0xTTRRGGBB, where each character represents the following:


     'Letra'     |   'Descricao'
-----------------|---------------------
        T        |	Transparencia
        R        |	Red component
        G        |	Green component	
        B        |	Blue component
-----------------|---------------------

RGB colors can be initialized as above, a few examples would be:


      'Cor'      | 'TRGB Representation'
-----------------|----------------------
      Red        |	   0x00FF0000
      Blue       |	   0X0000ff00
      Green      |	   0x000000FF	
-----------------|----------------------

--> Bit Shifting for color management <--

"Left shift (<<)"
Integers are stored, in memory, as a series of bits. For example, the number 6 stored as a 32-bit int would be:

00000000 00000000 00000000 00000110
Shifting this bit pattern to the left one position (6 << 1) would result in the number 12:

00000000 00000000 00000000 00001100
As you can see, the digits have shifted to the left by one position, and the last digit on the right is filled with a zero. 
You might also note that shifting left is equivalent to multiplication by powers of 2. So 6 << 1 is equivalent to 6 * 2, 
and 6 << 3 is equivalent to 6 * 8. A good optimizing compiler will replace multiplications with shifts when possible.

"Non-circular shifting"
Please note that these are not circular shifts. Shifting this value to the left by one position (3,758,096,384 << 1):

11100000 00000000 00000000 00000000
results in 3,221,225,472:

11000000 00000000 00000000 00000000
The digit that gets shifted "off the end" is lost. It does not wrap around.

"Logical right shift (>>>)"
A logical right shift is the converse to the left shift. Rather than moving bits to the left, they simply move to the right. 
For example, shifting the number 12:

00000000 00000000 00000000 00001100
to the right by one position (12 >>> 1) will get back our original 6:

00000000 00000000 00000000 00000110
So we see that shifting to the right is equivalent to division by powers of 2.


X---> Encoding and decoding colors <----X

Since each byte contains 2^8 values, and RGB values range from 0 to 255, we can perfectly fit a integer (as an int is 4 bytes). 
In order to set the values programatically we use bitshifting. Let’s create a function which does precisely that for us, shall we?

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
Because ints are stored from right to left, we need to bitshift each value the according amount of bits backwards. 
We can also do the exact opposite and retrieve integer values from a encoded TRGB integer.

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}