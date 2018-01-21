#include "crucible/configuration.h"

namespace crucible::Configuration {

	File::File(const string path) :
		m_path(path), m_valid(false)
	{
		/* TODO(kakra): Implement me! */
	}

	File::~File()
	{
		/* FIXME(kakra): Maybe clean up */
	}

	bool
	File::valid()
	{
		return m_valid;
	}

}
