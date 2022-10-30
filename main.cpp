
#include "main.h"

//Namespace
using namespace sf;
using namespace std;

//Prototype des fonction
void InputHandler(Event event, RenderWindow& window);
void LoadFont();
void SetText(Text &txt, String str);

//Variables
Font font;

//Fonction Main, Point de départ 
int main()
{

	// Création de la fenetre type RenderWindow
	RenderWindow window(VideoMode(winWidth,winHeight,32), "Titre de la fenetre");
	
	window.setVerticalSyncEnabled(true); //Activation du vsync
	
	//Chargement de la police
	LoadFont();
	//Création d'un text
	Text txt;
	//Fonction Proprieté du text
	SetText(txt, "Hello World!");

		//Boucle tant que la fenetre est ouverte
	while (window.isOpen())
	{

		Event event; //Varriable pour gerer l'événement

		//Boucle sur les événement
		while (window.pollEvent(event))
		{

			//Gestion des inputs / Event
			InputHandler(event, window);

		}

		//Couleur de la fenetre en noir
		window.clear(Color::Black);

		//Tous les élément du jeux
		window.draw(txt);

		//Dessiner a l'écran tout les éléments
		window.display();
	}

	return 0;
}


//Gestion des events et inputs
void InputHandler(Event event, RenderWindow& window)
{

	//Fermer la fenetre si on clic sur la croix
	if (event.type == Event::Closed)
	{

		window.close();//ferme la fenetre

	}

	//Gestion des input (clavier souris)
	//Detection btp apputé
	if (event.type == Event::KeyPressed)
	{

		if (event.key.code == Keyboard::Escape)
		{
			window.close();
		}

		if (event.key.code == Keyboard::Left)
		{
			SetText(txt, "Touche Gauche!");
		}

		if (event.key.code == Keyboard::Right)
		{
			SetText(txt, "Touche Droite!");
		}

	}

	//Detection btp souris
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			SetText(txt, "Clique Gauche!");
		}

		if (event.mouseButton.button == Mouse::Right)
		{
			SetText(txt, "Clique Droit!");
		}
	}

	//Autre facon de gerer (clavier souris)
	//Pour contrer le probleme de sacadement
	//Detection btp apputé
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		SetText(txt, "Up");
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		SetText(txt, "Down");
	}

	if (Mouse::isButtonPressed(Mouse::Middle))
	{
		SetText(txt, "Middle");
	}
}

//Charger la police d'ecriture
void LoadFont()
{

	//On verifi que la police est bien charger
	if (!font.loadFromFile("res/montserrat.ttf"))
	{
		//si erreur 
		cout << "erreur chargement font" << endl;
	}

}

//
void SetText(Text &txt, String str)
{
	//on lui indique quelle police utiliser
	txt.setFont(font);
	//on lui indique la chaine de caractère a afficher
	txt.setString(str);
	//on lui indique la taille de la police
	txt.setCharacterSize(26);
	//on lui donne une couleur de remplisage
	txt.setFillColor(Color::Cyan);
	//Modification du style 
	txt.setStyle(Text::Bold | Text::Underlined);
}

/*########################################################################################*/

/* Exemple de fenetre Basique:
	//Création de la fenetre avec taille et titre
	Window window;
	window.create(VideoMode(800, 600), "Mon Titre");

	//Modification du tritre
	window.setTitle("Titre Modifié");
*/