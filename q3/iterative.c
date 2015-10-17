/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <tree.h>
#include <time.h>
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

void flatten(struct TreeNode* root)
{
    struct TreeNode* leftt;
    while(root!=NULL) {
        if(root->left!=NULL) {
            leftt=root->left;
            while(leftt->right!=NULL) leftt=leftt->right;
            leftt->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}

int main()
{
    double endtime = 0;
    struct timespec start, end;

    Node *root = NULL;
    insert(&root, 1);
    insert(&(root->left), 2);
    insert(&(root->left->left), 3);
    insert(&(root->left), 4);
    insert(&root, 5);
    insert(&root, 6);

    // print_preorder(root);
    // printf("\n");
    // print_inorder(root);
    // printf("\n");
    // print_postorder(root);
    // printf("\n");
    FILE *fp;
    fp = fopen("iterative.txt","a");
    clock_gettime(CLOCK_REALTIME, &start);

    flatten(root);

    clock_gettime(CLOCK_REALTIME, &end);
    endtime =  diff_in_second(start, end);
    fprintf(fp, "%.9lf\n",endtime);
    fclose(fp);
    // print_preorder(root);
    // printf("\n");
    // print_inorder(root);
    // printf("\n");
    // print_postorder(root);
    // printf("\n");
    return 0;
}
