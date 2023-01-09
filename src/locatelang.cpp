//that can process a text containing segments written in different languages. This application should return the character position at which each segment
//starts, as well as the language in which the segment is written.
#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <limits>
using namespace std;

const int K = 5; // Length of context
const double ALPHA = 0.1; // Smoothing parameter for estimating probabilities
const double THRESHOLD = 1.0; // Distance threshold for identifying language segments
const int ALPHABETH_SIZE = 26; // Number of letters in the alphabet
const int DBL_MAX = 70; // Number of languages in the database

// Read a character from a stream, skipping over any characters that are not letters
bool readChar(istream &is, char *c) {
    while (is.get(*c)) {
        if (isalpha(*c)) {
            return true;
        }
    }
    return false;
}

class fcm {
private:
    int k;
    double alpha;
    
public:
    fcm(int k, double alpha) : k(k), alpha(alpha) {}
    
    string language;
    map<string, map<char, int>> model;
    double dist;
    double m_entropy;
    double e_entropy;
    int num_letras;
    
    void getModelo(map<string, map<char, int>> &model, char *filename) {
        ifstream ifs(filename, ios::in);
        
        string context;
        char c;
        for (int i = 0; i < k; i++) {
            readChar(ifs, &c);
            context = context + c;
        }
        
        char c_novo;
        while (readChar(ifs, &c_novo)) {
            map<char, int> &chars = model[context];
            chars[c_novo]++;
            context.erase(context.begin());
            context = context + c_novo;
        }
    }
    
    void getEntropy(map<string, map<char, int>> &model) {
        int aux;
        int entradas = 0;
        map<string, int> num_contexto;
        for (auto it = model.begin(); it != model.end(); ++it) {
            map<char, int> &mapa_novo = model[it->first];
            aux = 0;
            vector<int> value;
            for (auto it = mapa_novo.begin(); it != mapa_novo.end(); ++it) {
                value.push_back(it->second);
            }
            aux = accumulate(value.begin(), value.end(), 0);
            num_contexto[it->first] = aux;
            entradas = entradas + aux;
        }
        
        double contexto_prob, prob, contexto_entropia, H;
        int total;
        
        for (auto it = model.begin(); it != model.end(); ++it) {
            map<char, int> &mapa_novo = model[it->first];
            contexto_entropia = 0;
        for (auto it = mapa_novo.begin(); it != mapa_novo.end(); ++it) {
            prob = (double) it->second / total;
            contexto_entropia = contexto_entropia - prob * log2(prob);
        }
        
        H = H + contexto_entropia * contexto_prob;
    }
    
    m_entropy = H;
}

void estimate(map<string, map<char, int>> &model, char *filename) {
    ifstream ifs(filename, ios::in);
    
    string contexto;
    char aux;
    for (int i = 0; i < k; i++) {
        readChar(ifs, &aux);
        contexto = contexto + aux;
    }
    
    int n, total_n;
    double sumH = 0;
    int count = 0;
    
    while (!ifs.eof()) {
        readChar(ifs, &aux);
        count++;
        
        total_n = 0;
        
        if (model.find(contexto) == model.end()) {
            n = 0;
            total_n = 0;
            
        } else {
            map<char, int> &mapa_novo = model[contexto];
            n = mapa_novo[aux];
            
            vector<int> value;
            for (auto it = mapa_novo.begin(); it != mapa_novo.end(); ++it) {
                value.push_back(it->second);
            }
            total_n = accumulate(value.begin(), value.end(), 0);
        }
        
        sumH = sumH + (-log2((n + alpha) / (total_n + (alpha * ALPHABETH_SIZE))) / k);
        
        contexto.erase(contexto.begin());
        contexto = contexto + aux;
    }
    
    e_entropy = sumH / count;
    dist = sumH;
}
};

int main(int argc, char *argv[]) {
if (argc < 2) {
cout << "Error: Usage sintax is: ./tfcm <textfile>" << endl;
return 0;
}

vector<fcm> models;
string languages[argc - 1];
for (int i = 1; i < argc; i++) {
    fcm f(K, ALPHA);
    f.language = argv[i];
    f.getModelo(f.model, argv[i]);
    f.getEntropy(f.model);
    models.push_back(f);
    languages[i - 1] = argv[i];
}

ifstream ifs(argv[argc - 1], ios::in);
char c;
int pos = 0;
string context;
for (int i = 0; i < K; i++) {
    readChar(ifs, &c);
    context = context + c;
}

int start = 0;
double min_dist = numeric_limits<double>::max();
string min_lang;
while (ifs.get(c)) {
context += c;
if (context.size() > K) {
context.erase(context.begin());
}
if (context.size() == K) {
    double minDist = DBL_MAX;
    int index = -1;
    for (int i = 0; i < models.size(); i++) {
        models[i].estimate(models[i].model, (char*)argv[argc - 1]);
        if (models[i].dist < minDist) {
            minDist = models[i].dist;
            index = i;
        }
    }
    
    cout << "Segment starting at position " << pos - K + 1 << " is written in " << languages[index] << endl;
}

pos++;
}

ifs.close();

return 0;
};


