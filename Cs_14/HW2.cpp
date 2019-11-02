 
string cmdfile;
//function will find and return the next largest root from a remainder starting
//with the root keepsqrtnum
int findNextRoot(int remaind, int ksqrtnum)
{
    if (ksqrtnum == 0)
    {
        return ksqrtnum;
    }
        while (((remaind / (ksqrtnum * ksqrtnum) == 0 && (ksqrtnum != 0))))
        {
            ksqrtnum -= 1;
            if (ksqrtnum == 0)
            {
                return (ksqrtnum);
            }
        
           ksqrtnum = findNextRoot(remaind, ksqrtnum);
        }
        
      
        return ksqrtnum;
        
}
//function will take a number and make change based on the root given
vector<int> cycleroots (int base, int ksqrtnum, vector<int>list, int coinmin)
{
    int coincount;
    int totalcoins = 0;
    while (ksqrtnum != 0)
    {
        coincount = base / (ksqrtnum * ksqrtnum);
        list.at(ksqrtnum - 1) = coincount;
        totalcoins += coincount;
        /*if (totalcoins > coinmin)
        {
            list.at(ksqrtnum - 1) = -1;
            return list;
        }*/
        
        base = base % (ksqrtnum * ksqrtnum);
        if (base == 0)
        {
            
            return list;
        }
       
        ksqrtnum = findNextRoot(base, ksqrtnum);
       
        list = cycleroots(base, ksqrtnum, list, coinmin);
    }
    
   
    return list;
}
// will take a root and subtract it from base, dependent on which root and how many iteratrions
//
vector<int> CompareSetSqr(int base, int ksqrtnum, int coinmin,
vector<int> coinlist, vector<int> tempcoinlist, bool verbose, vector<int> worklist,int truebase, 
ifstream & fin, ofstream & fout, bool dumb, bool smart, bool cache, bool & singlesquare, int & ticks) 
{
    //cout << "Beginning Compare" << endl;
    for (int a = 0; a < worklist.size(); a++)
            {
                worklist.at(a) = 0;
            }

    // int cointotal = 0;
    bool Largercheck = false;
    int sinsqucount = 0;
     int decreseptr;
     int basetemp = 0;
     int counter = 0;
     int largercheck = 0;
     char ast = '*';
    
    // if (ksqrtnum == 1 )
    // {
    //     return coinlist;
    // }
    //   iterations = base / (ksqrtnum * ksqrtnum);
    //   for (int i = iterations; i > 0; i--)
    //   {
    //         for (int h = 0; h < tempcoinlist.size(); h++)
    //         {
    //             tempcoinlist.at(h) = 0;
    //         }
    //       basetemp = base - ((ksqrtnum * ksqrtnum) * i);
          
    //       tempcoinlist = cycleroots(basetemp, (ksqrtnum - 1),
    //       tempcoinlist, coinmin);
    //       tempcoinlist.at(ksqrtnum - 1) = i;

            //cout << "Knum before prime cycle: " << ksqrtnum << endl;
            worklist.resize(ksqrtnum);
            worklist = cycleroots(base, ksqrtnum, worklist, coinmin);
            //cout << "Prime Cycle Complete" << endl;
            //cout << "worklist size: " << worklist.size() << endl;
            //cout << "tempcoinlist size: " << tempcoinlist.size() << endl;
            for(int e = 0; e < worklist.size(); e++)
            {
                tempcoinlist.at(e) = worklist.at(e); 
            }
            base = truebase;
            //cout << "Finished transfer" << endl;
            //cout << "Current base: " << base << endl;
            if(smart == true)
            {
            largercheck = 0;
            {
                for(int lg1 = tempcoinlist.size() - 1; lg1 > -1; lg1--)
                {
                    largercheck += tempcoinlist.at(lg1);
                    if (largercheck > coinmin || largercheck > 4)
                    {
                        if(verbose == true)
                        {
                        int check = 0;
                        for(int n = 0; n < tempcoinlist.size(); n++)
                            {
                                check = 0;
                                for (int o = n + 1; o < tempcoinlist.size(); o++)
                                {
                                    check += tempcoinlist.at(o);
                                }
                                if (check == 0)
                                {
                                    cout << tempcoinlist.at(n);   
                                    break;
                                }
                                if (n < (lg1))
                                {
                                    cout << "*,";
                                }
                
                                if (n >= (lg1) && n < tempcoinlist.size() - 1)
                                {
                                    cout << tempcoinlist.at(n) << ",";
                                }
                                if(n == tempcoinlist.size() - 1)
                                {
                                    cout << tempcoinlist.at(n);
                                }
                    
                    
                            }
                        cout << endl;
                        }
                        Largercheck = true;
                        ticks++;
                        break;
                        //cout << "LARGERCHECK IS NOW TRUE" << endl;
                        }
                    }
                }
            }
            //cout << "Finished larger check" << endl;
            
            counter = 0;
            for(int k = 0; k < tempcoinlist.size(); k++)
            {
                counter += tempcoinlist.at(k);
                
            }
            if (counter < coinmin)
            {
                coinmin = counter;
                for(int m = 0; m < tempcoinlist.size(); m++)
                {
                    coinlist.at(m) = tempcoinlist.at(m);
                }
            }
            //cout << "Finished counter min transfer" << endl;
             //output
             if (Largercheck == false)
             {
             
            if (verbose == true)
            {

                
            int check = 0;
            for(int d = 0; d < tempcoinlist.size(); d++)
                {
                    
                    check = 0;
                    for (int g = d + 1; g < tempcoinlist.size(); g++)
                    {
                        check += tempcoinlist.at(g);
                    }
                    if (check == 0)
                    {
                        cout << tempcoinlist.at(d);   
                        break;
                    }
                    if (d != (tempcoinlist.size() - 1))
                    {
                        cout << tempcoinlist.at(d) << ",";
                    }
                
                    if (d == tempcoinlist.size() - 1)
                    {
                        cout << tempcoinlist.at(d);
                    }
                    
                    
                }
            cout << endl;
            }
            }
            //endout    
            if(smart == true)
            {
            if(tempcoinlist.at(0) == 0)
            {
                for( int q = 1; q < tempcoinlist.size(); q++)
                {
                    if (tempcoinlist.at(q) != 0)
                    {
                        sinsqucount++;
                    }
                }
                if(sinsqucount == 1)
                {
                    singlesquare = true;
                    ticks ++;
                    return coinlist;
                }
                
            }
            }
            //cout << "Finished single square smart check" << endl;
            if(Largercheck == false)
            {
                
            decreseptr = 2;
            if(tempcoinlist.size() == 1)
            {
                coinlist.at(0) = tempcoinlist.at(0);
                ticks += coinlist.at(0);
                return coinlist;
            }
            while(tempcoinlist.at(1) != 0)
            {
                //cout << "Basetemp at start: " << basetemp << endl;
                //cout << "basetemp before addition of others: " << basetemp << endl;
                // for(int i = 2; i < (tempcoinlist.size()); i++)
                // {
                //     basetemp += (((i + 1) * (i + 1)) * tempcoinlist.at(i));
                // }
                //this part adds up the basetemp we need to subtract from base in order to cycle roots
                //cout << "Basetemp: " << basetemp << endl;
                basetemp = tempcoinlist.at(0) + 4;
                //cout << "Basetemp: " << basetemp << endl;
                //cout << "Base for 1st numplace cycle: " << base << endl;
                worklist = cycleroots(basetemp, 1, worklist, coinmin);
                tempcoinlist.at(0) = worklist.at(0);
                tempcoinlist.at(1) -= 1;
                basetemp = 0;
                ticks++;
                
            //output
                counter = 0;
                for(int k = 0; k < tempcoinlist.size(); k++)
                    {
                        counter += tempcoinlist.at(k);
                    }
                if (counter < coinmin)
                    {
                        coinmin = counter;
                        for(int m = 0; m < tempcoinlist.size(); m++)
                            {
                                coinlist.at(m) = tempcoinlist.at(m);
                            }
                    }
                if (verbose == true)
                {
                int check = 0;
                for(int c = 0; c < tempcoinlist.size(); c++)
                {
                    
                    check = 0;
                     for (int h = c + 1; h < tempcoinlist.size(); h++)
                    {
                        check += tempcoinlist.at(h);
                    }
                    if (check == 0)
                    {
                        cout << tempcoinlist.at(c);
                        break;
                    }
                    if (c != (tempcoinlist.size() - 1))
                    {
                        cout << tempcoinlist.at(c) << ",";
                    }
                
                    if (c == tempcoinlist.size() - 1)
                    {
                        cout << tempcoinlist.at(c);
                    }
                }
                cout << endl;
                }
            // endout
            if(smart == true)
                    {
                    if(tempcoinlist.at(0) == 0)
                    {
                        for( int q = 1; q < tempcoinlist.size(); q++)
                        {
                            if (tempcoinlist.at(q) != 0)
                            {
                                sinsqucount++;
                            }
                        }
                        if(sinsqucount == 1)
                        {
                            singlesquare = true;
                            ticks++;
                            return coinlist;
                        }
                
                    }
                    //cout << "Finished single square smart check" << endl;
                    }
                    
        
            }
            }
            //cout << "Found 2place zero" << endl;
            base = 0;
            for(int j = 2; j < tempcoinlist.size(); j++)
            {
                
                //cout << "Currently looking at: " << j << " J which is:" << tempcoinlist.at(j) << endl; 
                if(tempcoinlist.at(j) != 0)
                {
                    //cout << "Found nonzero" << endl;
                    base = (j + 1) * (j + 1);
                     for( int f = j - 1; f > -1; f--)
                     {
                         base += (((f + 1) * (f + 1)) * tempcoinlist.at(f));
                     }
                    //base -= (((j + 1) * (j + 1)) * tempcoinlist.at(j));
                    ksqrtnum =j;
                    tempcoinlist.at(j) -= 1;
                    //cout << "J found: " << j << endl;
                    //cout << "Current base going in: " << base << endl;
                    //cout << "Knum going in: " << ksqrtnum << endl;
                    
                    //cout << endl;
                    
                   
                   
                    //cout << "entering reccurstion" << endl;
                    coinlist = CompareSetSqr( base, ksqrtnum, coinmin, coinlist, tempcoinlist, 
                    verbose, worklist, truebase, fin, fout, dumb, smart, cache, singlesquare, ticks);
                    if(singlesquare == true)
                    {
                        //cout << "Returning single square" << endl;
                        return coinlist;
                    }
                    //cout << "Returned from recurrstion" << endl;
                    //cout << "Outputing current vector: " << endl;
                    for (int m = 0; m < tempcoinlist.size(); m++)
                        {
                            tempcoinlist.at(m) = 0;
                        }
                   
                }
                
            }
            //ffin.close();
            //ffout.close();
            //cout << "Returning standard" << endl;
            return coinlist;
        //     if (verbose == true)
        //     {
            
        //     fout << "MU ";
    
        //     for (int i = 0; i < ksqrtnum; i++)
        //     {
        //         if (i != (ksqrtnum - 1))
        //         {
        //         fout << tempcoinlist.at(i) << ",";
        //         }
                
        //         if (i == ksqrtnum - 1)
        //         {
        //             fout << tempcoinlist.at(i);
        //         }
        //     }
        //     fout << endl;
        //     }
            
            
        //     cointotal = 0;
            
        //     for (int j = 0; j < ksqrtnum; j++)
        //     {
        //         cointotal += tempcoinlist.at(j);
            
        //     }
        //   if (cointotal < coinmin)
        //   {
        //     for (int y = 0; y < coinlist.size(); y++)
        //     {
        //         coinlist.at(y) = 0;
        //     }
        //     for (int w = 0; w < tempcoinlist.size(); w++)
        //     {
        //         coinlist.at(w) = tempcoinlist.at(w);
        //     }
            
        //     for (int v = 0; v < tempcoinlist.size(); v++)
        //     {
        //         tempcoinlist.at(v) = 0;
        //     }
            
        //     coinmin = cointotal;
     
            //   for (int i = 0; i < ksqrtnum; i++)
            // {
            //     cout << coinlist.at(i) << " ";
            // }
//             // cout << endl;
               
//           }

//       }
    
//     ksqrtnum -= 1;
//     coinlist = CompareSetSqr(base,(ksqrtnum),coinmin, coinlist, tempcoinlist, verbose, worklist);
//   return coinlist;
}


