// Code of ShenZhou
// ����ʯ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����ʯ");
    set("long", @LONG
����ɽ�����ƹ����������Сɽ��������Ĺȣ����������ҷ壬
������һ���ʯ���ϼ���Բ����ò���ҡ���Ϊ��ʯ������ɽ��֮�ϣ�
��ʯ�²���ɽ���Ƿֿ��ģ����Ա���Ϊ����ʯ��
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"northwest" : __DIR__"paiyun",
	"northeast" : __DIR__"beihai",
	"southeast" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
