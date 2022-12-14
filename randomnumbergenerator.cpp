#include "randomnumbergenerator.h"

#include <random>

RandomNumberGenerator::RandomNumberGenerator(){}

double RandomNumberGenerator::generate_random_number(double min, double max)
{
    std:: random_device rd;
    std:: mt19937 gen(rd());
    std:: uniform_real_distribution<> dis(min, max);

    return dis(gen);
}
