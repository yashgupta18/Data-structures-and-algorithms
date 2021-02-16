int minHeight(Node* root){
	if(root==NULL) return 0;

	int height=1;

	queue<Node*> q;
	q.push(root);

	while(true){
		int size=q.size();
		if(q.empty()){
			break;
		}

		while(size>0){
			int temp=q.top();
			q.pop();

			if(temp->left==NULL && temp->right==NULL){
				return height;
			}

			if(temp->left!=NULL){
				q.push(temp->left);
			}

			if(temp->right!=NULL){
				q.push(temp->right);
			}

			size--;
		}

		height++;
	}
	return height;
}

Time Complexity- O(n);
Space- O(n);