// scan the file sequentially checking that each record was stored properly
    cout << "scan file dummy.02 " << endl;
    scan1 = new HeapFileScan("dummy.02", status);
    if (status != OK)
        error.print(status);
    else {
        scan1->startScan(0, 0, STRING, NULL, EQ);
        i = 0;

        while (((status = scan1->scanNext(rec2Rid)) != FILEEOF)) {
            // reconstruct record i
            sprintf(rec1.s, "This is record %05d", i);
            rec1.i = i;
            rec1.f = i;
            status = scan1->getRecord(dbrec2);
            if (status != OK) break;
            if (memcmp(&rec1, dbrec2.data, sizeof(RECORD)) != 0)
                cout << "err0r reading record " << i << " back" << endl;
            i++;
        }