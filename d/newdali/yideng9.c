// Code of ShenZhou
// yideng quest room 9

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ǰ");
        set("long", @LONG
��������ɽ�۷壬ƽ������һ��СС��Ժ����ǰ��һ��������һ��С�ź��
���ϡ��Ա߶��͵�ɽ������һ��������һЩ�˹��������̨�ף��ƺ���һ������
ɽ�Ľݾ���
LONG);
	set("exits", ([
		"south" : __DIR__"yideng8",
		"enter" : __DIR__"yideng11",
		"down" : __DIR__"maze1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
