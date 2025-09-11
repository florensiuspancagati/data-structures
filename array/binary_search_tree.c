#include <stdio.h>
#include <stdlib.h>

// Struktur karakter untuk simpul dalam pohon biner
struct TreeNode {
    char karakter;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;
typedef Node *TreeRoot;

// Fungsi untuk membuat simpul baru dalam pohon
Node *createNode(char item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->karakter = item;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Inisialisasi pohon kosong
void initializeTree(TreeRoot *tree) {
    *tree = NULL;
}

// Fungsi untuk menambahkan simpul baru ke pohon
void addNode(Node **node, char item) {
    if (*node == NULL) {
        *node = createNode(item);
    }
}

// Traversal PreOrder: Akar - Kiri - Kanan (RASITE)
void preOrderTraversal(TreeRoot tree) {
    if (tree != NULL) {
        printf("%c ", tree->karakter); // Akar
        preOrderTraversal(tree->left); // Kiri
        preOrderTraversal(tree->right); // Kanan
    }
}

// Traversal InOrder: Kiri - Akar - Kanan (ISTARE)
void inOrderTraversal(TreeRoot tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->left); // Kiri
        printf("%c ", tree->karakter); // Akar
        inOrderTraversal(tree->right); // Kanan
    }
}

// Traversal PostOrder: Kiri - Kanan - Akar (ITSAER)
void postOrderTraversal(TreeRoot tree) {
    if (tree != NULL) {
        postOrderTraversal(tree->left); // Kiri
        postOrderTraversal(tree->right); // Kanan
        printf("%c ", tree->karakter); // Akar
    }
}

int main() {
    TreeRoot dificultTree;
    
    // Inisialisasi pohon
    initializeTree(&dificultTree);
    
    // Menambahkan simpul-simpul ke pohon
    addNode(&dificultTree, 'R');
    addNode(&dificultTree->left, 'A');
    addNode(&dificultTree->left->left, 'S');
    addNode(&dificultTree->left->left->right, 'T');
    addNode(&dificultTree->left->left->left, 'I');
    addNode(&dificultTree->right, 'E');

    printf("RASITE Traversal: ");
    preOrderTraversal(dificultTree);
    
    printf("\nISTARE Traversal: ");
    inOrderTraversal(dificultTree);
    
    printf("\nITSAER Traversal: ");
    postOrderTraversal(dificultTree);
    
    printf("\n");
    
    return 0;
}
