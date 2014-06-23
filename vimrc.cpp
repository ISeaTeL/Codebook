set ts=4
set bs=2		" allow backspacing over everything in insert mode
set ruler		" show the cursor position all the time
set nu
filetype on           " Enable filetype detection
filetype indent on    " Enable filetype-specific indenting
syntax on		" syntax highlight
set hlsearch		" search highlighting
set showmatch		" Cursor shows matching ) and }
set showmode		" Show current mode
set autoindent		" auto indentation
set incsearch		" incremental search
set nobackup		" no *~ backup files
set copyindent		" copy the previous indentation on autoindenting

"--------------------------------------------------------------------------- 
" USEFUL SHORTCUTS
"--------------------------------------------------------------------------- 
" set leader to ,
let mapleader=","
let g:mapleader=","

"replace the current word in all opened buffers
map <leader>r :call Replace()<CR>

" ,/ turn off search highlighting
nmap <leader>/ :nohl<CR>

" allow multiple indentation/deindentation in visual mode
vnoremap < <gv
vnoremap > >gv
