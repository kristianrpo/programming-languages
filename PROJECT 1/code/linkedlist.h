using namespace std;
node* string_to_SLL(string s)
{
    if(s.size() == 0) return NULL;
    node *head = new node(toupper(s[0]),"blanco");
    node* curr = head;
    for (int i = 1; i < s.size(); i++) {
        curr->next = new node(toupper(s[i]),"blanco");
        curr = curr->next;
    }
    return head;
}

void printColor(node* head)
{
  node* intento = head;
  Color::Modifier yellow(Color::FG_YELLOW);
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);
  Color::Modifier red(Color::FG_RED); 
  while (intento != NULL) 
  {
    if (intento->color=="amarillo")
    {
      cout<<yellow<<intento->data<<def;   
    }
    if (intento->color == "verde")
    {
      cout <<green<<intento->data<<def; 
    }
    if (intento->color =="blanco")
    {
      cout << intento->data;            
    }
    if(intento->color == "rojo")
    {
      cout<<red<<intento->data<<def;  
    }
    intento = intento->next;
  }
}

node* perder(node* h1){
  node* rh1=h1;
  while(rh1!= NULL){
    rh1->color ="rojo";
    rh1=rh1->next;
  }
  return h1;
}

node* comparar (node* h1,node* h2, bool &f, string p) 
{
  node* nh1 = h1;
  node* nh2 = h2;
  int i = 1;
  int j = 1;
  int c = 0;
  while(nh2 != NULL) 
  {
    nh1 = h1; 
    while(nh1 != NULL) 
    {
      if(nh1->data==nh2->data&&i==j) 
      {
        nh2->color = "verde"; 
        c=c+1;
        if(c==p.size()){
		    	f = true;
		    }
      }
      else if(nh1->data == nh2->data && i!=j)
      {
        if(nh2->color=="verde")
        {
          break;
        }
        else
        {
          nh2->color = "amarillo";
        }
      }   
      i = i+1;
      nh1 = nh1->next;
    }
    i = 1;
    j = j+1;
    nh2 = nh2->next;
  }
  return h2;
}
node* verifyVerde(node* h2){
  node* nh2 = h2;
  while(nh2 != NULL){
    if(nh2->color=="amarillo"){
      char letter = nh2->data;
      node* test = h2;
      while(test!=NULL){
        if(letter==test->data && test->color=="verde"){
          nh2->color="blanco";
        }
        test=test->next;
      }
    }
    nh2 = nh2->next;
  }
  return nh2;
}
