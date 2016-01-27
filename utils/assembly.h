#include "GblTrajectory.h"

namespace gblsim {
  class plane {
  public:
    plane();
    plane(double position, double material, bool measurement, double resolution = 0);

    double position() { return m_position; }

  private:
    bool m_measurement;
    double m_resolution;
    bool m_scatterer;
    double m_materialbudget;
    double m_position;

    friend class telescope;
  };

  class telescope {
  public:
    telescope(std::vector<gblsim::plane> planes);

    // Return the trajectory
    gbl::GblTrajectory getTrajectory();

  private:
    std::vector<gbl::GblPoint> m_listOfPoints;
  };
}