//Cracked by Roath
// Room: /d/beijing/west/fuchengmenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���Ǹ����ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chengqiang3",
  "north" : __DIR__"chengqiang2",
  "down" : __DIR__"fuchengmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
