// Code of ShenZhou
// Room: /d/xixia/jiuguan.c

inherit ROOM;

void create()
{
	set("short", "�ƹ�");
	set("long", @LONG
����һ��С�ƹݣ��������������ţ��忪������棬��ģ�Ĵ�����������
���˶ൽ���������Ъ�ţ�����һ�̰�����ɱ��ţ���⣬���ϼ��ڴ�������̾ƣ�
���㷹�����֮�ʴ��ϼ����������С���Σ���Ǯ�����ֺ�ʵ�ݣ������ر�������
�����ǳ�������������¥��¥�ݣ���������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nandajie",
]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	setup();
	replace_program(ROOM);
}
