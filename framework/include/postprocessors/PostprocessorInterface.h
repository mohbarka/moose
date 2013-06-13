/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef POSTPROCESSORINTERFACE_H
#define POSTPROCESSORINTERFACE_H

#include <map>
#include <string>

#include "InputParameters.h"
#include "ParallelUniqueId.h"
#include "PostprocessorData.h"

// Forward Declarations
class FEProblem;

class PostprocessorInterface
{
public:
  PostprocessorInterface(InputParameters & params);

  /**
   * Retrieve the value named "name"
   */
  PostprocessorValue & getPostprocessorValue(const std::string & name);

  /**
   * Retrieve the old value of a post-processor
   * @param name The name of the post-processor
   * @return The value of the post-processor
   */
  PostprocessorValue & getPostprocessorValueOld(const std::string & name);

  /**
   * Determine if the postprocessor exists
   * @param name The name of the postprocessor
   * @return True if the postprocessor exists
   */
  bool hasPostprocessor(const std::string & name);

private:
  FEProblem & _pi_feproblem;
  THREAD_ID _pi_tid;
};

#endif //POSTPROCESSORINTERFACE_H
