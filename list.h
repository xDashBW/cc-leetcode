#ifndef __list_h
#define __list_h

struct list_head {
  struct list_head *prev, *next;
};

#define list_head_init(h) ((h)->prev = (h), (h)->next = (h))

static inline void list_add_tail(struct list_head *node,
                                 struct list_head *head) {
  node->prev = head;
}


#endif
