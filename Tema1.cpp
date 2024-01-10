#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "transform2D.h"
#include "object2D.h"

using namespace std;
using namespace m1;
using namespace object2D;

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    static int screen_res_x = window->GetResolution().x; // 1280
    static int screen_res_y = window->GetResolution().y; // 720

    initial_res_x = window->GetResolution().x;
    initial_res_y = window->GetResolution().y;

    glm::vec3 corner = glm::vec3(0, 0, 0);

    cx = corner.x ;
    cy = corner.y ;

    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;

    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    // Initialize angularStep
    angularStep = 0;

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 0.5, 0), true);
    AddMeshToList(square1);
    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0.5, 0.5, 0.5));
    AddMeshToList(square2);

    // Bara rosie din grid
    Mesh* red_rectangular = object2D::CreateRectangular("red_rectangular", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(red_rectangular);

    // Mash-uri pt cele 4 tipuri de romburi
    // romb rosu
    Mesh* romb_rosu = object2D::CreateRomb("romb_rosu", corner, squareSide * 0.8, glm::vec3(1, 0, 0), true);
    AddMeshToList(romb_rosu);
    // romb albastru
    Mesh* romb_albastru = object2D::CreateRomb("romb_albastru", corner, squareSide * 0.8, glm::vec3(0, 0, 1), true);
    AddMeshToList(romb_albastru);
    // romb galben
    Mesh* romb_galben = object2D::CreateRomb("romb_galben", corner, squareSide * 0.8, glm::vec3(1, 1, 0), true);
    AddMeshToList(romb_galben);
    // romb mov
    Mesh* romb_mov = object2D::CreateRomb("romb_mov", corner, squareSide * 0.8, glm::vec3(0.8, 0, 0.8), true);
    AddMeshToList(romb_mov);

    Mesh* star = object2D::CreateStar("star", corner, squareSide * 0.20, glm::vec3(1, 1, 0.8), true);
    AddMeshToList(star);

    // Mash-uri pt stelutele proiectil
    Mesh* star_random_red = object2D::CreateStar("star_random_red", corner, squareSide * 0.5, glm::vec3(1, 0, 0), true);
    AddMeshToList(star_random_red);
    Mesh* star_random_blue = object2D::CreateStar("star_random_blue", corner, squareSide * 0.5, glm::vec3(0, 0, 1), true);
    AddMeshToList(star_random_blue);
    Mesh* star_random_yellow = object2D::CreateStar("star_random_yellow", corner, squareSide * 0.5, glm::vec3(1, 1, 0), true);
    AddMeshToList(star_random_yellow);
    Mesh* star_random_purple = object2D::CreateStar("star_random_purple", corner, squareSide * 0.5, glm::vec3(0.8, 0, 0.8), true);
    AddMeshToList(star_random_purple);

    // Mash-uri pt stelutele care apar random
    Mesh* star_random_green1 = object2D::CreateStar("star_random_green1", corner, squareSide * 0.5, glm::vec3(0.4, 1, 0.6), true);
    AddMeshToList(star_random_green1);
    Mesh* star_random_green2 = object2D::CreateStar("star_random_green2", corner, squareSide * 0.5, glm::vec3(0, 0.7, 0.23), true);
    AddMeshToList(star_random_green2);
    Mesh* star_random_green3 = object2D::CreateStar("star_random_green3", corner, squareSide * 0.5, glm::vec3(0, 0.2, 0.12), true);
    AddMeshToList(star_random_green3);
    Mesh* star_random_green4 = object2D::CreateStar("star_random_green4", corner, squareSide * 0.5, glm::vec3(0, 0.9, 0.54), true);
    AddMeshToList(star_random_green4);

    // Inima pt vieti
    Mesh* heart = object2D::CreateHeart("heart", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(heart);

    // Mash-uri hexagoane de 4 culori
    Mesh* hexagon_red = object2D::CreateHexagon("hexagon_red", corner, squareSide * 0.5, glm::vec3(1, 0, 0), glm::vec3(1, 1, 0.8), true);
    AddMeshToList(hexagon_red);
    Mesh* hexagon_blue = object2D::CreateHexagon("hexagon_blue", corner, squareSide * 0.5, glm::vec3(0, 0, 1), glm::vec3(1, 1, 0.8), true);
    AddMeshToList(hexagon_blue);
    Mesh* hexagon_yellow = object2D::CreateHexagon("hexagon_yellow", corner, squareSide * 0.5, glm::vec3(1, 1, 0), glm::vec3(1, 1, 0.8), true);
    AddMeshToList(hexagon_yellow);
    Mesh* hexagon_purple = object2D::CreateHexagon("hexagon_purple", corner, squareSide * 0.5, glm::vec3(0.8, 0, 0.8), glm::vec3(1, 1, 0.8), true);
    AddMeshToList(hexagon_purple);

    // initializam matricea pt a pastra romburile de pe grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            grid_romb[i][j] = NULL;
        }
    }

    // adaugam cele 3 vieti
    hearts.push_back(new Heart("heart", (screen_res_x / 2) + squareSide, screen_res_y - squareSide * 1.25, true));
    hearts.push_back(new Heart("heart", (screen_res_x / 2) + 2.5 * squareSide, screen_res_y - squareSide * 1.25, true));
    hearts.push_back(new Heart("heart", (screen_res_x / 2) + 4 * squareSide, screen_res_y - squareSide * 1.25, true));

    // adaugam in vector la inceputul fiecarui joc 3 stelute colectate
    collectedStars.push_back(new StarCollected("star", 6.5 * squareSide, screen_res_y - squareSide * 1.75, 0, true, squareSide / 2));
    collectedStars.push_back(new StarCollected("star", 6.5 * squareSide, screen_res_y - squareSide * 1.75, 0, true, squareSide / 2));
    collectedStars.push_back(new StarCollected("star", 6.5 * squareSide, screen_res_y - squareSide * 1.75, 0, true, squareSide / 2));

}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

}

