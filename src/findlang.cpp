#include "fcm.cpp"


int main(int argc, char** argv)
{

    int k = -1;
    float a = 0;
    char l ='a';


    while(k <= 0){
        cout << "Valor de k: ";
        cin >> k;
    }
    while(a <= 0){
        cout << "Valor de alpha: ";
        cin >> a;
    }
    
    
    fcm f = fcm(k, a);
    int distMin;
    string modelo;
    for(int i = 1; i < argc - 1; i++){
        
        map<string, map<char, int>> modelo_mapa;
        
        f.getModelo(modelo_mapa, argv[i]);
        
        f.estimate(modelo_mapa, argv[argc-1]);


        if(i == 1) {
            modelo = argv[i];
            distMin = f.dist;
        }
        else {
            if(distMin > f.dist) {
                modelo = argv[i];
                distMin = f.dist;
            }
        }
        cout << "Modelo criado" << endl;
    }

    string filename = modelo;
    int flag = 0;
    string linguagem_final;

    for (int i = string(filename).size(); i-- > 0;){
        if( filename[i] == '/'){
            flag++;
        }
        if(flag == 1){
            linguagem_final = filename[i] + linguagem_final;
        }
        if( filename[i] == '.'){
            flag++;
        }
        
    }
    cout << "\nLinguagem mais provavel de " << argv[argc-1] << ": " << linguagem_final << endl;
    
    return 0;
}