#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Função para encontrar a orientação do triplo (p, q, r)
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;    // colinear
    return (val > 0) ? 1 : 2;  // horário ou anti-horário
}

// Função para calcular a distância ao quadrado entre dois pontos
int distSq(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Ponto de referência global para a ordenação
Point p0;

// Função de comparação para ordenar pontos com base no ângulo polar
bool compare(const Point& p1, const Point& p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        // Se colinear, o ponto mais próximo vem primeiro
        return distSq(p0, p1) < distSq(p0, p2);
    }
    return o == 2; // anti-horário
}

// Função para calcular o casco convexo usando o algoritmo de Graham Scan
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // O casco convexo não está definido para menos de 3 pontos

    // Encontrar o ponto mais baixo (ou o mais à esquerda em caso de empate)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = y;
            min = i;
        }
    }

    // Colocar o ponto mais baixo na primeira posição
    swap(points[0], points[min]);
    p0 = points[0];

    // Ordenar os pontos restantes com base no ângulo polar em relação a p0
    sort(points.begin() + 1, points.end(), compare);

    // Inicializar a pilha para armazenar o casco convexo
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    // Processar os pontos restantes
    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    for (const auto& p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
