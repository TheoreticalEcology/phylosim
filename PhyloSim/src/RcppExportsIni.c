#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP PhyloSim_callModel(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                               SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                               SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                               SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"PhyloSim_callModel", (DL_FUNC) &PhyloSim_callModel, 22},
  {NULL, NULL, 0}
};

void R_init_PhyloSim(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}