void Tema1::RenderMap() {
    static int screen_res_x = window->GetResolution().x; // 1280
    static int screen_res_y = window->GetResolution().y; // 720

    // grid: 
    // dreptungi rosu:
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0.25 * squareSide);
    RenderMesh2D(meshes["red_rectangular"], shaders["VertexColor"], modelMatrix);

    // prima linie de patrate a grid-ului (linia de jos)
    for (int i = 1; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * 1.25 * squareSide, 0.25 * squareSide);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

        grid_of_squares[2][i - 1] = new Grid_square(i * 1.25 * squareSide, (i * 1.25 * squareSide) + squareSide, 0.25 * squareSide, 1.25 * squareSide);
    }

    // a doua linie din grid
    for (int i = 1; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * 1.25 * squareSide, 1.5 * squareSide);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

        grid_of_squares[1][i - 1] = new Grid_square(i * 1.25 * squareSide, i * 1.25 * squareSide + squareSide, 1.5 * squareSide, 2.5 * squareSide);
    }

    // a treia linie din grid
    for (int i = 1; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * 1.25 * squareSide, 2.75 * squareSide);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

        grid_of_squares[0][i - 1] = new Grid_square(i * 1.25 * squareSide, i * 1.25 * squareSide + squareSide, 2.75 * squareSide, 3.75 * squareSide);
    }

    // user interface:
    // chenare pt romburi
    for (int i = 0; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * squareSide * 1.5 + 0.5 * squareSide, screen_res_y - squareSide * 1.25);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
    }

    // romb rosu primul chenar:
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide, screen_res_y - 0.75 * squareSide);
    RenderMesh2D(meshes["romb_rosu"], shaders["VertexColor"], modelMatrix);

    // romb albastru chenarul 2:
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(2.5 * squareSide, screen_res_y - 0.75 * squareSide);
    RenderMesh2D(meshes["romb_albastru"], shaders["VertexColor"], modelMatrix);

    // romb galben chenarul 3:
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(4 * squareSide, screen_res_y - 0.75 * squareSide);
    RenderMesh2D(meshes["romb_galben"], shaders["VertexColor"], modelMatrix);

    // romb mov chenarul 4:
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(5.5 * squareSide, screen_res_y - 0.75 * squareSide);
    RenderMesh2D(meshes["romb_mov"], shaders["VertexColor"], modelMatrix);

    // stelute (de sub chenare):
    // prima steluta pt fiecare chenar cu romb
    for (int i = 0; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * squareSide * 1.5 + 0.65 * squareSide, screen_res_y - squareSide * 1.6);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }

    // a doua steluta pt chenareke 2, 3 so 4
    for (int i = 1; i <= 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i * squareSide * 1.5 + 0.95 * squareSide, screen_res_y - squareSide * 1.6);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }

    // a treia steluta pt chenarul 4
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 4.5 + 1.25 * squareSide, screen_res_y - squareSide * 1.6);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
}

