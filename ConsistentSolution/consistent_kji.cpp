#include "../GridReader/grid_reader.h"
#include <fstream>
#include <chrono>
#include <iomanip>

int main(int argc, char*argv[])
{
	//reading msh file
	std::ifstream in_file;
	in_file.open("./grids/cube.msh");
	if (!in_file)
	{
		std::cerr << "Error: Current file doesn't exists\n";
		return 1;
	}
	GR::msh3d xc;
	GR::msh3d yc;
	GR::msh3d zc;
	GR::read_and_allocate_grid(xc, yc, zc, in_file);
	in_file.close();
	
	//Perform shift
	auto start = std::chrono::system_clock::now();
	double x_shift = 1.0;
	double y_shift = 2.0;
	double z_shift = 3.0;
	size_t x_size = xc.size();
	size_t y_size = xc[0].size();
	size_t z_size = xc[0][0].size();
	for (size_t k = 0; k < z_size; ++k)
	{
		for (size_t j = 0; j < y_size; ++j)
		{
			for (size_t i = 0; i < x_size; ++i)
			{
				xc[i][j][k] += x_shift;
				yc[i][j][k] += y_shift;
				zc[i][j][k] += z_shift;
			}
		}
	}
	auto end = std::chrono::system_clock::now();

	//Computational time calculating
	std::chrono::duration<double> elapsed = end - start;
	std::cout << std::scientific << std::setprecision(11);
	std::cout << "Computational time: " << elapsed.count() << " s\n";

	//std::ofstream out_file("./grids/cube_new.msh");
	//GR::write_grid(xc, yc, zc, out_file);
	//out_file.close();

	return 0;
}
