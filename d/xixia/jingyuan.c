// Code of ShenZhou
// Room: /d/xixia/jingyuan.c

inherit ROOM;

void create()
{
	set("short", "��Զ");
	set("long", @LONG
��Զ�Ǹ�����С�ĳ��򣬻�ɳ�������ʮ��ĵط���һ���ŵ�����
����������ס�ˡ������������һ��ϴ�����ޣ��ۼ��˲��ٴӱ�����
������Щ�����˵�ǵ����Ƴ��������ͻ�ʺ��������ͱ�ʱ���֡���
Ҳ�Ǿ�Զ���������������߲�Զ���ǻƺӣ�������һ��ƬɳĮ��
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"desert",
  "north" : __DIR__"hsxia",
]));
       set("fjing", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
