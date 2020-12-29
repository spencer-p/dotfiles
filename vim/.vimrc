set nocompatible
syntax on
filetype indent plugin on
set modeline

set mouse=a

if has("unnamedplus")
  set clipboard=unnamedplus
elseif has("clipboard")
  set clipboard=unnamed
endif

set shiftwidth=4
set tabstop=4
set softtabstop=4
set autoindent
set tw=80 " TODO set color column?
set relativenumber
set ignorecase
set smartcase

let base16colorspace=256
colorscheme base16-eighties

" Disable annoying go-vim features
let g:go_highlight_diagnostic_errors = 0
let g:go_highlight_diagnostic_warnings = 0
