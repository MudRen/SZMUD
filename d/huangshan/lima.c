// Code of ShenZhou
// ����ͤ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����ͤ");
    set("long", @LONG
����ɰ���ϵ���Ҷ����һ��ͤ��ͤ�԰�����������С�����ն�
�����Ǹ���̫ƽ��ʮ��ʯ�̴��֣�ÿ�����ж��ɰ˳ߣ�������������
Ե��������ȵ��ͱ�֮��ʵΪ���ס�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southdown" : __DIR__"ciguang",
	"northup" : __DIR__"banshan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
