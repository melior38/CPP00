/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:21:47 by asouchet          #+#    #+#             */
/*   Updated: 2023/12/19 15:38:06 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(),
{
	for (int i = 0; i < 4; i++)
		this->_src[i] = NULL;
}


MateriaSource::MateriaSource(MateriaSource const &ref) : IMateriaSource(ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_src[i])
		{
			delete this->_src[i];
			this->_src[i] = NULL;
		}
		if (ref._src[i])
		{
			if (ref._src[i]->getType() == "ice")
				this->_src[i] = new ice();
			else if (ref._src[i]->getType() == "cure")
				this->_src[i] = new cure();
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_src[i])
		{
			delete this->_src[i];
			this->_src[i] = NULL;
		}
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_src[i])
		{
			delete this->_src[i];
			this->_src[i] = NULL;
		}
		if (ref._src[i])
		{
			if (ref._src[i]->getType() == "ice")
				this->_src[i] = new ice();
			else if (ref._src[i]->getType() == "cure")
				this->_src[i] = new cure();
		}
	}
	return *this;
}

virtual void	learnMateria(AMateria *m)
{

}

virtual AMateria*	createMateria(std::string const &type)
{

}

