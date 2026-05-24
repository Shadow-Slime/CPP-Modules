#include "header.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	if (!argv[2][0])
	{
		std::cerr << "s1 cannot be empty" << std::endl;
		return 1;
	}

	std::fstream file;
	std::fstream newfile;

	file.open(argv[1], std::ios::in);
	if (!file)
	{
		std::cerr << "Error opening first file" << std::endl;
		return 1;
	}
	std::string newname = argv[1];
	newname = "replaced_" + newname;
	newfile.open(newname.c_str(), std::ios::out);
	if (!newfile)
	{
		file.close();
		std::cerr << "Error opening second file" << std::endl;
		return 1;
	}
	find_and_replace(file, newfile, argv[2], argv[3]);
	file.close();
	newfile.close();
	return 0;
}

/* test text for the word bee
According to all known laws of aviation, there is no way that a bee should be able to fly.
Its wings are too small to get its fat little body off the ground.
The bee, of course, flies anyways.
Because bees don't care what humans think is impossible.
*/
