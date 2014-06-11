#aliases yay

alias ls='ls --color=auto --group-directories-first -X'
alias grep='grep --colour=auto'
alias sudo='sudo '
alias bspcfg='vim ~/.config/bspwm/bspwmrc'
alias keybindcfg='vim ~/.config/sxhkd/sxhkdrc'
#alias pacman='pacmatic'
alias bc='bc -q'
alias js='js17'
alias pls='sudo $(history -p !!)'
PATH=$HOME/.config/bin:$PATH
PROMPT_COMMAND=setprompt
export EDITOR="vim"

gtkheaders=`pkg-config --libs --cflags gtk+-2.0`

setprompt () {
returned=$?
#PS1='\[\033[01;32m\]\u@\h \
#\[\033[01;36m\][`trimwd 3 "\`pwd\`" $HOME`]\
#\
#\[\033[1;31m\]`if [ $returned != 0 ]; then echo "[$returned] "; fi;`\
#\[\033[0;35m\]'
PS1='\[\033[01;36m\][`trimwd 3 "\`pwd\`" $HOME`]\
\[\033[1;31m\] \
\[\033[1;31m\]`if [ $returned != 0 ]; then echo "[$returned] "; fi;`\
\[\033[01;32m\]» \
\[\033[0;35m\]'
}

#\[\033[1;35m\][`date +%I:%M`] \

preexec_invoke_exec () {
    [ -n "$COMP_LINE" ] && return  # do nothing if completing
    local this_command=`history 1 | sed -e "s/^[ ]*[0-9]*[ ]*//g"`;
    preexec "$this_command"
}
trap 'preexec_invoke_exec' DEBUG

preexec () {
    echo -n -e "\033[00m"
    tput sgr0
}

shopt -s extglob

note () {
    # if file doesn't exist, create it
    if [[ ! -f $HOME/.notes ]]; then
        touch $HOME/.notes
    fi

    if [[ $# -eq 0 ]]; then
        # no arguments, print file
        cat $HOME/.notes
    elif [[ "$1" == "-c" ]]; then
        # clear file
        echo "" > $HOME/.notes
    else
        # add all arguments to file
        echo "$@" >> $HOME/.notes
    fi
}

extract() {
    local c e i

    (($#)) || return

    for i; do
        c=''
        e=1

        if [[ ! -r $i ]]; then
            echo "$0: file is unreadable: \`$i'" >&2
            continue
        fi

        case $i in
            *.t@(gz|lz|xz|b@(2|z?(2))|a@(z|r?(.@(Z|bz?(2)|gz|lzma|xz)))))
                   c='bsdtar xvf';;
            *.7z)  c='7z x';;
            *.Z)   c='uncompress';;
            *.bz2) c='bunzip2';;
            *.exe) c='cabextract';;
            *.gz)  c='gunzip';;
            *.rar) c='unrar x';;
            *.xz)  c='unxz';;
            *.zip) c='unzip';;
            *)     echo "$0: unrecognized file extension: \`$i'" >&2
                   continue;;
        esac

        command $c "$i"
        e=$?
    done

    return $e
}

man() {
    env LESS_TERMCAP_mb=$'\E[01;31m' \
    LESS_TERMCAP_md=$'\E[01;38;5;74m' \
    LESS_TERMCAP_me=$'\E[0m' \
    LESS_TERMCAP_se=$'\E[0m' \
    LESS_TERMCAP_so=$'\E[38;5;246m' \
    LESS_TERMCAP_ue=$'\E[0m' \
    LESS_TERMCAP_us=$'\E[04;38;5;146m' \
    man "$@"
}
