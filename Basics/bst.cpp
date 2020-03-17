
struct bst{
	ll d;
	struct bst *l;
	struct bst *r;
};
struct bst *root=NULL;
struct bst *newNode(ll n)
{
	struct bst *temp=(struct bst*)malloc(sizeof(struct bst));
	temp->d=n;
	temp->l=temp->r=NULL;
	return temp;
}
struct bst *insert(struct bst* node,ll key)
{
	if(node==NULL)	return newNode(key);
	if(key<=node->d)
		node->l=insert(node->l,key);
	else if(key>node->d)
		node->r=insert(node->r,key);
	return node;
}
ll height(struct bst* node)
{
	if(node==NULL)
		return 0;
	return max(1+height(node->l),1+height(node->r));
}
