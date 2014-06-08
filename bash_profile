source ~/.bashrc

if [[ -z $DISPLAY && $XDG_VTNR -eq 1 ]];
then
    $?=0;
    exec startx;
fi
