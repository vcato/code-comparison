#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::cout;
using std::ostringstream;


static string quoted(const string &s)
{
  return '"' + s + '"';
}

static string operator ""_q(const char *s,size_t)
{
  return '"' + string(s) + '"';
}


static string member(const char *key,int value)
{
  ostringstream stream;

  stream << quoted(key) << ": " << value;

  return stream.str();
}


static string member(const char *key,const string &value)
{
  ostringstream stream;

  stream << quoted(key) << ": " << quoted(value);

  return stream.str();
}


static void usingEscapedQuotes()
{
  int frameno = 0;
  string TimeCode = "\"01:02:03:04\"";
  ostringstream ss;
  ss << "1";
  ostringstream stream;

  stream << "{\n";
  stream << "\"kind\": 3,\n";
  stream << "\"ver\": 1,\n";
  stream << "\"frameno\": " << frameno << ",\n";
  stream << "\"timecode\": " << TimeCode << ",\n";
  stream << "\"channels\": [\n";
  stream << ss.str() << "\n";
  stream << "]\n";
  stream << "}\n";

  cout << stream.str() << "\n";
}


static void usingRawStringLiterals()
{
  int frameno = 0;
  string TimeCode = R"("01:02:03:04")";
  ostringstream ss;
  ss << "1";
  ostringstream stream;

  stream << "{\n";
  stream << R"("kind": 3,)" "\n";
  stream << R"("ver": 1,)" "\n";
  stream << R"("frameno": )" << frameno << ",\n";
  stream << R"("timecode": )" << TimeCode << ",\n";
  stream << R"("channels": [)" "\n";
  stream << ss.str() << "\n";
  stream << "]\n";
  stream << "}\n";

  cout << stream.str() << "\n";
}


static void usingQuotedFunction()
{
  int frameno = 0;
  string TimeCode = "01:02:03:04";
  ostringstream ss;
  ss << "1";
  ostringstream stream;

  stream << "{\n";
  stream << quoted("kind") << ": 3,\n";
  stream << quoted("ver") << ": 1,\n";
  stream << quoted("frameno") << ": " << frameno << ",\n";
  stream << quoted("timecode") << ": " << quoted(TimeCode) << ",\n";
  stream << quoted("channels") << ": [\n";
  stream << ss.str() << "\n";
  stream << "]\n";
  stream << "}\n";

  cout << stream.str() << "\n";
}


static void usingUserDefinedLiteral()
{
  int frameno = 0;
  string TimeCode = "01:02:03:04";
  ostringstream ss;
  ss << "1";
  ostringstream stream;

  stream << "{\n";
  stream << "kind"_q << ": 3,\n";
  stream << "ver"_q << ": 1,\n";
  stream << "frameno"_q << ": " << frameno << ",\n";
  stream << "timecode"_q << ": " << quoted(TimeCode) << ",\n";
  stream << "channels"_q << ": [\n";
  stream << ss.str() << "\n";
  stream << "]\n";
  stream << "}\n";

  cout << stream.str() << "\n";
}


static void usingMemberHelper()
{
  int frameno = 0;
  string TimeCode = "01:02:03:04";
  ostringstream ss;
  ss << "1";
  ostringstream stream;

  stream << "{\n";
  stream << member("kind",3) << ",\n";
  stream << member("ver",1) << ",\n";
  stream << member("frameno",frameno) << ",\n";
  stream << member("timecode",TimeCode) << ",\n";
  stream << "channels"_q << ": [\n";
  stream << ss.str() << "\n";
  stream << "]\n";
  stream << "}\n";

  cout << stream.str() << "\n";
}


int main()
{
  usingEscapedQuotes();
  usingRawStringLiterals();
  usingQuotedFunction();
  usingUserDefinedLiteral();
  usingMemberHelper();
}
