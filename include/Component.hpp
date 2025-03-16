#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component {
  public:
    virtual ~Component() = default;
    virtual void update() {}
    virtual void render() {}
};

#endif
