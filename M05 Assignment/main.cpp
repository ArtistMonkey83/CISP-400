#include"Topograph.h"

int main()
{
    string Biloxi = "Biloxi.txt";
    string BiloxiOutput = "BiloxiMap.bmp";
    string BiloxiBestPath = "BiloxiMap2.bmp";

    string sierraNevadas = "map_input.txt";
    string sierraNevadasOutput = "map.bmp";
    string sierraNevadasBestPath = "map2.bmp";

    string Charleston = "Charleston.txt";
    string CharlestonOutput = "charlestonMap.bmp";
    string CharlestonBestPath = "charlestonMap2.bmp";


    // Draw sierraNevadas map
    Topograph map1(sierraNevadas);
    cout << "Sierra Nevada Topography: " << endl;
    cout <<"Height in rows: " << map1.getHeight() << endl;
    cout << "Width in columns: " << map1.getWidth() << endl;
    Bmp bmp(map1.getHeight(),map1.getWidth());
    map1.drawMap(bmp);
    cout << "Maximum Elevation: " << map1.getMax() << endl;
    cout << "Minimum Elevation: " << map1.getMin() << endl;
    bmp.write(sierraNevadasOutput);
    system(("eog " + sierraNevadasOutput + " &" ).c_str());

    // Draw the Best path through sierraNevadas
    map1.drawBestPath(bmp);
    bmp.write(sierraNevadasBestPath);
    cout <<"Best path: " << map1.getBest() << endl;
    system(("eog " + sierraNevadasBestPath + " &").c_str());
    cout << "\n\n";

    // Draw Charleston map
    Topograph map2(Charleston);
    cout << "South Carolina Topography: " << endl;
    cout <<"Height in rows: " << map2.getHeight() << endl;
    cout << "Width in columns: " << map2.getWidth() << endl;
    Bmp bmp2(map2.getHeight(),map2.getWidth());
    map2.drawMap(bmp2);
    cout << "Maximum Elevation: " << map2.getMax() << endl;
    cout << "Minimum Elevation: " << map2.getMin() << endl;
    bmp2.write(CharlestonOutput);
    system(("eog " + CharlestonOutput + " &").c_str());

    // Draw the Best path from Georgia through Charleston to the Atlantic Ocean
    map2.drawBestPath(bmp2);
    bmp2.write(CharlestonBestPath);
    cout <<"Best path: " << map2.getBest() << endl;
    system(("eog " + CharlestonBestPath + " &").c_str());
    cout << "\n\n";

    // Draw Gulf of Mexico map
    Topograph map3(Biloxi);
    cout << "Gulf of Mexico Topography: " << endl;
    cout <<"Height in rows: " << map3.getHeight() << endl;
    cout << "Width in columns: " << map3.getWidth() << endl;
    Bmp bmp3(map3.getHeight(),map3.getWidth());
    map3.drawMap(bmp3);
    cout << "Maximum Elevation: " << map3.getMax() << endl;
    cout << "Minimum Elevation: " << map3.getMin() << endl;
    bmp3.write(BiloxiOutput);
    system(("eog " + BiloxiOutput + " &").c_str());


    // Draw the Best path along the Gulf of Mexico
    map3.drawBestPath(bmp3);
    bmp3.write(BiloxiBestPath);
    cout <<"Best path: " << map3.getBest() << endl;
    system(("eog " + BiloxiBestPath + " &").c_str());
    cout << "\n\n";


    return 0;
}
