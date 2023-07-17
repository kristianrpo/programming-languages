using namespace std;
class Palabra{
private:
    string palabra = "";
public:
    void palabraJugar(){
        string arregloPalabras[40]={"LOMA","IGLU","HUIR","GEMA","FLOR","FRIO","EURO","CENA","BUHO","ARCO","PIANO","BALON","MURAL","CABLE","NACER","CENAR","HOGAR","BOLSA","TENIS","LIBRO","AUDIOS","RAPIDO","BONITA","CARIBE","BUSCAR","CHOZAS","ORIGEN","CUBANO","FLORES","PIPETA","PESCADO","PARTIDO","TECLADO","QUERIDA","MUSICAL","JAPONES","AMPLIOS","FABULAS","GRAFICO","BARONES"};
        int aleatorio;
        srand(time(NULL));
        aleatorio = rand() % 40;
        setPalabra(arregloPalabras[aleatorio]);
    }

    string getPalabra()
    {
        return this->palabra;
    }
    void setPalabra(string palabraAsignada)
    {
        this->palabra = palabraAsignada;
    }
};
