// Code of ShenZhou
// ��̨
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��̨");
    set("long", @LONG
��������Ժ���ҹ���ʯ����������̨��վ����̨�������ƺ���ΡΡ
׳�ۣ�����ʤ�ա�ʱ���ƾ��˼��������İ���ʱ��������ɢ��Ⱥ�������
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"left" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
