#include "ligerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ligerApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ligerApp::ligerApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ligerApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ligerApp::associateSyntax(_syntax, _action_factory);
}

ligerApp::~ligerApp() {}

// External entry point for dynamic application loading
extern "C" void
ligerApp__registerApps()
{
  ligerApp::registerApps();
}
void
ligerApp::registerApps()
{
  registerApp(ligerApp);
}

// External entry point for dynamic object registration
extern "C" void
ligerApp__registerObjects(Factory & factory)
{
  ligerApp::registerObjects(factory);
}
void
ligerApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void
ligerApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ligerApp::associateSyntax(syntax, action_factory);
}
void
ligerApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
