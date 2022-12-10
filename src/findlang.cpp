#include "fcm.cpp"


int main(int argc, char** argv)
{
   

    //Context order and alpha
    int k = -1;
    float a = 0;
    char l ='a';

    


    while(k <= 0){
        cout << "Insert context order (k): ";
        cin >> k;
    }
    while(a <= 0){
        cout << "Insert alpha (a): ";
        cin >> a;
    }
    
    
    //Load models and processing
    fcm f = fcm(k, a);
    int distMin;
    string modelLang;
    for(int i = 1; i < argc - 1; i++){
        
        map<string, map<char, int>> model;
        
        cout << "Begin processing " << argv[i] << endl;
        
        f.loadModel(model, argv[i]);
        
    

        f.estimate(model, argv[argc-1]);
        // cout << "distancia estimada: " << f.distance << endl;
        // cout << "entropia estimada: " << f.estimatedEntropy << endl;

        if(i == 1) {
            modelLang = argv[i];
            distMin = f.distance;
        }
        else {
            if(distMin > f.distance) {
                modelLang = argv[i];
                distMin = f.distance;
            }
        }
        cout << "Model loaded sucessfully!" << endl;
    }

    cout << "\nGuess for the language in which a text was written: " << modelLang << endl;
    
    return 0;
}