#include "LaplaceYoungApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
LaplaceYoungApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

LaplaceYoungApp::LaplaceYoungApp(InputParameters parameters) : MooseApp(parameters)
{
  LaplaceYoungApp::registerAll(_factory, _action_factory, _syntax);
}

LaplaceYoungApp::~LaplaceYoungApp() {}

void
LaplaceYoungApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"LaplaceYoungApp"});
  Registry::registerActionsTo(af, {"LaplaceYoungApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
LaplaceYoungApp::registerApps()
{
  registerApp(LaplaceYoungApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
LaplaceYoungApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  LaplaceYoungApp::registerAll(f, af, s);
}
extern "C" void
LaplaceYoungApp__registerApps()
{
  LaplaceYoungApp::registerApps();
}
