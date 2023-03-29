
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
    m->setCurrentValue(5);
    m->clearCurrentValue();
    // 0 is the default state
    EXPECT_EQ(0, m->getCurrentValue());
}

// test case
TEST_F(MathLibraryTest, testClearState) {
    m->setCurrentValue(5);
    m->add();
    m->clearState();
    EXPECT_EQ(0, m->getCurrentValue());
    EXPECT_EQ(0, m->getPreviousResult());
}