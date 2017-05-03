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
  flags = WIDGET_FLAG_NEEDS_RESIZE;
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



void Widget::process_resize ()
{
  SizeRequest req = { 0, 0 };
  size_request(&req);
  Allocation alloc;
  alloc.x = 0;
  alloc.y = 0;
  alloc.width = req.width;
  alloc.height = req.height;
  size_allocate(&alloc);
}



void Widget::size_request ( SizeRequest *req )
{
  if (needs_resize())
    {
      on_size_request(req);
      flags &= ~WIDGET_FLAG_NEEDS_RESIZE;
    }
  else
    {
      *req = request;
    }
}



void Widget::on_size_request ( SizeRequest *req )
{
}



void Widget::size_allocate ( Allocation *alloc )
{
  DEBUG("[TODO] size_alloc: %d, %d, %d, %d", alloc->x, alloc->y, alloc->width, alloc->height);
  on_size_allocate(alloc);
}



void Widget::on_size_allocate ( Allocation *alloc )
{
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
