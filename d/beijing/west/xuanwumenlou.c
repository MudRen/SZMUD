//Cracked by Roath
// Room: /d/beijing/west/xuanwumenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���������ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"xuanwumen",
  "east" : __DIR__"chengqiang5",
  "northwest" : __DIR__"chengqiang3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
