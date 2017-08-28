#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "jsonreader.hpp"
#include <string>

namespace chesspp {
    namespace config{
        class Configuration{
        protected:
            static std::string executablePath();
            std::string res_path;
            util::JsonReader reader;
        private:
            std::string validateConfigFile(std::string const &configFile);
        public:
            Configuration(std::string const &configFile) noexcept(false);
            virtual ~Configuration() = default;

            template<typename... Path>
            auto setting(Path const &... path)
            ->decltype(reader.navigate(path...)){
                return reader.navigate(path...);
            }
        };
    }
}

#endif // CONFIGURATION_HPP
