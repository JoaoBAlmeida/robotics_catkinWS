// Generated by gencpp from file challenge02/Pos.msg
// DO NOT EDIT!


#ifndef CHALLENGE02_MESSAGE_POS_H
#define CHALLENGE02_MESSAGE_POS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace challenge02
{
template <class ContainerAllocator>
struct Pos_
{
  typedef Pos_<ContainerAllocator> Type;

  Pos_()
    : X(0)  {
    }
  Pos_(const ContainerAllocator& _alloc)
    : X(0)  {
  (void)_alloc;
    }



   typedef int64_t _X_type;
  _X_type X;





  typedef boost::shared_ptr< ::challenge02::Pos_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::challenge02::Pos_<ContainerAllocator> const> ConstPtr;

}; // struct Pos_

typedef ::challenge02::Pos_<std::allocator<void> > Pos;

typedef boost::shared_ptr< ::challenge02::Pos > PosPtr;
typedef boost::shared_ptr< ::challenge02::Pos const> PosConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::challenge02::Pos_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::challenge02::Pos_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::challenge02::Pos_<ContainerAllocator1> & lhs, const ::challenge02::Pos_<ContainerAllocator2> & rhs)
{
  return lhs.X == rhs.X;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::challenge02::Pos_<ContainerAllocator1> & lhs, const ::challenge02::Pos_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace challenge02

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::challenge02::Pos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::challenge02::Pos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::challenge02::Pos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::challenge02::Pos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::challenge02::Pos_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::challenge02::Pos_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::challenge02::Pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1e404dd3cb6d4bfb308931d7bf3cfb43";
  }

  static const char* value(const ::challenge02::Pos_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1e404dd3cb6d4bfbULL;
  static const uint64_t static_value2 = 0x308931d7bf3cfb43ULL;
};

template<class ContainerAllocator>
struct DataType< ::challenge02::Pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "challenge02/Pos";
  }

  static const char* value(const ::challenge02::Pos_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::challenge02::Pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 X\n"
;
  }

  static const char* value(const ::challenge02::Pos_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::challenge02::Pos_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.X);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Pos_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::challenge02::Pos_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::challenge02::Pos_<ContainerAllocator>& v)
  {
    s << indent << "X: ";
    Printer<int64_t>::stream(s, indent + "  ", v.X);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHALLENGE02_MESSAGE_POS_H
