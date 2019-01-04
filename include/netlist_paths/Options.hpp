#ifndef NETLIST_PATHS_OPTIONS_HPP
#define NETLIST_PATHS_OPTIONS_HPP

namespace netlist_paths {

constexpr int NULL_VERTEX_ID = 0;
constexpr int VERTEX_TYPE_STR_MAX_LEN = 16;
constexpr const char *DEFAULT_OUTPUT_FILENAME = "netlist";

struct Options {
  bool debugMode;
  bool displayHelp;
  bool dumpDotfile;
  bool dumpNames;
  bool allPaths;
  bool allFanOut;
  bool reportLogic;
  bool fullFileNames;
  bool compile;
  bool boostParser;
  Options() :
      debugMode(false),
      displayHelp(false),
      dumpDotfile(false),
      dumpNames(false),
      allPaths(false),
      allFanOut(false),
      reportLogic(false),
      fullFileNames(false),
      compile(false),
      boostParser(false) {}
};

} // End netlist_paths namespace.

extern netlist_paths::Options options;

#endif // NETLIST_PATHS_OPTIONS_HPP