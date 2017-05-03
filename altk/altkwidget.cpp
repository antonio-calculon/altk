// altkwidget.hpp

#include "private.hpp"
#include "altkwidget.hpp"

using namespace altk;



Widget::Widget ()
{
  parent = NULL;
}



void Widget::set_parent ( Widget *parent )
{
  ASSERT(!this->parent);
  this->parent = parent;
}
