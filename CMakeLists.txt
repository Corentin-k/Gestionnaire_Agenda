cmake_minimum_required(VERSION 3.17)
project(Gestionnaire_Agenda C)

set(CMAKE_C_STANDARD 23)

add_executable(Gestionnaire_Agenda main.c fichier.c fichier.h
        timer.h
        timer.c
        research.c
        research.h
        research.c
        contact.c
        contact.h
)
configure_file(./noms2008nat_txt.txt noms2008nat_txt.txt COPYONLY)