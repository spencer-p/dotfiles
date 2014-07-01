#!/bin/bash

cd ~
feh --bg-center $HOME/.config/pics/balloon.png #set background

xset m 2/1 3 #mouse speed
xset r rate 250 30 #keyboard repeat rate
sxhkd & #key bindings
compton & #pretty windows
urxvtd -q -f -o #terminal daemon in background no & because --fork option is set
xrdb ~/.Xresources #xresources for pointer and urxvt colors and stuff
xsetroot -cursor_name left_ptr & #not stupid cursor
xset +fp /usr/share/fonts/local #fix font finding or something
xset fp rehash
naturalscrolling #uses xset to invert scrolling OSX style
dropboxd & #dropbox duh
customunclutter & #hide mouse when not in use, this is an alias in my bashrc
$HOME/.config/panel/panel & #start my panel
exec bspwm 2> ~/.bspwm.log
