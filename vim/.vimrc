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

set expandtab
set shiftwidth=4
set tabstop=4
set softtabstop=4

"colorscheme molokai
"colorscheme moss
colorscheme pablo

let &t_Co=16

"inoremap { {<CR><BS>}<Esc>bo
"inoremap { {<CR><BS>}<Esc>ko
"inoremap { {}<Esc>i\n
"inoremap { {<CR><CR>}<Esc>ki<tab>

set noerrorbells visualbell t_vb=
