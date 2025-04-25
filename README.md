# Philosophers

## 🧠 Description

Le projet **Philosophers** fait partie du cursus de l'école 42. Il a pour but de vous initier à la programmation concurrente à travers le **problème classique des philosophes** formulé par Edsger Dijkstra.

Ce projet met en jeu la synchronisation de threads et la gestion fine des ressources partagées (mutex), avec pour objectif principal d’éviter les problèmes classiques comme le **deadlock** (interblocage) ou le **starvation** (famine d’un thread).

---

## ⚙️ Règles du Problème

- Cinq philosophes sont assis autour d'une table circulaire.
- Chacun alterne entre trois actions : **penser**, **manger**, **dormir**.
- Pour **manger**, un philosophe a besoin de deux fourchettes (celle à sa gauche et celle à sa droite).
- Il ne peut prendre les fourchettes que si elles sont disponibles.
- L’objectif est que tous les philosophes puissent manger sans tomber dans un état d’attente infini (deadlock ou starvation).

---

## ✅ Objectifs

- Créer un programme multithreadé où chaque philosophe est représenté par un thread distinct.
- Protéger les ressources critiques (fourchettes) avec des mutex.
- Implémenter un système de surveillance pour détecter si un philosophe meurt de faim (ne mange pas à temps).
- Arrêter proprement tous les threads si l’un des philosophes meurt.

---

## 🧩 Paramètres

Le programme prend les arguments suivants :

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Explication des arguments :

| Argument                                  | Description                                                                 |
|-------------------------------------------|-----------------------------------------------------------------------------|
| `number_of_philosophers`                  | Nombre de philosophes et de fourchettes (≥ 1)                               |
| `time_to_die` (ms)                        | Temps sans manger avant qu’un philosophe ne meure                          |
| `time_to_eat` (ms)                        | Temps nécessaire pour manger                                               |
| `time_to_sleep` (ms)                      | Temps que le philosophe passe à dormir                                     |
| `number_of_times_each_philosopher_must_eat` _(optionnel)_ | Nombre de fois que chaque philosophe doit manger avant que le programme se termine |

---

## 🏗️ Implémentation

- Le programme utilise **pthread** pour créer les threads des philosophes.
- Chaque fourchette est représentée par un **mutex**.
- Une boucle principale surveille si un philosophe meurt ou si tous ont mangé le nombre requis de fois.
- Des **timestamps précis** sont utilisés pour mesurer les temps d’action et détecter les délais critiques.

---

## 🚀 Compilation

Compilez avec :

```bash
make
```

Nettoyez les fichiers objets :

```bash
make clean
```

Nettoyez tout :

```bash
make fclean
```

Recompilez proprement :

```bash
make re
```

---

## 🧪 Exemple d'utilisation

```bash
./philo 5 800 200 200
```

→ Lance 5 philosophes avec un `time_to_die` de 800ms, `time_to_eat` de 200ms et `time_to_sleep` de 200ms.

```bash
./philo 5 800 200 200 3
```

→ Même chose, mais le programme s’arrête dès que chaque philosophe a mangé 3 fois.

---

## 🛑 Gestion des erreurs

Le programme gère et affiche les erreurs suivantes :

- Mauvais nombre d’arguments
- Valeurs non numériques ou négatives
- Échecs lors de la création de threads ou d'initialisation de mutex

---

## 🧵 Concepts abordés

- Threads (`pthread_create`, `pthread_join`)
- Mutex (`pthread_mutex_t`)
- Conditions de course et synchronisation
- Gestion de la concurrence et timing précis
- Protection des sections critiques
- Arrêt propre de threads et libération de ressources

---

## 📌 Remarques

- Le programme doit être précis à quelques millisecondes près.
- Les messages affichés doivent être cohérents et ne pas se chevaucher.
- Aucun comportement indéfini ne doit être toléré.

---

## ✍️ Exemple de sortie

```
0 1 is thinking
0 2 is thinking
0 3 is thinking
0 4 is thinking
0 5 is thinking
1 2 has taken a fork
1 2 has taken a fork
1 2 is eating
...
```

---

## 📚 Ressources utiles

- [Man pthreads](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [Problème des philosophes sur Wikipédia](https://fr.wikipedia.org/wiki/Probl%C3%A8me_des_philosophes)
- Documentation 42 sur les threads et mutex

---
