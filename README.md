# ReadString.c
## malloc
* void *malloc(size_t size)
* メモリの割り当て

```cpp
// 例 (int型: 4バイトとする。　∴ sizeof(int) == 4)
int *p;
p = malloc(sizeof(int)) // 12バイトのメモリ領域が確保される
```

```cpp
### イメージ (参考ページ: http://www.geocities.jp/sugachan1973/doc/funto36.html)
/********************* ポインタ変数 p **********************/

番 |  　メモリの        |           番 |    メモリの       |
地 | 　アドレス空間     |           地 |    アドレス空間   |
===============================================================
  _______________________            __________________________
1 |_____________________|          24|________________________|
2 |___アドレス番地 25___|    ==>  # 25|_____|            |_____|
3 |_____________________|        # 26|_____|  4バイト分 |_____|
4 |_____________________|        # 27|_____|    確保    |_____|
5 |_____________________|        # 28|_____|____________|_____|
...
```

### void*
* 汎用のポインタ型、どんな型にも変換できる。
* キャストすればいい

### mallocの使い方例
* (キャスト)malloc(確保したいサイズ)
```cpp
int *p;
p = (int *p)malloc(sizeof(int));
```

* readString.cより
```cpp
...
struct node *p;
// 動的なメモリ確保
p = (struct node*)malloc(sizeof(struct node));
if(p == NULL){
    fprintf(stderr, "malloc: error\n");
    exit(EXIT_FAILURE);
}
...
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
    // 開放したいポインタをpにいれていく
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
