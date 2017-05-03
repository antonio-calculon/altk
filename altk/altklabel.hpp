// altklabel.hpp

#ifndef _ALTKLABEL_HPP_
#define _ALTKLABEL_HPP_

#include "altk/altkwidget.hpp"

#include <string>



// altk::Label
//
namespace altk
{
  class Label : public Widget
  {
  private:
    std::string text;

  public:
    Label ( const char *text );
  };
}

#endif
