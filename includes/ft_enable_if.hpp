#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include <iostream>

namespace ft
{
	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };
}

#endif 

/* SFINAE : Substitution Failure is not an Error
L'échec de la substitution n'est pas une erreur fait référence à une situation en C++ où une 
substitution non valide de paramètres de modèle n'est pas en soi une erreur.
*/