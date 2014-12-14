require("BaseScript.lua")

MoveObject = class(BaseScript,
{

})


function MoveObject : Start()
end

function MoveObject : Update()
	gameObject.SetPosition(0,gameObject.GetX() * (5.0 * delta));
end


moveObject = MoveObject:Create()
