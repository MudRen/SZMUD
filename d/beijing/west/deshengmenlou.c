//Cracked by Roath
// Room: /d/beijing/west/deshengmenlou.c

inherit ROOM;

void create()
{
	set("short", "��ʤ�ų�¥");
	set("long", @LONG
���ǵ�ʤ�ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"deshengmen",
  "east" : "/d/beijing/east/chengqiang1",
  "southwest" : __DIR__"chengqiang1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
