/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:25:45 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/21 15:46:45 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int array[] = {10, -29, -300, 42, 500};
    iter(array, 5, print_int<int>);
    std::string array_string[] = {"Hello", "World", "42", "CPP", "42"};
    iter(array_string, 5, print_string<std::string>);
    return 0;
}