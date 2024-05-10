/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-tekspice-axel.petitjean
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <exception>
#include "iostream"

namespace Arcade {
    class Error : public std::exception {
        public:
            Error(const std::string &error);
            const char* what() const noexcept override;
        private:
            std::string _error;

    };
}
#endif /* !ERROR_HPP_ */
