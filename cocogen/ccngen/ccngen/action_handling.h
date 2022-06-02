#pragma once
enum ccn_action_id {
    CCNAC_ID_DYNAMICGENUSERFILES,
    CCNAC_ID_DYNAMICGENAST,
    CCNAC_ID_DYNAMICGENTRAVDATA,
    CCNAC_ID_STATICGENAST,
    CCNAC_ID_STATICBACKEND,
    CCNAC_ID_DYNAMICBACKEND,
    CCNAC_ID_PHASEDRIVER,
    CCNAC_ID_UNPACKLIFETIMES,
    CCNAC_ID_SEMANTIC,
    CCNAC_ID_OPTS,
    CCNAC_ID_STARTPHASE,
    CCNAC_ID_PRINT,
    CCNAC_ID_SETLITERALCONTAINS,
    CCNAC_ID_SETLITERALDIFFERENCE,
    CCNAC_ID_SETLITERALINTERSECT,
    CCNAC_ID_SETLITERALUNION,
    CCNAC_ID_SETLITERALINSERT,
    CCNAC_ID_REACHABILITY,
    CCNAC_ID_UNWRAPSETEXPR,
    CCNAC_ID_BUILDSYMBOLTABLE,
    CCNAC_ID_CHECKEXISTANCE,
    CCNAC_ID_DYNAMICGENNODEMACROS,
    CCNAC_ID_DYNAMICGENNODESTRUCTS,
    CCNAC_ID_DYNAMICGENNODEINITFUNCTIONS,
    CCNAC_ID_DYNAMICGENNODEUNION,
    CCNAC_ID_DYNAMICGENNODECONSTRUCTOR,
    CCNAC_ID_DYNAMICGENENUM,
    CCNAC_ID_DYNAMICGENENUMVALUES,
    CCNAC_ID_DYNAMICGENTRAVVTABLE,
    CCNAC_ID_DYNAMICGENNODESFORTRAVTABLE,
    CCNAC_ID_DYNAMICGENPASSTABLE,
    CCNAC_ID_DYNAMICGENTRAVTABLE,
    CCNAC_ID_DYNAMICGENSYSTEMTRAVERSALS,
    CCNAC_ID_DYNAMICGENACTIONSHEADER,
    CCNAC_ID_DYNAMICGENTRAVACTIONS,
    CCNAC_ID_DYNAMICGENCOPYTRAVERSAL,
    CCNAC_ID_DYNAMICGENCONSTRUCTORCALL,
    CCNAC_ID_DYNAMICGENMARKTRAVERSAL,
    CCNAC_ID_DYNAMICGENFREETRAVERSAL,
    CCNAC_ID_DYNAMICGENCHECKTRAVERSAL,
    CCNAC_ID_DYNAMICGENNAMEUTILITIES,
    CCNAC_ID_DYNAMICGENTRAVDATASTRUCTS,
    CCNAC_ID_DYNAMICGENTRAVDATACTORS,
    CCNAC_ID_DYNAMICGENTRAVDATACTORSHEADER,
    CCNAC_ID_DYNAMICGENTRAVDATAGETTERS,
    CCNAC_ID_DYNAMICGENTRAVDATAUNION,
    CCNAC_ID_DYNAMICGENTRAVFUNCTIONS,
    CCNAC_ID_GENACTIONARRAY,
    CCNAC_ID_GENACTIONARRAYHEADER,
    CCNAC_ID_GENIDSTABLES,
    CCNAC_ID_GENGATEHEADER,
    CCNAC_ID_DYNAMICGENTRAVDATATABLES,
    CCNAC_ID_GENDOT,
    CCNAC_ID_DYNAMICUSERGENTRAVERSALS,
    CCNAC_ID_DYNAMICUSERGENPASSES,
    CCNAC_ID_STATICGENNODESTRUCTS,
    CCNAC_ID_MAPIDTOLIFETIME,
    CCNAC_ID_ASSIGNIDTOACTION,
    CCNAC_ID_CHECKLIFETIMES,
    CCNAC_ID_DYNAMICGENBASENODEINIT,
    CCNAC_ID_DYNAMICSWITCHTOASTSOURCE,
    CCNAC_ID_DYNAMICGENBASENODE,
    CCNAC_ID_DYNAMIC_START_AST_HEADER,
    CCNAC_ID_DYNAMICSWITCHTRAVDATA,
    CCNAC_ID_DYNAMICSTARTTRAVDATA,
    CCNAC_ID_DYNAMICSTARTTABLEGEN,
    CCNAC_ID_DYNAMICSTARTENUMHEADER,
    CCNAC_ID_DOOPTS,
    CCNAC_ID_GENDEFINES,
    CCNAC_ID_SCANANDPARSE,
    CCNAC_ID_check,
    CCNAC_ID_free,
    CCNAC_ID_cleanup,
    CCNAC_ID_NULL,
};

#ifndef CCN_NUM_OF_ACTIONS
#define CCN_NUM_OF_ACTIONS 73
#endif
#ifndef CCN_ROOT_TYPE
#define CCN_ROOT_TYPE NT_AST
#endif
#ifndef CCN_ROOT_ACTION
#define CCN_ROOT_ACTION CCNAC_ID_STARTPHASE
#endif

