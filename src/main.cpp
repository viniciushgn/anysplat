#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

#include <cstdio>//prints
#include <iostream>//prints

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return -1;
    }

    SDL_Window* window_ptr = SDL_CreateWindow("anySplat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    if(!window_ptr){
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer_ptr = SDL_CreateRenderer(window_ptr, -1, 0);
    if(!renderer_ptr){
        SDL_DestroyWindow(window_ptr);
        SDL_Quit();
        return -1;
    }

    //init imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void) io;

    ImGui_ImplSDL2_InitForSDLRenderer(window_ptr, renderer_ptr);
    ImGui_ImplSDLRenderer2_Init(renderer_ptr);

    bool running = true;
    float f = 1.0f;//debug, probably delete

    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
            if (e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }
            }
            ImGui_ImplSDL2_ProcessEvent(&e);
        }
            //GAME LOOP-------------------------------------------

            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("note: ReadMe");
            ImGui::Text("Hello World!\nThis is Anny\nthe personification of this viewer.\nHere are some useful\ninstructions:\n don't mess shit up");
            ImGui::End();

            ImGui::Begin("Upload Splat File");
            ImGui::Text("Splat File %d", 123);
                if (ImGui::Button("Upload")){
                    printf("file is received");
                    std::cout << f << "\n";
                }
                    
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::End();


            ImGui::Render();
            SDL_SetRenderDrawColor(renderer_ptr, 120,180,255,255);
            SDL_RenderClear(renderer_ptr);

            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(),renderer_ptr);
            SDL_RenderPresent(renderer_ptr);
        
    }
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer_ptr);
    SDL_DestroyWindow(window_ptr);
    SDL_Quit();
    return 0;
}
