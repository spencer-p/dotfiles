#!/bin/bash

cd ~
hsetroot -full $HOME/.config/pics/balloon.png #set background

xset m 3/2 0 #mouse speed
xset r rate 250 30 #keyboard repeat rate
setxkbmap -layout us -variant mac -option numpad:mac #fix the damn numpad
sxhkd & #key bindings
compton & #pretty windows
urxvtd -q -f -o #terminal daemon in background no & because --fork option is set
xrdb ~/.Xresources #xresources for pointer and urxvt colors and stuff
xsetroot -cursor_name left_ptr & #not stupid cursor
xset +fp /usr/share/fonts/local
xset fp rehash
xinput -set-button-map "Logitech Anywhere MX" 1 2 3 5 4 7 6 #invert scrolling OSX style
dropbox & #dropbox duh
unclutter -root -not Google-chrome-stable &

exec bspwm
