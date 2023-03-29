
#include "gtest/gtest.h"

#include "../MathLibrary.h"

// fixture class
class MathLibraryTest : public ::testing::Test {
protected:
    // setup
    virtual void SetUp() {
        // initialize
        m = new MathLibrary();
    }
    MathLibrary *m;
};

// test case
TEST_F(MathLibraryTest, testClearCurrentValue) {
    // set current value
    m->setCurrentValue(5);
    // clear current value
    m->clearCurrentValue();
    // check if current value is 0
    EXPECT_EQ(0, m->getCurrentValue());
}