#include "fcm.cpp"

int main(int argc, char** argv)
{
    if(argc < 2){
        cout << "Error: Usage sintax is: ./lang <textfile> <textfile>" << endl;
        return 0; 
    }

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
    map<string, map<char, int>> model;
   
    f.getModelo(model, argv[1]);
  
        
    cout << "Modelo criado" << endl;

    f.estimate(model, argv[2]);
    cout << "num bits estimados para comprimir: " << f.dist<< endl;
    cout << "num bits estimados por caracter: " << f.dist/f.num_letras << endl;

    
    return 0;
}