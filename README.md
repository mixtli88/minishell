# minishell spanish

Minishell
A simplified UNIX command-line interpreter
Minishell Logo (opcional)

📌 Tabla de Contenidos
Descripción

Características Implementadas

Instalación y Uso

Ejemplos de Comandos

Estructura del Proyecto

Recursos y Referencias

Autores

🚀 Descripción
Minishell es un proyecto de 42 School que consiste en crear un intérprete de comandos simple, similar a bash o zsh.

Implementa un prompt interactivo.

Ejecuta comandos básicos (ls, echo, pwd, cd, etc.).

Maneja redirecciones (>, >>, <, <<) y pipes (|).

Soporta variables de entorno ($PATH, $HOME, etc.).

Gestiona señales (Ctrl+C, Ctrl+D, Ctrl+\).

💡 Características Implementadas
✅ Comandos built-in:

echo (con opción -n)

cd (con ~ y -)

pwd

export

unset

env

exit

✅ Redirecciones y pipes:

> (sobrescribir archivo)

>> (añadir a archivo)

< (leer entrada desde archivo)

<< (here-document)

| (pipes entre comandos)

✅ Manejo de variables de entorno:

Expansión de $VAR

Expansión de $? (último estado de salida)

✅ Señales:

Ctrl+C → Interrumpe el comando actual

Ctrl+D → Cierra el shell

Ctrl+\ → No hace nada (como en bash)

✅ Otras funcionalidades:

Comillas simples ('texto') y dobles ("texto")

Múltiples comandos separados por ;

🔧 Instalación y Uso
Requisitos
Sistema Linux / macOS

Compilador gcc

make

Compilación
bash
Copy
git clone https://github.com/tu-usuario/minishell.git
cd minishell
make
Ejecución
bash
Copy
./minishell
Salir del programa
bash
Copy
exit
Ejecutar un script
bash
Copy
./minishell < script.sh
📜 Ejemplos de Comandos
bash
Copy
$> echo "Hola 42" && ls -la | grep .c
$> cat file.txt | wc -l > count.txt
$> cd ~/Desktop && pwd
$> export MY_VAR=42 && echo $MY_VAR
$> unset MY_VAR
$> exit
🗂️ Estructura del Proyecto
Copy
minishell/
├── includes/       # Archivos de cabecera (.h)
├── src/            # Código fuente (.c)
│   ├── builtins/   # Comandos built-in
│   ├── exec/       # Ejecución de comandos
│   ├── parser/     # Análisis de entrada
│   └── utils/      # Funciones auxiliares
├── libft/          # Librería estándar de 42
├── Makefile        # Script de compilación
└── README.md       # Documentación
📚 Recursos y Referencias
Bash Reference Manual

42 Minishell Subject

Tutorial de Shell

👥 Autores
Tu Nombre

Tu Compañero

Este formato es claro, profesional y cubre todo lo necesario para presentar tu proyecto. Puedes personalizarlo con más detalles técnicos si lo necesitas.

Bonus:
Si quieres darle más estilo, puedes usar Markdown emojis.

Si tu proyecto tiene tests, añade una sección "Pruebas".

Si usas gráficos, puedes incluir un diagrama de flujo con Mermaid.

¡Espero que te ayude! 🚀

dame esto tambien en ingles y frances

# minishell English

🌍 README in English | Français
🇬🇧 English Version
Minishell
A simplified UNIX command-line interpreter
📌 Table of Contents
Description

Implemented Features

Installation & Usage

Command Examples

Project Structure

Resources & References

Authors

🚀 Description
Minishell is a 42 School project that involves creating a simple command-line interpreter, similar to bash or zsh.

Implements an interactive prompt.

Executes basic commands (ls, echo, pwd, cd, etc.).

Handles redirections (>, >>, <, <<) and pipes (|).

Supports environment variables ($PATH, $HOME, etc.).

Manages signals (Ctrl+C, Ctrl+D, Ctrl+\).

💡 Implemented Features
✅ Built-in commands:

echo (with -n option)

cd (with ~ and -)

pwd

export

unset

env

exit

✅ Redirections & pipes:

> (overwrite file)

>> (append to file)

< (read input from file)

<< (here-document)

| (pipes between commands)

✅ Environment variables:

