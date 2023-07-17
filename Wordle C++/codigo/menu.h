using namespace std;
class Menu
{
  public:
    void menu()
    {
      bool tov = true;
      while(tov)
      {
        cout<<" "<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"| BIENVENIDO A WORDLE EN C++ |"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<" "<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"1. INICIAR JUEGO"<<endl;
        int numero = 0;
        cin>>numero;
        switch(numero)
        {
          case 0:
            tov = false;
            break;
          case 1:
            jugar();
            break;
          default:
            cout<<" "<<endl;
            cout<<"INGRESE UN NUMERO VALIDO"<<endl;
            cout<<" "<<endl;
            break;
        }
      }
    }

    void jugar()
    {
      Palabra p1;
      p1.palabraJugar();
      string palabrita = p1.getPalabra();
      node* head1 = string_to_SLL(palabrita);
      int i=1;
      bool win = false;
      cout<<"-------------------------------"<<endl;
      cout<<"|    SE GENERÓ UNA PALABRA    |"<<endl;
      cout<<"-------------------------------"<<endl;
      cout<<"La palabra a jugar tiene "<<palabrita.size()<<" caracteres"<<endl;
      while(i<=6)
      {
        cout<<" "<<endl;
        cout<<"Ingresa palabra, te quedan: "<<7-i<<" intentos"<<endl;
        string palabra = "";
        cin>>palabra;
        while(palabra.size()!=palabrita.size()){ 
        	if(palabra.size()<palabrita.size()){
        		cout<<"Esta palabra es muy corta. Por favor ingrese una de "<<palabrita.size()<<" caracteres"<<endl;
        	}else if(palabra.size()>palabrita.size()){
        		cout<<"Esta palabra es muy larga. Por favor ingrese una de "<< palabrita.size()<<" caracteres"<<endl;
			}
        	cin>>palabra;
		}
        node* head2 = string_to_SLL(palabra);
        head2 = comparar(head1,head2,win,palabrita);
        verifyVerde(head2);
        printColor(head2);
        if(win){
          cout<<"\n-----------------------------------------";
          cout<<"\n|¡FELICITACIONES! HA ACERTADO LA PALABRA|";
          cout<<"\n-----------------------------------------"<<endl;
          break;
        }
        if(i==6){
          perder(head1);
          cout<<"\nSE ACABARON LOS INTENTOS, LA PALABRA ERA ";
          printColor(head1);  
          cout<<", INTENTA JUGAR DE NUEVO A ADIVINAR LA PALABRA"<<endl;
        }
        i=i+1;
      }
      cout<<" "<<endl;
      cout<<" "<<endl;
      
    }
};
