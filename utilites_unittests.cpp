#include "gtest/gtest.h"
#include "utilities.h"

TEST(RotateVectorTests,GivenA3DVector_WhenAskedToRotateA3DVector_ExpectAVectorRotatedByAnAngle)
{
    Utilities utilities;

    double angleToRotate{.5};
    const Vector3D startingOrention{0,1,0};
    const Vector3D GOLDorentionVectorRotated{-.479,.878,0};
    Vector3D rotated3dVector{0,0,0};

    rotated3dVector=utilities.rotate_vector(angleToRotate,startingOrention);

    EXPECT_NEAR(GOLDorentionVectorRotated[0],rotated3dVector[0],1e-3);
    EXPECT_NEAR(GOLDorentionVectorRotated[1],rotated3dVector[1],1e-3);
    EXPECT_NEAR(GOLDorentionVectorRotated[2],rotated3dVector[2],1e-3);
}

TEST(FoodAndAntLocationInUtilies,GivenATwo3DVectors_WhenCheckingToSeeIfTheyAreTheExcatlySame_ExpectBoolForIfTheyMatchToBeTrue)
{
    Utilities utilities;

    const Vector3D antPostion(1,1,1);
    const Vector3D foodPostion(1,1,1);

    bool doesTheAntHaveFood{false};

    doesTheAntHaveFood=utilities.check_range(antPostion,foodPostion);

    EXPECT_TRUE(doesTheAntHaveFood);
}

TEST(FoodAndAntLocationInUtilies,GivenATwo3DVectors_WhenCheckingToSeeIfTheyNearlyTheSame_ExpectBoolForIfTheyMatchToBeTrue)
{
    Utilities utilities;

    const Vector3D antPostion(1,1,1);
    const Vector3D foodPostion(.95,.95,1);

    bool doesTheAntHaveFood{false};

    doesTheAntHaveFood=utilities.check_range(antPostion,foodPostion);

    EXPECT_TRUE(doesTheAntHaveFood);
}
