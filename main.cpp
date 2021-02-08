#include "lib.h"



int main(){
  vector<string> branches;
  vector<int> data_arr;

  

  cout<<"input:"<<endl;
  

  int num;
  while (cin>>num){
    data_arr.push_back(num);
  }

  print_input(data_arr);

  node *ROOT,*current_obj;
  current_obj=(struct node*)malloc(sizeof(struct node));
  ROOT=(struct node*)malloc(sizeof(struct node));
  ROOT->left=NULL;
  ROOT->right=NULL;
  ROOT->data=9;
  current_obj=ROOT;


  for (int i=0;i<data_arr.size();i++){
    int input=data_arr[i];
    if (input==0){
      if (current_obj->left==NULL){
        current_obj->left=new_node(0);
        current_obj=ROOT;
      } else {
        current_obj=current_obj->left;
      }
    } else if (input==1) {
      if (current_obj->right==NULL){
        current_obj->right=new_node(1);
        current_obj=ROOT;
      } else {
        current_obj=current_obj->right;
      }
      
    }
    
    
  }

  
  count_branches(ROOT,"",branches);

  //traverse(ROOT);
  cout<<endl;
  free_mem(ROOT);
  
  cout<<endl<<"Fa agai:"<<endl;
  if (branches.size()<50){
    for (string i : branches){
      
      cout<<i<<endl;
    }
  }
  cout<<endl;

  cout<<"Agak hosszanak atlaga: "<<average(branches)<<endl;
  cout<<"Fa againak a szama: "<<branches.size()<<endl;
  cout<<"Szoras: "<<deviation(branches)<<endl;
  cout<<"Korrigalt szoras: "<<corrigated_deviation(branches)<<endl;

  return 0;

}
