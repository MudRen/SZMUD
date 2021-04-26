// Code of ShenZhou
// Room: /d/xiangyang/yueyang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR "����¥" NOR);
	set("long", @LONG
�ഫ����¥��ǰ��Ϊ�����⽫³�����ˮʦ���ı��롣�ƿ�Ԫ������������
˵��������ʱʼ��¥������������¥�����Ἰ���˷ϣ��Զ�ͥ���ϰ�Ǩ�Դˡ�¥
����һ��ƽ���м䣬����ͷ����һ���Ʒ����������Ʒ����д��顰����ʤ״����
�ֺ��ң������ԡ���������¥��������ͥ����ˮ�������䣬����������
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 1, "y" : 3 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"jzjie1",
  "enter" : __DIR__"yueyang1",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
