Installer les bibliothèques liées dynamiquement :
	- elles sont compilées à part 
	- elles doivent être liées à chaque projet
	- les mises à jour des bibliothèques sont automatiquement faites sur les projets (sans même recompiler le porjet)

Pour Windows, il faut mettre dans le dossier C:\Windows\System32 (celui où il y a déjà opengl32.dll) les fichiers suivants :
	- freeglut.dll
	- glew32.dll
que vous trouverez dans leur dossier bin respectifs.
Attention, il faut choisir les bibliothèques correspondant à votre sytème (Win32 ou x64)