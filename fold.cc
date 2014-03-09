#include <iostream>
#include <vector>

struct Entity
{
	int key;
	
	bool operator==(Entity const & other) const
	{
		return key == other.key;
	}
};

typedef std::vector<Entity> Entities;
typedef std::vector<Entities> FoldedEntities;

FoldedEntities fold(Entities const & entities)
{
	std::vector<bool> visited(entities.size(), false);

	FoldedEntities result;
	Entity const * example = 0;

	if (entities.empty()) {
		return result;
	}

	bool complete = false;
	while (complete) {
		complete = true;
		example = 0;

		for (size_t i = 0; i < entities.size(); ++i) {
			if (!visited[i]) {
				complete = false;
				if (example == 0) {
					result.push_back(Entities());
					example = &entities[i];

					visited[i] = true;
					result.back().push_back(entities[i]);
				} else {
					if (*example == entities[i]) {
						visited[i] = true;
						result.back().push_back(entities[i]);
					}
				}
			}
		}
	}

	return result;
}

int main()
{
	return 0;
}