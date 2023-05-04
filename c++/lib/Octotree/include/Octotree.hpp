#pragma once
#include <glm/vec3.hpp>


struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;

    Ray(const glm::vec3& origin, const glm::vec3& direction)
        : origin(origin), direction(direction) {}
};

template <typename T>
class CompactOctree
{
public:
    CompactOctree();
    ~CompactOctree();

    void insert(const glm::vec3& position, const T& value);
    bool query(const glm::vec3& position, T& result) const;
    glm::vec3 trace(const Ray& ray) const;

private:
    struct OctreeNode
    {
        glm::vec3 center;
        glm::vec3 half_size;
        OctreeNode* children[8] = { nullptr };
        bool is_leaf = true;
        T value;
    };
    OctreeNode* root = nullptr;
    size_t node_count = 0;

    void insert(OctreeNode* node, const glm::vec3& position, const T& value);
    bool query(const OctreeNode* node, const glm::vec3& position, T& result) const;
    void delete_node(OctreeNode* node);

    int intersect_cube(const Ray& ray, const glm::vec3& cube_center, const float size) const;
    glm::vec3 trace(OctreeNode* node, const Ray& ray, const glm::vec3& cube_center, const float size) const;
};
