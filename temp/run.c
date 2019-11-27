{                                                                                  
TChain chain("tree");                                                        
chain.Add("MyEvents.root");  
chain.Add("MyEvents1.root");  
                                                                                   
cout << chain->GetEntries() << endl;                                               
///////////////////////////chain->MakeSelector("slicer");                          
chain->Process("SelectorName.C");                                                        
//chain->Process("slicer.C","",1000000,0);                                         
                                                                                   
gSystem->Exit(0);                                                                  
                                                                                   
}                                                                                  