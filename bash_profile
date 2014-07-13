source ~/.bashrc

if [[ -z $DISPLAY && $XDG_VTNR -eq 1 && -z "`pgrep X`" ]];
then
    startx
fi
