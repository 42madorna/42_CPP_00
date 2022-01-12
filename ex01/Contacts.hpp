/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:39:53 by madorna-          #+#    #+#             */
/*   Updated: 2022/01/12 05:40:21 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contact class prototype
*/

class Contacts{
	public:
		int idx;
		std::string f_name;
		std::string l_name;
		std::string nickname;
		uint64_t phone;
		std::string d_secret;
};