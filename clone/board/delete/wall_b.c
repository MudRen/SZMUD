inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIY"�˴������������ԣ�лл��~"NOR,({"board"}));
set("location", "/u/wall/workroom");
set("board_id","wall_b");
set("long","���ǻ����������ʦ���������԰塣\n");
setup();
set("capacity",300);
replace_program(BULLETIN_BOARD);
}


