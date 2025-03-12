# To-Do List for Game Engine Development

## Oh God I am so Overwhelmed

It's not like making a game engine is hard, per-se, it's just kind of...all-consuming. At least I only need to do everything once.

But trying to think of how to keep it really organised and modular and future-proof is a bit of a headache.

## What to Actually Do

### Finalise Scene and Entity Structure

* Make sure Scene and Entity classes are set up properly.
* Implement basic methods in Scene for init(), update(), render(), clean().
* For Entity, ensure there's a render() and update() method (or whatever makes sense for your game entities).

### Render all the way up

* Scene calls render on entity (perhaps entity should have a visible attribute).
* SceneManager calls render on active Scene (when there's a SceneManager)
* GameController calls render on SceneManager and actually renders the scene.
* Job done.
* Job's a good'un.
* Job's a fish.
* Job's a fish?
* Job's a fish.

### Set Up Input Handling

* InputController: Create a general InputController class.
* Sub-classes: KeyboardController, MouseController, GameController
* Implement basic methods like keyPressed(), keyHeld(), keyReleased().
* Entity Integration: Pass input data to entities via handleInput() methods.
* This will give entities access to input without needing to directly query SDL.

### GameController Integration

* Add InputController (or KeyboardController) as an attribute of GameController.
* GameController should initialize and manage the InputController instance.
* Implement a way for the GameController to pass relevant input data to the Scene (scene references GameController so it can access input data also).

### Layer Class

* Layer class: Implement a Layer class to group and manage entities for rendering.
* Each Layer will have a name and a vector of Entity pointers.
* Sorting layers can determine rendering order.
* Layers can have a z index to determine rendering order.
* This will help in organizing rendering logic when you have a lot of objects to draw.

### Layer Stack

* Create a LayerStack class (manages a stack of layers).
* Each Scene will have a LayerStack to manage how entities are grouped.
* Layers will be rendered from bottom to top, based on stack order.
* Layers can be pushed, popped and sorted as needed. Sorting can be based on z index or custom sorting functions.
* Why would I need a stack even?
* Just use a vector? We can append, insert, remove etc but realistically it only needs to be sorted if new layers are added or removed.

### Scene Manager

* SceneManager: Implement a SceneManager to handle scene transitions (adding, removing, switching scenes).
* Support multiple scenes, stack management (push and pop).
* Think about how scenes will interact with one another (overlay, background, etc.).
* Essentially it will have a scene stack, and will manage the current scene.

### Render a Red Square

* Now we can render a red square on the screen.
* Create a simple Entity subclass (like Player) that renders a red square.
* Add the entity to a layer and render it on the screen.
* This will test the layer and rendering system.
* If you got this far, you're doing great! (Thanks me, who wrote this)

### Sprite Class

* Implement a Sprite class to handle rendering textures.
* The Sprite class should have a texture, position, and size.
* It can also have some other stuff like rotation, scale, etc.
* Entity can have a sprite component and method to render the sprite.
* This will probably be like, sprite->render(*window->renderer) or something idk I'm not a game engine.

### Tile Class

* Tiles are like sprites but for tile-based games.

### Tilemap Class

* Tilemap is a collection of tiles.
* Tilemap determines what tiles to render and where.
* Implement a Tilemap class to handle rendering tile-based levels.

### This is starting to get a bit much

* Okay things like Tilemaps and stuff could just be json files or something.
* Scenes could be json files too.
* When scenes are json files, we can add it into the Scene constructor to load the scene from a file during init.
* So start to think about how to load scenes and tilemaps from files.

### Okay At This Point it's Sort of a Game Engine

* Yeah let's be real, this is a game engine now.
* It's going to take a while to get here
