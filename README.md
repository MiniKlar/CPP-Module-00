# CPP Module 00 — Introduction to C++

> First step of the 42 C++ piscine: moving from C to C++. Namespaces, classes,
> member functions, I/O streams, initialization lists, and `static` / `const`.

This module contains three exercises (`ex00`, `ex01`, `ex02`), each self-contained
in its own directory with its own `Makefile`.

---

## 🇬🇧 English

### Theme

The goal of this module is the transition from procedural C to object-oriented C++,
through the fundamentals:

- **Namespaces** and the standard library (`std::cout`, `std::cin`, `std::string`).
- **Classes**, member functions, encapsulation (`private` / `public`).
- **I/O streams**: reading user input with `std::getline`, formatting output with `<iomanip>`.
- **Initialization lists** and constructors / destructors.
- **`static`** members and methods (shared state across instances).
- **`const`** member functions and references.
- Separation of declarations (`.hpp`) and definitions (`.cpp`).

All exercises are compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

### Exercises

| Directory | Binary | What it does |
|-----------|--------|--------------|
| `ex00` | `Megaphone` | A CLI program that prints its command-line arguments in **UPPERCASE** (concatenated). With no argument, it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`. First contact with `main(argc, argv)`, `std::cout` and `std::endl`. |
| `ex01` | `Phonebook` | An interactive **PhoneBook**. A `Contact` class (first/last name, nickname, phone number, darkest secret) with getters/setters, and a `Phonebook` class holding a fixed array of 8 contacts. Commands `ADD`, `SEARCH`, `EXIT`; input validation; formatted columnar display using `<iomanip>`. Demonstrates classes, encapsulation, `const` getters, and I/O streams. A separate `UI` module handles the logo, screen clearing and prompts. |
| `ex02` | `Accountability` | The classic 42 **Account** exercise (GlobalBanksters United). An `Account` class tracking deposits and withdrawals, with `static` members and `static` methods sharing global state across all accounts (`_nbAccounts`, `_totalAmount`, `_totalNbDeposits`, `_totalNbWithdrawals`). `const` member functions and timestamped logging. The expected output must match a reference log. |

### Build & Run

Each exercise builds independently with `make` inside its own directory:

```bash
# ex00 — Megaphone
cd ex00 && make && ./Megaphone "hello world"     # -> HELLO WORLD
./Megaphone                                       # -> * LOUD AND UNBEARABLE FEEDBACK NOISE *

# ex01 — Phonebook (interactive)
cd ex01 && make && ./Phonebook

# ex02 — Accountability
cd ex02 && make && ./Accountability
```

Useful `Makefile` rules (available in every exercise): `make` / `all`, `clean`,
`fclean`, `re`.

### What I learned

- **From C to C++**: keeping a familiar procedural skeleton (`main`, loops) while
  adopting `std::string`, streams and references instead of `char *` and `printf`.
- **Classes & encapsulation**: keeping data `private` and exposing behaviour through
  member functions, getters and setters.
- **Standard streams**: `std::cout` / `std::cin`, line-based input with
  `std::getline`, and aligned formatting with `<iomanip>`.
- **`static` & `const`**: shared state across instances via `static` members, and
  read-only methods via `const`.
- **Project structure**: splitting declarations (`.hpp`) from definitions (`.cpp`)
  and driving the build with a `Makefile`.

---

## 🇫🇷 Français

### Thème

L'objectif de ce module est le passage du C procédural au C++ orienté objet, à
travers les fondamentaux :

- **Namespaces** et bibliothèque standard (`std::cout`, `std::cin`, `std::string`).
- **Classes**, fonctions membres, encapsulation (`private` / `public`).
- **Flux d'entrée/sortie** : lecture du clavier avec `std::getline`, mise en forme
  de l'affichage avec `<iomanip>`.
- **Listes d'initialisation**, constructeurs / destructeurs.
- Membres et méthodes **`static`** (état partagé entre les instances).
- Fonctions membres et références **`const`**.
- Séparation des déclarations (`.hpp`) et des définitions (`.cpp`).

Tous les exercices se compilent avec `c++ -Wall -Wextra -Werror -std=c++98`.

### Exercices

| Dossier | Binaire | Ce qu'il fait |
|---------|---------|---------------|
| `ex00` | `Megaphone` | Un programme en ligne de commande qui affiche ses arguments en **MAJUSCULES** (concaténés). Sans argument, il affiche `* LOUD AND UNBEARABLE FEEDBACK NOISE *`. Premier contact avec `main(argc, argv)`, `std::cout` et `std::endl`. |
| `ex01` | `Phonebook` | Un **répertoire téléphonique** interactif. Une classe `Contact` (prénom, nom, surnom, numéro, secret le plus sombre) avec getters/setters, et une classe `Phonebook` contenant un tableau fixe de 8 contacts. Commandes `ADD`, `SEARCH`, `EXIT` ; validation des entrées ; affichage en colonnes formaté avec `<iomanip>`. Met en pratique les classes, l'encapsulation, les getters `const` et les flux. Un module `UI` distinct gère le logo, le nettoyage de l'écran et les invites. |
| `ex02` | `Accountability` | L'exercice **Account** classique de 42 (GlobalBanksters United). Une classe `Account` suivant les dépôts et retraits, avec des membres et méthodes `static` partageant un état global entre tous les comptes (`_nbAccounts`, `_totalAmount`, `_totalNbDeposits`, `_totalNbWithdrawals`). Fonctions membres `const` et journalisation horodatée. La sortie doit correspondre à un log de référence. |

### Compilation & Lancement

Chaque exercice se compile indépendamment avec `make` dans son propre dossier :

```bash
# ex00 — Megaphone
cd ex00 && make && ./Megaphone "hello world"     # -> HELLO WORLD
./Megaphone                                       # -> * LOUD AND UNBEARABLE FEEDBACK NOISE *

# ex01 — Phonebook (interactif)
cd ex01 && make && ./Phonebook

# ex02 — Accountability
cd ex02 && make && ./Accountability
```

Règles `Makefile` utiles (présentes dans chaque exercice) : `make` / `all`,
`clean`, `fclean`, `re`.

### Ce que ça m'a apporté

- **Du C au C++** : conserver un squelette procédural familier (`main`, boucles)
  tout en adoptant `std::string`, les flux et les références à la place des
  `char *` et de `printf`.
- **Classes & encapsulation** : garder les données `private` et exposer le
  comportement via des fonctions membres, getters et setters.
- **Flux standard** : `std::cout` / `std::cin`, lecture ligne à ligne avec
  `std::getline`, et alignement de l'affichage avec `<iomanip>`.
- **`static` & `const`** : état partagé entre les instances via les membres
  `static`, et méthodes en lecture seule via `const`.
- **Structure du projet** : séparation des déclarations (`.hpp`) et des
  définitions (`.cpp`), build piloté par un `Makefile`.
