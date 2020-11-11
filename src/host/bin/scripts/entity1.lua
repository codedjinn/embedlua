
ent = {};

ent.init = function()
    print("init from LUA");
    return true;
end

ent.update = function()
   -- print("update" .. tostring(time*2));
   print("update");
end

