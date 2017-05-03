// altkwidget.hpp

#include "private.hpp"
#include "altkwidget.hpp"
#include "altkdisplay.hpp"

using namespace altk;



void WidgetVisitor::start ( Widget *widget )
{
  visit(widget);
}




Widget::Widget ()
{
  flags = 0;
  parent = NULL;
}



Display *Widget::get_display ()
{
  Widget *root = get_root();
  if (root)
    return root->get_display();
  else
    return NULL;
}



Widget *Widget::get_root ()
{
  Widget *w;
  while (w->parent)
    w = w->parent;
  if (w->is_root_widget())
    return w;
  else
    return NULL;
}


  
void Widget::set_parent ( Widget *parent )
{
  ASSERT(!this->parent);
  this->parent = parent;
}



void Widget::queue_resize ()
{
  Widget *w = this;
  while (w && w->is_visible())
    {
      w->flags |= WIDGET_FLAG_NEEDS_RESIZE;
      if (w->is_root_widget())
        {
          Display *d = w->get_display();
          if (d)
            d->queue_resize(w);
          break;
        }
      w = w->parent;
    }
}



void ShowAllVisitor::visit ( Widget *widget )
{
  widget->flags |= (WIDGET_FLAG_VISIBLE | WIDGET_FLAG_NEEDS_RESIZE);
  widget->accept(this);
}


                      
void Widget::show_all ()
{
  ShowAllVisitor v;
  v.start(this);
  queue_resize();
}
