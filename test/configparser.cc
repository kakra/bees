#define BEES_CONFIG_FILE "fixtures/valid-bees.conf"

#include "tests.h"

#include "crucible/configuration.h"

#include <cassert>

using namespace crucible;

static
void
test_invalid_configuration()
{
	Configuration::File config("fixtures/invalid-bees.conf");
	assert(config.valid() == false);
}

static
void
test_valid_configuration()
{
	Configuration::File config(BEES_CONFIG_FILE);
	assert(config.valid() == true);
}

int main(int, const char **)
{
	RUN_A_TEST(test_invalid_configuration());
	RUN_A_TEST(test_valid_configuration());

	exit(EXIT_SUCCESS);
}