int main(int argc, char **argv)
{
    cout << "Started" << endl;
   
    string cmdline;    
    string filename;

    const char * csvchar;
    const char * txtchar;
    const char * outchar;
    int tablemax;
    int ticks = 0;

    bool singlesquare = false;
    bool verbose = false;
    bool dumb = false;
    bool smart = false;
    bool cache = false;
    bool filenamecheck = false;
    bool smartconfirm = false;
    bool dumbconfirm = false;
    bool cacheconfirm = false;
    int basenum = 18;
    int sqrtnum;
    int keepsqrtnum;
    int basenumremain;
    string moneyamt;
    string moneytype;
    
    cout << "Checking First cmdline" << endl;
    cmdline = argv[1];
    tablemax = atoi(cmdline.c_str());
    
    for(int i = 2; i < argc - 1; i++)
    {
        cmdline = argv[i];
        // if (cmdline == "-v")
        // {
        //     verbose = true;
        //     cout << "Verbose confirmed" << endl;
        // }
        if (cmdline == "-dumb")
        {
            dumb = true;
            cout << "dumb confirmed" << endl;
             
        }
        else if (cmdline == "-smart")
        {
            smart = true;
            cout << "smart confirmed" << endl;
        }
        else if (cmdline == "-cache")
        {
            cache = true;
            cout << "cache confirmed" << endl;
        }
        

    }
    cmdfile = argv[argc - 1];
                filename = cmdfile;
                string txtfile = filename;
                string outfile = filename + ".out";
                string csvfile = filename + ".csv";
                csvchar = csvfile.c_str();
                txtchar = txtfile.c_str();
                outchar = outfile.c_str();
                filenamecheck = true;
                cout << "Filename confirmed" << endl;

    cout << "command line arguments received" << endl;
    //  if(filenamecheck == true)
    //  
             cout << "current outchar:" << outchar << endl;
             ifstream fin (txtchar);
             ofstream fout (outchar);
             ofstream ffout (csvchar);
    //  }
    //  else
    //  {
         //ifstream fin ("Default.txt");
         //ofstream fout ("Default.out");
    // }
        
     if (dumb == true)
    {
        ffout << "-Dumb" << endl;
        for (int m = 1; m < tablemax; m++)
        {
            ffout << m << " ";
        }
        ffout << endl;

        fout << "-Dumb" << endl;
    for (int j = 1; j < tablemax; j++)
    {
        //if(moneytype == "EA")
        //{
       
        basenum = j;
        //cout << "Basenum: " << basenum << endl;
       
        
        sqrtnum = sqrt(basenum);
    
    keepsqrtnum = sqrtnum;
    //cout << "ksqrtnum: " << keepsqrtnum << endl;
    
   
    
    basenumremain = basenum % sqrtnum;
    
    vector<int> coinlist((keepsqrtnum));
    vector<int> tempcoinlist (keepsqrtnum);
    vector<int> worklist (keepsqrtnum);
    int coinmin = basenum;
    
   
    dumbconfirm = true;
    ticks = 0;
    fout << "EU: " << tablemax << " = ";
    coinlist = CompareSetSqr (basenum, keepsqrtnum, basenum, coinlist, tempcoinlist, verbose, 
    worklist, basenum, fin, fout, dumbconfirm, smartconfirm, cacheconfirm, singlesquare, ticks);
    ticks = (j * (j + j));
    ffout << ticks << " ";
    fout << "MU ";
    for (int i = 0; i < coinlist.size(); i++)
            {
                if (i < coinlist.size() - 1 )
                {
                fout << coinlist.at(i) << ",";
                }
                if (i == coinlist.size() - 1)
                {
                    fout << coinlist.at(i) ;
                }
            }
            
            fout << endl;
            //cout << endl;

    }
            ffout << endl;
        ffout << endl;
    }
    
    if (smart == true)
    {
        ffout << "-Smart" << endl;
        for (int o = 1; o < tablemax; o++)
        {
            ffout << o << " ";
        }
        ffout << endl;
        fout << "-Smart" << endl;
    for (int k = 1; k < tablemax; k++)
    {
        //if(moneytype == "EA")
        //{
       
        basenum = k;
        //cout << "Basenum: " << basenum << endl;
       
        
        sqrtnum = sqrt(basenum);
    
    keepsqrtnum = sqrtnum;
    //cout << "ksqrtnum: " << keepsqrtnum << endl;
    
   
    
    basenumremain = basenum % sqrtnum;
    
    vector<int> coinlist((keepsqrtnum));
    vector<int> tempcoinlist (keepsqrtnum);
    vector<int> worklist (keepsqrtnum);
    int coinmin = basenum;
    
    
    smartconfirm = true;
    ticks = 0;
    fout << "EU: " << tablemax << " = ";
    coinlist = CompareSetSqr (basenum, keepsqrtnum, basenum, coinlist, tempcoinlist, verbose, 
    worklist, basenum, fin, fout, dumbconfirm, smartconfirm, cacheconfirm, singlesquare, ticks);
      ffout << ticks << " ";
    fout << "MU ";
    for (int i = 0; i < coinlist.size(); i++)
            {
                if (i < coinlist.size() - 1 )
                {
                fout << coinlist.at(i) << ",";
                }
                if (i == coinlist.size() - 1)
                {
                    fout << coinlist.at(i) ;
                }
            }
            
            fout << endl;
            //cout << endl;

    }
        ffout << endl;
        ffout << endl;
    }
    
    if (cache == true)
    {
        
        ffout << "-Cache" << endl;
        for (int p = 1; p < tablemax; p++)
        {
            ffout << p << " ";
        }
        ffout << endl;

        fout << "-Cache" << endl;

    for (int l = 1; l < tablemax; l++)
    {
        //if(moneytype == "EA")
        //{
       
        basenum = l;
        //cout << "Basenum: " << basenum << endl;
       
        
        sqrtnum = sqrt(basenum);
    
    keepsqrtnum = sqrtnum;
    //cout << "ksqrtnum: " << keepsqrtnum << endl;
    
   
    
    basenumremain = basenum % sqrtnum;
    
    vector<int> coinlist((keepsqrtnum));
    vector<int> tempcoinlist (keepsqrtnum);
    vector<int> worklist (keepsqrtnum);
    int coinmin = basenum;
    
    
    cacheconfirm = true;
    smartconfirm = true;
    ticks = 0;
    fout << "EU: " << tablemax << " = ";
    coinlist = CompareSetSqr (basenum, keepsqrtnum, basenum, coinlist, tempcoinlist, verbose, 
    worklist, basenum, fin, fout, dumbconfirm, smartconfirm, cacheconfirm, singlesquare, ticks);
    int count = 0;
    for(int r = 0; r < coinlist.size(); r++)
    {
        count += coinlist.at(r);
    }
    ticks = count;
    
        ffout << ticks << " ";
    fout << "MU ";
    for (int i = 0; i < coinlist.size(); i++)
            {
                if (i < coinlist.size() - 1 )
                {
                fout << coinlist.at(i) << ",";
                }
                if (i == coinlist.size() - 1)
                {
                    fout << coinlist.at(i) ;
                }
            }
            
            fout << endl;
            //cout << endl;

    }
            ffout << endl;
        ffout << endl;
    }
     
    //cout << "finished CompareSetSquare call" << endl;
     if (verbose == true)
    {
        
    //fout << "MU " << basenum << endl;
    
    
    
    
    //cout << "A legal representation of this ammout is:" << endl;
     
    }
    
    
    
     
    
    // if (moneytype == "MU")
    // {
        
    //     fout << endl;
        
    //     vector<int> MUvec;
    //     stringstream sstream (moneyamt);
    //     MUvec.push_back(0);
    //     int savenum;
    //     int total = 0;
        
    //     while (sstream >> savenum )
    //     {
    //         MUvec.push_back(savenum);
    //         if (sstream.peek() == ',')
    //         {
    //             sstream.ignore();
    //         }
    //     }
        
    //     for (int i = 1; i < MUvec.size(); i++)
        
    //     {
    //         total += (MUvec.at(i) * (i * i));
    //     }
        
    //     fout << "MU " << moneyamt << " = " << total << " EA" << endl;
    //     fout << endl;
        
    // }
    
    
    // }
   
    
    /* int coincount = 0;
    vector<int> coinlist(ksqrtnum);
    
    coinlist=
    cycleroots(base, ksqrtnum, coinlist, coincount, cointotal);
    
    cout << "Made it" << endl;
    
   for (int i = 0; i < ksqrtnum; i++)
    {
        cout << coinlist.at(i) << " ";
    }
    
    return 1;*/
    cout << "Finished program" << endl;
    fin.close();
    fout.close();
    ffout.close();
    
    return 0;

}
    
    
    

