// modified from https://zh.wikipedia.org/wiki/%E7%BA%A6%E7%91%9F%E5%A4%AB%E6%96%AF%E9%97%AE%E9%A2%98

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct _LinkNode{
    int value;
    struct _LinkNode *next;
} LinkNode, *LinkNodePtr;

LinkNodePtr createCycle(int total) {
	int index = 0;
	LinkNodePtr head = NULL, curr = NULL, prev = NULL;
	head = (LinkNodePtr) malloc(sizeof(LinkNode));
	head->value = index;
	prev = head;

	while (--total > 0) {
		curr = (LinkNodePtr) malloc(sizeof(LinkNode));
		curr->value = ++index;
		prev->next = curr;
		prev = curr;
	}
	curr->next = head;
	return head;
}

void run(int total, int tag) {
	LinkNodePtr node = createCycle(total);
	LinkNodePtr prev = NULL;
	const int start = 1;
	int index = start;
	while (node != node->next) {
		if (index == tag) {
			printf("delete: %d\n", node->value);
			if (tag == start) {
                // when tag == 1;
                prev = node->next;
                free(node);
                node = prev;
			} else {
				prev->next = node->next;
                free(node);
                node = prev->next;
			}
			index = start;
		} else {
			prev = node;
			node = node->next;
			index++;
		}
	}
    printf("left: %d", node->value);
}

// int main(int argc, char* argv[]) {
//         if (argc < 3) return -1;
// 	run(atoi(argv[1]), atoi(argv[2]));
// 	return 0;
// }

int main(){
    run(5, 3);
    return 0;
}
