#include "gtest/gtest.h"
#include "world.h"

TEST(BuildVectorOfAntPointers,GivenAVectorToStore3DVectors_WhenProgramStartsUp_ExpectAVectorOf3DVectors)
{
    World world;

    double numberOfAnts{0};

    std::vector<double> valuesFromVectorOfAnts;
    std::vector<double> GOLDvaluesOfAntPostions;

    numberOfAnts=world.get_number_of_ants();

    for(int i{0}; i<numberOfAnts;i++)
    {
        GOLDvaluesOfAntPostions.push_back(0);
        GOLDvaluesOfAntPostions.push_back(0);
        GOLDvaluesOfAntPostions.push_back(0);
    }

    for(const Ant& a: world.get_ants())
    {
        const Vector3D& postion=a.get_postion();
        valuesFromVectorOfAnts.push_back(postion[0]);
        valuesFromVectorOfAnts.push_back(postion[1]);
        valuesFromVectorOfAnts.push_back(postion[2]);
    }

    EXPECT_EQ(GOLDvaluesOfAntPostions,valuesFromVectorOfAnts);
}
