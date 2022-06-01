mkdir include
mkdir include\enet
mkdir include\fmt
mkdir include\config
mkdir include\events
mkdir include\logger
mkdir include\math
mkdir include\player
mkdir include\runner
mkdir include\sdk
mkdir include\server

copy .\vendor\enet\include\enet\*.h include\enet
copy .\vendor\fmt\include\fmt\*.h include\fmt

copy .\src\config\config.h include\config\
copy .\src\config\macros.h include\config\

copy .\src\events\manager.h include\events\
copy .\src\events\context.h include\events\

copy .\src\logger\logger.h include\logger\

copy .\src\math\math.h include\math\

copy .\src\player\player.h include\player\

copy .\src\runner\run.h include\runner\

copy .\src\sdk\packet.h include\sdk\
copy .\src\sdk\update.h include\sdk\
copy .\src\sdk\variant.h include\sdk\

copy .\src\server\server.h include\server\