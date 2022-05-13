#include "ccngen/ast.h"
#include "ccn/dynamic_core.h"
#include "palm/memory.h"
struct ccn_node *MARKid(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_id->orig);
    MEMmark(arg_node->data.N_id->lwr);
    MEMmark(arg_node->data.N_id->upr);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_id);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKienum(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_ienum->iinfo);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_ienum);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKattribute(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_attribute);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKitravdata(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_itravdata->include_file);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_itravdata);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKsetoperation(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_setoperation);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKsetliteral(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_setliteral);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKsetreference(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_setreference);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKste(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_ste);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKchild(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_child);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKlifetime_range(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_lifetime_range);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKilifetime(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_ilifetime);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKinodeset(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_inodeset->iinfo);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_inodeset);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKinode(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_inode->iifno);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_inode);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKipass(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_ipass->iifno);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_ipass);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKitraversal(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_itraversal->iinfo);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_itraversal);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKiphase(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(arg_node->data.N_iphase->iinfo);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_iphase);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKiactions(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_iactions);
    MEMmark(arg_node);
    return arg_node;
}

struct ccn_node *MARKast(struct ccn_node *arg_node) {
    TRAVchildren(arg_node);
    MEMmark(NODE_FILENAME(arg_node));
    MEMmark(arg_node->data.N_ast);
    MEMmark(arg_node);
    return arg_node;
}

