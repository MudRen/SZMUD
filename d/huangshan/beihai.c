// Code of ShenZhou
// ����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����");
    set("long", @LONG
�λ�ɽ�����Ǳ����ġ����︽���ǹ��ճ�������ĺõط�������
��һ�͵꣬���οͿɹ��ޣ��峿���ճ�������������̨�����߿ɵ���
��ͤ��
LONG);

    set("exits", ([ /* sizeof() == 5 */
	"west" : __DIR__"paiyun",
	"south" : __DIR__"guangmin",
	"north" : __DIR__"qinglian",
	"southwest" : __DIR__"feilai",
	"southeast" : __DIR__"mengbi",
	"enter" : __DIR__"kedian",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
