
#pragma once

#include <memory>
#include "Table.hpp"

class Room
{
private:
	/* data */
public:
	Room(std::unique_ptr<Table> tables);
	~Room();
};
