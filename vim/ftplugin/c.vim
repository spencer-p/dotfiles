inoremap { {<CR><BS>}<Esc>bo
inoremap <End> {

"inoremap q <Esc>:q!<CR>

"inoremap ( ()<Left>
"inoremap (( (
"inoremap ) <Right>
"inoremap )) )

"inoremap [ []<Left>
"inoremap [[ [
"inoremap ] <Right>
"inoremap ]] ]

"function SmartDoubleQuote()
    "<Right><Esc>
    ":let c = getline(".")[col(".") - 1]
    ":if c != '\"'
    "    <Left>"<Esc>
    ":else
    "    <Left>""<Right><Esc>
    ":endif
    ":unlet c
    "i hello
"endfunction

"inoremap " <Esc>:call SmartDoubleQuote()<CR>i
"inoremap "" "

