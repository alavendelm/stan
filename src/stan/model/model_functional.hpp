#ifndef STAN_MODEL_MODEL_FUNCTIONAL_HPP
#define STAN_MODEL_MODEL_FUNCTIONAL_HPP

#include <Eigen/Dense>
#include <iostream>

namespace stan {
  namespace model {

    // Interface for automatic differentiation of models
    template <class M>
    struct model_functional {
      const M& model;
      std::ostream* o;

      model_functional(const M& m, std::ostream* out)
        : model(m), o(out) {}

      template <typename T>
      T operator()(Eigen::Matrix<T, Eigen::Dynamic, 1>& x) const {
        return model.template log_prob<true, true, T>(x, o);
      }
    };

  }
}
#endif
