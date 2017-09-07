// This is the main DLL file.

#include "FastTextSharp.h"
#include "../../src/fasttext.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

namespace FastTextSharp {

  public ref class FastText
  {
  private:
    fasttext::FastText *_fastText;

  public:
    FastText(String ^path)
    {
      _fastText = new fasttext::FastText();
      _fastText->loadModel(msclr::interop::marshal_as<std::string>(path));
    }

    ~FastText()
    {
      delete _fastText;
      _fastText = 0;
    }

    IEnumerable<Tuple<String^, float>^>^ NearestNeighbor(String ^word, int matches)
    {
      std::vector<std::pair<float, std::string>> output;
      output.reserve(matches);
      _fastText->nn(msclr::interop::marshal_as<std::string>(word), matches, output);

      List<Tuple<String^, float>^>^ result = gcnew List<Tuple<String^, float>^>(matches);

      for (auto &i : output) {
        result->Add(Tuple::Create(msclr::interop::marshal_as<String^>(i.second), i.first));
      }

      return result;
    }
  };
}
