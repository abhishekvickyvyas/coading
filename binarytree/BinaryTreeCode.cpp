// C implementation of the approach 
#include <malloc.h> 
#include <stdio.h> 
#include<bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to 
// left child and a pointer to right child 
typedef struct treenode { 
    int val; 
    struct treenode* left; 
    struct treenode* right; 
} node; 

// Helper function that allocates a new node with the 
// given data and NULL left and right pointers 
node* createNode(int val) 
{ 
    node* newNode = (node*)malloc(sizeof(node)); 
    newNode->val = val; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 

// function to find height of tree given root node of tree as input
int hightOfTree(node* root)
	{
           if(root==NULL)
           		return 0;
           	return 1+max(hightOfTree(root->left),hightOfTree(root->right));

	}
// print all nodes of gien level . 
// input parameters are tree root node and level that need to be print (level), currentLevel (initial zero)
void levelOrderHelper_printEachLevel(node* root,int level,int currentLevel)
		{
            if(root ==NULL)
            	return ;
			if(currentLevel== level)
				 {
				 	cout<< root->val<<" ";
				 }

			levelOrderHelper_printEachLevel(root->left,level,currentLevel+1);
			levelOrderHelper_printEachLevel(root->right,level,currentLevel+1);

		}


/// print level order of a tree give the root node of tree
// reverseLO== true => print leaf level to root level(bottom to top ) else root level to leaf(top to bottom)
void levelOrder (node* tree,bool reverseLO)
	{
       int hight_of_tree=hightOfTree(tree);
       // cout<<"hight of tree is :- "<<hight_of_tree<"\n";

  

       for(int i=0;i<hight_of_tree;i++)	
       		{
       			if(reverseLO)
       				levelOrderHelper_printEachLevel(tree,hight_of_tree-i-1,0);
       			else
       				levelOrderHelper_printEachLevel(tree,i,0);	
       		}
     cout<<"\n";
	}
int  diameterOfBT(node* root)
	{
		if(root==NULL)
			return 0;
		int leftSubTreeHight=hightOfTree(root->left);
		int rightSubTreeHight=hightOfTree(root->right);
		int newDimeterAtCurentNode=1+leftSubTreeHight+rightSubTreeHight;
		int currentMaxDiameter=max(diameterOfBT(root->left),diameterOfBT(root->right));
			
		return max(newDimeterAtCurentNode,currentMaxDiameter);
	}
void inOrder(node* root)
	{
		if(root==NULL)
			return;
		inOrder(root->left);
		cout<<root->val<<" ";
		inOrder(root->right);
	}
void iterativeInOrder(node* root)
	{
		stack<node*> s;
		node * currentNode=root;
		while(!s.empty() || currentNode!=NULL)
				{
					if(currentNode!=NULL)
						{
							s.push(currentNode);
							currentNode=currentNode->left;
						}
					else
						{
							node* stcakTop=s.top();
							s.pop();
							cout<<stcakTop->val<<" ";
							currentNode=stcakTop->right;
						}


				}
		cout<<"\n";
	}
void preOrder(node* root)
	{
		if(root==NULL)
			return;
		cout<<root->val<<" ";
		preOrder(root->left);
		
		preOrder(root->right);
	}
void iterativePreOrder(node *root)
	{
		/// as inorder
		stack<node*> s;
		// node * currentNode=root;
		// while(!s.empty() || currentNode!=NULL)
		// 		{
		// 			if(currentNode!=NULL)
		// 				{
		// 					s.push(currentNode);
		// 					cout<<currentNode->val<<" ";
		// 					currentNode=currentNode->left;
		// 				}
		// 			else
		// 				{
		// 					node* stcakTop=s.top();
		// 					s.pop();
							
		// 					currentNode=stcakTop->right;
		// 				}


		// 		}

		//other way
		s.push(root);
		while(!s.empty())
			{
				node * currentNode=s.top();
				s.pop();
				cout<<currentNode->val<<" ";

				if(currentNode->right)
					s.push(currentNode->right);
				if(currentNode->left)
					s.push(currentNode->left);


			}

			cout<<"\n";

	}
void postOrder(node* root)
	{
		if(root==NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->val<<" ";
		
	}
void iterativePostOrder(node* root)
	{
		stack<node*> s;
		stack<node*> resultPostOrder;
		s.push(root);
		while(!s.empty())
			{
				node * currentNode=s.top();
				s.pop();
				resultPostOrder.push(currentNode);
				if(currentNode->left)
					s.push(currentNode->left);

				if(currentNode->right)
					s.push(currentNode->right);
				

			}
		while(!resultPostOrder.empty())
			{
				node * temp=resultPostOrder.top();
				resultPostOrder.pop();
				cout<<temp->val<<" ";
			}

			cout<<"\n";


	}

/// "root"=> current root node of subtree// mp=> map to map level, level => curent level intiall  zero
void leftView(node* root,unordered_map<int,int> &mp,int level)
		{
			// cout<<"helo\n";
			if(!root)
				return;

            if((mp.find(level) == mp.end()))
            	{
            		mp[level]=1;
            		cout<<root->val<<" ";

            	}
            // cout<<"helo1\n";
        	leftView(root->left,mp,level+1);
        	leftView(root->right,mp,level+1);    

		}

/// for given root node of a tree it will print left view of tree
void leftView(node* root)
	{
		unordered_map<int,int> mp;
		// cout<<"left view of tree is \n";
		leftView(root,mp,0);


	}


/// "root"=> current root node of subtree// mp=> map to map level, level => curent level intiall  zero
void rightView(node* root,unordered_map<int,int> &mp,int level)
		{
			// cout<<"helo\n";
			if(!root)
				return;

            if((mp.find(level) == mp.end()))
            	{
            		mp[level]=1;
            		cout<<root->val<<" ";

            	}
            // cout<<"helo1\n";
        	rightView(root->right,mp,level+1);
        	rightView(root->left,mp,level+1);
        	    

		}
// for a given root of a tree print the right view of the tree
void rightView(node* root)
	{
		unordered_map<int,int> mp;
		rightView(root,mp,0);
	}

/// "root"=> current root node of subtree// hightMap=> map to map level, level => curent level intiall  zero
// widthMap => left or right width , width of root is zero , left child of root is -1 and right child of root is +1 go in save way
	// width => store the width initally for root it is zero
void topView(node* root,unordered_map<int,int> &widthMap,unordered_map<int,int> &hightMap,int width,int level)
	{

			if(!root)
				return;

            if((widthMap.find(width) == widthMap.end()))
            	{
            		widthMap[width]=root->val;
            		hightMap[width]=level;
            		

            	}
            else
            	{

            		if(level<hightMap[width])
            			{
        					widthMap[width]=root->val;
            				hightMap[width]=level;
            							    				
            			}

            	}

        	topView(root->left,widthMap,hightMap,width-1,level+1);
        	topView(root->right,widthMap,hightMap,width+1,level+1);


	}
// for a given root of a tree print the top view of the tree
void topView(node* root)
	{
   		unordered_map<int,int> widthMap;
   		unordered_map<int,int> hightMap;
   		topView(root,widthMap,hightMap,0,0);
   		map<int, int> orderedMapis(widthMap.begin(), widthMap.end());
   		for(auto x:orderedMapis)
   				{
   					// cout<<x.first<<" "<<x.second<<" \n";
   					cout<<x.second<<" ";
   				}
	}
/// "root"=> current root node of subtree// hightMap=> map to map level, level => curent level intiall  zero
// widthMap => left or right width , width of root is zero , left child of root is -1 and right child of root is +1 go in save way
	// width => store the width initally for root it is zero
void bottomView(node* root,unordered_map<int,int> &widthMap,unordered_map<int,int> &hightMap,int width,int level)
	{

			if(!root)
				return;

            if((widthMap.find(width) == widthMap.end()))
            	{
            		widthMap[width]=root->val;
            		hightMap[width]=level;
            		

            	}
            else
            	{

            		if(level>hightMap[width])
            			{
        					widthMap[width]=root->val;
            				hightMap[width]=level;
            							    				
            			}

            	}

        	bottomView(root->left,widthMap,hightMap,width-1,level+1);
        	bottomView(root->right,widthMap,hightMap,width+1,level+1);


	}
// for a given root of a tree print the bottom view of the tree
void bottomView(node* root)
	{
		unordered_map<int,int> widthMap;
   		unordered_map<int,int> hightMap;
   		bottomView(root,widthMap,hightMap,0,0);
   		map<int, int> orderedMapis(widthMap.begin(), widthMap.end());
   		for(auto x:orderedMapis)
   				{
   					// cout<<x.first<<" "<<x.second<<" \n";
   					cout<<x.second<<" ";
   				}

	}

void zigZagtraversal(node* root)
	{
		stack<node*> cl;
		stack<node*> nl;
		// cout<<"hi";
		if(root==NULL)
			return;
		cl.push(root);

		while((!cl.empty()) || (!nl.empty()))
				{
					// cout<<"\nhello\n";

                     while(!cl.empty())
                     	{
                     		node * tempcl=cl.top();
                     		cout<<tempcl->val<<" ";
                     		cl.pop();
                     		nl.push(tempcl->left);
                     		nl.push(tempcl->right);

                     	}

                     	while(!nl.empty())
                     	{
                     		node * tempnl=nl.top();
                     		cout<<tempnl->val<<" ";
                     		nl.pop();
                     		cl.push(tempnl->right);
                     		cl.push(tempnl->left);
                     		

                     	}

                     	// cout<<"hi\n";

				}


	}

void diagonaltraversalPre(node * root, map<int,vector<node *>> &mp,int diagIndex)
	{
		if(root==NULL)
			return;
		mp[diagIndex].push_back(root);

		diagonaltraversalPre(root->left,mp,diagIndex+1);
		diagonaltraversalPre(root->right,mp,diagIndex);	

	}
void diagonaltraversal(node* tree)
	{
	   map<int,vector<node* >> mp;
	   diagonaltraversalPre(tree,mp,0);
	   for (auto x : mp)
	   		{
	   			cout<< x.first<<" =>  ";
	   			for(auto y: x.second)
	   					{
	   						cout<<y->val<<" ";
	   					}
	   				cout<<"\n";

	   		}

	}

void leftboundrytraversal(node *root)
	{
		if(root==NULL)
				return;
			
		if(root->left)
			{
				cout<<root->val<<" ";
				leftboundrytraversal(root->left);
			}
		else if(root->right)
			{
				cout<<root->val<<" ";
				leftboundrytraversal(root->right);
			}
	}
void rightboundrytraversal(node *root)
	{
		if(root==NULL)
				return;
			
		if(root->right)
			{
				
				rightboundrytraversal(root->right);
				cout<<root->val<<" ";
			}
		else  if(root->left)
			{
				
				rightboundrytraversal(root->left);
				cout<<root->val<<" ";
			}
		
	}
void leavestraversal(node *root)
	{
		if(root==NULL)
				return;
		leavestraversal(root->left);
		if(!(root->left) && !(root->right))
			{
				cout<<root->val<<" ";
			}
		leavestraversal(root->right);
	}
void boundrytraversal(node *tree)
	{
		if(tree==NULL)
			return;
		// vector<node*> vis;
		cout<<tree->val<<" ";
		leftboundrytraversal(tree->left);
		leavestraversal(tree->left);
		leavestraversal(tree->right);
		rightboundrytraversal(tree->right);


	}

void apls1_bt(node* tree)
	{
		cout<<"enter operation number\n 1. level order traversal\n 2. reverse level order traversal\n 3. diameter of a Binary tree \n 4. Inorder(recursion + iterative )\n 5. Pre-rder(recursion + iterative )\n 6. Post-order(recursion + iterative\n 7. left view of tree\n 8. right view of tree \n 9. top view of tree\n 10. bottom View of Binary tree is \n 11. zig-zag traversal\n 12. diagonal traversal\n 13. boundry traversal\n";
		int n;
		cin>>n;
		if(n==1)
			{
				cout<<"level order traversal is =>\n";
				levelOrder(tree,false);
			}
		if(n==2)
			{
				cout<<"reverse level order traversal is =>\n";
				levelOrder(tree,true);
			}
		if(n==3)
			{
				cout<<"diameter  of Binary tree is \n";
				cout<<diameterOfBT(tree)<<"\n";
			}
		if(n==4)
			{
				cout<<"In-order recursion  of Binary tree is \n";
				inOrder(tree);
				cout<<"\nIn-order iterative  of Binary tree is \n";
				iterativeInOrder(tree);
				
			}
		if(n==5)
			{
				cout<<"Pre-order recursion  of Binary tree is \n";
				preOrder(tree);
				cout<<"\nPre-order iterative  of Binary tree is \n";
				iterativePreOrder(tree);
				
			}
		if(n==6)
			{
				cout<<"Post-order recursion  of Binary tree is \n";
				postOrder(tree);
				cout<<"\nPost-order iterative  of Binary tree is \n";
				iterativePostOrder(tree);
			}
		if(n==7)
			{
				cout<<"Left View of Binary tree is \n";
				leftView(tree);
				cout<<"\n";

			}
		if(n==8)
			{
				cout<<"right View of Binary tree is \n";
				rightView(tree);
				cout<<"\n";

			}
		if(n==9)
			{
				cout<<"top View of Binary tree is \n";
				topView(tree);
				cout<<"\n";

			}
		if(n==10)
			{
				cout<<"bottom View of Binary tree is \n";
				bottomView(tree);
				cout<<"\n";

			}
		if(n==11)
			{
				cout<<"zig-zag traversal Binary tree is \n";
				zigZagtraversal(tree);
				cout<<"\n";

			}
		if(n==12)
			{
				cout<<"diagonal traversal Binary tree is \n";
				diagonaltraversal(tree);
				cout<<"\n";

			}
		if(n==13)
			{
				cout<<"boundry traversal Binary tree is \n";
				boundrytraversal(tree);
				cout<<"\n";

			}


	}

int main() 
{ 

    // node* tree = createNode(5); 
    // tree->left = createNode(3); 
    // tree->right = createNode(6); 
    // tree->left->left = createNode(2); 
    // tree->left->right = createNode(4); 

    node* tree = createNode(1); 
    tree->left = createNode(2); 
    tree->right = createNode(3); 
    tree->left->left = createNode(7); 
    tree->left->right = createNode(6);
    tree->right->left = createNode(5); 
    tree->right->right = createNode(4);


    // left right view tree
    // node* tree = createNode(5); 
    // tree->left = createNode(3); 
    // tree->right = createNode(6); 
    // // tree->left->left = createNode(2); 
    // tree->left->right = createNode(4); 
    // tree->right->left = createNode(15); 
    // tree->right->right = createNode(14); 

    // tree->right->left->left=createNode(34);
    // tree->right->left->right=createNode(35);
    // tree->right->left->left->right=createNode(36);
    // tree->right->left->left->right->left=createNode(37);
    // tree->right->left->left->right->right=createNode(38);
    // tree->right->left->left->right->right->right=createNode(39);
    // tree->right->left->left->right->right->right->right=createNode(40);
    // tree->right->left->left->right->right->right->left=createNode(41);
    // tree->right->left->left->right->right->right->left->right=createNode(44);
    // tree->right->left->left->right->right->right->left->left=createNode(42);
    // tree->right->left->left->right->right->right->left->left->right=createNode(43);


    // tree->left->right->left=createNode(2);
    // tree->left->right->left->left=createNode(8);
    // tree->left->right->left->left->right=createNode(7);
    // tree->left->right->left->left->right->left=createNode(16);
    // tree->left->right->left->left->right->left->left=createNode(26);
    // tree->left->right->left->left->right->left->right=createNode(27);
    // Print inorder traversal of the input tree 
    printf("Binary Tree operations "); 
    apls1_bt(tree);  
  

    // itreativePreorder

    return 0; 
} 
