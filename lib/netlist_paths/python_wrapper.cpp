#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "netlist_paths/Exception.hpp"
#include "netlist_paths/Options.hpp"
#include "netlist_paths/RunVerilator.hpp"
#include "netlist_paths/NetlistPaths.hpp"

void translateException(const netlist_paths::Exception& e) {
  PyErr_SetString(PyExc_RuntimeError, e.what());
};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_vertex_dtype_str_overloads,
                                       getVertexDTypeStr, 1, 2);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_vertex_dtype_width_overloads,
                                       getVertexDTypeWidth, 1, 2);

BOOST_PYTHON_MODULE(py_netlist_paths)
{
  using namespace boost::python;
  using namespace netlist_paths;

  register_exception_translator<Exception>(&translateException);

  class_<Path>("Path")
     .def(vector_indexing_suite<Path>());

  class_<Options, boost::noncopyable>("Options", no_init)
    .def("get_instance",       &Options::getInstancePtr,
                               return_value_policy<reference_existing_object>())
    .staticmethod("get_instance")
    .def("set_match_wildcard", &Options::setMatchWildcard)
    .def("set_match_regex",    &Options::setMatchRegex);

  int (RunVerilator::*run)(const std::string&, const std::string&) const = &RunVerilator::run;

  class_<RunVerilator, boost::noncopyable>("RunVerilator",
                                           init<const std::string&>())
    .def("run", run);

  class_<NetlistPaths, boost::noncopyable>("NetlistPaths",
                                           init<const std::string&>())
    .def("reg_exists",             &NetlistPaths::regExists)
    .def("startpoint_exists",      &NetlistPaths::startpointExists)
    .def("endpoint_exists",        &NetlistPaths::endpointExists)
    .def("path_exists",            &NetlistPaths::pathExists)
    .def("get_any_path",           &NetlistPaths::getAnyPath)
    .def("dump_names",             &NetlistPaths::dumpNamesStdOut)
    .def("get_dtype_width",        &NetlistPaths::getDTypeWidth)
    .def("get_vertex_dtype_str",   &NetlistPaths::getVertexDTypeStr,
                                   get_vertex_dtype_str_overloads())
    .def("get_vertex_dtype_width", &NetlistPaths::getVertexDTypeWidth,
                                   get_vertex_dtype_width_overloads());
}
