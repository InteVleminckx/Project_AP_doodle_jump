#include "Platform_L.h"

Platform_L::Platform_L() = default;

void Platform_L::setTemporary(bool temporary) {m_temporary = temporary;}

void Platform_L::setVertical(bool vertical) {m_vertical = vertical;}

void Platform_L::setHorizontal(bool horizontal) {m_horizontal = horizontal;}

bool Platform_L::isTemporary() const {return m_temporary;}

bool Platform_L::isVertical() const {return m_vertical;}

bool Platform_L::isHorizontal() const {return m_horizontal;}

Platform_L_static::Platform_L_static() = default;

Platform_L_vertical::Platform_L_vertical() {setVertical(true);}

Platform_L_horizontal::Platform_L_horizontal() {setHorizontal(true);}

Platform_L_temporary::Platform_L_temporary() {setTemporary(true);}
