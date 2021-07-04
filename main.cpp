
#include <iostream>
#include <string>

#include <json.hpp>
using json = nlohmann::json;

#include "Player.hpp"

int main(int argc, char const *argv[])
{

	// Player jojo("jojo", "dubois", Level::competitive);

	// json jjj = jojo.toJson();

	// Player jaja(jjj["name"].get<std::string>(), jjj["surname"].get<std::string>(), getLevelFromStr(jjj["level"].get<std::string>()));

	// Player juju(jjj);

	// std::cout << jjj.dump(2) << std::endl;
	// std::cout << getLevelFromStr(jjj["level"].get<std::string>()) << std::endl;
	// std::cout << jaja.toJson().dump(2) << std::endl;
	// std::cout << juju.toJson().dump(2) << std::endl;

    // Here is a JSON text
    std::string text = R"(
    {
        "Book": {
            "Width":  450,
            "Height": 30,
            "Title":  "Hello World",
            "isBiography": false,
            "NumOfCopies": 4,
            "LibraryIDs": [2319, 1406, 3854, 987]
        }
    }
    )";

    // Let's parse and serialize JSON
    json j_complete = json::parse(text);
    std::cout  << j_complete.dump(4) << std::endl;


	return 0;
}
