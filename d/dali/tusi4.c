// Code of ShenZhou
// Room: /d/newdali/tusi4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ǻ�������һ¥һ�׵���ʽ�������ݽǵ��ϸ�ܣ����ξ�����
����ͼ�������޻�ľ�ĵ�̣�������������·��ӱ����������ʮ������˾
���б�����õ�һ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tusi2",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
