/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** OpenLib
*/

#ifndef OPENLIB_HPP_
#define OPENLIB_HPP_
#include "../interfaces/IGraphical.hpp"
#include <dlfcn.h>
#include <memory>
#include <vector>

namespace Arcade {

    class OpenLib {
        public:
            OpenLib(const std::string &libName);
            ~OpenLib();
            const std::unique_ptr<IGraphical> &getLib();


        protected:
        private:
            std::shared_ptr<void> handle;
            std::unique_ptr<IGraphical> ptr;
    };
}

#endif /* !OPENLIB_HPP_ */
