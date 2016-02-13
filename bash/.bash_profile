if [ "$TERM" = "linux" ]; then
    _SEDCMD='s/.*\*color\([0-9]\{1,\}\).*#\([0-9a-fA-F]\{6\}\).*/\1 \2/p'
    for i in $(sed -n "$_SEDCMD" $HOME/.Xresources | \
               awk '$1 < 16 {printf "\\e]P%X%s", $1, $2}'); do
        echo -en "$i"
    done
fi
#dialog --no-lines --ok-label "Go" --cancel-label "Shell" --menu "Choose graphical environment:" 10 0 3 bspwm '' gnome ''
source ~/.bashrc
