
entity1 = {};

entity1.init = function()
    print("init from LUA");
    return true;
end

entity1.update = function(time)
    print("update" .. tostring(time*2));
end

