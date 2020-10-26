local keyboard = {}

KEYS = {
    W = 32, -- figure out code
    A = 33,
    S = 34,
    D = 35
}

PressedKeys = {}

function is_key_pressed(key)
    
    if (PressedKeys[key] == true)
        return true;
    end

    return false;

end