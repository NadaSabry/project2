typedef int EntryType;

typedef struct nodeTree{
EntryType info;
struct nodeTree *right;
struct nodeTree *left;
}NodeTree;

typedef NodeTree *TreeType;

void createTree(TreeType *t);
int EmptyTree(TreeType t);
int FullTree(TreeType t);
void Inorder(TreeType t,void(*pvisit)(EntryType*));
void preorder(TreeType t,void(*pvisit)(EntryType));
void postorder(TreeType t,void(*pvisit)(EntryType));
int Size(TreeType t);
int Height(TreeType t);
void Clear(TreeType *t);
void Insert(TreeType *t,EntryType item);

void DeletNode(TreeType *pt);
int Delete(TreeType *t,EntryType k);

int search_binary_tree(TreeType t,EntryType k);
int search_BST(TreeType t,EntryType k);

int leaves_count(TreeType t);

void printLevel(TreeType t);
void givenLevel(TreeType t,int level);

