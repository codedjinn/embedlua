local keyboard = {}

KEYS = {
    Left,
    Right,
    Up,
    Down
}

PressedKeys = {}

function is_key_pressed(key)
    
    if (PressedKeys[key] == true)
        return true;
    end

    return false;

end