#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define inbuf_len 1 << 16
#define outbuf_len 1 << 16

void Init();
void TypeLetter(char L);
void UndoCommands(int U);
char GetLetter(int P);

int main() {
    int tmp;

    /* Set input and output buffering */
    char *inbuf, *outbuf;
    inbuf = (char*)malloc(inbuf_len * sizeof(char));
    outbuf = (char*)malloc(outbuf_len * sizeof(char));
    tmp = setvbuf(stdin, inbuf, _IOFBF, inbuf_len);
    tmp = setvbuf(stdout, outbuf, _IOFBF, outbuf_len);

    Init();

    int cmd_num;
    tmp = scanf("%d", &cmd_num);
    assert(tmp == 1);

    int i;
    for (i = 0; i < cmd_num; i++) {
        char cmd;
        tmp = scanf(" %c", &cmd);
        assert(tmp == 1);
        if (cmd == 'T') {
            char letter;
            tmp = scanf(" %c", &letter);
            assert(tmp == 1);
            TypeLetter(letter);
        } else if (cmd == 'U') {
            int number;
            tmp = scanf("%d", &number);
            assert(tmp == 1);
            UndoCommands(number);
        } else if (cmd == 'Q') {
            int index;
            char letter;
            tmp = scanf("%d", &index);
            assert(tmp == 1);
            letter = GetLetter(index);
            printf("%c\n", letter);
        }
    }

    return 0;
}

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
const int M = 100000;
const int N = 100000;
// const int N = 5;
int tot, len[M], his;
struct node {
    int l, r;
    char val;
    node *lson, *rson;
} t[15000000];
node* history[M];

void build(node* cur) {
    if (cur->l == cur->r) return;
    int mid = (cur->l + cur->r) >> 1;
    t[tot].l = cur->l, t[tot].r = mid, cur->lson = &t[tot++];
    t[tot].l = mid + 1, t[tot].r = cur->r, cur->rson = &t[tot++];
    build(cur->lson);
    build(cur->rson);
}

void Init() {
    his = 1;
    tot = 1;
    history[0] = &t[0];
    t[0].l = 1;
    t[0].r = N;
    len[0] = 0;
    build(history[0]);
}

void print(node* cur) {
    cerr << "cur = " << (cur - t) << ' ' << cur->l << ' ' << cur->r << ' ' << '\n';
    if (cur->l == cur->r) return;
    print(cur->lson);
    print(cur->rson);
}

void TypeLetter(char L) {
    node *old = history[his - 1], *root = &t[tot], *cur = &t[tot++];
    root->l = 1, root->r = N;
    len[his] = len[his - 1] + 1;
    int pos = len[his];
    // cerr << "Begin TypeLetter\n";
    while (cur->l != cur->r) {
        // cerr << "cur = "<< (cur-t) << ' ' << cur->l << ' ' << cur->r << ' '
        // << '\n';
        int mid = (cur->l + cur->r) >> 1;
        if (pos <= mid) {
            t[tot].l = cur->l, t[tot].r = mid, cur->lson = &t[tot], cur->rson = old->rson, old = old->lson;
        } else {
            t[tot].l = mid + 1, t[tot].r = cur->r, cur->lson = old->lson, cur->rson = &t[tot], old = old->rson;
        }
        cur = &t[tot++];
    }
    // cerr << "cur = "<< (cur-t) << ' ' << cur->l << ' ' << cur->r << ' ' <<
    // '\n'; cerr << "End TypeLetter\n\n";
    cur->val = L;
    // print(root);
    // cerr << "\n\n";
    history[his++] = root;
}

void UndoCommands(int U) {
    history[his] = history[his - U - 1];
    len[his] = len[his - U - 1];
    ++his;
}

char GetLetter(int P) {
    // ++P;
    node* cur = history[his - 1];
    while (cur->l != cur->r) cur = (P <= ((cur->l + cur->r) >> 1)) ? (cur->lson) : (cur->rson);
    return cur->val;
}