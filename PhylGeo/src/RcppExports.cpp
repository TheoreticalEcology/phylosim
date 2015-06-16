// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// rcpp_hello_world
List rcpp_hello_world();
RcppExport SEXP PhylGeo_rcpp_hello_world() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(rcpp_hello_world());
    return __result;
END_RCPP
}
// RcppModel
NumericMatrix RcppModel(int dim, int specRate, int runs);
RcppExport SEXP PhylGeo_RcppModel(SEXP dimSEXP, SEXP specRateSEXP, SEXP runsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type dim(dimSEXP);
    Rcpp::traits::input_parameter< int >::type specRate(specRateSEXP);
    Rcpp::traits::input_parameter< int >::type runs(runsSEXP);
    __result = Rcpp::wrap(RcppModel(dim, specRate, runs));
    return __result;
END_RCPP
}
