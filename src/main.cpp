#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return -1;
    }

    SDL_Window* window_ptr = SDL_CreateWindow("anysplat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
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

    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
            ImGui_ImplSDL2_ProcessEvent(&e);
        }
            //GAME LOOP-------------------------------------------

            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("note");
            ImGui::Text("Hello World");
            ImGui::End();

            ImGui::Begin("note second");
            ImGui::Text("Hello Second World");
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
