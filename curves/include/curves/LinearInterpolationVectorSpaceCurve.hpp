#ifndef CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_CURVE_HPP
#define CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_CURVE_HPP

#include "VectorSpaceCurve.hpp"
#include "HermiteCoefficientManager.hpp"

namespace curves {

class LinearInterpolationVectorSpaceCurve : public VectorSpaceCurve {
 public:
  typedef VectorSpaceCurve::ValueType ValueType;
  typedef VectorSpaceCurve::DerivativeType DerivativeType;
  typedef VectorSpaceCurve::EvaluatorType EvaluatorType;
  typedef VectorSpaceCurve::EvaluatorTypePtr EvaluatorTypePtr;

  /// \brief Initialize with the dimension of the vector space
  LinearInterpolationVectorSpaceCurve(size_t dimension);
  virtual ~LinearInterpolationVectorSpaceCurve();

  /// Print the value of the coefficient, for debugging and unit tests
  virtual void print(const std::string& str = "") const;
  
  /// \brief Get the coefficients that are active at a certain time.
  virtual void getCoefficientsAt(Time time, 
                                 Coefficient::Map& outCoefficients) const;

  /// \brief Get the coefficients that are active within a range \f$[t_s,t_e) \f$.
  virtual void getCoefficientsInRange(Time startTime, 
                                      Time endTime, 
                                      Coefficient::Map& outCoefficients) const;

  /// \brief Get all of the curve's coefficients.
  virtual void getCoefficients(Coefficient::Map& outCoefficients) const;
  
  /// \brief Set a coefficient.
  virtual void setCoefficient(Key key, const Coefficient& value);

  /// \brief Set coefficients.
  virtual void setCoefficients(Coefficient::Map& coefficients);


  /// The first valid time for the curve.
  virtual Time getMinTime() const;
  
  /// The one past the last valid time for the curve.
  virtual Time getMaxTime() const;

  /// Extend the curve so that it can be evaluated at these times.
  /// Try to make the curve fit to the values.
  /// Underneath the curve should have some default policy for fitting.
  virtual void extend(const std::vector<Time>& times,
                      const std::vector<ValueType>& values) = 0;

  /// \brief Fit a new curve to these data points.
  ///
  /// The existing curve will be cleared.
  /// Underneath the curve should have some default policy for fitting.
  virtual void fitCurve(const std::vector<Time>& times,
                        const std::vector<ValueType>& values) = 0;

  /// Evaluate the ambient space of the curve.
  virtual Eigen::VectorXd evaluate(Time time) const;
  
  /// Evaluate the curve derivatives.
  virtual Eigen::VectorXd evaluateDerivative(Time time, unsigned derivativeOrder) const;

  /// \brief Get an evaluator at this time
  EvaluatorTypePtr getEvaluator(Time time) const;

  ///@}

 private:
  HermiteCoefficientManager manager_;
};

} // namespace curves


#endif /* CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_CURVE_HPP */