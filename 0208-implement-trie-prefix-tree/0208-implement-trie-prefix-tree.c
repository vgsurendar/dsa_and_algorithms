#define ALPHABET 26

typedef struct Trie {
    struct Trie* child[ALPHABET];
    bool isEOW;
} Trie;

Trie* trieCreate() {
    int i = 0;
    Trie* newNode = (Trie*)malloc(sizeof(Trie));
    for (i = 0; i < ALPHABET; i++) {
        newNode->child[i] = NULL;
    }
    newNode->isEOW = false;
    return newNode;
}

void trieInsert(Trie* obj, char* word) {
    int i = 0;
    Trie* curr = obj;

    while (*word) {
        i = *word - 'a';
        if (curr->child[i] == NULL) {
            curr->child[i] = trieCreate();
        }
        curr = curr->child[i];
        word++;
    }
    curr->isEOW = true;
    return;
}

bool trieSearch(Trie* obj, char* word) {
    int i = 0;
    Trie* curr = obj;

    if (obj == NULL) {
        return false;
    }

    while (*word) {
        i = *word - 'a';
        if (curr->child[i] != NULL) {
            curr = curr->child[i];
        } else {
            return false;
        }
        word++ ;
    }
    if (curr->isEOW == true) {
        return true;
    }
    return false;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    int i = 0;
    Trie* curr = obj;

    if (obj == NULL) {
        return false;
    }

    while (*prefix) {
        i = *prefix - 'a';
        if (curr->child[i] != NULL) {
            curr = curr->child[i];
        } else {
            return false;
        }
        prefix++;
    }

    return true;
}

void trieFree(Trie* obj) {
    int i = 0;

    if (obj == NULL) {
        return;
    }

    for (i = 0; i < ALPHABET; i++) {
        if (obj->child[i] != NULL) {
            trieFree(obj->child[i]);
        }
    }
    free(obj);
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/