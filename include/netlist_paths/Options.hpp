#ifndef NETLIST_PATHS_OPTIONS_HPP
#define NETLIST_PATHS_OPTIONS_HPP

namespace netlist_paths {

constexpr int NULL_VERTEX_ID = 0;
constexpr int VERTEX_TYPE_STR_MAX_LEN = 16;
constexpr const char *DEFAULT_OUTPUT_FILENAME = "netlist";

struct Options {
  bool debugMode;
  bool verboseMode;
  bool displayHelp;
  bool dumpDotfile;
  bool dumpNames;
  bool allPaths;
  bool startPoints;
  bool endPoints;
  bool fanOutDegree;
  bool fanInDegree;
  bool reportLogic;
  bool fullFileNames;
  bool compile;
  bool boostParser;
  Options() :
      debugMode(true),
      verboseMode(true),
      displayHelp(false),
      dumpDotfile(false),
      dumpNames(false),
      allPaths(false),
      startPoints(false),
      endPoints(false),
      fanOutDegree(false),
      fanInDegree(false),
      reportLogic(false),
      fullFileNames(false),
      compile(false),
      boostParser(false) {}
};

extern netlist_paths::Options options;

} // End netlist_paths namespace.

#endif // NETLIST_PATHS_OPTIONS_HPP
