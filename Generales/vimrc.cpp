set ts=4
set bs=2		" allow backspacing over everything in insert mode
set ruler		" show the cursor position all the time
set nu
syntax on		" syntax highlight
set hlsearch		" search highlighting
set showmatch		" Cursor shows matching ) and }
set showmode		" Show current mode
set autoindent		" auto indentation
set incsearch		" incremental search
set nobackup		" no *~ backup files
set copyindent		" copy the previous indentation on autoindenting

" set leader to ,
let mapleader=","
let g:mapleader=","

" ,/ turn off search highlighting
nmap <leader>/ :nohl<CR>

" allow multiple indentation/deindentation in visual mode
vnoremap < <gv
vnoremap > >gv
