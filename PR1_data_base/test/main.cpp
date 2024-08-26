// // main.cpp
// #include <iostream>
// #include <getopt.h>

// int main(int argc, char *argv[]) {
//     // Определяем длинные опции
//     static struct option long_options[] = {
//         {"add",    no_argument,       0,  'a' },
//         {"append", required_argument, 0,  'b' },
//         {"delete", required_argument, 0,  'c' },
//         {"verbose", no_argument,      0,  'v' },
//         {"create", required_argument, 0,  'd' },
//         {"file",   required_argument, 0,  'f' },
//         {0,        0,                 0,  0   }
//     };

//     int option_index = 0;
//     int option;

//     while ((option = getopt_long(argc, argv, "ab:c:d:f:", long_options, &option_index)) != -1) {
//         switch (option) {
//             case 'a':
//                 std::cout << "Option add" << std::endl;
//                 break;
//             case 'b':
//                 std::cout << "Option append with value: " << optarg << std::endl;
//                 break;
//             case 'c':
//                 std::cout << "Option delete with value: " << optarg << std::endl;
//                 break;
//             case 'v':
//                 std::cout << "Option verbose" << std::endl;
//                 break;
//             case 'd':
//                 std::cout << "Option create with value: " << optarg << std::endl;
//                 break;
//             case 'f':
//                 std::cout << "Option file with value: " << optarg << std::endl;
//                 break;
//             case '?':
//                 std::cerr << "Unknown option: " << option << std::endl;
//                 return 1;
//             default:
//                 break;
//         }
//     }
//     return 0;
// }

//g++ main.cpp -o GetoptLongExample
//GetoptLongExample.exe --add --append=value1 --delete=value2 --verbose --create=value3 --file=value4
