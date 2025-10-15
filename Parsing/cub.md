map :
    - only composed of 1,0,N,S,W,E (Allowed for bonus : O,C (open/closed door))
    - closed/surrounded by walls (if not return error)
    
    - Except for the map content, each type of element can be separated by one or
    more empty lines.
    
    - Except for the map content which always has to be the last, each type of
    element can be set in any order in the file.
    
    - Except for the map, each type of information from an element can be separated
    by one or more spaces.

    - The map must be parsed as it looks in the file. Spaces are a valid part of the
    map and are up to you to handle. You must be able to parse any kind of map,
    as long as it respects the rules of the map.

    - Except for the map, each element must begin with its type identifier (composed
    by one or two characters), followed by its specific information in a strict order: 
        - North texture:
            - NO ./path_to_the_north_texture
            - identifier: N/NO
            - path to the north texture 
        - South
            - Identifier: S/SO
        - West
            - Identifier: W/WE
        - East
            - Identifier: E/EA
        - Floor color
            - Identifier: F
            - RGB
        - Ceiling color
            - identifier: C
            - RGB

    - Map

    - if an error is found -> return : "Error\n" followed by an accurate error message (ex: Map isn't closed)

https://github.com/mcombeau/cub3D
