#ifndef _GRID_READER_H_
#define _GRID_READER_H_

#include <iostream>
#include <vector>

namespace GR
{
	typedef std::vector<std::vector<std::vector<double>>> msh3d;

	void allocate_msh3d( 
			     size_t x_size, 
			     size_t y_size, 
			     size_t z_size,
			     msh3d & xc,
			     msh3d & yc,
			     msh3d & zc
			   );


	void read_grid(
			msh3d & xc,
			msh3d & yc,
			msh3d & zc,
			std::istream & in = std::cin
		      );
	
	void read_and_allocate_grid(
				     msh3d & xc,
				     msh3d & yc,
				     msh3d & zc,
				     std::istream & in = std::cin
				   );

	void write_grid(
			const msh3d & xc,
			const msh3d & yc,
			const msh3d & zc,
			std::ostream & out = std::cout
		       );
}

#endif
