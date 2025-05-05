#include "../include/param.hpp"
#include "../include/ComputerClub.hpp"
#include "../include/Time.hpp"
#include "../include/Parser.hpp"

int main(int argc, char* argv[]) {
    
    string filename(argv[1]);
    ComputerClub club;


    try {
        check_param(argc, argv);
        club = Parser::parser(filename);

    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    club.process_event();

    Time time(1, 3);

    return EXIT_SUCCESS;



}