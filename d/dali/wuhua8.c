// Code of ShenZhou
// Room: /d/dali/wuhua8.c

#include <ansi.h>
#include <dbase.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ȣ�ͨ��������˵����ҡ����˶�¥��ëձ�Ѿ�
���ɴ��ף�����ľ���ϻ���л�����棬�����Щ��ʱ�˵��ֻ���ÿ��
�߰˲�������һ����̨���������̴�ͭ�������γ�����֮����һ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wuhua3.c",
  "enter" : __DIR__"wuhua4.c",
]));
	set("no_clean_up", 0);
set("cost", 1);
	setup();
}
