//Cracked by Roath
// Room: /d/beijing/east/zuoanmenlou.c

inherit ROOM;

void create()
{
	set("short", "���ų�¥");
	set("long", @LONG
�������ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chengqiang8",
  "down" : __DIR__"zuoanmen",
  "east" : __DIR__"chengqiang7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
