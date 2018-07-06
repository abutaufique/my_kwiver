/*ckwg +29
 * Copyright 2018 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _KWIVER_ARROWS_NON_MAXIMUM_SUPPRESSION_H_
#define _KWIVER_ARROWS_NON_MAXIMUM_SUPPRESSION_H_

#include <arrows/core/kwiver_algo_core_export.h>

#include <vital/algo/refine_detections.h>

namespace kwiver {
namespace arrows {
namespace core {

// -----------------------------------------------------------------------------
/**
 * \class non_maximum_suppression
 *
 * \brief Prunes overlapping detections
 *
 * \iports
 * \iport{detections}
 *
 * \oports
 * \oport{pruned_detections}
 */
class KWIVER_ALGO_CORE_EXPORT non_maximum_suppression
  : public vital::algorithm_impl<non_maximum_suppression,
    vital::algo::refine_detections>
{

public:
  static constexpr char const* name = "non_maximum_suppression";

  static constexpr char const* description =
    "Refines detections based on overlap.\n\n"
    "This algorithm sorts through detections, pruning detections that heavily overlap with higher confidence detections.";

  non_maximum_suppression();
  virtual ~non_maximum_suppression();

  /// Get this algorithm's \link kwiver::vital::config_block configuration block \endlink
  virtual vital::config_block_sptr get_configuration() const;
  /// Set this algorithm's properties via a config block
  virtual void set_configuration(vital::config_block_sptr config);
  /// Check that the algorithm's currently configuration is valid
  virtual bool check_configuration(vital::config_block_sptr config) const;

  /// Refine all object detections on the provided image
  /**
   * This method analyzes the supplied image and and detections on it,
   * returning a refined set of detections.
   *
   * \param image_data the image pixels
   * \param detections detected objects
   * \returns vector of image objects refined
   */
  virtual vital::detected_object_set_sptr
  refine( vital::image_container_sptr image_data,
          vital::detected_object_set_sptr detections ) const;

private:

  /// private implementation class
  class priv;
  const std::unique_ptr<priv> d_;

 }; // end class non_maximum_suppression


}}} // end namespace
#endif /* _KWIVER_ARROWS_NON_MAXIMUM_SUPPRESSION_H_ */
