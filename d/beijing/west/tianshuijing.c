//Cracked by Roath
// Room: /d/beijing/west/tianshuijing.c

inherit ROOM;

void create()
{
	set("short", "��ˮ����ͬ");
	set("long", @LONG
������ͬ�䲻���ۣ�����Ϊ��ͬ����һ����ˮ������������������
ˮ��������ˮ����ˮ�����١��Ͻ�������ˮ��Ҫÿ��ȥ��Ȫɽ�˻أ���
���ڲ������ˮ���ͶԱ�������ͨ������Ϊ��Ҫ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"youandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
