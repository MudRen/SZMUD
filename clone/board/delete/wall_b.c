inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIY"此处必须文明留言，谢谢！~"NOR,({"board"}));
set("location", "/u/wall/workroom");
set("board_id","wall_b");
set("long","这是怀念和其他巫师交流的留言板。\n");
setup();
set("capacity",300);
replace_program(BULLETIN_BOARD);
}


