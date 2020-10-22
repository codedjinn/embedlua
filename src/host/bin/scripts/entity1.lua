
function init()
    print("init from LUA");
    return true;
end

function update(time)
    print("update" .. tostring(time*2));
end