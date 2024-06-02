#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ponto {//Define a point
    int x, y;
};

double calculateDistance(const Ponto &p1, const Ponto &p2) {//Calculate the distance between two points
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int orientation(const Ponto &p, const Ponto &q, const Ponto &r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);//Apply a cross product between the PQ vector and the QR vector to discover of the points(P, Q and R) are collinear or not
    // val = 0: The points are collinear, because when cross product is equal to 0, the vectors are straighly in the same line.
    // val > 0: The points form a clockwise turn.
    // val < 0: The points form a counterclockwise turn
    if (val == 0){//0 -> If the points are collinear(lie in a single straight line)
        return 0;
    }
    return (val > 0) ? 1 : 2;  // 1 -> If the points make a clockwise turn(giram no sentido horário) | 2 -> If the points make a counterclockwise turn(giram no sentido anti-horário) 
}


bool compare(const Ponto &p1, const Ponto &p2, const Ponto &pivo) {//Function to compare two points with the pivot point
    int o = orientation(pivo, p1, p2);
    if (o == 0){//If the points are collinear
        return calculateDistance(pivo, p2) >= calculateDistance(pivo, p1);
    }
    return o == 2;
}

// Função para encontrar o fecho convexo(Convex hull) usando o Algoritmo de Graham
vector<Ponto> fechoConvexo(vector<Ponto> &pontos) {
    int n = pontos.size();
    if (n < 3){// O fecho convexo não é definido para menos de 3 pontos
        return {};
    }
    // Encontre o ponto com a menor coordenada y (em caso de empate, menor x)
    int min_y = 0;
    for (int i = 1; i < n; i++) {
        if (pontos[i].y < pontos[min_y].y || (pontos[i].y == pontos[min_y].y && pontos[i].x < pontos[min_y].x))
            min_y = i;
    }
    swap(pontos[0], pontos[min_y]);
    Ponto pivo = pontos[0];//Define esse ponto de menor coordenada Y(em caso de empate, menor x) como sendo o pivot

    // Ordene os pontos pelo ângulo polar em relação ao ponto pivô
    sort(pontos.begin() + 1, pontos.end(), [pivo](const Ponto &p1, const Ponto &p2) {
        return compare(p1, p2, pivo);
    });

    // Use uma pilha para construir o fecho convexo
    vector<Ponto> fecho;
    fecho.push_back(pontos[0]);
    fecho.push_back(pontos[1]);

    for (int i = 2; i < n; i++) {
        while (fecho.size() > 1 && orientation(fecho[fecho.size() - 2], fecho.back(), pontos[i]) != 2){//If the orientation of the 
            fecho.pop_back();
        }
        fecho.push_back(pontos[i]);
    }

    return fecho;
}

double calculatePerimeter(const vector<Ponto> &fecho) {//Function to calculate the perimeter of each convex hull
    double perimetro = 0.0;
    int n = fecho.size();
    for (int i = 0; i < n; i++) {
        perimetro += calculateDistance(fecho[i], fecho[(i + 1) % n]);
    }
    return perimetro;
}

int main() {
    int numArvores;
    cin >> numArvores;
    vector<Ponto> pontos(numArvores);
    
    for (int i = 0; i < numArvores; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    vector<Ponto> fecho = fechoConvexo(pontos);//Calcula o fecho convexo(convex hull)
    double perimetro = calculatePerimeter(fecho);

    // Arredondar para cima
    cout << ceil(perimetro) << endl;

    return 0;
}
