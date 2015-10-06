# test
## malloc
* void *malloc(size_t size)
* メモリの割り当て

### void*
* 汎用のポインタ型、どんな型にも変換できる。

### mallocの使い方例
* (キャスト)malloc(確保したいサイズ)
* int \*p;
p = (int *p)malloc(sizeof(int));

## free
* void free(void *ptr)
* mallocで確保したメモリを開放する