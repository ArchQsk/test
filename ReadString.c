/*
 * 単方向のリスト
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

struct node{
    char jp[BUFSIZE];
    char en[BUFSIZE];
    struct node *next;
};

struct node *addString(struct node *head, char *str);
void printNode(struct node *p);
void freeNode(struct node *p);

int main(void)
{
    /**** file open ****/
    FILE* fp;
    char filename[] = "text.txt";
    if((fp = fopen(filename, "r")) == NULL){
        fprintf(stderr, "fopen: error\n");
        exit(EXIT_FAILURE);
    }
    
    /**** read file ****/
    char str[BUFSIZE];
    struct node *head = NULL;
    while(fgets(str, BUFSIZE, fp) != NULL){
        head = addString(head, str);
    }
    printNode(head);
    
    /***** close *****/
    freeNode(head);
    fclose(fp);
    return 0;
}

/*
 * 機能: nodeを作成し、連結する
 * 引数: struct node *head ... nodeの先頭ポインタ
 *       char *str         ... 追加したい文字列
 *       -- format: 英語 日本語
 */
struct node *addString(struct node *head, char *str)
{
    struct node *p;
    // 動的なメモリ確保
    p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        fprintf(stderr, "malloc: error\n");
        exit(EXIT_FAILURE);
    }
    
    // 読み込んだ1行を日本語と英語に分けて、nodeに格納
    sscanf(str, "%s %s", p->en, p->jp);
    // nodeの連結
    p->next = head;
    head = p;
    
    return head;
}

/* 
 * 機能: nodeの中身を表示する
 */
void printNode(struct node *p)
{
    while(p != NULL){
        printf("%s %s\n", p->en, p->jp);
        p = p->next;
    }
}

/*
 * 機能: mallocで確保した領域を、順に開放する
 */
void freeNode(struct node *p)
{
    struct node *tmp;
    while(p != NULL){
        tmp = p->next;
        free(p);
        p = tmp;
    }
}
