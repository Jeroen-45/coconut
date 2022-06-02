#include "ccngen/ast.h"
#include "ccngen/enum.h"
char *nodetypeToName(node_st *node) {
    switch (NODE_TYPE(node)) {
        case NT_ID:
            return "id";
            break;
        case NT_IENUM:
            return "ienum";
            break;
        case NT_ATTRIBUTE:
            return "attribute";
            break;
        case NT_ITRAVDATA:
            return "itravdata";
            break;
        case NT_SETOPERATION:
            return "setoperation";
            break;
        case NT_SETLITERAL:
            return "setliteral";
            break;
        case NT_SETREFERENCE:
            return "setreference";
            break;
        case NT_STE:
            return "ste";
            break;
        case NT_CHILD:
            return "child";
            break;
        case NT_LIFETIME_RANGE:
            return "lifetime_range";
            break;
        case NT_ILIFETIME:
            return "ilifetime";
            break;
        case NT_INODESET:
            return "inodeset";
            break;
        case NT_INODE:
            return "inode";
            break;
        case NT_IPASS:
            return "ipass";
            break;
        case NT_ITRAVERSAL:
            return "itraversal";
            break;
        case NT_IPHASE:
            return "iphase";
            break;
        case NT_IACTIONS:
            return "iactions";
            break;
        case NT_AST:
            return "ast";
            break;
        default:
            return "Unknown";
                }

}

