// Copyright 2022 Kenji Brameld
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <QPainter>
#include "vision_msgs_layers/bounding_box_2d.hpp"

namespace vision_msgs_layers
{

void BoundingBox2D::overlay(
  QPainter & painter,
  const vision_msgs::msg::BoundingBox2D & msg)
{
  painter.save();

  QPen pen = painter.pen();
  pen.setWidth(2);
  painter.setPen(pen);

  // Draw Bounding Box and Confidence
  painter.translate(msg.center.position.x, msg.center.position.y);
  painter.rotate(-msg.center.theta * 180.0 / 3.141592654);
  painter.drawRect(-msg.size_x / 2, -msg.size_y / 2, msg.size_x, msg.size_y);

  painter.restore();
}

}  // namespace vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(vision_msgs_layers::BoundingBox2D, rqt_image_overlay_layer::PluginInterface)
