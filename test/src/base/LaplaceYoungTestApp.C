//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "LaplaceYoungTestApp.h"
#include "LaplaceYoungApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
LaplaceYoungTestApp::validParams()
{
  InputParameters params = LaplaceYoungApp::validParams();
  return params;
}

LaplaceYoungTestApp::LaplaceYoungTestApp(InputParameters parameters) : MooseApp(parameters)
{
  LaplaceYoungTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

LaplaceYoungTestApp::~LaplaceYoungTestApp() {}

void
LaplaceYoungTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  LaplaceYoungApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"LaplaceYoungTestApp"});
    Registry::registerActionsTo(af, {"LaplaceYoungTestApp"});
  }
}

void
LaplaceYoungTestApp::registerApps()
{
  registerApp(LaplaceYoungApp);
  registerApp(LaplaceYoungTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
LaplaceYoungTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  LaplaceYoungTestApp::registerAll(f, af, s);
}
extern "C" void
LaplaceYoungTestApp__registerApps()
{
  LaplaceYoungTestApp::registerApps();
}