$VAR expansion

$? (last exit status)

✅ Signal handling:

Ctrl+C → Interrupts current command

Ctrl+D → Exits the shell

Ctrl+\ → Does nothing (like in bash)

✅ Other features:

Single ('text') and double ("text") quotes

Multiple commands separated by ;

🔧 Installation & Usage
Requirements
Linux / macOS

gcc compiler

make

Compilation
bash
Copy
git clone https://github.com/your-user/minishell.git
cd minishell
make
Execution
bash
Copy
./minishell
Exiting
bash
Copy
exit
Running a script
bash
Copy
./minishell < script.sh
📜 Command Examples
bash
Copy
$> echo "Hello 42" && ls -la | grep .c
$> cat file.txt | wc -l > count.txt
$> cd ~/Desktop && pwd
$> export MY_VAR=42 && echo $MY_VAR
$> unset MY_VAR
$> exit
🗂️ Project Structure
Copy
minishell/
├── includes/       # Header files (.h)
├── src/            # Source code (.c)
│   ├── builtins/   # Built-in commands
│   ├── exec/       # Command execution
│   ├── parser/     # Input parsing
│   └── utils/      # Helper functions
├── libft/          # 42's standard library
├── Makefile        # Build script
└── README.md       # Documentation
📚 Resources & References
Bash Reference Manual

42 Minishell Subject

Shell Scripting Tutorial

👥 Authors
Your Name

Your Partner


# minishell Francaise

Minishell
Un interpréteur de commandes UNIX simplifié
📌 Table des Matières
Description

Fonctionnalités Implémentées

Installation & Utilisation

Exemples de Commandes

Structure du Projet

Ressources & Références

Auteurs

🚀 Description
Minishell est un projet de 42 visant à créer un interpréteur de commandes simplifié, similaire à bash ou zsh.

Possède un prompt interactif.

Exécute des commandes basiques (ls, echo, pwd, cd, etc.).

Gère les redirections (>, >>, <, <<) et pipes (|).

Prend en charge les variables d’environnement ($PATH, $HOME, etc.).

Traite les signaux (Ctrl+C, Ctrl+D, Ctrl+\).

💡 Fonctionnalités Implémentées
✅ Commandes intégrées :

echo (avec l’option -n)

cd (avec ~ et -)

pwd

export

unset

env

exit

✅ Redirections et pipes :

> (écraser un fichier)

>> (ajouter à un fichier)

< (lire depuis un fichier)

<< (here-document)

| (pipes entre commandes)

✅ Variables d’environnement :

Expansion de $VAR

Expansion de $? (dernier statut de sortie)

✅ Gestion des signaux :

Ctrl+C → Interrompt la commande actuelle

Ctrl+D → Quitte le shell

Ctrl+\ → Ne fait rien (comme dans bash)

✅ Autres fonctionnalités :

Guillemets simples ('texte') et doubles ("texte")

Commandes multiples séparées par ;

🔧 Installation & Utilisation
Prérequis
Linux / macOS

Compilateur gcc

make

## Compilation
bash
Copy
git clone https://github.com/votre-utilisateur/minishell.git
cd minishell
make

##Exécution
./minishell

Quitter
exit

Exécuter un script
./minishell < script.sh

📜 Exemples de Commandes
$> echo "Bonjour 42" && ls -la | grep .c
$> cat fichier.txt | wc -l > compteur.txt
$> cd ~/Bureau && pwd
$> export MA_VAR=42 && echo $MA_VAR
$> unset MA_VAR
$> exit

🗂️ Structure du Projet
minishell/
├── includes/       # Fichiers d’en-tête (.h)
├── get_next_line/  # fonction utilitaries
├── src/            # Code source (.c)
│   ├── builtins/   # Commandes intégrées
│   ├── exec/       # Exécution des commandes
│   ├── parsing/    # Analyse des entrées
│   └── main/       # fonction main
├── libft/          # Librairie standard de 42
├── Makefile        # Script de compilation
└── README.md       # Documentation
📚 Ressources & Références
Manuel de Bash

- Sujet du Minishell (42)
    https://cdn.intra.42.fr/pdf/pdf/93116/fr.subject.pdf

👥 Auteurs
Fan Yu Wu
Maicol Abril
