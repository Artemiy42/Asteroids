#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Assets.h"
#include "Settings.h"

template <class Container>
void split(const std::string& str, Container& cont, const std::string& delims = " ")
{
    std::size_t current, previous = 0;

    current = str.find_first_of(delims);
    
    while (current != std::string::npos)
    {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find_first_of(delims, previous);
    }

    cont.push_back(str.substr(previous, current - previous));
}

void on_age(int age)
{
    std::cout << "On age: " << age << '\n';
}

int main(int argc, char* argv[])
{
    /*
    if (argc > 1)
    {
        std::string arg;
        std::vector<std::string> splitResult;

        for (int i = 1; i < argc; ++i)
        {
            arg = argv[i];

            if (arg == "--help")
            {
                std::cout << "usage: Asteroids.exe [--help] [--version] [-window <value>x<value>] [-map <value>x<value>]"
                             "[-num_asteroids <value>] [-num_ammo <value>] [-ability_probability <value>]"
                          << std::endl;
                return 0;
            }
            else if (arg == "--version")
            {
                std::cout << "Asteroids version 0.3.4" << std::endl;
                return 0;
            }
            else if (arg == "-window") 
            {
                if (i + 1 < argc)
                {
                    split(argv[++i], splitResult, "xX");

                    if (splitResult.size() == 2)
                    {
                        try
                        {
                            Settings::Instance().setVidoeMode(std::stoi(splitResult[0]), std::stoi(splitResult[1]));
                        }
                        catch (std::exception const& ex)
                        {
                            std::cout << "Input correct integer value" << std::endl;
                            return 1;
                        }
                    }
                    else
                    {
                        std::cout << "Argument must have 1 value letter x and 1 value. Example: 800x600 " << std::endl;
                        return 1;
                    }

                    splitResult.clear();
                }
                else 
                {
                    std::cerr << "-window option requires one argument size window (800x600)." << std::endl;
                    return 1;
                }
            }
            else if (arg == "-map")
            {
                if (i + 1 < argc)
                {
                    split(argv[++i], splitResult, "xX");
                    
                    if (splitResult.size() == 2)
                    {
                        try
                        {
                            Settings::Instance().setMapSize(std::stoi(splitResult[0]), std::stoi(splitResult[1]));
                        }
                        catch (std::exception const& ex)
                        {
                            std::cout << "Input correct integer value" << std::endl;
                            return 1;
                        }
                    }
                    else
                    {
                        std::cout << "Argument must have 1 value letter x and 1 value. Example: 1000x1000 " << std::endl;
                        return 1;
                    }
                    
                    splitResult.clear();
                }
                else
                {
                    std::cerr << "-map option requires one argument size map (1000x1000)." << std::endl;
                    return 1;
                }
            }
            else if (arg == "-num_asteroids")
            {
                if (i + 1 < argc)
                {
                    try
                    {
                        Settings::Instance().setNumberOfAsteroids(std::stoi(argv[++i]));
                    }
                    catch (std::exception const& ex)
                    {
                        std::cout << "Input correct integer value" << std::endl;
                        return 1;
                    }
                }
                else
                {
                    std::cerr << "-num_asteroids option requires one argument numver of asteroids (10)." << std::endl;
                    return 1;
                }
            }
            else if (arg == "-num_ammo")
            {
                if (i + 1 < argc)
                {
                    try
                    {
                        Settings::Instance().setNumberOfAmmo(std::stoi(argv[++i]));
                    }
                    catch (std::exception const& ex)
                    {
                        std::cout << "Input correct integer value" << std::endl;
                        return 1;
                    }
                }
                else
                {
                    std::cerr << "-num_ammo option requires one argument numver of ammo (4)." << std::endl;
                    return 1;
                }
            }
            else if (arg == "-ability_probability")
            {
                if (i + 1 < argc)
                {
                    try
                    {
                        Settings::Instance().setAbilityProbability(std::stof(argv[++i]));
                    }
                    catch (std::exception const& ex)
                    {
                        std::cout << "Input correct float value" << std::endl;
                        return 1;
                    }
                }
                else
                {
                    std::cerr << "-num_ammo option requires one argument numver of ammo (4)." << std::endl;
                    return 1;
                }
            }
            else
            {
                std::cerr << "unknown option: " << arg << std::endl;
                return 1;
            }
        }
    }   
    */
    /*
    try
    {
        options_description desc{ "Options" };
        desc.add_options()
            ("help,h", "Help screen")
            ("pi", value<float>()->default_value(3.14f), "Pi")
            ("age", value<int>()->notifier(on_age), "Age");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else if (vm.count("age"))
            std::cout << "Age: " << vm["age"].as<int>() << '\n';
        else if (vm.count("pi"))
            std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
    }
    catch (const error & ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return 0;*/
    Assets::Instance().load();

    Game game;

    game.setupSystem();
    game.initialize();

    while (game.loop());

    game.shutdown();

    return 0;
}