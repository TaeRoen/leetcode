struct node {
    char s;
    struct node *prior;
};

struct stack {
    struct node *head;
    struct node *top;
};

void push(struct stack *s, char c) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->s = c;
    if (s->top) {
        n->prior = s->top;
        s->top = n;
    } else {
        s->head = n;
        s->top = n;
        n->prior = NULL;
    }
}

char pop(struct stack *s) {
    if (!s->top) {
        return '\n';
    }
    char res = s->top->s;
    if (s->top->prior) {
        struct node *tmp = s->top->prior;
        free(s->top);
        s->top = tmp;
    } else {
        free(s->top);
        s->top = NULL;
        s->head = NULL;
    }
    return res;
}

bool isValid(char *s) {
    struct stack sk;
    sk.head = NULL;
    sk.top = NULL;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            push(&sk, s[i]);
        }
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            char tmp = pop(&sk);
            if (tmp == '{' && s[i] != '}') {
                return false;
            }
            if (tmp == '[' && s[i] != ']') {
                return false;
            }
            if (tmp == '(' && s[i] != ')') {
                return false;
            }
            if (tmp == '\n') {
                return false;
            }
        }
    }
    if (sk.top) {
        return false;
    }
    return true;
}