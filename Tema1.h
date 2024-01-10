#pragma once

#include "components/simple_scene.h"
#include <vector>

namespace m1
{
    class Romb {
    public:
        std::string color;
        bool keep_rendering;
        int id_color;
        int radius;
        float scaleX;
        float scaleY;

        Romb(std::string color, bool keep_rendering, int id_color, int radius, float scaleX, float scaleY) {
            this->color = color;
            this->keep_rendering = keep_rendering;
            this->id_color = id_color;
            this->radius = radius;
            this->scaleX = scaleX;
            this->scaleY = scaleY;
        }

    };

    class Grid_square {
    public:
        float left;
        float right;
        float bottom;
        float top;

        Grid_square(float left, float right, float bottom, float top) {
            this->left = left;
            this->right = right;
            this->bottom = bottom;
            this->top = top;
        }

    };

    class StarModel {
    public:
        std::string color;
        int random_X_coord; // centrul stelutei pe axa Ox
        int random_Y_coord; // centrul stelutei pe axa Oy
        int color_id;
        bool life_status;
        int radius;
        float scaleX;
        float scaleY;

        StarModel(std::string color, int random_X_coord, int random_Y_coord, int color_id, bool life_status, int radius, float scaleX, float scaleY) {
            this->color = color;
            this->random_X_coord = random_X_coord;
            this->random_Y_coord = random_Y_coord;
            this->color_id = color_id;
            this->life_status = life_status;
            this->radius = radius;
            this->scaleX = scaleX;
            this->scaleY = scaleY;
        }
    };

    class Hexagon {
    public:
        std::string color;
        int lives;
        int pos_hexagon_right;
        int pos_hexagon_bottom;
        int color_id;
        int radius;
        float scaleX;
        float scaleY;

        Hexagon(std::string color, int lives, int pos_hexagon_right, int pos_hexagon_bottom, int color_id, int radius, float scaleX, float scaleY) {
            this->color = color;
            this->lives = lives;
            this->pos_hexagon_right = pos_hexagon_right;
            this->pos_hexagon_bottom = pos_hexagon_bottom;
            this->color_id = color_id;
            this->radius = radius;
            this->scaleX = scaleX;
            this->scaleY = scaleY;
        }
    };

    class StarCollected {
    public:
        std::string color;
        int random_X_coord;
        int random_Y_coord;
        int color_id;
        bool life_status;
        int radius;

        StarCollected(std::string color, int random_X_coord, int random_Y_coord, int color_id, bool life_status, int radius) {
            this->color = color;
            this->random_X_coord = random_X_coord;
            this->random_Y_coord = random_Y_coord;
            this->color_id = color_id;
            this->life_status = life_status;
            this->radius = radius;
        }

    };

    class Heart {
    public:
        std::string color;
        int X_coord;
        int Y_coord;
        bool life_status;

        Heart(std::string color, int X_coord, int Y_coord, bool life_status) {
            this->color = color;
            this->X_coord = X_coord;
            this->Y_coord = Y_coord;
            this->life_status = life_status;
        }

    };

    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderMap();

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;
        bool ok;
        bool direction;
        float rotation = 0;
        float squareSide = 100;
        int initial_res_x;
        int initial_res_y;

        // rombul selectat pt drag&drop
        Romb* currentlySelectedRomb = NULL;
        float mouseX;
        float mouseY;
        float coord_romb_x;
        float coord_romb_y;

        Romb* grid_romb[3][3];
        Grid_square* grid_of_squares[3][3];
        
        float timeSinceLastStar = 0;
        //StarModel* currentlySelectedStar = NULL;
        std::vector<StarModel*> starForPoints;
        std::string star_color_possible;
        
        int pos_hex_right_curr = 0;
        float timeSinceLastHexagon = 0;
        Hexagon* currentlySelectedHexagon = NULL;
        std::vector<Hexagon*> hexagons;
        std::string hex_color_possible;
        int nr_of_hexagons = 0;
        int timeForSpawningAnotherHexagon = 5;

        int color_id_hex_curr = 0;
        int color_id_romb_curr = 0;
        
        std::vector<StarModel*> thrown_stars;
        float time_since_interval = 0;
        std::string thrown_star_color;
        std::vector<StarCollected*> collectedStars;

        std::vector<Heart*> hearts;
    };

}   // namespace m1
