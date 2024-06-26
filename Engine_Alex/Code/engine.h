//
// engine.h: This file contains the types and functions relative to the engine.
//

#pragma once

#include "platform.h"
#include "BufferSupFuncs.h"
#include "ModelLoadingFuncs.h"
#include "Globals.h"

const VertexV3V2 vertices[] = {
    {glm::vec3(-1.0,-1.0,0.0), glm::vec2(0.0,0.0)},
    {glm::vec3(1.0,-1.0,0.0), glm::vec2(1.0,0.0)},
    {glm::vec3(1.0,1.0,0.0), glm::vec2(1.0,1.0)},
    {glm::vec3(-1.0,1.0,0.0), glm::vec2(0.0,1.0)},
};

const u16 indices[] =
{
    0,1,2,
    0,2,3
};

struct App
{
    void ColorAttachment(GLuint& colorAttachmentHandle);
    void DepthAttachment(GLuint& depthAttachmentHandle);
    void UpdateEntityBuffer();

    void processInput(GLFWwindow* window);

    void ConfigureFrameBuffer(FrameBuffer& aConfigFB);
    void CreatePointLight(u32 GeometryIndex, vec3 position, vec3 direction, vec3 color);
    void CreateDirectionalLight(u32 GeometryIndex, vec3 color, vec3 direction, vec3 position);
    void RenderGeometry(const Program& texturedMeshProgram);

    const GLuint CreateTexture(const bool isFloatingPoint = false);

    // Loop
    f32  deltaTime;
    bool isRunning;

    // Input
    Input input;

    // Graphics
    char gpuName[64];
    char openGlVersion[64];

    ivec2 displaySize;

    std::vector<Texture>    textures;
    std::vector<Material>   materials;
    std::vector<Mesh>       meshes;
    std::vector<Model>      models;
    std::vector<Program>    programs;

    GLuint renderToBackBufferShader;
    GLuint renderToFrameBufferShader;
    GLuint freamebufferToQuadShader;

    // program indices
    u32 texturedGeometryProgramIdx = 0;
    u32 texturedMeshProgramIdx = 0;

    u32 patricioModel = 0;
    GLuint texturedMeshProgram_uTexture;
    
    // texture indices
    u32 diceTexIdx;
    u32 whiteTexIdx;
    u32 blackTexIdx;
    u32 normalTexIdx;
    u32 magentaTexIdx;

    // Mode
    Mode mode;

    // Embedded geometry (in-editor simple meshes such as
    // a screen filling quad, a cube, a sphere...)
    GLuint embeddedVertices;
    GLuint embeddedElements;

    // Location of the texture uniform in the textured quad shader
    GLuint programUniformTexture;

    // VAO object to link our screen filling quad with our textured quad shader
    GLuint vao;

    std::string openglDebugInfo;

    GLint maxUniformBufferSize;
    GLint uniformBlockAligment;
    Buffer localUniformBuffer;
    std::vector<Entity> entities;
    std::vector<Light> lights;

    GLuint globalParamsOffset;
    GLuint globalParamsSize;

    FrameBuffer defferredFrameBuffer;

    //Camera Parameters
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float yaw;
    float pitch;
    bool firstMouse = true;
};

void Init(App* app);

void Gui(App* app);

void Update(App* app);

void Render(App* app);