void Tema1::Update(float deltaTimeSeconds)
{
    static int screen_res_x = window->GetResolution().x; // 1280
    static int screen_res_y = window->GetResolution().y; // 720
    static int diagonal_ok = 0;

    // deseneaza partea statica a jocului (grid-ul)
    RenderMap();

    // vietile logica si render
    for (Heart* heart : hearts) {
        if (heart->life_status == true && hearts.size() != 0) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(heart->X_coord, heart->Y_coord);
            RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
        }
    }

    // keep rendering the rhombs while you drag them around
    if (this->currentlySelectedRomb != NULL && this->currentlySelectedRomb->keep_rendering != false) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(mouseX, screen_res_y - mouseY);

        coord_romb_x = mouseX - (squareSide / 2);
        coord_romb_y = screen_res_y - mouseY - (squareSide / 2);

        if (this->currentlySelectedRomb->color == "red") {
            RenderMesh2D(meshes["romb_rosu"], shaders["VertexColor"], modelMatrix);
        }
        else if (this->currentlySelectedRomb->color == "albastru") {
            RenderMesh2D(meshes["romb_albastru"], shaders["VertexColor"], modelMatrix);
        }
        else if (this->currentlySelectedRomb->color == "galben") {
            RenderMesh2D(meshes["romb_galben"], shaders["VertexColor"], modelMatrix);
        }
        else {
            RenderMesh2D(meshes["romb_mov"], shaders["VertexColor"], modelMatrix);
        }

    }

    // logica aparitie hexagoane la intervale aleatoare 
    timeSinceLastHexagon += deltaTimeSeconds;

    if (timeSinceLastHexagon > timeForSpawningAnotherHexagon) {
        int random_nr_color_hex = static_cast <int> (rand()) / (static_cast <float> (RAND_MAX / (4 - 0)));
        timeForSpawningAnotherHexagon = 5 + (rand() % 5);

        if (random_nr_color_hex == 0) {
            hex_color_possible = "hexagon_red";
            color_id_hex_curr = 0;
        }
        else if (random_nr_color_hex == 1) {
            hex_color_possible = "hexagon_blue";
            color_id_hex_curr = 1;
        }
        else if (random_nr_color_hex == 2) {
            hex_color_possible = "hexagon_yellow";
            color_id_hex_curr = 2;
        }
        else if (random_nr_color_hex == 3) {
            hex_color_possible = "hexagon_purple";
            color_id_hex_curr = 3;
        }

        if (nr_of_hexagons < 12) {
            float y_rand = 0.25 * squareSide + (1.25 * squareSide) * (rand() % 3);

            hexagons.push_back(new Hexagon(hex_color_possible, 3, screen_res_x + squareSide / 2,
                y_rand, color_id_hex_curr, squareSide / 2, 1, 1));
        }
        timeSinceLastHexagon = 0;
    }

    // logica miscare si render stelute-proiectil
    angularStep += deltaTimeSeconds * 0.7;
    for (StarModel* star: thrown_stars) {
        if (star->life_status != false) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(star->random_X_coord, star->random_Y_coord);
            modelMatrix *= transform2D::Rotate(-1 * angularStep * 5);
            modelMatrix *= transform2D::Translate(cx, cy);
            star->random_X_coord += deltaTimeSeconds * 1.5 * squareSide;
            RenderMesh2D(meshes[star->color], shaders["VertexColor"], modelMatrix);
        }
    }

    // logica si render hexagoane
    std::vector<Hexagon*> hexagons_to_remove;
    for (Hexagon* hexagon : hexagons) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(hexagon->pos_hexagon_right - squareSide / 2, hexagon->pos_hexagon_bottom + squareSide / 2);
        // animatie de micsorare hexagon cand moare
        if (hexagon->lives == 0) {
            if (hexagon->scaleX > 0 && hexagon->scaleY > 0) {
                hexagon->scaleX -= 0.5 * deltaTimeSeconds;
                hexagon->scaleY -= 0.5 * deltaTimeSeconds;
            }
            modelMatrix *= transform2D::Scale(hexagon->scaleX, hexagon->scaleX);
        }
        RenderMesh2D(meshes[hexagon->color], shaders["VertexColor"], modelMatrix);
        hexagon->pos_hexagon_right -= deltaTimeSeconds * 0.5 * squareSide;

        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                if ((hexagon->pos_hexagon_right < screen_res_x && grid_romb[j][i] != NULL && hexagon->lives > 0) && hexagon->pos_hexagon_bottom == grid_of_squares[j][i]->bottom) { 
                    // daca a trecut hexagonul de linia imaginara si avem vreun romb de culoarea hexagonului, incepe atacul cu stelute
                    if (grid_romb[j][i]->id_color == hexagon->color_id) {
                        time_since_interval += deltaTimeSeconds;
                        if (time_since_interval > 2) {
                            if (grid_romb[j][i]->id_color == 0) {
                                thrown_star_color = "star_random_red";
                            }
                            else if (grid_romb[j][i]->id_color == 1) {
                                thrown_star_color = "star_random_blue";
                            }
                            else if (grid_romb[j][i]->id_color == 2) {
                                thrown_star_color = "star_random_yellow";
                            }
                            else  if (grid_romb[j][i]->id_color == 3) {
                                thrown_star_color = "star_random_purple";
                            }
                            thrown_stars.push_back(new StarModel(thrown_star_color, grid_of_squares[j][i]->right,
                                grid_of_squares[j][i]->top - (squareSide / 2), grid_romb[j][i]->id_color, true, squareSide / 2, 1, 1));
                            time_since_interval = 0;
                        }
                    }

                    // daca un hexagon atinge un romb, rombul moare
                    int dist_hex_romb = abs((hexagon->pos_hexagon_right - squareSide / 2) - grid_of_squares[j][i]->right + squareSide / 2);
                    int radius_sum_hex_romb = hexagon->radius + grid_romb[j][i]->radius;
                    if (dist_hex_romb < radius_sum_hex_romb) {
                        grid_romb[j][i]->keep_rendering = false;
                    }

                }
            }
        }

        // verificam daca o stea-proiectil are coliziune cu un hexagon, si ii scadem acestuia vieti
        for (StarModel* star : thrown_stars) {
            if (star->life_status != false) {
                int dist = abs((hexagon->pos_hexagon_right - squareSide / 2) - star->random_X_coord + squareSide * 0.3);
                int radius_sum = star->radius + hexagon->radius;
                if (dist < radius_sum && star->color_id == hexagon->color_id && hexagon->lives > 0 && (hexagon->pos_hexagon_bottom + squareSide / 2) == star->random_Y_coord) {
                    star->life_status = false;
                    hexagon->lives--;
                }
            }
        }

        // daca un hexagon a ajuns la dereptunghiul rosu, jucatorul pierde o viata
        if (hexagon->pos_hexagon_right < 0.5 * squareSide && hearts.size() != 0) {
            hearts.pop_back();
        }

        if (hexagon->pos_hexagon_right < 0.5 * squareSide || hexagon->scaleX < 0.1) {
            hexagons_to_remove.push_back(hexagon);
        }
    }

    for (Hexagon* hexagon_to_delete : hexagons_to_remove) {
        hexagons.erase(std::remove(hexagons.begin(), hexagons.end(), hexagon_to_delete), hexagons.end());
    }

    // logica render romburi din grid si animatia de micsorare pt disparitie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid_romb[i][j] != NULL) {
                if (grid_romb[i][j]->keep_rendering != false) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(squareSide / 2, squareSide / 2);
                    modelMatrix *= transform2D::Translate(grid_of_squares[i][j]->left, grid_of_squares[i][j]->bottom);

                    if (grid_romb[i][j]->color == "red") {
                        RenderMesh2D(meshes["romb_rosu"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "albastru") {
                        RenderMesh2D(meshes["romb_albastru"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "galben") {
                        RenderMesh2D(meshes["romb_galben"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "mov") {
                        RenderMesh2D(meshes["romb_mov"], shaders["VertexColor"], modelMatrix);
                    }
                }
                else {

                    if (grid_romb[i][j]->scaleX > 0 && grid_romb[i][j]->scaleY > 0) {
                        grid_romb[i][j]->scaleX -= 0.7 * deltaTimeSeconds;
                        grid_romb[i][j]->scaleY -= 0.7 * deltaTimeSeconds;
                    }

                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(squareSide / 2, squareSide / 2);
                    modelMatrix *= transform2D::Translate(grid_of_squares[i][j]->left, grid_of_squares[i][j]->bottom);
                    modelMatrix *= transform2D::Scale(grid_romb[i][j]->scaleX, grid_romb[i][j]->scaleX);

                    if (grid_romb[i][j]->color == "red") {
                        RenderMesh2D(meshes["romb_rosu"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "albastru") {
                        RenderMesh2D(meshes["romb_albastru"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "galben") {
                        RenderMesh2D(meshes["romb_galben"], shaders["VertexColor"], modelMatrix);
                    }
                    else if (grid_romb[i][j]->color == "mov") {
                        RenderMesh2D(meshes["romb_mov"], shaders["VertexColor"], modelMatrix);
                    }

                    if (grid_romb[i][j]->scaleX < 0.1) {
                        grid_romb[i][j] = NULL;
                    }
                }
            }
        }
    }

    // calcul pt aparitia aleatoare a stellutelor pt puncte 
    int random_nr = 5 + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (10 - 5)));
    int random_nr_color = 0;
    random_nr_color = 0 + static_cast <int> (rand()) / (static_cast <float> (RAND_MAX / (4 - 0)));

    if (random_nr_color == 0) {
        star_color_possible = "star_random_green1";
    } else if (random_nr_color == 1) {
        star_color_possible = "star_random_green2";
    } else if (random_nr_color == 2) {
        star_color_possible = "star_random_green3";
    } else if (random_nr_color == 3) {
        star_color_possible = "star_random_green4";
    }

    timeSinceLastStar += deltaTimeSeconds;
    
    if (timeSinceLastStar > random_nr) {
        for (int i = 0; i < 3; i++) {
            if (starForPoints.size() < 10 && collectedStars.size() < 15) {
                int random_X_coord = 0 + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (1080 - 0)));
                int random_Y_coord = 0 + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (520 - 0)));

                starForPoints.push_back(new StarModel(star_color_possible, random_X_coord, random_Y_coord, random_nr_color, true, squareSide / 2, 1, 1));
            }
        }
        timeSinceLastStar = 0;
    }

    for (StarModel* star : starForPoints) {
        if (star->scaleX > 0) {
            star->scaleX -= 0.5 * deltaTimeSeconds;
        }
        std::string curr_star_color;
        curr_star_color = star->color;
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star->random_X_coord, star->random_Y_coord);
        if (star->life_status != true) {
            modelMatrix *= transform2D::Scale(star->scaleX, star->scaleX);
        }
        RenderMesh2D(meshes[star->color], shaders["VertexColor"], modelMatrix);
    }

    // render stelute colectate
    for (StarCollected* star_collected : collectedStars) {
        modelMatrix = glm::mat3(1);
        auto it = (find(collectedStars.begin(), collectedStars.end(), star_collected));
        int index = it - collectedStars.begin();
        modelMatrix *= transform2D::Translate(star_collected->random_X_coord + index * (squareSide * 0.35) + 0.25 * squareSide, star_collected->random_Y_coord);
        RenderMesh2D(meshes[star_collected->color], shaders["VertexColor"], modelMatrix);
    }

    // daca nr de vieti este 0 -> finalul jocului
    if (hearts.size() == 0) {
        exit(0);
    }
}


