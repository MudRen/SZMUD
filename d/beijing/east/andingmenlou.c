//Cracked by Roath
// Room: /d/beijing/east/andingmenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���ǰ����ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chengqiang1",
  "down" : __DIR__"andingmen",
  "east" : __DIR__"chengqiang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
