ce programme nous introduit la manipulation des fd (file descriptor) via l'utilisation des fonctions pipe(), dup2() pour rediriger 
les lectures et ecritures suivant nos besoins.

Cela se matérialise ici par la création d'une ligne de commande shell avec un ou plusieur "|". Nous devons aussi pouvoir lire dans 
un fichier 1 via "<" et rediriger le résultat d'une commande donc ecrire dans un fichier 2 via ">"

le modèle etant:
./pipex <infile> <cmd1> <cmd2> <cmd3> ... <outfile>

exemple: test1 < cat | grep "papa" > test2
ici nous pourrons lancer: ./pipex test1 cat "grep papa" test 2

