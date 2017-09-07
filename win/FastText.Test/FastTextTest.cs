using System;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FastText.Test
{
  [TestClass]
  public class FastTextTest
  {
    [TestMethod]
    public void NearestNeighbor()
    {
      using (var engine = new FastTextSharp.FastText(@"C:\Users\eric.domke\Documents\Code\fastText-master\tests\result\lumen_03.bin"))
      {
        var matches = engine.NearestNeighbor("domke", 20);
        Assert.AreEqual(20, matches.Count());
      }
    }
  }
}
