#pragma once

#include <franka_hw/franka_state_interface.h>
#include <hardware_interface/internal/hardware_resource_manager.h>
#include <string>

namespace franka_hw {

/** \brief A handle used to read and command a Cartesian Pose to a Franka. */
class FrankaCartesianPoseHandle : public FrankaStateHandle {
 public:
  FrankaCartesianPoseHandle() = delete;

  /**
   * \param cartesian_state_handle The cartesian state handle
   * \param command A reference to the storage field for the cartesian pose
   * passed a desired homogeneous transformation O_T_EE_d
   */
  FrankaCartesianPoseHandle(const FrankaStateHandle& franka_state_handle,
                            std::array<double, 16>& command)
      : FrankaStateHandle(franka_state_handle), command_(&command) {}

  void setCommand(const std::array<double, 16>& command) {
    *command_ = command;
  }
  const std::array<double, 16>& getCommand() const { return *command_; }

 private:
  std::array<double, 16>* command_;
};

/** \brief Hardware interface to support commanding Cartesian poses to a Franka.
 */
class FrankaPoseCartesianInterface
    : public hardware_interface::HardwareResourceManager<
          FrankaCartesianPoseHandle,
          hardware_interface::ClaimResources> {};

/** \brief A handle used to read and command a Cartesian Velocity to a Franka.
 */
class FrankaCartesianVelocityHandle : public FrankaStateHandle {
 public:
  FrankaCartesianVelocityHandle() = delete;

  /**
   * \param cartesian_state_handle The cartesian state handle
   * \param command A reference to the storage field for the cartesian velocity
   * passed a desired homogeneous transformation O_T_EE_d
   */
  FrankaCartesianVelocityHandle(const FrankaStateHandle& franka_state_handle,
                                std::array<double, 6>& command)
      : FrankaStateHandle(franka_state_handle), command_(&command) {}

  void setCommand(std::array<double, 6>& command) { *command_ = command; }
  const std::array<double, 6>& getCommand() const { return *command_; }

 private:
  std::array<double, 6>* command_;
};

/** \brief Hardware interface to support commanding Cartesian velocities to a
 * Franka
 */
class FrankaVelocityCartesianInterface
    : public hardware_interface::HardwareResourceManager<
          FrankaCartesianVelocityHandle,
          hardware_interface::ClaimResources> {};

}  // namespace franka_hw
