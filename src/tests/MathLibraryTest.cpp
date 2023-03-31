
#include "gtest/gtest.h"

#include "../MathLibrary.h"

#include <math.h>

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

TEST_F(MathLibraryTest, testClearCurrentValue) {
    m->setCurrentValue(5);
    m->clearCurrentValue();
    // 0 is the default state
    EXPECT_EQ(0, m->getCurrentValue());
}

TEST_F(MathLibraryTest, testClearState) {
    m->setCurrentValue(5);
    m->add();
    m->clearState();
    EXPECT_EQ(0, m->getCurrentValue());
    EXPECT_EQ(0, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testSetCurrentValue) {
    m->clearCurrentValue();
    m->setCurrentValue(5);
    EXPECT_EQ(5, m->getCurrentValue());
}

TEST_F(MathLibraryTest, testAdd) {
    m->clearCurrentValue();
    m->setCurrentValue(5);
    m->setCurrentValue(5);
    m->add();
    EXPECT_EQ(10, m->getPreviousResult());
    m->setCurrentValue(10);
    m->add();
    EXPECT_EQ(20, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testSubtract) {
    m->clearCurrentValue();
    m->setCurrentValue(5);
    m->setCurrentValue(5);
    m->subtract();
    EXPECT_EQ(0, m->getPreviousResult());
    m->setCurrentValue(10);
    EXPECT_EQ(-10, m->getCurrentValue());
}
TEST_F(MathLibraryTest, testMultiply) {
    m->clearCurrentValue();
    m->setCurrentValue(5);
    m->setCurrentValue(5);
    m->multiply();
    EXPECT_EQ(25, m->getPreviousResult());
    m->setCurrentValue(10);
    m->multiply();
    EXPECT_EQ(250, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testDivide) {
    m->clearCurrentValue();
    m->setCurrentValue(20);
    m->setCurrentValue(4);
    m->divide();
    EXPECT_EQ(5, m->getPreviousResult());
    m->setCurrentValue(5);
    m->divide();
    EXPECT_EQ(1, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculateFactorial) {
    m->clearCurrentValue();
    m->setCurrentValue(5);
    m->calculateFactorial();
    EXPECT_EQ(120, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculatePower) {
    m->clearCurrentValue();
    m->setCurrentValue(2);
    m->calculatePower();
    EXPECT_EQ(4, m->getPreviousResult());
    m->setCurrentValue(3);
    m->calculatePower();
    EXPECT_EQ(64, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculateRoot) {
    m->clearCurrentValue();
    m->setCurrentValue(729);
    m->calculateRoot();
    EXPECT_EQ(27, m->getPreviousResult());
    m->setCurrentValue(3);
    m->calculateRoot();
    EXPECT_EQ(3, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculateSin){
    m->clearCurrentValue();
    m->switchToDegrees();
    m->setCurrentValue(90);
    m->calculateSin();
    EXPECT_EQ(1, m->getPreviousResult());
    m->switchToRadians();
    m->setCurrentValue(M_PI / 2);
    m->calculateSin();
    EXPECT_EQ(1, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculateCos){
    m->clearCurrentValue();
    m->switchToDegrees();
    m->setCurrentValue(0);
    m->calculateCos();
    EXPECT_EQ(1, m->getPreviousResult());
    m->switchToRadians();
    m->setCurrentValue(M_PI);
    m->calculateCos();
    EXPECT_EQ(-1, m->getPreviousResult());
    m->setCurrentValue(M_PI / 2);
    m->calculateCos();
    EXPECT_EQ(0, m->getPreviousResult());
}

TEST_F(MathLibraryTest, testCalculateTan){
    m->clearCurrentValue();
    m->switchToDegrees();
    m->setCurrentValue(45);
    m->calculateTan();
    EXPECT_EQ(1, m->getPreviousResult());
    m->setCurrentValue(60);
    m->calculateTan();
    EXPECT_EQ(sqrt(3), m->getPreviousResult());
    m->switchToRadians();
    m->setCurrentValue(M_PI / 4);
    m->calculateTan();
    EXPECT_EQ(1, m->getPreviousResult());
    m->setCurrentValue(M_PI / 3);
    m->calculateTan();
    EXPECT_EQ(sqrt(3), m->getPreviousResult());
}
