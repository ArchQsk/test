# test
## malloc
* void *malloc(size_t size)
* メモリの割り当て

### void*
* 汎用のポインタ型、どんな型にも変換できる。
* キャストすればいい

### mallocの使い方例
* (キャスト)malloc(確保したいサイズ)
```cpp
int *p;
p = (int *p)malloc(sizeof(int));
```

## free
* void free(void *ptr)
* mallocで確保したメモリを開放する

## プログラムについて
* 単方向のリストを用いたプログラム
* 読み込みファイル名: test.txt (適宜変更する)