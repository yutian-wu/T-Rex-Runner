
// CPP
#include <math.h>

// LOCAL
#include "game_object.h"
#include "renderer.h"
#include "game_env.h"
#include "utility.h"


GameObject::GameObject(TRex::Object obj, double x, double y) : obj_(obj)
{
  x_ = x;
  y_ = y;
  
  a_x_ = 0;
  a_y_ = 0;
  
  v_x_ = 0;
  v_y_ = 0;
  
	collided_ = false;
}


GameObject::~GameObject() {}


void GameObject::Render(Renderer& renderer)
{
  GameShape src_rect, dest_rect;
  src_rect.x = dest_rect.x = x_;
  src_rect.y = dest_rect.y = y_;
  src_rect.w = dest_rect.w = width_;
  src_rect.h = dest_rect.h = height_;
  
  int s_width, s_height;
  renderer.GetSceneSize(s_width, s_height);
  
  if ((x_ >= s_width || (x_ < 0 && x_ + width_ <= 0)) ||
      (y_ >= s_height || (y_ < 0 && y_ + height_ <= 0)))
  {
    state_ = Out;
  }
  else
  {
    dest_rect.x = getMax(x_, 0);
    src_rect.w = dest_rect.w = getMin(x_ + width_, s_width) - dest_rect.x;
    dest_rect.y = getMax(y_, 0);
    src_rect.h = dest_rect.h = getMin(y_ + height_, s_height) - dest_rect.y;
    src_rect.x = dest_rect.x - x_;
    src_rect.y = dest_rect.y - y_;
    renderer.Render(obj_, &src_rect, &dest_rect);
  }
}


bool GameObject::CollidedWith(const GameObject& obj, int w, int h) const
{
  int width  = (w >= 0)? w : width_;
  int height = (h >= 0)? h : height_;
  
  return (x_ + width >= obj.x_ &&
          x_ <= obj.x_ + obj.width_ &&
          y_ + height >= obj.y_ &&
          y_ <= obj.y_ + obj.height_);
}



void GameObject::UpdateLocation(double time)
{
  x_ += displacement(v_x_, a_x_, time);
  y_ += displacement(v_y_, a_y_, time);
  v_x_ += time * a_x_;
  v_y_ += time * a_y_;
}


void GameObject::SetSize(int width, int height)
{
  if (width != -1) width_ = width;
  if (height != -1) height_ = height;
}

void GameObject::SetPosition(double x, double y)
{
  if (x != -1) x_ = x;
  if (y != -1) y_ = y;
}

void GameObject::SetVx(double v_x)
{
  v_x_ = v_x;
}

void GameObject::SetVy(double v_y)
{
  v_y_ = v_y;
}

void GameObject::SpeedUp(double scale)
{
  v_y_ = scale * v_y_;
  v_x_ = scale * v_x_;
}


double GameObject::GetY()
{
  return y_;
}


double GameObject::GetX()
{
  return x_;
}


int GameObject::GetWidth()
{
  return width_;
}


int GameObject::GetHeight()
{
  return height_;
}

double GameObject::GetTopRightX()
{
  return x_ + width_;
}

double GameObject::GetVY()
{
  return v_y_;
}

double GameObject::GetVX()
{
  return v_x_;
}
