" basic setting
set ts=4
set bs=2
set ruler
set nu
syntax on
set hlsearch
set showmatch
set showmode
set autoindent
set incsearch
set copyindent

" set leader to ,
let mapleader=","
let g:mapleader=","

" ,/ turn off search highlighting
nmap <leader>/ :nohl<CR>

" allow multiple indentation/deindentation in visual mode
vnoremap < <gv
vnoremap > >gv