void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
    // Add key press event
}

void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}

void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

    mouseX = (1.0f * mouseX / window->GetResolution().x) * initial_res_x;
    mouseY = (1.0f * mouseY / window->GetResolution().y) * initial_res_y;

    this->mouseX = mouseX;
    this->mouseY = mouseY;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    int screen_res_y = initial_res_y;

    mouseX = (1.0f * mouseX / window->GetResolution().x) * initial_res_x;
    mouseY = (1.0f * mouseY / window->GetResolution().y) * initial_res_y;

    // daca se da click stanga pe un element:
    if (window->MouseHold(GLFW_MOUSE_BUTTON_1)) {
        // pe un romb -> se tine minte ce fel de romb este pt a fi render-uit pana i se da drop undeva
        if (mouseX > 0.5 * squareSide && mouseX < 1.5 * squareSide &&
            mouseY < squareSide * 1.25 && mouseY > squareSide * 0.25 && collectedStars.size() >= 1) {
            this->currentlySelectedRomb = new Romb("red", true, 0, (squareSide * 0.8) / 2, 1, 1);
        }
        else if (mouseX > 2 * squareSide && mouseX < 3 * squareSide &&
            mouseY < squareSide * 1.25 && mouseY > squareSide * 0.25 && collectedStars.size() >= 2) {
            this->currentlySelectedRomb = new Romb("albastru", true, 1, (squareSide * 0.8) / 2, 1, 1);
        }
        else if (mouseX > 3.5 * squareSide && mouseX < 4.5 * squareSide &&
            mouseY < squareSide * 1.25 && mouseY > squareSide * 0.25 && collectedStars.size() >= 2) {
            this->currentlySelectedRomb = new Romb("galben", true, 2, (squareSide * 0.8) / 2, 1, 1);
        }
        else if (mouseX > 5 * squareSide && mouseX < 6 * squareSide &&
            mouseY < squareSide * 1.25 && mouseY > squareSide * 0.25 && collectedStars.size() >= 3) {
            this->currentlySelectedRomb = new Romb("mov", true, 3, (squareSide * 0.8) / 2, 1, 1);
        }

        // pe o stea verde -> se sterge steaua si se adauga o stea la cele colectate
        std::vector<StarModel*> starsToRemove;
        for (StarModel* star : starForPoints) {

            if (mouseX > star->random_X_coord - squareSide / 2 && mouseX < star->random_X_coord + squareSide / 2 &&
                screen_res_y - mouseY > star->random_Y_coord - squareSide / 2 && screen_res_y - mouseY < star->random_Y_coord + squareSide / 2) {
                starsToRemove.push_back(star);
                break;
            }
        }
        for (StarModel* star_to_delete : starsToRemove) {
            starForPoints.erase(std::remove(starForPoints.begin(), starForPoints.end(), star_to_delete), starForPoints.end());
            // add another star to the collected ones
            if (collectedStars.size() < 15) {
                collectedStars.push_back(new StarCollected("star", 6.5 * squareSide, screen_res_y - squareSide * 1.75, 0, true, squareSide / 2));
            }
        }
    }

    // daca se da click dreapta pe un romb se va sterge
    if (window->MouseHold(GLFW_MOUSE_BUTTON_2)) {
        printf("click dreapta merge!\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mouseX > grid_of_squares[i][j]->left && mouseX < grid_of_squares[i][j]->right &&
                    screen_res_y - mouseY > grid_of_squares[i][j]->bottom && screen_res_y - mouseY < grid_of_squares[i][j]->top && grid_romb[i][j] != NULL) {
                    grid_romb[i][j]->keep_rendering = false;
                }
            }
        }

    }
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    int screen_res_y = initial_res_y;
    mouseX = (1.0f * mouseX / window->GetResolution().x) * initial_res_x;
    mouseY = (1.0f * mouseY / window->GetResolution().y) * initial_res_y;

    float romb_stg = mouseX - 0.25 * squareSide * 0.1;
    float romb_dr = romb_stg + 0.5 * squareSide * 0.1;
    float romb_sus = screen_res_y - mouseY + 0.5 * squareSide * 0.1;
    float romb_jos = screen_res_y - mouseY - 0.5 * squareSide * 0.1;

    // verifica daca un romb a fost plasat in unul dintre patratele din grid
    if (this->currentlySelectedRomb != NULL) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (romb_stg > grid_of_squares[i][j]->left && romb_dr < grid_of_squares[i][j]->right &&
                    romb_jos > grid_of_squares[i][j]->bottom && romb_sus < grid_of_squares[i][j]->top && grid_romb[i][j] == NULL) {

                    grid_romb[i][j] = this->currentlySelectedRomb;
                    
                    if (grid_romb[i][j]->id_color == 0) {
                        collectedStars.pop_back();
                    } else if (grid_romb[i][j]->id_color == 1) {
                        collectedStars.resize(collectedStars.size() - 2);
                    } else if (grid_romb[i][j]->id_color == 2) {
                        collectedStars.resize(collectedStars.size() - 2);
                    } else if (grid_romb[i][j]->id_color == 3) {
                        collectedStars.resize(collectedStars.size() - 3);
                    }
                }
            }
        }
        this->currentlySelectedRomb = NULL;
    }
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
