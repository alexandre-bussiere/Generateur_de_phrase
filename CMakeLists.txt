cmake_minimum_required(VERSION 3.21)
project(Generateur_de_phrase C)

set(CMAKE_C_STANDARD 99)

add_executable(Generateur_de_phrase main.c struct.h tree.c tree.h take-from-txt.c take-from-txt.h functionOfListAgreeForm.c functionOfListAgreeForm.h functionOfListOfSon.c functionOfListOfSon.h Create_random_sentences.c Create_random_sentences.h)
