#include "std_lib_facilities.h"
#include <cstdlib>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

void print_input(vector<int> bit)
{
  if (bit.size()<=1000){
    int i=1;
    for(int x : bit){
      cout<<x;
      if (i%60==0){
        cout<<endl;
      }
      i++;
    }
  }
}

struct node* new_node(int value)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;
}

void traverse(struct node *unit)
{
  if (unit!=NULL){
    traverse(unit->left);
    cout << " " << unit->data;
    traverse(unit->right);
  }
}

void count_branches(struct node *unit,string current_string, vector<string>& data)
{
   if (unit!=NULL){
    if (unit->data!=9){
      current_string+=to_string(unit->data);
    }
    if (unit->left==NULL && unit->right==NULL){
      data.push_back(current_string);
    }
    count_branches(unit->left,current_string,data);
    count_branches(unit->right,current_string,data);
  }
}

void traverse_wout_output(struct node *unit){
  if (unit!=NULL){
    traverse_wout_output(unit->left);
    traverse_wout_output(unit->right);
  }
}

void free_mem(struct node *temp)
{
  //if (temp != NULL) {
  //  traverse_wout_output(temp->left);
  //  free(temp);
  //  cout<<"Successful"<<endl;
  //  traverse_wout_output(temp->right);

  free(temp);
  //}
}

float average(vector<string> data)
{
  int overall_length=0;
  for (string x:data){
    overall_length+=x.length();
  }

  float avg=float(overall_length)/float(data.size());

  return avg;

}

float deviation(vector<string> data)
{
  float sum=0;
  float avg=average(data);
  for (string x : data){
    sum+=(float(x.length()-avg)*float(x.length()-avg));
  }

  return sqrt(sum/data.size());
}


float corrigated_deviation(vector<string> data)
{
  float sum=0;
  float avg=average(data);
  for (string x : data){
    sum+=(float(x.length()-avg)*float(x.length()-avg));
  }

  return sqrt(sum/(data.size()-1));
}

