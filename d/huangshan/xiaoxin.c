// Code of ShenZhou
// С����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "С����");
    set("long", @LONG
С����һ���پ��ڣ�һ������Ԩ����̤��ʯ�ţ�����סҪ���ȷ�
��һ���紵������ǰ��ɽ���ų�Ͽ����ͷ���裬������������һ
��С�ģ����������׹���ڡ�
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"yixian1",
	"southeast" : __DIR__"banshan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
