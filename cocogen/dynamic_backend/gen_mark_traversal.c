#include "assert.h"
#include <globals.h>
#include <stddef.h>
#include <stdio.h>

#include "gen_helpers/out_macros.h"
#include "palm/ctinfo.h"
#include "palm/str.h"
#include "ccn/dynamic_core.h"


static node_st *ast;
static node_st *curr_node;

node_st *DGMTast(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    GNopenSourceFile(ctx, "ccn_mark.c");
    OUT("#include \"ccngen/ast.h\"\n");
    OUT("#include \"ccn/dynamic_core.h\"\n");
    OUT("#include \"palm/memory.h\"\n");
    ast = node;
    TRAVopt(AST_INODES(node));
    return node;
}

node_st *DGMTiactions(node_st *node)
{
    return node;
}

node_st *DGMTiphase(node_st *node)
{
    return node;
}

node_st *DGMTitraversal(node_st *node)
{
    return node;
}

node_st *DGMTitravdata(node_st *node)
{
    return node;
}

node_st *DGMTipass(node_st *node)
{
    TRAVchildren(node);
    return node;
}

node_st *DGMTinode(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    curr_node = node;
    OUT_START_FUNC("struct ccn_node *MARK%s(struct ccn_node *arg_node)", ID_LWR(INODE_NAME(node)));
    if (INODE_ICHILDREN(node)) {
        OUT_FIELD("TRAVchildren(arg_node)");
    }
    TRAVopt(INODE_IATTRIBUTES(node));
    OUT_FIELD("MEMmark(NODE_FILENAME(arg_node))");
    OUT_FIELD("MEMmark(arg_node->data.N_%s)", ID_LWR(INODE_NAME(node)));
    OUT_FIELD("MEMmark(arg_node)");
    OUT_FIELD("return arg_node");
    OUT_END_FUNC();
    TRAVopt(INODE_NEXT(node));
    return node;
}

node_st *DGMTinodeset(node_st *node)
{
    TRAVchildren(node);
    return node;
}

node_st *DGMTchild(node_st *node)
{
    return node;
}

node_st *DGMTattribute(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    if (ATTRIBUTE_TYPE(node) == AT_string) {
        OUT_FIELD("MEMmark(arg_node->data.N_%s->%s)", ID_LWR(INODE_NAME(curr_node)), ID_LWR(ATTRIBUTE_NAME(node)));
    }
    TRAVopt(ATTRIBUTE_NEXT(node));
    return node;
}

node_st *DGMTste(node_st *node)
{

    TRAVchildren(node);
    return node;
}

node_st *DGMTsetoperation(node_st *node)
{

    TRAVchildren(node);
    return node;
}

node_st *DGMTsetliteral(node_st *node)
{

    TRAVchildren(node);
    return node;
}

node_st *DGMTsetreference(node_st *node)
{

    TRAVchildren(node);
    return node;
}

node_st *DGMTienum(node_st *node)
{
    return node;
}

node_st *DGMTid(node_st *node)
{
    return node;
}

node_st *DGMTilifetime(node_st *node)
{
    return node;
}

node_st *DGMTlifetime_range(node_st *node)
{
    return node;
}
