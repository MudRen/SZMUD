//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��ɽ�µ�ɽ���ϣ���Ƭ�����ɣ�ī��ï�ܣ�ͤͤ������������ɡ��
������ա��������Ұ������ɽ��Ѥ����������������ʯ���յ�
���ϣ���ͤ���̶���ǽ����Ȼ������һ�������ĺ�ˮ����ӯӯ�����
��һ�㡣��ʱһֻˮ���ӹ����棬�����ɫ���˻��������˵�ӳ����
����Ӱ����ɽ���ɡ�
LONG
	);
	set("exits", ([
                "eastdown" : __DIR__"tianchi",
                "northup" : "/d/lingjiu/shanjiao",
        ]));
	set("bing_can", 7);
	set("cost", 4);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
