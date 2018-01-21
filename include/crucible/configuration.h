#ifndef CRUCIBLE_CONFIGURATION_H

#include <string>

namespace crucible {
	namespace Configuration {
		using namespace std;

		/* File is a in-memory representation of a configuration file,
		 * tokenized with the basic syntax checks done. It understands the
		 * basic structure of configuration sections and does nothing with
		 * the data yet. In a second pass, these sections will then be used
		 * to initialize the parsed configuration.
		 */
		class File {
			string m_path;
			bool m_valid = false;
		public:
			File(const string path);
			~File();
			bool valid();
		};
	}
}

#define CRUCIBLE_CONFIGURATION_H
#endif
