/*
 * Copyright (c) 2015 United States Government as represented by
 * the National Aeronautics and Space Administration.  No copyright
 * is claimed in the United States under Title 17, U.S.Code. All Other
 * Rights Reserved.
 */
#ifndef WCV_TVAR_H_
#define WCV_TVAR_H_

#include "Detection3D.h"
#include "Vect3.h"
#include "Velocity.h"
#include "WCVTable.h"
#include "ConflictData.h"
#include "LossData.h"
#include <string>

namespace larcfm {
class WCV_tvar : public Detection3D {

protected:
  WCVTable table;
  std::string id;

public:
  static bool pvsCheck;

  /** This returns a copy of the object's internal table */
  WCVTable getWCVTable();

  /** This sets the internal table to be a copy of the supplied one. */
  void setWCVTable(const WCVTable& tables);

  double getDTHR() const;
  double getDTHR(const std::string& u) const;

  double getZTHR() const;
  double getZTHR(const std::string& u) const;

  double getTTHR() const;
  double getTTHR(const std::string& u) const;

  double getTCOA() const;
  double getTCOA(const std::string& u) const;

  void setDTHR(double val);
  void setDTHR(double val, const std::string& u);

  void setZTHR(double val);
  void setZTHR(double val, const std::string& u);

  void setTTHR(double val);
  void setTTHR(double val, const std::string& u);

  void setTCOA(double val);
  void setTCOA(double val, const std::string& u);

  virtual double horizontal_tvar(const Vect2& s, const Vect2& v) const = 0;

  virtual LossData horizontal_WCV_interval(double T, const Vect2& s, const Vect2& v) const = 0;

  bool horizontal_WCV(const Vect2& s, const Vect2& v) const;

  bool violation(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi) const;

  bool conflict(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi, double B, double T) const;

  ConflictData conflictDetection(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi, double B, double T) const;

  LossData WCV3D(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi, double B, double T) const;

  LossData WCV_interval(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi, double B, double T) const;

private:
  void print_PVS_input(const Vect3& so, const Velocity& vo, const Vect3& si, const Velocity& vi, double B, double T) const;

  void print_PVS_output(double time_in, double time_out, const std::string& comment) const;

public:
   std::string toString() const;

  ParameterData getParameters() const;

  void updateParameterData(ParameterData& p) const;

  void setParameters(const ParameterData& p);

  virtual Detection3D* copy() const = 0;
  virtual Detection3D* make() const = 0;
  virtual std::string getSimpleClassName() const = 0;
  virtual std::string getSimpleSuperClassName() const {
    return "WCV_tvar";
  }

  std::string getIdentifier() const;

  void setIdentifier(const std::string& s);

  bool equals(Detection3D* o) const;


};
}
#endif
