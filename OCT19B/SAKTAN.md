# Operations on a Matrix

_[Présentation du problème](https://www.codechef.com/problems/SAKTAN)_

_Vous disposez d'une matrice de **N lignes** (numérotées de 1 à N) et **M colonnes** (numérotées de 1 à M) remplie de 0._
_Vous effectuez sur cette matrice les opérations suivantes **Q fois**:_
* _lire sur l'entrée standard les coordonnées (x, y) d'une cellule valide_
* _ajouter 1 à toutes les cellules de la ligne x_
* _ajouter 1 à toutes les cellules de la colonne y_

_**Votre objectif est de compter le nombre de cellules contenant un entier impair dans la matrice résultante.**_

<br/>

## Préliminaires: lire l'entrée
L'énoncé indique que l'entrée consiste en:
* un entier T entre 1 et 300 représentant le nombre de tests à passer
* Pour chaque test:
    * trois entiers N, M et Q entre 1 et 10<sup>5</sup>
    * Q lignes composées:
        * d'un entier x entre 1 et N
        * d'un entier y entre 1 et M

Je vous propose d'organiser votre code en séparant la lecture de l'entrée standard de l'exécution de la logique.
Pour ce faire, toute la logique sera placée dans une fonction que j'ai appelé ```run_testcase``` tandis que l'entrée standard sera lue dans une boucle principale.

```cpp
#include <iostream>
using namespace std;

int run_testcase(int n, int m, int q);

int main() {
    int T;
    int N, M, Q;

    cin >> T;

    while (T--) { // Notation fonctionnant grâce au fait que 0 et false sont équivalents en C++.
        cin >> N >> M >> Q;
        cout << run_testcase(N, M, Q) << endl;
    }

	return(0);
}

int run_testcase(int n, int m, int q) {
    int x, y;
 
    while (q--) {
        cin >> x >> y;
    }
 
    return(-1);  // La valeur retournée n'importe pas pour l'instant.
}
```

**Si vous n'avez pas encore essayé de résoudre ce problème par vous-même, c'est le moment de vous creuser les méninges !**
Ce problème a été initialement posé dans le cadre d'un concours d'une dizaine de jours, il est donc tout à fait normal que vous y passiez un peu de temps.
A l'inverse, ne perdez pas non plus votre temps à chercher une solution que vous n'êtes peut-être pas en mesure de trouver.
_Deux jours me semble être un compromis raisonnable._

<br/>

## Le nerf de la guerre: élaboration de l'algorithme
### Algorithme naif
La solution la plus facile à imaginer est d'exécuter toutes les opérations indiquées dans l'énoncé, dans l'ordre.
Ainsi, cela revient à:
* créer une matrice de dimensions N x M remplie de 0
* lire sur l'entrée standard Q couples (x, y) de ligne et de colonne auxquelles rajouter 1 (et faire cette opération)
* et enfin parcourir toute la matrice pour compter le nombre de cellules impaires

Si cela ne vous semble pas super facile à faire, essayez de compléter la fonction ```run_testcase``` avec cet algorithme pour vous entraîner un peu.

Voici un exemple de fonction ```run_testcase``` qui correspond à cet algorithme :
```cpp
int run_testcase(int n, int m, int q) {
    int matrix[n][m]; // Créer la matrice de dimensions N x M
    int x, y;
    int ans;

    // Initialisation de la matrice à 0 dans chaque cellule
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }

    // Exécution des Q opérations
    while (q--) {
        cin >> x >> y;

        for (int i = 0; i < m; i++) matrix[x - 1][i]++;
        for (int i = 0; i < n; i++) matrix[i][y - 1]++;
    }

    // Calcul de la réponse
    ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2)  ans++;  // Un nombre impair modulo 2 fait 1, ce qui sera évalué à true.
        }
    }

    return(ans);
}
```

Toutefois, comme vous vous en doutiez, cette solution présente des inconvénients:
* elle est trop gourmande en **temps**: elle implique de faire Q * (M + N) + M * N calculs
_(si cet inconvénient vous semble abstrait, faites le calcul avec la valeur maximale que peuvent prendre ces nombres)_
* elle est trop gourmande en **mémoire**: la matrice que vous devez stocker peut s'avérer trop grande
_(vous ne pouvez raisonnablement pas stocker une matrice de 10<sup>5</sup> x 10<sup>5</sup> = 10<sup>10</sup>)_

**Vous arriverez malgré tout à passer le premier jeu de subtests (40 %).**

<br/>

### Algorithme solution
Une manière de trouver une solution, quand on n'a pas d'idée pour un point de départ, est d'essayer de remédier aux écueils de la solution naïve.
Comme il est difficile, de prime abord, de se fixer pour objectif de réduire significativement la complexité en temps de l'algorithme naïf, je vous propose de déjà diminuer la consommation de mémoire.

Le plus simple est de ne plus utiliser de matrice car la taille de cette matrice dépend de la multiplication de deux nombres pouvant être très grands.
C'est une mesure un peu radicale, mais vous n'avez pas le choix: la taille de la matrice est trop grande, vous devez trouver une solution en vous en passant.
En revanche, il est possible de créer deux tableaux - un pour les lignes et un pour les colonnes - sans que cela consomme trop de mémoire.

**Si ce n'est pas déjà fait, prenez le temps de réfléchir à la manière dont vous vous y prendriez pour compter le nombre de cellules impaires en ne conservant que des informations concernant les lignes et les colonnes.**

Vous ne disposez plus que de deux tableaux pour stocker des informations.
Dans un tableau, vous pourriez compter le nombre de fois que chaque ligne a été incrémentée, et dans l'autre, le nombre de fois que chaque colonne a été incrémentée.
En fait, comme vous n'avez pas besoin de savoir combien de fois, mais simplement si c'est un nombre pair ou impair, vous pourriez même n'y conserver qu'un booléen à inverser à chaque fois que la ligne ou la colonne doit être incrémentée.

```cpp
int run_testcase(int n, int m, int q) {
    bool    rows[n] = {false};  // Notation pour initialiser le tableau à false
    bool    cols[m] = {false};
    int     x, y;

    while (q--) {
        cin >> x >> y;

        rows[x - 1] = !rows[x - 1]; // x - 1 et non x car l'indexation commence à 0 en C++
        cols[y - 1] = !cols[y - 1];
    }

    return(-1);  // La valeur retournée n'importe pas pour l'instant.
}
```

Ici, au lieu de parcourir les tableaux pour compter le nombre de lignes et de colonnes impaires, il est possible de les compter au fur et à mesure.
Votre code doit donc ressembler à ceci:

```cpp
int run_testcase(int n, int m, int q) {
    bool    rows[n] = {false};
    bool    cols[m] = {false};
    int     orows = 0;  // odd rows
    int     ocols = 0;
    int     x, y;

    while (q--) {
        cin >> x >> y;

        // Condition ternaire: diminuer si la ligne était paire et devient impaire
        //                     augmenter si la ligne était impaire et devient paire.
        orows = (rows[x - 1] ? orows - 1 : orows + 1);
        rows[x - 1] = ! rows[x - 1];

        ocols = (cols[y - 1] ? ocols - 1 : ocols + 1);
        cols[y - 1] = ! cols[y - 1];
    }

    // Le nombre de cellules par ligne est le nombre de colonnes,
    // et le nombre de cellules par colonne est le nombre de lignes.
    return (orows *  m + ocols * n);  // Faire la somme donne une réponse erronée, est-ce que vous voyez pourquoi ?
}
```

Vous disposez maintenant d'un algorithme qui s'exécute dans les limites de temps et de mémoires accordées.
Malheureusement, il ne fonctionne pas !
En effet, le nombre de cellules impaires n'est pas la somme des nombre de lignes et de colonnes impaires (multipliés par le nombre de cellules respectivement par ligne et par colonne, cela s'entend).

