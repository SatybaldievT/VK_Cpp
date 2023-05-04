#include <gtest/gtest.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "Octree.h"

TEST(OctreeTest, InsertAndQuery)
{
    CompactOctree<int> octree;

    // Insert a value at a specific position
    glm::vec3 position(1.0f, 2.0f, 3.0f);
    int value = 42;
    octree.insert(position, value);

    // Query the value at the same position
    int result;
    ASSERT_TRUE(octree.query(position, result));
    EXPECT_EQ(value, result);

    // Query a value at a different position
    glm::vec3 other_position(4.0f, 5.0f, 6.0f);
    ASSERT_FALSE(octree.query(other_position, result));
}

TEST(OctreeTest, Delete)
{
    CompactOctree<int> octree;

    // Insert some values
    glm::vec3 position1(1.0f, 2.0f, 3.0f);
    int value1 = 42;
    octree.insert(position1, value1);

    glm::vec3 position2(4.0f, 5.0f, 6.0f);
    int value2 = 84;
    octree.insert(position2, value2);

    // Delete the octree
    octree.~CompactOctree();

    // Check that the nodes have been deleted
    OctreeNode *root = octree.root;
    ASSERT_EQ(root, nullptr);
}

TEST(OctreeTest, Trace)
{
    CompactOctree<int> octree;

    // Insert some values
    glm::vec3 position1(1.0f, 2.0f, 3.0f);
    int value1 = 42;
    octree.insert(position1, value1);

    glm::vec3 position2(4.0f, 5.0f, 6.0f);
    int value2 = 84;
    octree.insert(position2, value2);

    // Create a ray
    glm::vec3 ray_origin(0.0f, 0.0f, 0.0f);
    glm::vec3 ray_direction(1.0f, 1.0f, 1.0f);
    Ray ray(ray_origin, ray_direction);

    // Trace the octree
    glm::vec3 cube_center(0.0f, 0.0f, 0.0f);
    float size = 10.0f;
    glm::vec3 result = octree.trace(ray, cube_center, size);

    // Check the result
    glm::vec3 expected_result(1.0f, 1.0f, 1.0f);
    ASSERT_EQ(result, expected_result);
}
