//Cracked by Roath
// Room: /d/beijing/east/dianmen.c

inherit ROOM;

void create()
{
	set("short", "�ذ���");
	set("long", @LONG
�ذ����ǻʳǵĺ��ţ���ʳ�������찲��ңң��ԣ���
�����찲�����ƻֺ꣬����ǽ���ʣ���ɫ�������������⣬��
���ûʣ��������¼����֮�������Ͼ����Ͻ����ˣ���ͨ����
�ǲ��ܿ����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"zhaoyangdajie2",
  "south" : __DIR__"shouhuangdian",
  "north" : "/d/beijing/west/gulou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
