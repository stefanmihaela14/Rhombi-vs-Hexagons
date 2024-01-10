#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"
#include <math.h>

using namespace object2D;

Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangular(const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill) 
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(0.75 * length, 0, 0), color),
        VertexFormat(corner + glm::vec3(0.75 * length, 3.5 * length, 0), color),
        VertexFormat(corner + glm::vec3(0, 3.5 * length, 0), color)
    };

    Mesh* rectangular = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangular->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangular->InitFromData(vertices, indices);
    return rectangular;
}

Mesh* object2D::CreateRomb(const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;
    int z = 1.5;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, z), color),
        VertexFormat(corner + glm::vec3(-1 * 0.25 * length, 0, z), color),  
        VertexFormat(corner + glm::vec3(0, -1 * 0.5 * length, z), color),               
        VertexFormat(corner + glm::vec3(0.25 * length, 0, z), color),   
        VertexFormat(corner + glm::vec3(0, 0.5 * length, z), color),           

        VertexFormat(corner + glm::vec3(0.05 * length, -1 * 0.15 * length, z), color),    
        VertexFormat(corner + glm::vec3(0.05 * length, 0.15 * length, z), color),    
        VertexFormat(corner + glm::vec3(0.5 * length, 0.15 * length, z), color),   
        VertexFormat(corner + glm::vec3(0.5 * length, -1 * 0.15 * length, z), color)   
    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = {
                                        0,1,2,
                                        0,2,3,
                                        0,3,4,
                                        0,4,1,
                                        3,5,8,
                                        3,8,7,
                                        3,7,6
                                        
    };

    if (!fill) {
        romb->SetDrawMode(GL_TRIANGLES);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);

    }

    romb->InitFromData(vertices, indices);
    return romb;;
}

Mesh* object2D::CreateStar(const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    int z = 4;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0.675 * length , z), color),  
        VertexFormat(corner + glm::vec3(-1 * 0.4 * length, -1 * 0.5 * length, z), color),           
        VertexFormat(corner + glm::vec3(0 * length, -1 * 0.25 * length, z), color),    
        VertexFormat(corner + glm::vec3(0.4 * length, -1 * 0.5 * length, z), color),          
        VertexFormat(corner + glm::vec3(0.675 * length, 0.25 * length, z), color),    
        VertexFormat(corner + glm::vec3(-1 * 0.675 * length, 0.25 * length, z), color),   

    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = {
                                        0, 1, 2,
                                        2, 3, 0,
                                        2, 4, 5
    };

    if (!fill) {
        romb->SetDrawMode(GL_TRIANGLES);
    }

    romb->InitFromData(vertices, indices);
    return romb;;
}

Mesh* object2D::CreateHeart(const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0.5 * length, 0.75 * length , 0), color),   
        VertexFormat(corner + glm::vec3(0.25 * length, length, 0), color),   
        VertexFormat(corner + glm::vec3(0, length, 0), color),   
        VertexFormat(corner + glm::vec3(0, 0.5 * length, 0), color), 
        VertexFormat(corner + glm::vec3(0.5 * length, 0, 0), color), 
        VertexFormat(corner + glm::vec3( length, 0.5 * length, 0), color),   
        VertexFormat(corner + glm::vec3( length, length, 0), color),   
        VertexFormat(corner + glm::vec3(0.75 * length, length, 0), color),   
        VertexFormat(corner + glm::vec3(length, 0.85 * length, 0), color),   
        VertexFormat(corner + glm::vec3(0.85 * length, length, 0), color),    
        VertexFormat(corner + glm::vec3(0.15 * length, length, 0), color),    
        VertexFormat(corner + glm::vec3(0, 0.85 * length, 0), color),    
    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = {
                                        0, 3, 4,
                                        0, 4, 5,
                                        0, 5, 7,
                                        5, 8, 7,
                                        8, 9, 7,
                                        3, 0, 1,
                                        3, 1, 11,
                                        11, 1, 10
    };

    if (!fill) {
        romb->SetDrawMode(GL_TRIANGLES);
    }

    romb->InitFromData(vertices, indices);
    return romb;;
}

Mesh* object2D::CreateHexagon(const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    glm::vec3 inner_color,
    bool fill)
{
    glm::vec3 corner = center;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 1), color),   
        VertexFormat(corner + glm::vec3(0, length, 1), color),   
        VertexFormat(corner + glm::vec3(-1 * sin(3.14 / 3) * length, length / 2, 1), color),    
        VertexFormat(corner + glm::vec3(-1 * sin(3.14 / 3) * length, -1 * 0.5 * length, 1), color), 
        VertexFormat(corner + glm::vec3(0, -1 * length, 1), color),   
        VertexFormat(corner + glm::vec3(sin(3.14 / 3) * length, -1 * length / 2, 1), color),    
        VertexFormat(corner + glm::vec3(sin(3.14 / 3) * length, length / 2, 1), color),   

        VertexFormat(corner + glm::vec3(0, 0, 2), inner_color),   
        VertexFormat(corner + glm::vec3(0, length / 2, 2), inner_color),  
        VertexFormat(corner + glm::vec3(-1 * sin(3.14 / 3) * length / 2, length / 4, 2), inner_color),   
        VertexFormat(corner + glm::vec3(-1 * sin(3.14 / 3) * length / 2, -1 * 0.5 * length / 2, 2), inner_color), 
        VertexFormat(corner + glm::vec3(0, -1 * length / 2, 2), inner_color),    
        VertexFormat(corner + glm::vec3(sin(3.14 / 3) * length / 2, -1 * length / 4, 2), inner_color),    
        VertexFormat(corner + glm::vec3(sin(3.14 / 3) * length / 2, length / 4, 2), inner_color),   
    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = {
                                            0, 1, 2,
                                            0, 2, 3,
                                            0, 3, 4,
                                            0, 4, 5,
                                            0, 5, 6,
                                            0, 6, 1,

                                            7, 8, 9,
                                            7, 9, 10,
                                            7, 10, 11,
                                            7, 11, 12,
                                            7, 12, 13,
                                            7, 13, 8

    };

    if (!fill) {
        romb->SetDrawMode(GL_TRIANGLES);
    }


    romb->InitFromData(vertices, indices);
    return romb;;
}