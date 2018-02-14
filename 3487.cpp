#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Tree {
	int key;
	Tree *fa, *l, *r;
	int size;
	bool flag;
};

bool space;

void Update(Tree *T) {
	if (T == NULL) 
		return;
	if (T -> flag) {
		swap(T -> l, T -> r);
		T -> flag = false;
		if (T -> l != NULL)
			T -> l -> flag ^= true;
		if (T -> r != NULL)
			T -> r -> flag ^= true;
	}
}

void MakeTree(Tree *&T, int n) {
	bool k = false;
	Tree *cur, *pre;
	for (int i = n+1; i >= 0; -- i) {
		cur = new Tree;
		cur -> key = i;
		cur -> fa = cur -> l = cur -> r = NULL;
		cur -> size = 1;
		cur -> flag = false;
		if (k) {
			cur -> r = pre;
			pre -> fa = cur;
			cur -> size = pre -> size + 1;
		}
		else
			k = true;
		pre = cur;
	}
	T = cur;
}

void Zig(Tree *x) {
	Tree *y = x->fa;
	Tree *z = y->fa;
	Tree *k = x->r;
	int sx = x->size, sy = y->size, sk = 0;
	if (k != NULL)
		sk = k->size;
	y->l = k;
	x->r = y;
	if (z != NULL) {
		if (y == z->l)
			z->l = x;
		else
			z->r = x;
	}
	if (k != NULL)
		k->fa = y;
	y->fa = x;
	x->fa = z;
	y->size = sy - sx + sk;
	x->size = sx - sk + y->size;
}

void Zag(Tree *x) {
	Tree *y = x->fa;
	Tree *z = y->fa;
	Tree *k = x->l;
	int sx = x->size, sy = y->size, sk = 0;
	if (k != NULL)
		sk = k->size;
	y->r = k;
	x->l = y;
	if (z != NULL) {
		if (y == z->r)
			z->r = x;
		else
			z->l = x;
	}
	if (k != NULL)
		k->fa = y;
	y->fa = x;
	x->fa = z;
	y->size = sy - sx + sk;
	x->size = sx - sk + y->size;
}

Tree* FindTag(Tree *T, int x) {
	if (T == NULL)
		return NULL;
	Update(T);
	Tree *p;
	p = T;
	int sum = 1;
	if (p->l != NULL)
		sum += p->l->size;
	while (sum != x && p != NULL) {
		if (sum < x) {
			p = p->r;
			x -= sum;
		}
		else
			p = p->l;
		Update(p);
		sum = 1;
		if (p->l != NULL)
			sum += p->l->size;
	}
	Update(p);
	return p;
}

void Splay(int x, Tree *&T) {
	Update(T);
	Tree *p, *X, *end, *newt;
	end = T->fa;
	newt = T;
	if (end != NULL)
		newt = T->fa;
	X = FindTag(newt, x);
	while (X->fa != end) {
		p = X->fa;
		if (end == p->fa) {
			if (X == p->l)
				Zig(X);
			else
				Zag(X);
			break;
		}
		if (X == p->l) {
			if (p == p->fa->l) {
				Zig(p);
				Zig(X);
			}
			else {
				Zig(X);
				Zag(X);
			}
		}
		else {
			if (p == p->fa->r) {
				Zag(p);
				Zag(X);
			}
			else {
				Zag(X);
				Zig(X);
			}
		}
	}
	T = X;
}

void CUT(Tree *&T, int a, int b, int c) {
	Splay(a-1, T);
	Splay(b+1, T->r);
	Tree *tmp;
	tmp = T->r->l;
	tmp->fa = NULL;
	T->r->l = NULL;
	T->r->size -= tmp->size;
	T->size -= tmp->size;
	Splay(c, T);
	Splay(c+1, T->r);
	T->r->l = tmp;
	tmp->fa = T->r;
	T->r->size += tmp->size;
	T->size += tmp->size;
}

void FLIP(Tree *&T, int a, int b) {
	Splay(a-1, T);
	Splay(b+1, T->r);
	T->r->l->flag ^= true;
}

void FreeTree(Tree *T) {
	if (T == NULL) 
		return;
	FreeTree(T->l);
	FreeTree(T->r);
	free(T);
}

void PrintTree(Tree *T, int n) {
	if (T == NULL) 
		return;
	Update(T);
	PrintTree(T->l, n);
	if (T->key != 0 && T->key != n+1) {
		if (space) 
			printf(" ");
		else 
			space = true;
		printf("%d", T->key);
	}
	PrintTree(T->r, n);
}

int main() {
    Tree *T;
    int n, q, a, b, c;
    char s[8];

    while (scanf("%d%d", &n, &q) == 2 && n >= 0 && q >= 0) {
    	space = false;
    	T = NULL;
    	MakeTree(T, n);
    	while (q --) {
    		scanf("%s", s);
    		if (s[0] == 'C') {
    			scanf("%d%d%d", &a, &b, &c);
    			CUT(T, a+1, b+1, c+1);
    		}
    		else {
    			scanf("%d%d", &a, &b);
    			FLIP(T, a+1, b+1);
    		}
    	}
    	PrintTree(T, n);
    	printf("\n");
    	FreeTree(T);
    }

    return 0;
}