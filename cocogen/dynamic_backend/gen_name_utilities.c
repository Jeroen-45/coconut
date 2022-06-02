/**
 * @file
 *
 * Traversal that generates utility function to return the names of
 */

#include <assert.h>
#include <ccngen/trav.h>
#include <palm/memory.h>
#include <stdio.h>

#include "ccn/dynamic_core.h"
#include "gen_helpers/out_macros.h"
#include "globals.h"
#include "palm/str.h"
#include "gen_helpers.h"

void DGNUinit() {
    DATA_DGNU_GET()->travid = "";
    return;
}
void DGNUfini() { return; }


node_st *DGNUast(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    GNopenSourceFile(ctx, "name_util.c");
    OUT("#include \"ccngen/ast.h\"\n");
    OUT("#include \"ccngen/enum.h\"\n");

    OUT_START_FUNC("char *nodetypeToName(node_st *node)");
    OUT_BEGIN_SWITCH("NODE_TYPE(node)");
    TRAVinodes(node);
    OUT_BEGIN_DEFAULT_CASE();
    OUT("return \"Unknown\";\n");
    OUT_END_CASE_NO_BREAK();
    OUT_END_SWITCH();
    OUT_END_FUNC();

    OUT_START_FUNC("char *handlerToName(enum ccn_traversal_type t, enum ccn_nodetype n)");
    OUT_BEGIN_SWITCH("t");
    DATA_DGNU_GET()->inodes = AST_INODES(node);
    TRAVitraversals(node);
    OUT_BEGIN_DEFAULT_CASE();
    OUT("return \"Unknown\";\n");
    OUT_END_CASE_NO_BREAK();
    OUT_END_SWITCH();
    OUT_END_FUNC();

    GNopenIncludeFile(ctx, "name_util.h");
    OUT("#include \"ast.h\"\n");
    OUT("#include \"enum.h\"\n");
    OUT("char *nodetypeToName(node_st *node);");
    OUT("char *handlerToName(enum ccn_traversal_type t, enum ccn_nodetype n);");

    return node;
}

node_st *DGNUinode(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    OUT_BEGIN_CASE("NT_%s", ID_UPR(INODE_NAME(node)));
    OUT_STATEMENT("return \"%s%s\"", DATA_DGNU_GET()->travid, ID_ORIG(INODE_NAME(node)));
    OUT_END_CASE();
    TRAVnext(node);
    return node;
}

node_st *DGNUitraversal(node_st *node)
{
    GeneratorContext *ctx = globals.gen_ctx;
    OUT_BEGIN_CASE("TRAV_%s", ID_UPR(ITRAVERSAL_IPREFIX(node)));
    OUT_BEGIN_SWITCH("n");
    DATA_DGNU_GET()->travid = ID_UPR(ITRAVERSAL_IPREFIX(node));
    TRAVopt(DATA_DGNU_GET()->inodes);
    OUT_BEGIN_DEFAULT_CASE();
    OUT("return \"Unknown\";\n");
    OUT_END_CASE_NO_BREAK();
    OUT_END_SWITCH();
    OUT_END_CASE();
    TRAVnext(node);
    return node;
}