**Prenez le temps de réfléchir à ce que vous faites.**

La valeur d'une cellule ne dépend pas seulement de l'incrémentation de la ligne où elle figure, mais aussi de l'incrémentation de sa colonne.
Autrement dit, l'algorithme ne prend pas en compte le fait que les lignes et les colonnes se croisent !
Pourtant, vous n'êtes pas loin d'avoir trouvé la solution.

**Si vous n'avez pas encore trouvé la solution, prenez un crayon et une feuille, et dessinez ce qu'il se passe dans la matrice lorsqu'une ligne et une colonne impaires ou paires se croisent.**

Le tableau ci-dessous résume ce à quoi devraient ressembler vos trouvailles:

|  L \ C  |  paire  | impaire |
| ------- |:-------:| -------:|
|  paire  |  paire  | impaire |
| impaire | impaire |  paire  |

En faisant la somme telle que dans l'algorithme précédent, tous les cas sont gérés sauf un: celui où une ligne impaire croise une colonne impaire.
Une façon simple de le gérer est:
* pour le calcul par ligne, de retrancher au nombre de colonnes par lesquelles on les multiplie le nombre de colonnes impaires
* pour le calcul par colonne, de retrancher au nombre de lignes par lesquelles on les multiplie le nombre de lignes impaires

Ce qui donne: ```orows * (m - ocols) + ocols * (n - orows)```.
Si cette formule ne vous convainc pas, essayez de faire un dessin de la matrice (personnellement, c'est comme ça que je l'ai trouvée).

**Vous disposez d'un bon algorithme, mais ne parvennez pas encore à passer le dernier jeu de subtests (80 %).**

<br/>

## Respectez les contraintes, _toutes_ les contraintes

Pour réussir le dernier jeu de subtests, votre code doit supporter des nombres plus grands que ce qui peut tenir dans un int.
Je vous propose de rajouter la ligne suivante en début de code:
```cpp
#define ull unsigned long long
```
puis de remplacer par ```ull``` tous les int pour des variables qui pourraient en dépasser le maximum.

Félicitations, vous êtes venus à bout de ce problème !
