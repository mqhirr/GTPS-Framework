mkdir include
mkdir include/config
mkdir include/events
mkdir include/logger
mkdir include/math
mkdir include/player
mkdir include/runner
mkdir include/sdk
mkdir include/server

cp src/config/config.h include/config/
cp src/config/macros.h include/config/

cp src/events/manager.h include/events/
cp src/events/context.h include/events/

cp src/logger/logger.h include/logger/

cp src/math/math.h include/math/

cp src/player/player.h include/player/

cp src/runner/run.h include/runner/

cp src/sdk/packet.h include/sdk/
cp src/sdk/update.h include/sdk/
cp src/sdk/variant.h include/sdk/

cp src/server/server.h include/server/