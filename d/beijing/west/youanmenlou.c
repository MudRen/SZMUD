//Cracked by Roath
// Room: /d/beijing/west/youanmenlou.c

inherit ROOM;

void create()
{
	set("short", "�Ұ��ų�¥");
	set("long", @LONG
�����Ұ��ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chengqiang6",
  "down" : __DIR__"youanmen",
  "east" : __DIR__"chengqiang7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
