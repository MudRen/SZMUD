//Cracked by Roath
// Room: /d/beijing/zijincheng/guang3.c

inherit ROOM;

void create()
{
	set("short", "�ٳ�");
	set("long", @LONG
���ǽ����ٳ���ר����Ϊ���־������õġ���������ƽ����
���Ե�����������������Ķ����˲���ѩ���ı�����ÿ���磬�У�
�����̣��ڲٳ��϶��Ǻ�ɱ�������ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wuyingmen",
  "north" : __DIR__"wuyingdian",
  "west" : __DIR__"huanzhangdian",
  "east" : __DIR__"ningdaodian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
