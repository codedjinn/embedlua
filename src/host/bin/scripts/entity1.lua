ent = {};

ent.init = function()
    print("init from LUA");
    return true;
end

ent.update = function()
   --print("update " .. tostring(time*2));
   print("update with no arg");
end

function update()
    print("ffs");
end

--print("COME ON MAN");