char *handlerToName(enum ccn_traversal_type t, enum ccn_nodetype n) {
    switch (t) {
        case TRAV_PRT:
            switch (n) {
                case NT_ID:
                    return "PRTid";
                    break;
                case NT_IENUM:
                    return "PRTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "PRTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "PRTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "PRTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "PRTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "PRTsetreference";
                    break;
                case NT_STE:
                    return "PRTste";
                    break;
                case NT_CHILD:
                    return "PRTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "PRTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "PRTilifetime";
                    break;
                case NT_INODESET:
                    return "PRTinodeset";
                    break;
                case NT_INODE:
                    return "PRTinode";
                    break;
                case NT_IPASS:
                    return "PRTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "PRTitraversal";
                    break;
                case NT_IPHASE:
                    return "PRTiphase";
                    break;
                case NT_IACTIONS:
                    return "PRTiactions";
                    break;
                case NT_AST:
                    return "PRTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SLC:
            switch (n) {
                case NT_ID:
                    return "SLCid";
                    break;
                case NT_IENUM:
                    return "SLCienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SLCattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SLCitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SLCsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SLCsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SLCsetreference";
                    break;
                case NT_STE:
                    return "SLCste";
                    break;
                case NT_CHILD:
                    return "SLCchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SLClifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SLCilifetime";
                    break;
                case NT_INODESET:
                    return "SLCinodeset";
                    break;
                case NT_INODE:
                    return "SLCinode";
                    break;
                case NT_IPASS:
                    return "SLCipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SLCitraversal";
                    break;
                case NT_IPHASE:
                    return "SLCiphase";
                    break;
                case NT_IACTIONS:
                    return "SLCiactions";
                    break;
                case NT_AST:
                    return "SLCast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SLD:
            switch (n) {
                case NT_ID:
                    return "SLDid";
                    break;
                case NT_IENUM:
                    return "SLDienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SLDattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SLDitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SLDsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SLDsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SLDsetreference";
                    break;
                case NT_STE:
                    return "SLDste";
                    break;
                case NT_CHILD:
                    return "SLDchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SLDlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SLDilifetime";
                    break;
                case NT_INODESET:
                    return "SLDinodeset";
                    break;
                case NT_INODE:
                    return "SLDinode";
                    break;
                case NT_IPASS:
                    return "SLDipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SLDitraversal";
                    break;
                case NT_IPHASE:
                    return "SLDiphase";
                    break;
                case NT_IACTIONS:
                    return "SLDiactions";
                    break;
                case NT_AST:
                    return "SLDast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SLIS:
            switch (n) {
                case NT_ID:
                    return "SLISid";
                    break;
                case NT_IENUM:
                    return "SLISienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SLISattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SLISitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SLISsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SLISsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SLISsetreference";
                    break;
                case NT_STE:
                    return "SLISste";
                    break;
                case NT_CHILD:
                    return "SLISchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SLISlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SLISilifetime";
                    break;
                case NT_INODESET:
                    return "SLISinodeset";
                    break;
                case NT_INODE:
                    return "SLISinode";
                    break;
                case NT_IPASS:
                    return "SLISipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SLISitraversal";
                    break;
                case NT_IPHASE:
                    return "SLISiphase";
                    break;
                case NT_IACTIONS:
                    return "SLISiactions";
                    break;
                case NT_AST:
                    return "SLISast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SLU:
            switch (n) {
                case NT_ID:
                    return "SLUid";
                    break;
                case NT_IENUM:
                    return "SLUienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SLUattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SLUitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SLUsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SLUsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SLUsetreference";
                    break;
                case NT_STE:
                    return "SLUste";
                    break;
                case NT_CHILD:
                    return "SLUchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SLUlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SLUilifetime";
                    break;
                case NT_INODESET:
                    return "SLUinodeset";
                    break;
                case NT_INODE:
                    return "SLUinode";
                    break;
                case NT_IPASS:
                    return "SLUipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SLUitraversal";
                    break;
                case NT_IPHASE:
                    return "SLUiphase";
                    break;
                case NT_IACTIONS:
                    return "SLUiactions";
                    break;
                case NT_AST:
                    return "SLUast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SLI:
            switch (n) {
                case NT_ID:
                    return "SLIid";
                    break;
                case NT_IENUM:
                    return "SLIienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SLIattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SLIitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SLIsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SLIsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SLIsetreference";
                    break;
                case NT_STE:
                    return "SLIste";
                    break;
                case NT_CHILD:
                    return "SLIchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SLIlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SLIilifetime";
                    break;
                case NT_INODESET:
                    return "SLIinodeset";
                    break;
                case NT_INODE:
                    return "SLIinode";
                    break;
                case NT_IPASS:
                    return "SLIipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SLIitraversal";
                    break;
                case NT_IPHASE:
                    return "SLIiphase";
                    break;
                case NT_IACTIONS:
                    return "SLIiactions";
                    break;
                case NT_AST:
                    return "SLIast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_RCB:
            switch (n) {
                case NT_ID:
                    return "RCBid";
                    break;
                case NT_IENUM:
                    return "RCBienum";
                    break;
                case NT_ATTRIBUTE:
                    return "RCBattribute";
                    break;
                case NT_ITRAVDATA:
                    return "RCBitravdata";
                    break;
                case NT_SETOPERATION:
                    return "RCBsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "RCBsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "RCBsetreference";
                    break;
                case NT_STE:
                    return "RCBste";
                    break;
                case NT_CHILD:
                    return "RCBchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "RCBlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "RCBilifetime";
                    break;
                case NT_INODESET:
                    return "RCBinodeset";
                    break;
                case NT_INODE:
                    return "RCBinode";
                    break;
                case NT_IPASS:
                    return "RCBipass";
                    break;
                case NT_ITRAVERSAL:
                    return "RCBitraversal";
                    break;
                case NT_IPHASE:
                    return "RCBiphase";
                    break;
                case NT_IACTIONS:
                    return "RCBiactions";
                    break;
                case NT_AST:
                    return "RCBast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_USE:
            switch (n) {
                case NT_ID:
                    return "USEid";
                    break;
                case NT_IENUM:
                    return "USEienum";
                    break;
                case NT_ATTRIBUTE:
                    return "USEattribute";
                    break;
                case NT_ITRAVDATA:
                    return "USEitravdata";
                    break;
                case NT_SETOPERATION:
                    return "USEsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "USEsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "USEsetreference";
                    break;
                case NT_STE:
                    return "USEste";
                    break;
                case NT_CHILD:
                    return "USEchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "USElifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "USEilifetime";
                    break;
                case NT_INODESET:
                    return "USEinodeset";
                    break;
                case NT_INODE:
                    return "USEinode";
                    break;
                case NT_IPASS:
                    return "USEipass";
                    break;
                case NT_ITRAVERSAL:
                    return "USEitraversal";
                    break;
                case NT_IPHASE:
                    return "USEiphase";
                    break;
                case NT_IACTIONS:
                    return "USEiactions";
                    break;
                case NT_AST:
                    return "USEast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_BST:
            switch (n) {
                case NT_ID:
                    return "BSTid";
                    break;
                case NT_IENUM:
                    return "BSTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "BSTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "BSTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "BSTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "BSTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "BSTsetreference";
                    break;
                case NT_STE:
                    return "BSTste";
                    break;
                case NT_CHILD:
                    return "BSTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "BSTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "BSTilifetime";
                    break;
                case NT_INODESET:
                    return "BSTinodeset";
                    break;
                case NT_INODE:
                    return "BSTinode";
                    break;
                case NT_IPASS:
                    return "BSTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "BSTitraversal";
                    break;
                case NT_IPHASE:
                    return "BSTiphase";
                    break;
                case NT_IACTIONS:
                    return "BSTiactions";
                    break;
                case NT_AST:
                    return "BSTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_CEX:
            switch (n) {
                case NT_ID:
                    return "CEXid";
                    break;
                case NT_IENUM:
                    return "CEXienum";
                    break;
                case NT_ATTRIBUTE:
                    return "CEXattribute";
                    break;
                case NT_ITRAVDATA:
                    return "CEXitravdata";
                    break;
                case NT_SETOPERATION:
                    return "CEXsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "CEXsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "CEXsetreference";
                    break;
                case NT_STE:
                    return "CEXste";
                    break;
                case NT_CHILD:
                    return "CEXchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "CEXlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "CEXilifetime";
                    break;
                case NT_INODESET:
                    return "CEXinodeset";
                    break;
                case NT_INODE:
                    return "CEXinode";
                    break;
                case NT_IPASS:
                    return "CEXipass";
                    break;
                case NT_ITRAVERSAL:
                    return "CEXitraversal";
                    break;
                case NT_IPHASE:
                    return "CEXiphase";
                    break;
                case NT_IACTIONS:
                    return "CEXiactions";
                    break;
                case NT_AST:
                    return "CEXast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGNM:
            switch (n) {
                case NT_ID:
                    return "DGNMid";
                    break;
                case NT_IENUM:
                    return "DGNMienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGNMattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGNMitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGNMsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGNMsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGNMsetreference";
                    break;
                case NT_STE:
                    return "DGNMste";
                    break;
                case NT_CHILD:
                    return "DGNMchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGNMlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGNMilifetime";
                    break;
                case NT_INODESET:
                    return "DGNMinodeset";
                    break;
                case NT_INODE:
                    return "DGNMinode";
                    break;
                case NT_IPASS:
                    return "DGNMipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGNMitraversal";
                    break;
                case NT_IPHASE:
                    return "DGNMiphase";
                    break;
                case NT_IACTIONS:
                    return "DGNMiactions";
                    break;
                case NT_AST:
                    return "DGNMast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGNS:
            switch (n) {
                case NT_ID:
                    return "DGNSid";
                    break;
                case NT_IENUM:
                    return "DGNSienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGNSattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGNSitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGNSsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGNSsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGNSsetreference";
                    break;
                case NT_STE:
                    return "DGNSste";
                    break;
                case NT_CHILD:
                    return "DGNSchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGNSlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGNSilifetime";
                    break;
                case NT_INODESET:
                    return "DGNSinodeset";
                    break;
                case NT_INODE:
                    return "DGNSinode";
                    break;
                case NT_IPASS:
                    return "DGNSipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGNSitraversal";
                    break;
                case NT_IPHASE:
                    return "DGNSiphase";
                    break;
                case NT_IACTIONS:
                    return "DGNSiactions";
                    break;
                case NT_AST:
                    return "DGNSast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGIF:
            switch (n) {
                case NT_ID:
                    return "DGIFid";
                    break;
                case NT_IENUM:
                    return "DGIFienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGIFattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGIFitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGIFsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGIFsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGIFsetreference";
                    break;
                case NT_STE:
                    return "DGIFste";
                    break;
                case NT_CHILD:
                    return "DGIFchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGIFlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGIFilifetime";
                    break;
                case NT_INODESET:
                    return "DGIFinodeset";
                    break;
                case NT_INODE:
                    return "DGIFinode";
                    break;
                case NT_IPASS:
                    return "DGIFipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGIFitraversal";
                    break;
                case NT_IPHASE:
                    return "DGIFiphase";
                    break;
                case NT_IACTIONS:
                    return "DGIFiactions";
                    break;
                case NT_AST:
                    return "DGIFast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGBU:
            switch (n) {
                case NT_ID:
                    return "DGBUid";
                    break;
                case NT_IENUM:
                    return "DGBUienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGBUattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGBUitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGBUsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGBUsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGBUsetreference";
                    break;
                case NT_STE:
                    return "DGBUste";
                    break;
                case NT_CHILD:
                    return "DGBUchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGBUlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGBUilifetime";
                    break;
                case NT_INODESET:
                    return "DGBUinodeset";
                    break;
                case NT_INODE:
                    return "DGBUinode";
                    break;
                case NT_IPASS:
                    return "DGBUipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGBUitraversal";
                    break;
                case NT_IPHASE:
                    return "DGBUiphase";
                    break;
                case NT_IACTIONS:
                    return "DGBUiactions";
                    break;
                case NT_AST:
                    return "DGBUast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGNC:
            switch (n) {
                case NT_ID:
                    return "DGNCid";
                    break;
                case NT_IENUM:
                    return "DGNCienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGNCattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGNCitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGNCsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGNCsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGNCsetreference";
                    break;
                case NT_STE:
                    return "DGNCste";
                    break;
                case NT_CHILD:
                    return "DGNCchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGNClifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGNCilifetime";
                    break;
                case NT_INODESET:
                    return "DGNCinodeset";
                    break;
                case NT_INODE:
                    return "DGNCinode";
                    break;
                case NT_IPASS:
                    return "DGNCipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGNCitraversal";
                    break;
                case NT_IPHASE:
                    return "DGNCiphase";
                    break;
                case NT_IACTIONS:
                    return "DGNCiactions";
                    break;
                case NT_AST:
                    return "DGNCast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGE:
            switch (n) {
                case NT_ID:
                    return "DGEid";
                    break;
                case NT_IENUM:
                    return "DGEienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGEattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGEitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGEsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGEsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGEsetreference";
                    break;
                case NT_STE:
                    return "DGEste";
                    break;
                case NT_CHILD:
                    return "DGEchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGElifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGEilifetime";
                    break;
                case NT_INODESET:
                    return "DGEinodeset";
                    break;
                case NT_INODE:
                    return "DGEinode";
                    break;
                case NT_IPASS:
                    return "DGEipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGEitraversal";
                    break;
                case NT_IPHASE:
                    return "DGEiphase";
                    break;
                case NT_IACTIONS:
                    return "DGEiactions";
                    break;
                case NT_AST:
                    return "DGEast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGEV:
            switch (n) {
                case NT_ID:
                    return "DGEVid";
                    break;
                case NT_IENUM:
                    return "DGEVienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGEVattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGEVitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGEVsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGEVsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGEVsetreference";
                    break;
                case NT_STE:
                    return "DGEVste";
                    break;
                case NT_CHILD:
                    return "DGEVchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGEVlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGEVilifetime";
                    break;
                case NT_INODESET:
                    return "DGEVinodeset";
                    break;
                case NT_INODE:
                    return "DGEVinode";
                    break;
                case NT_IPASS:
                    return "DGEVipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGEVitraversal";
                    break;
                case NT_IPHASE:
                    return "DGEViphase";
                    break;
                case NT_IACTIONS:
                    return "DGEViactions";
                    break;
                case NT_AST:
                    return "DGEVast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTV:
            switch (n) {
                case NT_ID:
                    return "DGTVid";
                    break;
                case NT_IENUM:
                    return "DGTVienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTVattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTVitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTVsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTVsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTVsetreference";
                    break;
                case NT_STE:
                    return "DGTVste";
                    break;
                case NT_CHILD:
                    return "DGTVchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTVlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTVilifetime";
                    break;
                case NT_INODESET:
                    return "DGTVinodeset";
                    break;
                case NT_INODE:
                    return "DGTVinode";
                    break;
                case NT_IPASS:
                    return "DGTVipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTVitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTViphase";
                    break;
                case NT_IACTIONS:
                    return "DGTViactions";
                    break;
                case NT_AST:
                    return "DGTVast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGNFTT:
            switch (n) {
                case NT_ID:
                    return "DGNFTTid";
                    break;
                case NT_IENUM:
                    return "DGNFTTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGNFTTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGNFTTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGNFTTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGNFTTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGNFTTsetreference";
                    break;
                case NT_STE:
                    return "DGNFTTste";
                    break;
                case NT_CHILD:
                    return "DGNFTTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGNFTTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGNFTTilifetime";
                    break;
                case NT_INODESET:
                    return "DGNFTTinodeset";
                    break;
                case NT_INODE:
                    return "DGNFTTinode";
                    break;
                case NT_IPASS:
                    return "DGNFTTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGNFTTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGNFTTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGNFTTiactions";
                    break;
                case NT_AST:
                    return "DGNFTTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGPT:
            switch (n) {
                case NT_ID:
                    return "DGPTid";
                    break;
                case NT_IENUM:
                    return "DGPTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGPTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGPTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGPTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGPTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGPTsetreference";
                    break;
                case NT_STE:
                    return "DGPTste";
                    break;
                case NT_CHILD:
                    return "DGPTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGPTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGPTilifetime";
                    break;
                case NT_INODESET:
                    return "DGPTinodeset";
                    break;
                case NT_INODE:
                    return "DGPTinode";
                    break;
                case NT_IPASS:
                    return "DGPTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGPTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGPTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGPTiactions";
                    break;
                case NT_AST:
                    return "DGPTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTT:
            switch (n) {
                case NT_ID:
                    return "DGTTid";
                    break;
                case NT_IENUM:
                    return "DGTTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTTsetreference";
                    break;
                case NT_STE:
                    return "DGTTste";
                    break;
                case NT_CHILD:
                    return "DGTTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTTilifetime";
                    break;
                case NT_INODESET:
                    return "DGTTinodeset";
                    break;
                case NT_INODE:
                    return "DGTTinode";
                    break;
                case NT_IPASS:
                    return "DGTTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTTiactions";
                    break;
                case NT_AST:
                    return "DGTTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGST:
            switch (n) {
                case NT_ID:
                    return "DGSTid";
                    break;
                case NT_IENUM:
                    return "DGSTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGSTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGSTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGSTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGSTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGSTsetreference";
                    break;
                case NT_STE:
                    return "DGSTste";
                    break;
                case NT_CHILD:
                    return "DGSTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGSTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGSTilifetime";
                    break;
                case NT_INODESET:
                    return "DGSTinodeset";
                    break;
                case NT_INODE:
                    return "DGSTinode";
                    break;
                case NT_IPASS:
                    return "DGSTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGSTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGSTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGSTiactions";
                    break;
                case NT_AST:
                    return "DGSTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGAH:
            switch (n) {
                case NT_ID:
                    return "DGAHid";
                    break;
                case NT_IENUM:
                    return "DGAHienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGAHattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGAHitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGAHsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGAHsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGAHsetreference";
                    break;
                case NT_STE:
                    return "DGAHste";
                    break;
                case NT_CHILD:
                    return "DGAHchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGAHlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGAHilifetime";
                    break;
                case NT_INODESET:
                    return "DGAHinodeset";
                    break;
                case NT_INODE:
                    return "DGAHinode";
                    break;
                case NT_IPASS:
                    return "DGAHipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGAHitraversal";
                    break;
                case NT_IPHASE:
                    return "DGAHiphase";
                    break;
                case NT_IACTIONS:
                    return "DGAHiactions";
                    break;
                case NT_AST:
                    return "DGAHast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTA:
            switch (n) {
                case NT_ID:
                    return "DGTAid";
                    break;
                case NT_IENUM:
                    return "DGTAienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTAattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTAitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTAsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTAsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTAsetreference";
                    break;
                case NT_STE:
                    return "DGTAste";
                    break;
                case NT_CHILD:
                    return "DGTAchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTAlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTAilifetime";
                    break;
                case NT_INODESET:
                    return "DGTAinodeset";
                    break;
                case NT_INODE:
                    return "DGTAinode";
                    break;
                case NT_IPASS:
                    return "DGTAipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTAitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTAiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTAiactions";
                    break;
                case NT_AST:
                    return "DGTAast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGCT:
            switch (n) {
                case NT_ID:
                    return "DGCTid";
                    break;
                case NT_IENUM:
                    return "DGCTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGCTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGCTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGCTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGCTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGCTsetreference";
                    break;
                case NT_STE:
                    return "DGCTste";
                    break;
                case NT_CHILD:
                    return "DGCTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGCTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGCTilifetime";
                    break;
                case NT_INODESET:
                    return "DGCTinodeset";
                    break;
                case NT_INODE:
                    return "DGCTinode";
                    break;
                case NT_IPASS:
                    return "DGCTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGCTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGCTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGCTiactions";
                    break;
                case NT_AST:
                    return "DGCTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGCC:
            switch (n) {
                case NT_ID:
                    return "DGCCid";
                    break;
                case NT_IENUM:
                    return "DGCCienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGCCattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGCCitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGCCsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGCCsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGCCsetreference";
                    break;
                case NT_STE:
                    return "DGCCste";
                    break;
                case NT_CHILD:
                    return "DGCCchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGCClifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGCCilifetime";
                    break;
                case NT_INODESET:
                    return "DGCCinodeset";
                    break;
                case NT_INODE:
                    return "DGCCinode";
                    break;
                case NT_IPASS:
                    return "DGCCipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGCCitraversal";
                    break;
                case NT_IPHASE:
                    return "DGCCiphase";
                    break;
                case NT_IACTIONS:
                    return "DGCCiactions";
                    break;
                case NT_AST:
                    return "DGCCast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGMT:
            switch (n) {
                case NT_ID:
                    return "DGMTid";
                    break;
                case NT_IENUM:
                    return "DGMTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGMTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGMTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGMTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGMTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGMTsetreference";
                    break;
                case NT_STE:
                    return "DGMTste";
                    break;
                case NT_CHILD:
                    return "DGMTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGMTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGMTilifetime";
                    break;
                case NT_INODESET:
                    return "DGMTinodeset";
                    break;
                case NT_INODE:
                    return "DGMTinode";
                    break;
                case NT_IPASS:
                    return "DGMTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGMTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGMTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGMTiactions";
                    break;
                case NT_AST:
                    return "DGMTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGFT:
            switch (n) {
                case NT_ID:
                    return "DGFTid";
                    break;
                case NT_IENUM:
                    return "DGFTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGFTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGFTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGFTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGFTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGFTsetreference";
                    break;
                case NT_STE:
                    return "DGFTste";
                    break;
                case NT_CHILD:
                    return "DGFTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGFTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGFTilifetime";
                    break;
                case NT_INODESET:
                    return "DGFTinodeset";
                    break;
                case NT_INODE:
                    return "DGFTinode";
                    break;
                case NT_IPASS:
                    return "DGFTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGFTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGFTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGFTiactions";
                    break;
                case NT_AST:
                    return "DGFTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGCHT:
            switch (n) {
                case NT_ID:
                    return "DGCHTid";
                    break;
                case NT_IENUM:
                    return "DGCHTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGCHTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGCHTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGCHTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGCHTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGCHTsetreference";
                    break;
                case NT_STE:
                    return "DGCHTste";
                    break;
                case NT_CHILD:
                    return "DGCHTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGCHTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGCHTilifetime";
                    break;
                case NT_INODESET:
                    return "DGCHTinodeset";
                    break;
                case NT_INODE:
                    return "DGCHTinode";
                    break;
                case NT_IPASS:
                    return "DGCHTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGCHTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGCHTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGCHTiactions";
                    break;
                case NT_AST:
                    return "DGCHTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGNU:
            switch (n) {
                case NT_ID:
                    return "DGNUid";
                    break;
                case NT_IENUM:
                    return "DGNUienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGNUattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGNUitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGNUsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGNUsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGNUsetreference";
                    break;
                case NT_STE:
                    return "DGNUste";
                    break;
                case NT_CHILD:
                    return "DGNUchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGNUlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGNUilifetime";
                    break;
                case NT_INODESET:
                    return "DGNUinodeset";
                    break;
                case NT_INODE:
                    return "DGNUinode";
                    break;
                case NT_IPASS:
                    return "DGNUipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGNUitraversal";
                    break;
                case NT_IPHASE:
                    return "DGNUiphase";
                    break;
                case NT_IACTIONS:
                    return "DGNUiactions";
                    break;
                case NT_AST:
                    return "DGNUast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDS:
            switch (n) {
                case NT_ID:
                    return "DGTDSid";
                    break;
                case NT_IENUM:
                    return "DGTDSienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDSattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDSitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDSsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDSsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDSsetreference";
                    break;
                case NT_STE:
                    return "DGTDSste";
                    break;
                case NT_CHILD:
                    return "DGTDSchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDSlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDSilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDSinodeset";
                    break;
                case NT_INODE:
                    return "DGTDSinode";
                    break;
                case NT_IPASS:
                    return "DGTDSipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDSitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDSiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDSiactions";
                    break;
                case NT_AST:
                    return "DGTDSast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDC:
            switch (n) {
                case NT_ID:
                    return "DGTDCid";
                    break;
                case NT_IENUM:
                    return "DGTDCienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDCattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDCitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDCsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDCsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDCsetreference";
                    break;
                case NT_STE:
                    return "DGTDCste";
                    break;
                case NT_CHILD:
                    return "DGTDCchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDClifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDCilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDCinodeset";
                    break;
                case NT_INODE:
                    return "DGTDCinode";
                    break;
                case NT_IPASS:
                    return "DGTDCipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDCitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDCiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDCiactions";
                    break;
                case NT_AST:
                    return "DGTDCast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDCH:
            switch (n) {
                case NT_ID:
                    return "DGTDCHid";
                    break;
                case NT_IENUM:
                    return "DGTDCHienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDCHattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDCHitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDCHsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDCHsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDCHsetreference";
                    break;
                case NT_STE:
                    return "DGTDCHste";
                    break;
                case NT_CHILD:
                    return "DGTDCHchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDCHlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDCHilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDCHinodeset";
                    break;
                case NT_INODE:
                    return "DGTDCHinode";
                    break;
                case NT_IPASS:
                    return "DGTDCHipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDCHitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDCHiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDCHiactions";
                    break;
                case NT_AST:
                    return "DGTDCHast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDG:
            switch (n) {
                case NT_ID:
                    return "DGTDGid";
                    break;
                case NT_IENUM:
                    return "DGTDGienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDGattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDGitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDGsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDGsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDGsetreference";
                    break;
                case NT_STE:
                    return "DGTDGste";
                    break;
                case NT_CHILD:
                    return "DGTDGchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDGlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDGilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDGinodeset";
                    break;
                case NT_INODE:
                    return "DGTDGinode";
                    break;
                case NT_IPASS:
                    return "DGTDGipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDGitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDGiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDGiactions";
                    break;
                case NT_AST:
                    return "DGTDGast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDU:
            switch (n) {
                case NT_ID:
                    return "DGTDUid";
                    break;
                case NT_IENUM:
                    return "DGTDUienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDUattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDUitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDUsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDUsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDUsetreference";
                    break;
                case NT_STE:
                    return "DGTDUste";
                    break;
                case NT_CHILD:
                    return "DGTDUchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDUlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDUilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDUinodeset";
                    break;
                case NT_INODE:
                    return "DGTDUinode";
                    break;
                case NT_IPASS:
                    return "DGTDUipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDUitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDUiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDUiactions";
                    break;
                case NT_AST:
                    return "DGTDUast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGT_F:
            switch (n) {
                case NT_ID:
                    return "DGT_Fid";
                    break;
                case NT_IENUM:
                    return "DGT_Fienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGT_Fattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGT_Fitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGT_Fsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGT_Fsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGT_Fsetreference";
                    break;
                case NT_STE:
                    return "DGT_Fste";
                    break;
                case NT_CHILD:
                    return "DGT_Fchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGT_Flifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGT_Filifetime";
                    break;
                case NT_INODESET:
                    return "DGT_Finodeset";
                    break;
                case NT_INODE:
                    return "DGT_Finode";
                    break;
                case NT_IPASS:
                    return "DGT_Fipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGT_Fitraversal";
                    break;
                case NT_IPHASE:
                    return "DGT_Fiphase";
                    break;
                case NT_IACTIONS:
                    return "DGT_Fiactions";
                    break;
                case NT_AST:
                    return "DGT_Fast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_GAA:
            switch (n) {
                case NT_ID:
                    return "GAAid";
                    break;
                case NT_IENUM:
                    return "GAAienum";
                    break;
                case NT_ATTRIBUTE:
                    return "GAAattribute";
                    break;
                case NT_ITRAVDATA:
                    return "GAAitravdata";
                    break;
                case NT_SETOPERATION:
                    return "GAAsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "GAAsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "GAAsetreference";
                    break;
                case NT_STE:
                    return "GAAste";
                    break;
                case NT_CHILD:
                    return "GAAchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "GAAlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "GAAilifetime";
                    break;
                case NT_INODESET:
                    return "GAAinodeset";
                    break;
                case NT_INODE:
                    return "GAAinode";
                    break;
                case NT_IPASS:
                    return "GAAipass";
                    break;
                case NT_ITRAVERSAL:
                    return "GAAitraversal";
                    break;
                case NT_IPHASE:
                    return "GAAiphase";
                    break;
                case NT_IACTIONS:
                    return "GAAiactions";
                    break;
                case NT_AST:
                    return "GAAast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_GAAH:
            switch (n) {
                case NT_ID:
                    return "GAAHid";
                    break;
                case NT_IENUM:
                    return "GAAHienum";
                    break;
                case NT_ATTRIBUTE:
                    return "GAAHattribute";
                    break;
                case NT_ITRAVDATA:
                    return "GAAHitravdata";
                    break;
                case NT_SETOPERATION:
                    return "GAAHsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "GAAHsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "GAAHsetreference";
                    break;
                case NT_STE:
                    return "GAAHste";
                    break;
                case NT_CHILD:
                    return "GAAHchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "GAAHlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "GAAHilifetime";
                    break;
                case NT_INODESET:
                    return "GAAHinodeset";
                    break;
                case NT_INODE:
                    return "GAAHinode";
                    break;
                case NT_IPASS:
                    return "GAAHipass";
                    break;
                case NT_ITRAVERSAL:
                    return "GAAHitraversal";
                    break;
                case NT_IPHASE:
                    return "GAAHiphase";
                    break;
                case NT_IACTIONS:
                    return "GAAHiactions";
                    break;
                case NT_AST:
                    return "GAAHast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_GIT:
            switch (n) {
                case NT_ID:
                    return "GITid";
                    break;
                case NT_IENUM:
                    return "GITienum";
                    break;
                case NT_ATTRIBUTE:
                    return "GITattribute";
                    break;
                case NT_ITRAVDATA:
                    return "GITitravdata";
                    break;
                case NT_SETOPERATION:
                    return "GITsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "GITsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "GITsetreference";
                    break;
                case NT_STE:
                    return "GITste";
                    break;
                case NT_CHILD:
                    return "GITchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "GITlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "GITilifetime";
                    break;
                case NT_INODESET:
                    return "GITinodeset";
                    break;
                case NT_INODE:
                    return "GITinode";
                    break;
                case NT_IPASS:
                    return "GITipass";
                    break;
                case NT_ITRAVERSAL:
                    return "GITitraversal";
                    break;
                case NT_IPHASE:
                    return "GITiphase";
                    break;
                case NT_IACTIONS:
                    return "GITiactions";
                    break;
                case NT_AST:
                    return "GITast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_GGH:
            switch (n) {
                case NT_ID:
                    return "GGHid";
                    break;
                case NT_IENUM:
                    return "GGHienum";
                    break;
                case NT_ATTRIBUTE:
                    return "GGHattribute";
                    break;
                case NT_ITRAVDATA:
                    return "GGHitravdata";
                    break;
                case NT_SETOPERATION:
                    return "GGHsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "GGHsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "GGHsetreference";
                    break;
                case NT_STE:
                    return "GGHste";
                    break;
                case NT_CHILD:
                    return "GGHchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "GGHlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "GGHilifetime";
                    break;
                case NT_INODESET:
                    return "GGHinodeset";
                    break;
                case NT_INODE:
                    return "GGHinode";
                    break;
                case NT_IPASS:
                    return "GGHipass";
                    break;
                case NT_ITRAVERSAL:
                    return "GGHitraversal";
                    break;
                case NT_IPHASE:
                    return "GGHiphase";
                    break;
                case NT_IACTIONS:
                    return "GGHiactions";
                    break;
                case NT_AST:
                    return "GGHast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DGTDT:
            switch (n) {
                case NT_ID:
                    return "DGTDTid";
                    break;
                case NT_IENUM:
                    return "DGTDTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DGTDTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DGTDTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DGTDTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DGTDTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DGTDTsetreference";
                    break;
                case NT_STE:
                    return "DGTDTste";
                    break;
                case NT_CHILD:
                    return "DGTDTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DGTDTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DGTDTilifetime";
                    break;
                case NT_INODESET:
                    return "DGTDTinodeset";
                    break;
                case NT_INODE:
                    return "DGTDTinode";
                    break;
                case NT_IPASS:
                    return "DGTDTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DGTDTitraversal";
                    break;
                case NT_IPHASE:
                    return "DGTDTiphase";
                    break;
                case NT_IACTIONS:
                    return "DGTDTiactions";
                    break;
                case NT_AST:
                    return "DGTDTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_GD:
            switch (n) {
                case NT_ID:
                    return "GDid";
                    break;
                case NT_IENUM:
                    return "GDienum";
                    break;
                case NT_ATTRIBUTE:
                    return "GDattribute";
                    break;
                case NT_ITRAVDATA:
                    return "GDitravdata";
                    break;
                case NT_SETOPERATION:
                    return "GDsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "GDsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "GDsetreference";
                    break;
                case NT_STE:
                    return "GDste";
                    break;
                case NT_CHILD:
                    return "GDchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "GDlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "GDilifetime";
                    break;
                case NT_INODESET:
                    return "GDinodeset";
                    break;
                case NT_INODE:
                    return "GDinode";
                    break;
                case NT_IPASS:
                    return "GDipass";
                    break;
                case NT_ITRAVERSAL:
                    return "GDitraversal";
                    break;
                case NT_IPHASE:
                    return "GDiphase";
                    break;
                case NT_IACTIONS:
                    return "GDiactions";
                    break;
                case NT_AST:
                    return "GDast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DUGT:
            switch (n) {
                case NT_ID:
                    return "DUGTid";
                    break;
                case NT_IENUM:
                    return "DUGTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DUGTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DUGTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DUGTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DUGTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DUGTsetreference";
                    break;
                case NT_STE:
                    return "DUGTste";
                    break;
                case NT_CHILD:
                    return "DUGTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DUGTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DUGTilifetime";
                    break;
                case NT_INODESET:
                    return "DUGTinodeset";
                    break;
                case NT_INODE:
                    return "DUGTinode";
                    break;
                case NT_IPASS:
                    return "DUGTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DUGTitraversal";
                    break;
                case NT_IPHASE:
                    return "DUGTiphase";
                    break;
                case NT_IACTIONS:
                    return "DUGTiactions";
                    break;
                case NT_AST:
                    return "DUGTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_DUGP:
            switch (n) {
                case NT_ID:
                    return "DUGPid";
                    break;
                case NT_IENUM:
                    return "DUGPienum";
                    break;
                case NT_ATTRIBUTE:
                    return "DUGPattribute";
                    break;
                case NT_ITRAVDATA:
                    return "DUGPitravdata";
                    break;
                case NT_SETOPERATION:
                    return "DUGPsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "DUGPsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "DUGPsetreference";
                    break;
                case NT_STE:
                    return "DUGPste";
                    break;
                case NT_CHILD:
                    return "DUGPchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "DUGPlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "DUGPilifetime";
                    break;
                case NT_INODESET:
                    return "DUGPinodeset";
                    break;
                case NT_INODE:
                    return "DUGPinode";
                    break;
                case NT_IPASS:
                    return "DUGPipass";
                    break;
                case NT_ITRAVERSAL:
                    return "DUGPitraversal";
                    break;
                case NT_IPHASE:
                    return "DUGPiphase";
                    break;
                case NT_IACTIONS:
                    return "DUGPiactions";
                    break;
                case NT_AST:
                    return "DUGPast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_SGNS:
            switch (n) {
                case NT_ID:
                    return "SGNSid";
                    break;
                case NT_IENUM:
                    return "SGNSienum";
                    break;
                case NT_ATTRIBUTE:
                    return "SGNSattribute";
                    break;
                case NT_ITRAVDATA:
                    return "SGNSitravdata";
                    break;
                case NT_SETOPERATION:
                    return "SGNSsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "SGNSsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "SGNSsetreference";
                    break;
                case NT_STE:
                    return "SGNSste";
                    break;
                case NT_CHILD:
                    return "SGNSchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "SGNSlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "SGNSilifetime";
                    break;
                case NT_INODESET:
                    return "SGNSinodeset";
                    break;
                case NT_INODE:
                    return "SGNSinode";
                    break;
                case NT_IPASS:
                    return "SGNSipass";
                    break;
                case NT_ITRAVERSAL:
                    return "SGNSitraversal";
                    break;
                case NT_IPHASE:
                    return "SGNSiphase";
                    break;
                case NT_IACTIONS:
                    return "SGNSiactions";
                    break;
                case NT_AST:
                    return "SGNSast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_MITL:
            switch (n) {
                case NT_ID:
                    return "MITLid";
                    break;
                case NT_IENUM:
                    return "MITLienum";
                    break;
                case NT_ATTRIBUTE:
                    return "MITLattribute";
                    break;
                case NT_ITRAVDATA:
                    return "MITLitravdata";
                    break;
                case NT_SETOPERATION:
                    return "MITLsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "MITLsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "MITLsetreference";
                    break;
                case NT_STE:
                    return "MITLste";
                    break;
                case NT_CHILD:
                    return "MITLchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "MITLlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "MITLilifetime";
                    break;
                case NT_INODESET:
                    return "MITLinodeset";
                    break;
                case NT_INODE:
                    return "MITLinode";
                    break;
                case NT_IPASS:
                    return "MITLipass";
                    break;
                case NT_ITRAVERSAL:
                    return "MITLitraversal";
                    break;
                case NT_IPHASE:
                    return "MITLiphase";
                    break;
                case NT_IACTIONS:
                    return "MITLiactions";
                    break;
                case NT_AST:
                    return "MITLast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_AITA:
            switch (n) {
                case NT_ID:
                    return "AITAid";
                    break;
                case NT_IENUM:
                    return "AITAienum";
                    break;
                case NT_ATTRIBUTE:
                    return "AITAattribute";
                    break;
                case NT_ITRAVDATA:
                    return "AITAitravdata";
                    break;
                case NT_SETOPERATION:
                    return "AITAsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "AITAsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "AITAsetreference";
                    break;
                case NT_STE:
                    return "AITAste";
                    break;
                case NT_CHILD:
                    return "AITAchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "AITAlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "AITAilifetime";
                    break;
                case NT_INODESET:
                    return "AITAinodeset";
                    break;
                case NT_INODE:
                    return "AITAinode";
                    break;
                case NT_IPASS:
                    return "AITAipass";
                    break;
                case NT_ITRAVERSAL:
                    return "AITAitraversal";
                    break;
                case NT_IPHASE:
                    return "AITAiphase";
                    break;
                case NT_IACTIONS:
                    return "AITAiactions";
                    break;
                case NT_AST:
                    return "AITAast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        case TRAV_CLT:
            switch (n) {
                case NT_ID:
                    return "CLTid";
                    break;
                case NT_IENUM:
                    return "CLTienum";
                    break;
                case NT_ATTRIBUTE:
                    return "CLTattribute";
                    break;
                case NT_ITRAVDATA:
                    return "CLTitravdata";
                    break;
                case NT_SETOPERATION:
                    return "CLTsetoperation";
                    break;
                case NT_SETLITERAL:
                    return "CLTsetliteral";
                    break;
                case NT_SETREFERENCE:
                    return "CLTsetreference";
                    break;
                case NT_STE:
                    return "CLTste";
                    break;
                case NT_CHILD:
                    return "CLTchild";
                    break;
                case NT_LIFETIME_RANGE:
                    return "CLTlifetime_range";
                    break;
                case NT_ILIFETIME:
                    return "CLTilifetime";
                    break;
                case NT_INODESET:
                    return "CLTinodeset";
                    break;
                case NT_INODE:
                    return "CLTinode";
                    break;
                case NT_IPASS:
                    return "CLTipass";
                    break;
                case NT_ITRAVERSAL:
                    return "CLTitraversal";
                    break;
                case NT_IPHASE:
                    return "CLTiphase";
                    break;
                case NT_IACTIONS:
                    return "CLTiactions";
                    break;
                case NT_AST:
                    return "CLTast";
                    break;
                default:
                    return "Unknown";
                                }

            break;
        default:
            return "Unknown";
                }

}

