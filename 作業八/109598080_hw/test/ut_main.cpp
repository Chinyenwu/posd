#include <gtest/gtest.h>
#include "ut_app.h"
#include "ut_folder.h"
#include "ut_iterator.h"
#include "ut_utility.h"
#include "ut_visitor.h"
#include "ut_node_scanner.h"
//#include "ut_node_builder.h"
//#include "ut_node_parser.h"


int main(int argc, char ** argv) {
    /*std::cout << int('a') << "\n";
    std::cout << int('z') << "\n";
    std::cout << int('A') << "\n";
    std::cout << int('Z') << "\n";
    std::cout << int('0') << "\n";
    std::cout << int('9') << "\n";
    std::cout << int('.') << "\n";
    std::cout << int(',') << "\n";*/
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
