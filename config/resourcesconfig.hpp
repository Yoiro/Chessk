#ifndef RESOURCESCONFIG_HPP
#define RESOURCESCONFIG_HPP

#include "Configuration.hpp"
#include "res/ResourceManager.hpp"

namespace chesspp{
    namespace config {
        class RessourcesConfig: public Configuration{
            res::ResourceManager res;
        public:
            RessourcesConfig(): Configuration{"config/chesspp/ressources.json"},
                res{*this}
            {}
            res::ResourceManager& resources() noexcept{
                return res;
            }
        };
    }
}


#endif // RESOURCESCONFIG_HPP
