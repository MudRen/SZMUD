// Code of ShenZhou 
// /clone/board/mxj_b.c 
inherit BULLETIN_BOARD;
#include <ansi.h>  

void create()
{
set_name(HIY"马冥风(Mxj)留言板"NOR, ({ "board" }) );
set("location", "/u/mxj/workroom");
set("board_id", "mxj_b");
set("long", "这是一个供马冥风(Mxj)与其他巫师交留的留言板。\n" ); 
setup();
set("capacity", 900); 
replace_program(BULLETIN_BOARD);
}

