//Cracked by Roath
// Room: /d/beijing/west/yonganmenlou.c

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
  "west" : __DIR__"chengqiang7",
  "down" : __DIR__"yonganmen",
  "east" : "/d/beijing/east/chengqiang8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
