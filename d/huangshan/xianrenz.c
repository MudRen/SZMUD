// Code of ShenZhou
// ����ָ·
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����ָ·");
    set("long", @LONG
����ɽ·�ϣ�ֻ����������ʯ����Ŀ���ǣ��������ɣ����涷
�á�����һ���ʯ������ϲȵ���������ɿɵǣ���Ϊ��ϲȵ��÷����
����������һ���ʯ�ԴӲ���һ������ϲȵ�����һλ������۵���
�ˣ��������֣�ָ����·�Ե�һ���辶�����ǽ���������ָ·����
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"xianren",
	"west" : __DIR__"yunfang",
	"northup" : __DIR__"mengbi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
