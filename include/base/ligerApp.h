#ifndef LIGERAPP_H
#define LIGERAPP_H

#include "MooseApp.h"

class ligerApp;

template <>
InputParameters validParams<ligerApp>();

class ligerApp : public MooseApp
{
public:
  ligerApp(InputParameters parameters);
  virtual ~ligerApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LIGERAPP_H */
