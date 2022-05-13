#include "ccngen/actions.h"
#include "ccn/ccn_types.h"
#include "ccn/dynamic_core.h"
const ccn_trav_ft print_vtable[_NT_SIZE] = { &TRAVerror, &PRTid, &PRTienum, &PRTattribute, &PRTitravdata, &PRTsetoperation, &PRTsetliteral, &PRTsetreference, &PRTste, &PRTchild, &PRTlifetime_range, &PRTilifetime, &PRTinodeset, &PRTinode, &PRTipass, &PRTitraversal, &PRTiphase, &PRTiactions, &PRTast, };
const ccn_trav_ft setliteralcontains_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &SLCsetliteral, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft setliteraldifference_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &SLDsetliteral, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft setliteralintersect_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &SLISsetliteral, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft setliteralunion_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &SLUsetliteral, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft setliteralinsert_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &SLIsetliteral, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft reachability_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &RCBsetliteral, &TRAVnop, &TRAVnop, &RCBchild, &TRAVnop, &TRAVnop, &RCBinodeset, &RCBinode, &TRAVnop, &RCBitraversal, &TRAVnop, &TRAVnop, &RCBast, };
const ccn_trav_ft unwrapsetexpr_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &USEsetoperation, &USEsetliteral, &USEsetreference, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &USEast, };
const ccn_trav_ft buildsymboltable_vtable[_NT_SIZE] = { &TRAVerror, &BSTid, &BSTienum, &BSTattribute, &BSTitravdata, &BSTsetoperation, &BSTsetliteral, &BSTsetreference, &BSTste, &BSTchild, &BSTlifetime_range, &BSTilifetime, &BSTinodeset, &BSTinode, &BSTipass, &BSTitraversal, &BSTiphase, &BSTiactions, &BSTast, };
const ccn_trav_ft checkexistance_vtable[_NT_SIZE] = { &TRAVerror, &CEXid, &CEXienum, &CEXattribute, &CEXitravdata, &CEXsetoperation, &CEXsetliteral, &CEXsetreference, &CEXste, &CEXchild, &CEXlifetime_range, &CEXilifetime, &CEXinodeset, &CEXinode, &CEXipass, &CEXitraversal, &CEXiphase, &CEXiactions, &CEXast, };
const ccn_trav_ft dynamicgennodemacros_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &DGNMattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGNMchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGNMinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGNMast, };
const ccn_trav_ft dynamicgennodestructs_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &DGNSattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGNSchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGNSinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGNSast, };
const ccn_trav_ft dynamicgennodeinitfunctions_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &DGIFattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGIFchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGIFinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGIFast, };
const ccn_trav_ft dynamicgennodeunion_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &DGBUinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGBUast, };
const ccn_trav_ft dynamicgennodeconstructor_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &DGNCattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGNCchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGNCinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGNCast, };
const ccn_trav_ft dynamicgenenum_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &DGEinodeset, &DGEinode, &DGEipass, &DGEitraversal, &TRAVnop, &TRAVnop, &DGEast, };
const ccn_trav_ft dynamicgenenumvalues_vtable[_NT_SIZE] = { &TRAVerror, &DGEVid, &DGEVienum, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVnop, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &DGEVast, };
const ccn_trav_ft dynamicgentravvtable_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTVitraversal, &TRAVnop, &TRAVnop, &DGTVast, };
const ccn_trav_ft dynamicgennodesfortravtable_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &DGNFTTinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGNFTTast, };
const ccn_trav_ft dynamicgenpasstable_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &DGPTipass, &TRAVchildren, &TRAVnop, &TRAVnop, &DGPTast, };
const ccn_trav_ft dynamicgentravtable_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTTitraversal, &TRAVnop, &TRAVnop, &DGTTast, };
const ccn_trav_ft dynamicgensystemtraversals_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &DGSTinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGSTast, };
const ccn_trav_ft dynamicgenactionsheader_vtable[_NT_SIZE] = { &TRAVerror, &DGAHid, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &DGAHsetliteral, &TRAVchildren, &TRAVnop, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &DGAHinode, &DGAHipass, &DGAHitraversal, &TRAVchildren, &TRAVchildren, &DGAHast, };
const ccn_trav_ft dynamicgentravactions_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &DGTAinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTAast, };
const ccn_trav_ft dynamicgencopytraversal_vtable[_NT_SIZE] = { &TRAVerror, &DGCTid, &DGCTienum, &DGCTattribute, &DGCTitravdata, &DGCTsetoperation, &DGCTsetliteral, &DGCTsetreference, &DGCTste, &DGCTchild, &DGCTlifetime_range, &DGCTilifetime, &DGCTinodeset, &DGCTinode, &DGCTipass, &DGCTitraversal, &DGCTiphase, &DGCTiactions, &DGCTast, };
const ccn_trav_ft dynamicgenconstructorcall_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &DGCCattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGCCchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGCCinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGCCast, };
const ccn_trav_ft dynamicgenmarktraversal_vtable[_NT_SIZE] = { &TRAVerror, &DGMTid, &DGMTienum, &DGMTattribute, &DGMTitravdata, &DGMTsetoperation, &DGMTsetliteral, &DGMTsetreference, &DGMTste, &DGMTchild, &DGMTlifetime_range, &DGMTilifetime, &DGMTinodeset, &DGMTinode, &DGMTipass, &DGMTitraversal, &DGMTiphase, &DGMTiactions, &DGMTast, };
const ccn_trav_ft dynamicgenfreetraversal_vtable[_NT_SIZE] = { &TRAVerror, &DGFTid, &DGFTienum, &DGFTattribute, &DGFTitravdata, &DGFTsetoperation, &DGFTsetliteral, &DGFTsetreference, &DGFTste, &DGFTchild, &DGFTlifetime_range, &DGFTilifetime, &DGFTinodeset, &DGFTinode, &DGFTipass, &DGFTitraversal, &DGFTiphase, &DGFTiactions, &DGFTast, };
const ccn_trav_ft dynamicgenchecktraversal_vtable[_NT_SIZE] = { &TRAVerror, &DGCHTid, &DGCHTienum, &DGCHTattribute, &DGCHTitravdata, &DGCHTsetoperation, &DGCHTsetliteral, &DGCHTsetreference, &DGCHTste, &DGCHTchild, &DGCHTlifetime_range, &DGCHTilifetime, &DGCHTinodeset, &DGCHTinode, &DGCHTipass, &DGCHTitraversal, &DGCHTiphase, &DGCHTiactions, &DGCHTast, };
const ccn_trav_ft dynamicgentravdatastructs_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &DGTDSitravdata, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDSitraversal, &TRAVnop, &TRAVnop, &DGTDSast, };
const ccn_trav_ft dynamicgentravdatactors_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &DGTDCitravdata, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDCitraversal, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft dynamicgentravdatactorsheader_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDCHitraversal, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft dynamicgentravdatagetters_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDGitraversal, &TRAVnop, &TRAVnop, &TRAVchildren, };
const ccn_trav_ft dynamicgentravdataunion_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDUitraversal, &TRAVnop, &TRAVnop, &DGTDUast, };
const ccn_trav_ft dynamicgentravfunctions_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &DGT_Fchild, &TRAVnop, &TRAVnop, &TRAVchildren, &DGT_Finode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGT_Fast, };
const ccn_trav_ft genactionarray_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &GAAipass, &GAAitraversal, &GAAiphase, &TRAVnop, &GAAast, };
const ccn_trav_ft genactionarrayheader_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &GAAHipass, &GAAHitraversal, &GAAHiphase, &TRAVnop, &GAAHast, };
const ccn_trav_ft genidstables_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &GITiphase, &GITiactions, &GITast, };
const ccn_trav_ft gengateheader_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &GGHiphase, &TRAVnop, &GGHast, };
const ccn_trav_ft dynamicgentravdatatables_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &DGTDTitraversal, &TRAVnop, &TRAVnop, &DGTDTast, };
const ccn_trav_ft gendot_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &GDattribute, &TRAVnop, &TRAVchildren, &GDsetliteral, &TRAVnop, &TRAVnop, &GDchild, &TRAVnop, &TRAVnop, &GDinodeset, &GDinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &GDast, };
const ccn_trav_ft dynamicusergentraversals_vtable[_NT_SIZE] = { &TRAVerror, &DUGTid, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVnop, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &DUGTinode, &TRAVchildren, &DUGTitraversal, &TRAVchildren, &TRAVchildren, &DUGTast, };
const ccn_trav_ft dynamicusergenpasses_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &DUGPipass, &TRAVchildren, &TRAVnop, &TRAVnop, &DUGPast, };
const ccn_trav_ft staticgennodestructs_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &SGNSattribute, &TRAVnop, &TRAVchildren, &SGNSsetliteral, &TRAVnop, &TRAVnop, &SGNSchild, &TRAVnop, &TRAVnop, &SGNSinodeset, &SGNSinode, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &SGNSast, };
const ccn_trav_ft mapidtolifetime_vtable[_NT_SIZE] = { &TRAVerror, &MITLid, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVchildren, &TRAVnop, &TRAVchildren, &MITLlifetime_range, &MITLilifetime, &TRAVchildren, &MITLinode, &TRAVchildren, &TRAVchildren, &TRAVchildren, &MITLiactions, &MITLast, };
const ccn_trav_ft assignidtoaction_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVchildren, &AITAiactions, &AITAast, };
const ccn_trav_ft checklifetimes_vtable[_NT_SIZE] = { &TRAVerror, &TRAVnop, &TRAVnop, &CLTattribute, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVnop, &TRAVchildren, &TRAVchildren, &TRAVnop, &TRAVchildren, &TRAVnop, &TRAVnop, &CLTast, };
const ccn_pass_ft ccn_pass_vtable[_PASS_SIZE] = { &PASSerror, &dynamicGenBaseNodeInit, &dynamicSwitchToAstSource, &dynamicGenBaseNode, &dynamic_start_ast_header, &dynamicSwitchTravData, &dynamicStartTravData, &dynamicStartTableGen, &dynamicStartEnumHeader, &doOpts, &genDefines, &SPscanAndParse, };
const ccn_trav_ft ccn_copy_vtable[_NT_SIZE] = { &TRAVerror, &CPYid, &CPYienum, &CPYattribute, &CPYitravdata, &CPYsetoperation, &CPYsetliteral, &CPYsetreference, &CPYste, &CPYchild, &CPYlifetime_range, &CPYilifetime, &CPYinodeset, &CPYinode, &CPYipass, &CPYitraversal, &CPYiphase, &CPYiactions, &CPYast, };
const ccn_trav_ft ccn_check_vtable[_NT_SIZE] = { &TRAVerror, &CHKid, &CHKienum, &CHKattribute, &CHKitravdata, &CHKsetoperation, &CHKsetliteral, &CHKsetreference, &CHKste, &CHKchild, &CHKlifetime_range, &CHKilifetime, &CHKinodeset, &CHKinode, &CHKipass, &CHKitraversal, &CHKiphase, &CHKiactions, &CHKast, };
const ccn_trav_ft ccn_free_vtable[_NT_SIZE] = { &TRAVerror, &DELid, &DELienum, &DELattribute, &DELitravdata, &DELsetoperation, &DELsetliteral, &DELsetreference, &DELste, &DELchild, &DELlifetime_range, &DELilifetime, &DELinodeset, &DELinode, &DELipass, &DELitraversal, &DELiphase, &DELiactions, &DELast, };
const ccn_trav_ft ccn_error_vtable[_NT_SIZE] = { &TRAVerror, &TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,&TRAVerror,};
const ccn_trav_ft ccn_mark_vtable[_NT_SIZE] = { &TRAVerror, &MARKid, &MARKienum, &MARKattribute, &MARKitravdata, &MARKsetoperation, &MARKsetliteral, &MARKsetreference, &MARKste, &MARKchild, &MARKlifetime_range, &MARKilifetime, &MARKinodeset, &MARKinode, &MARKipass, &MARKitraversal, &MARKiphase, &MARKiactions, &MARKast, };
const ccn_trav_ft *ccn_trav_vtable[_TRAV_SIZE] = { ccn_error_vtable, print_vtable, setliteralcontains_vtable, setliteraldifference_vtable, setliteralintersect_vtable, setliteralunion_vtable, setliteralinsert_vtable, reachability_vtable, unwrapsetexpr_vtable, buildsymboltable_vtable, checkexistance_vtable, dynamicgennodemacros_vtable, dynamicgennodestructs_vtable, dynamicgennodeinitfunctions_vtable, dynamicgennodeunion_vtable, dynamicgennodeconstructor_vtable, dynamicgenenum_vtable, dynamicgenenumvalues_vtable, dynamicgentravvtable_vtable, dynamicgennodesfortravtable_vtable, dynamicgenpasstable_vtable, dynamicgentravtable_vtable, dynamicgensystemtraversals_vtable, dynamicgenactionsheader_vtable, dynamicgentravactions_vtable, dynamicgencopytraversal_vtable, dynamicgenconstructorcall_vtable, dynamicgenmarktraversal_vtable, dynamicgenfreetraversal_vtable, dynamicgenchecktraversal_vtable, dynamicgentravdatastructs_vtable, dynamicgentravdatactors_vtable, dynamicgentravdatactorsheader_vtable, dynamicgentravdatagetters_vtable, dynamicgentravdataunion_vtable, dynamicgentravfunctions_vtable, genactionarray_vtable, genactionarrayheader_vtable, genidstables_vtable, gengateheader_vtable, dynamicgentravdatatables_vtable, gendot_vtable, dynamicusergentraversals_vtable, dynamicusergenpasses_vtable, staticgennodestructs_vtable, mapidtolifetime_vtable, assignidtoaction_vtable, checklifetimes_vtable, ccn_free_vtable, ccn_check_vtable, ccn_copy_vtable, ccn_mark_vtable, };
const ccn_trav_data_ft trav_data_init_vtable[_TRAV_SIZE] = {TRAVdataNOP,TRAVdataNOP,TRAVdataInitsetliteralContains,TRAVdataInitsetliteralDifference,TRAVdataInitsetliteralIntersect,TRAVdataInitsetliteralUnion,TRAVdataInitsetliteralInsert,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataInitdynamicGenCheckTraversal,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataInitdynamicGenTravFunctions,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataInitdynamicGenTravDataTables,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP, TRAVdataNOP, TRAVdataNOP};
const ccn_trav_data_ft trav_data_free_vtable[_TRAV_SIZE] = {TRAVdataNOP,TRAVdataNOP,TRAVdataFreesetliteralContains,TRAVdataFreesetliteralDifference,TRAVdataFreesetliteralIntersect,TRAVdataFreesetliteralUnion,TRAVdataFreesetliteralInsert,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataFreedynamicGenCheckTraversal,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataFreedynamicGenTravFunctions,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataFreedynamicGenTravDataTables,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP,TRAVdataNOP, TRAVdataNOP, TRAVdataNOP};
