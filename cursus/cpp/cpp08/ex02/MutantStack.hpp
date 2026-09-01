/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/06/09 13:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        // Canonical Orthodox Form
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        // Typedefs for short exposure of iterators from base container
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Exposed iteration methods
        iterator                begin();
        iterator                end();
        const_iterator          begin() const;
        const_iterator          end() const;
        
        reverse_iterator        rbegin();
        reverse_iterator        rend();
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

#include "MutantStack.tpp"

#endif
