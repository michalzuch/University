#include <vector>
#include <unordered_map>
#include <iostream>
#include "Dict.hpp"

// Compress file to .LZW archive
void encode(std::string file) {
    std::cout << "Compressing " << file << "..." << std::endl;
    std::string input_sequence;
    std::string output_file = file + "_compressed.LZW";
    
    // Import data from selected file
    std::ifstream file_to_compress;
    file_to_compress.open(file, std::fstream::in);

    std::string input;
    while (std::getline(file_to_compress, input)) {
        input_sequence += input;
        input_sequence += '\n';
    }
    input_sequence.pop_back();

    // Create default table
    Dict<std::string, int> table;
    for (int i = 0; i <= 255; i++) {
        std::string character = "";
        character += char(i);
        table.insert(std::make_pair(character, i));
    }

    // Get first character
    std::string c;
    std::string s;
    c += input_sequence[0];

    int code = 256;
    std::vector<int> output;
    for (int i = 0; i < input_sequence.length(); i++) {
        if (i != input_sequence.length() - 1) {
            s += input_sequence[i + 1];
        }

        // If table does not contain c + s add it, else check c + c + s
        if (table.find(c + s)) {
            c += s;
        } else {
            output.push_back(table[c]);
            table[c + s] = code;
            code++;
            c = s;
        }
        s = "";
    }
    output.push_back(table[c]);

    // Save results to file
    std::ofstream fileOut(output_file);
    for (int i: output)
        fileOut << i << " ";

    // Close the files
    file_to_compress.close();
    fileOut.close();

    std::cout << "File " << file << " compressed to " << output_file << "." << std::endl;
}

// Decompress file from .LZW archive
void decode(std::string file) {
    std::cout << "Decompressing " << file << "..." << std::endl;
    std::vector<int> vector_sequence;
    std::string output_file = file + "_decompressed.txt";

    // Import data from selected file
    std::ifstream file_to_decompress;
    file_to_decompress.open(file, std::fstream::in);

    int input;
    while (file_to_decompress >> input)
        vector_sequence.push_back(input);

    // Create default table
    Dict<int, std::string> table;
    for (int i = 0; i <= 255; i++) {
        std::string character;
        character += char(i);
        table.insert(std::make_pair(i, character));
    }


    int num1 = vector_sequence[0];
    int num2;
    std::string pk = table[num1];
    std::string pc;
    std::string output;
    pc += pk[0];
    output += pk;
    
    int count = 256;
    for (int i = 0; i < vector_sequence.size() - 1; i++) {
        num2 = vector_sequence[i + 1];
        if (!table.find(num2)) {
            pk = table[num1];
            pk += pc;
        } else {
            pk = table[num2];
        }
        output += pk;
        pc = "";
        pc += pk[0];
        table[count] = table[num1] + pc;
        count++;
        num1 = num2;
    }

    // Save results to file
    std::ofstream fileOut(output_file);
    fileOut << output;

    // Close the files
    file_to_decompress.close();
    fileOut.close();

    std::cout << "File " << file << " decompressed to " << output_file  << "." << std::endl;
}

// Show usage instructions
void help() {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "-------------- Lempel-Ziv-Welch Compressor --------------" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "  compress file                                          " << std::endl;
    std::cout << "      example: ./LZW.x compress file.txt                 " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "  decompress file                                        " << std::endl;
    std::cout << "      example: ./LZW.x decompress file.txt_compressed.LZW" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "  help                                                   " << std::endl;
    std::cout << "      example: ./LZW.x help                              " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}