int minHeight(Node* root){
	if(root==NULL) return 0;

	if(root->left==NULL){
		minHeight(root->right) + 1;
	}

	if(root->right==NULL){
		minHeight(root->left) + 1;
	}

	return 1 + min(minHeight(root->left), minHeight(root->right));
}

Time Complexity- O(n);
Space- O(1);