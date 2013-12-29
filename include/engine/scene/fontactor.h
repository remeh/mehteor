#ifndef MEH_FONTACTOR_H
#define MEH_FONTACTOR_H

#include <vector>

#include "engine/sprite.h"
#include "engine/scene/actor.h"

using namespace std;

namespace meh {

class FontActor : public Actor {
    private:
        vector< shared_ptr<Sprite> >* sprtes;

    protected:
    public:
        FontActor(vector< shared_ptr<Sprite> >* sprites);
        ~FontActor();

        void draw(Renderer* renderer);
        void update();
};

} // namespace meh

#endif // MEH_FONTACTOR_H

