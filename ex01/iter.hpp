/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:42 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 15:48:18 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* array, const size_t length, void (*func)(T&)){
    for (size_t i = 0; i < length; i++){ // const size_t i = 0; i < length; i++
        func(array[i]);
    }
}
template <typename T>
void iter(const T* array, const size_t length, void (*func)(const T&)){
    for (size_t i = 0; i < length; i++){ // const size_t i = 0; i < length; i++
        func(array[i]);
    }
}

template <typename T>
void print_int(const T& value){
    std::cout << value << std::endl;
}

template <typename T>
void print_string(const T& value){
    std::cout << value << std::endl;
}

#endif