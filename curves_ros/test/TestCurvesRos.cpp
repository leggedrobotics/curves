/*!
 * @file        TestCurvesRos.cpp
 * @authors     Prajish Sankar (ANYbotics)
 * @brief       Tests for the curves_ros package.
 * @note        Contains just a dummy test.
 */

#include <gtest/gtest.h>
#include <ros/ros.h>

class TestCurvesRos : public ::testing::Test {
  void SetUp() override {
    const std::map<std::string, std::string> remappings{};
    ros::init(remappings, "curves_ros_test");
    ros::start();
  }

  void TearDown() override { ros::shutdown(); }
};

TEST_F(TestCurvesRos, DummyTest) {  // NOLINT
  ASSERT_TRUE(true);
}
