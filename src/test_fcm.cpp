
#include "fcm.cpp"

#include<map>
#include<string>



int main(int argc, char *argv[]){

   if(argc < 2){
        cout << "Error: Usage sintax is: ./tfcm <textfile>" << endl;
        return 0; 
    }

    fcm f(5, 0.1);
    map<string, map<char, int>> model;

    for(int i = 1; i < argc - 1; i++){
        cout << "trying to process: " << argv[i] << endl;
        
        f.loadModel(model, argv[i]);

        f.calculateModelEntropy(model);
        cout << "entropia do modelo: " << f.modelEntropy << endl;
        
        // estimar entropia de um texto de entrada
        f.estimate(model, (char*)"../src/models/simple.txt");
        cout << "distancia estimada: " << f.distance << endl;
        cout << "entropia estimada: " << f.estimatedEntropy << endl;
    }


}