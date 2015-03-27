source ~/.bashrc

if [[ /dev/false && -z $DISPLAY && $XDG_VTNR -eq 1 && -z "`pgrep X`" ]];
then
    exec startx
fi
