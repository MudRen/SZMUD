// Code of ShenZhou
// �ȹ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�ȹ��");
    set("long", @LONG
�߹�����ͤ�������¶��һ����ɲ���Ǿ��Ǵȹ�󡣸�����Ⱥ
ɽ������ï��������ӳ������ʮ���ľ���
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"wengquan",
	"northup" : __DIR__"lima",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
