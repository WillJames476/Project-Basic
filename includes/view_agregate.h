#ifndef VIEW_AGREGATE_H
#define VIEW_AGREGATE_H

#include <memory>

#include "model_agregate.h"
#include "../src/Account/Account_view.h"

struct View_agregate
{
  std::shared_ptr<Account_view> account;
};

#endif
