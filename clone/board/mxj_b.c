// Code of ShenZhou 
// /clone/board/mxj_b.c 
inherit BULLETIN_BOARD;
#include <ansi.h>  

void create()
{
set_name(HIY"��ڤ��(Mxj)���԰�"NOR, ({ "board" }) );
set("location", "/u/mxj/workroom");
set("board_id", "mxj_b");
set("long", "����һ������ڤ��(Mxj)��������ʦ���������԰塣\n" ); 
setup();
set("capacity", 900); 
replace_program(BULLETIN_BOARD);
}

