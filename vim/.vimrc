set mouse=a

set nocompatible

" Pathogen
call pathogen#infect()
call pathogen#helptags()
 
set statusline=%<\ %n:%f\ %m%r%y%=%-35.(line:\ %l\ of\ %L,\ col:\ %c%V\ (%P)%)
filetype plugin indent on
 
syntax on
au BufReadPost *.nxc set syntax=c
set number
set hlsearch
set showmatch
set ignorecase
set wrap
set autoindent
set smarttab
set smartindent
set history=1000
if has("unnamedplus")
  set clipboard=unnamedplus
elseif has("clipboard")
  set clipboard=unnamed
endif

set shiftwidth=4
set tabstop=4
set softtabstop=4

"set t_Co=256

set background=dark
"colorscheme molokai
"colorscheme moss
"colorscheme pablo
"let g:solarized_termcolors=16
"colorscheme solarized
"colorscheme base16-flat

set noerrorbells visualbell t_vb=

vnoremap . :norm.<CR>

"Run love games with ctrl-k
map <C-k> :!love .<CR><CR>

let g:SuperTabDefaultCompletionType = "context"
let g:SuperTabContextDefaultCompletionType = "<c-n>"
