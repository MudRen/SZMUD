// Code of ShenZhou
// ʨʯ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʨʯ");
    set("long", @LONG
��������Ժ�����ʨʯ�����Կ����������µ���ء���ˮ��̣�ǧ
ɽ��ӳ���˳�������ɽ�е�һ��������һ��΢�紵������ˮ������ɽӰ
��ҡ��ʹ��ɽ����
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"right" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
