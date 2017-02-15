In this project you will discover the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.
You will also discover your first graphic library: miniLibX. This library was developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard, mouse and expose.

/* sources */

http://thomas.tissotdupont.free.fr/MinilibX%20Manual/mlx_window_create.html

/* how to install minilibx on macos Sierra */
	* if not istalled, install XQartz – https://www.xquartz.org
										https://ru.wikipedia.org/wiki/XQuartz		
	* compile lib with "make"
	* sudo cp mlx.h /usr/X11/include
	* sudo cp libmlx.a /usr/X11/lib
	* now u can test it, compile with this flags
		clang -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit <test.c>
		
/* how to install man pages of minilibx */
	* sudo cp mlx_new_image.1 /usr/share/man/man1/mlx_new_image.1
	* sudo gzip /usr/share/man/man1/mlx_new_image.1
and so on ...