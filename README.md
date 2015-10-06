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
* 連結リストにした場合、mallocで確保したメモリをすべて開放しなくてはいけない
```cpp
// mallocで確保した領域を、順に開放する
void freeNode(struct node *p)
{
    struct node *tmp;
    // 解法したいポインタをpにいれていく
    while(p != NULL){
        tmp = p->next; // 次のノードのアドレスを一時保存
        free(p); // 開放
        p = tmp; // 一時保存した次のノードのアドレスをpにいれる
    }
}
```

## プログラムについて
* 単方向のリストを用いたプログラム
* 読み込みファイル名: text.txt (適宜変更する)
* mallocの使い方の参考程度にどうぞ