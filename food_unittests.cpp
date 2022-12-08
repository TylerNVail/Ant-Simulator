#include "gtest/gtest.h"
#include "food.h"

TEST(SetupOfFood,GivenNothing_WhenAskedForAFoodPostionAtStartup_ExpectFoodPostionThatIsA3DVector)
{
    Food food;
    Vector3D vector;

    Vector3D GOLDpostion;
    Vector3D returnedPostionFromFood;

    returnedPostionFromFood=food.get_postion();

    EXPECT_EQ(GOLDpostion[0],returnedPostionFromFood[0]);
    EXPECT_EQ(GOLDpostion[1],returnedPostionFromFood[1]);
    EXPECT_EQ(GOLDpostion[2],returnedPostionFromFood[2]);
}
